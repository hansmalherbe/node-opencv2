#define BUILDING_NODE_EXTENSION

#include <iostream>
#include "Mat.h"
#include "help.h"
#include <boost/any.hpp>
#include "object_proxy.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace v8;
using namespace help;

Mat::Mat(cv::Mat matobj) : m(matobj) {};
Mat::~Mat() {};

Persistent<Function> Mat::constructor;

void Mat::init() {

	auto tpl = FunctionTemplate::New(funcTemplate);
	tpl->SetClassName(String::NewSymbol("Mat"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	constructor = Persistent<Function>::New(tpl->GetFunction());
}

Mat* Mat::fromSpec(object_proxy spec) {

	if (spec.has("rows") && spec.has("cols")) {
		return new Mat(cv::Mat(spec.get<int>("rows"), spec.get<int>("cols"), CV_8UC3));
	}
	return new Mat(cv::Mat());
}

Handle<Value> Mat::funcTemplate(const Arguments& args) {
	
	return try_scope([&]()->Handle<Value> {

		auto spec = object_proxy::from_args(args, 0);
		Mat* matp = fromSpec(spec);

		if (!matp)
			throw reference_error("Cannot construct Mat object");

		matp->Wrap(args.This());

		return args.This();

	});
}

Handle<Value> Mat::newInstance(const Arguments& args) {

	HandleScope scope;

	const unsigned argc = 1;
	Handle<Value> argv[argc] = { args[0] };
	auto instance = constructor->NewInstance(argc, argv);

	return scope.Close(instance);
}

Handle<Value> Mat::imshow(const Arguments& args) {

	return proc_scope([&]() {

		auto matobj = unwrap<Mat>(args, 1, "Mat");
		cv::imshow(js<std::string>(args[0]).parse("window name"), matobj->m);

	});
}

Handle<Value> Mat::wrapFresh(cv::Mat newMat) {

	Handle<Value> argv[1] = { Object::New() };
	Local<Object> instance = constructor->NewInstance(1, argv);
	Mat* matobj = new Mat(newMat);
	matobj->Wrap(instance);
	return instance;

}

Handle<Value> Mat::imread(const Arguments& args) {

	return fun_scope([&]()->Handle<Value> {
		
		//auto path = cast(args);
		auto path = js<std::string>(args[0]).parse("file path");
		cv::Mat m(cv::imread(path, -1));
		if (!m.data)
			throw reference_error("Could not open or find " + path);
		return wrapFresh(m);

	});
}

Handle<Value> Mat::cvtColor(const Arguments& args) {

	return proc_scope([&]() {
		
		auto mat0 = unwrap<Mat>(args, 0, "Mat");
		auto mat1 = unwrap<Mat>(args, 1, "Mat");
		//int code = has<2>(args) ? js<int>::out(args[2], "code") : CV_RGB2GRAY;
		
		int code = js<int>(args[2]).parse("code", CV_RGB2GRAY);
		cv::cvtColor(mat0->m, mat1->m, code);

	});
}

