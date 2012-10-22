#define BUILDING_NODE_EXTENSION

#include <node_inc.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "cv_types.h"
#include "help.h"
#include "mat.h"

using namespace v8;
using namespace help;

void exposeConstants(v8::Handle<v8::Object> target) {
	NODE_DEFINE_CONSTANT(target, CV_8U);
	NODE_DEFINE_CONSTANT(target, CV_8S);
	NODE_DEFINE_CONSTANT(target, CV_16U);
	NODE_DEFINE_CONSTANT(target, CV_16S);
	NODE_DEFINE_CONSTANT(target, CV_32S);
	NODE_DEFINE_CONSTANT(target, CV_32F);
	NODE_DEFINE_CONSTANT(target, CV_64F);
	NODE_DEFINE_CONSTANT(target, CV_USRTYPE1);
	NODE_DEFINE_CONSTANT(target, CV_8UC1);
	NODE_DEFINE_CONSTANT(target, CV_8UC2);
	NODE_DEFINE_CONSTANT(target, CV_8UC3);
	NODE_DEFINE_CONSTANT(target, CV_8UC4);
	NODE_DEFINE_CONSTANT(target, CV_8SC1);
	NODE_DEFINE_CONSTANT(target, CV_8SC2);
	NODE_DEFINE_CONSTANT(target, CV_8SC3);
	NODE_DEFINE_CONSTANT(target, CV_8SC4);
	NODE_DEFINE_CONSTANT(target, CV_16UC1);
	NODE_DEFINE_CONSTANT(target, CV_16UC2);
	NODE_DEFINE_CONSTANT(target, CV_16UC3);
	NODE_DEFINE_CONSTANT(target, CV_16UC4);
	NODE_DEFINE_CONSTANT(target, CV_16SC1);
	NODE_DEFINE_CONSTANT(target, CV_16SC2);
	NODE_DEFINE_CONSTANT(target, CV_16SC3);
	NODE_DEFINE_CONSTANT(target, CV_16SC4);
	NODE_DEFINE_CONSTANT(target, CV_32SC1);
	NODE_DEFINE_CONSTANT(target, CV_32SC2);
	NODE_DEFINE_CONSTANT(target, CV_32SC3);
	NODE_DEFINE_CONSTANT(target, CV_32SC4);
	NODE_DEFINE_CONSTANT(target, CV_32FC1);
	NODE_DEFINE_CONSTANT(target, CV_32FC2);
	NODE_DEFINE_CONSTANT(target, CV_32FC3);
	NODE_DEFINE_CONSTANT(target, CV_32FC4);
	NODE_DEFINE_CONSTANT(target, CV_64FC1);
	NODE_DEFINE_CONSTANT(target, CV_64FC2);
	NODE_DEFINE_CONSTANT(target, CV_64FC3);
	NODE_DEFINE_CONSTANT(target, CV_64FC4);
	NODE_DEFINE_CONSTANT(target, CV_BGR2BGRA);
	NODE_DEFINE_CONSTANT(target, CV_RGB2RGBA);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2BGR);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2RGBA);
	NODE_DEFINE_CONSTANT(target, CV_RGB2BGRA);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2RGB);
	NODE_DEFINE_CONSTANT(target, CV_RGB2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2RGBA);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2BGRA);
	NODE_DEFINE_CONSTANT(target, CV_BGR2GRAY);
	NODE_DEFINE_CONSTANT(target, CV_RGB2GRAY);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2BGR);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2RGB);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2BGRA);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2RGBA);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2GRAY);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2GRAY);
	NODE_DEFINE_CONSTANT(target, CV_BGR2BGR565);
	NODE_DEFINE_CONSTANT(target, CV_RGB2BGR565);
	NODE_DEFINE_CONSTANT(target, CV_BGR5652BGR);
	NODE_DEFINE_CONSTANT(target, CV_BGR5652RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2BGR565);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2BGR565);
	NODE_DEFINE_CONSTANT(target, CV_BGR5652BGRA);
	NODE_DEFINE_CONSTANT(target, CV_BGR5652RGBA);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2BGR565);
	NODE_DEFINE_CONSTANT(target, CV_BGR5652GRAY);
	NODE_DEFINE_CONSTANT(target, CV_BGR2BGR555);
	NODE_DEFINE_CONSTANT(target, CV_RGB2BGR555);
	NODE_DEFINE_CONSTANT(target, CV_BGR5552BGR);
	NODE_DEFINE_CONSTANT(target, CV_BGR5552RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGRA2BGR555);
	NODE_DEFINE_CONSTANT(target, CV_RGBA2BGR555);
	NODE_DEFINE_CONSTANT(target, CV_BGR5552BGRA);
	NODE_DEFINE_CONSTANT(target, CV_BGR5552RGBA);
	NODE_DEFINE_CONSTANT(target, CV_GRAY2BGR555);
	NODE_DEFINE_CONSTANT(target, CV_BGR5552GRAY);
	NODE_DEFINE_CONSTANT(target, CV_BGR2XYZ);
	NODE_DEFINE_CONSTANT(target, CV_RGB2XYZ);
	NODE_DEFINE_CONSTANT(target, CV_XYZ2BGR);
	NODE_DEFINE_CONSTANT(target, CV_XYZ2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2YCrCb);
	NODE_DEFINE_CONSTANT(target, CV_RGB2YCrCb);
	NODE_DEFINE_CONSTANT(target, CV_YCrCb2BGR);
	NODE_DEFINE_CONSTANT(target, CV_YCrCb2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2HSV);
	NODE_DEFINE_CONSTANT(target, CV_RGB2HSV);
	NODE_DEFINE_CONSTANT(target, CV_BGR2Lab);
	NODE_DEFINE_CONSTANT(target, CV_RGB2Lab);
	NODE_DEFINE_CONSTANT(target, CV_BayerBG2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BayerGB2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BayerRG2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BayerGR2BGR);
	NODE_DEFINE_CONSTANT(target, CV_BayerBG2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BayerGB2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BayerRG2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BayerGR2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2Luv);
	NODE_DEFINE_CONSTANT(target, CV_RGB2Luv);
	NODE_DEFINE_CONSTANT(target, CV_BGR2HLS);
	NODE_DEFINE_CONSTANT(target, CV_RGB2HLS);
	NODE_DEFINE_CONSTANT(target, CV_HSV2BGR);
	NODE_DEFINE_CONSTANT(target, CV_HSV2RGB);
	NODE_DEFINE_CONSTANT(target, CV_Lab2BGR);
	NODE_DEFINE_CONSTANT(target, CV_Lab2RGB);
	NODE_DEFINE_CONSTANT(target, CV_Luv2BGR);
	NODE_DEFINE_CONSTANT(target, CV_Luv2RGB);
	NODE_DEFINE_CONSTANT(target, CV_HLS2BGR);
	NODE_DEFINE_CONSTANT(target, CV_HLS2RGB);
	NODE_DEFINE_CONSTANT(target, CV_BayerBG2BGR_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerGB2BGR_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerRG2BGR_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerGR2BGR_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerBG2RGB_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerGB2RGB_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerRG2RGB_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BayerGR2RGB_VNG);
	NODE_DEFINE_CONSTANT(target, CV_BGR2HSV_FULL);
	NODE_DEFINE_CONSTANT(target, CV_RGB2HSV_FULL);
	NODE_DEFINE_CONSTANT(target, CV_BGR2HLS_FULL);
	NODE_DEFINE_CONSTANT(target, CV_RGB2HLS_FULL);
	NODE_DEFINE_CONSTANT(target, CV_HSV2BGR_FULL);
	NODE_DEFINE_CONSTANT(target, CV_HSV2RGB_FULL);
	NODE_DEFINE_CONSTANT(target, CV_HLS2BGR_FULL);
	NODE_DEFINE_CONSTANT(target, CV_HLS2RGB_FULL);
	NODE_DEFINE_CONSTANT(target, CV_LBGR2Lab);
	NODE_DEFINE_CONSTANT(target, CV_LRGB2Lab);
	NODE_DEFINE_CONSTANT(target, CV_LBGR2Luv);
	NODE_DEFINE_CONSTANT(target, CV_LRGB2Luv);
	NODE_DEFINE_CONSTANT(target, CV_Lab2LBGR);
	NODE_DEFINE_CONSTANT(target, CV_Lab2LRGB);
	NODE_DEFINE_CONSTANT(target, CV_Luv2LBGR);
	NODE_DEFINE_CONSTANT(target, CV_Luv2LRGB);
	NODE_DEFINE_CONSTANT(target, CV_BGR2YUV);
	NODE_DEFINE_CONSTANT(target, CV_RGB2YUV);
	NODE_DEFINE_CONSTANT(target, CV_YUV2BGR);
	NODE_DEFINE_CONSTANT(target, CV_YUV2RGB);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_SCRAMBLED);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_NORMAL);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_USE_AVG);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_SCALE);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_ROWS);
	NODE_DEFINE_CONSTANT(target, CV_COVAR_COLS);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_BINARY);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_BINARY_INV);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_TRUNC);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_TOZERO);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_TOZERO_INV);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_MASK);
	NODE_DEFINE_CONSTANT(target, CV_THRESH_OTSU);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_MOUSEMOVE);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONDOWN);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONDOWN);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONDOWN);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONUP);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONUP);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONUP);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_LBUTTONDBLCLK);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_RBUTTONDBLCLK);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_MBUTTONDBLCLK);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_LBUTTON);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_RBUTTON);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_MBUTTON);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_CTRLKEY);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_SHIFTKEY);
	NODE_DEFINE_CONSTANT(target, CV_EVENT_FLAG_ALTKEY);
}

namespace cv {
	void exposeConstants(Handle<Object> target) {
		NODE_DEFINE_CONSTANT(target, THRESH_BINARY);
		NODE_DEFINE_CONSTANT(target, THRESH_BINARY_INV);
		NODE_DEFINE_CONSTANT(target, THRESH_TRUNC);
		NODE_DEFINE_CONSTANT(target, THRESH_TOZERO);
		NODE_DEFINE_CONSTANT(target, THRESH_TOZERO_INV);
		NODE_DEFINE_CONSTANT(target, THRESH_MASK);
		NODE_DEFINE_CONSTANT(target, THRESH_OTSU);
		NODE_DEFINE_CONSTANT(target, DECOMP_LU);
		NODE_DEFINE_CONSTANT(target, DECOMP_SVD);
		NODE_DEFINE_CONSTANT(target, DECOMP_EIG);
		NODE_DEFINE_CONSTANT(target, DECOMP_CHOLESKY);
		NODE_DEFINE_CONSTANT(target, DECOMP_QR);
		NODE_DEFINE_CONSTANT(target, DECOMP_NORMAL);
		NODE_DEFINE_CONSTANT(target, NORM_INF);
		NODE_DEFINE_CONSTANT(target, NORM_L1);
		NODE_DEFINE_CONSTANT(target, NORM_L2);
		NODE_DEFINE_CONSTANT(target, NORM_TYPE_MASK);
		NODE_DEFINE_CONSTANT(target, NORM_RELATIVE);
		NODE_DEFINE_CONSTANT(target, NORM_MINMAX);
		NODE_DEFINE_CONSTANT(target, CMP_EQ);
		NODE_DEFINE_CONSTANT(target, CMP_GT);
		NODE_DEFINE_CONSTANT(target, CMP_GE);
		NODE_DEFINE_CONSTANT(target, CMP_LT);
		NODE_DEFINE_CONSTANT(target, CMP_LE);
		NODE_DEFINE_CONSTANT(target, CMP_NE);
		NODE_DEFINE_CONSTANT(target, GEMM_1_T);
		NODE_DEFINE_CONSTANT(target, GEMM_2_T);
		NODE_DEFINE_CONSTANT(target, GEMM_3_T);
		NODE_DEFINE_CONSTANT(target, DFT_INVERSE);
		NODE_DEFINE_CONSTANT(target, DFT_SCALE);
		NODE_DEFINE_CONSTANT(target, DFT_ROWS);
		NODE_DEFINE_CONSTANT(target, DFT_COMPLEX_OUTPUT);
		NODE_DEFINE_CONSTANT(target, DFT_REAL_OUTPUT);
		NODE_DEFINE_CONSTANT(target, DCT_INVERSE);
		NODE_DEFINE_CONSTANT(target, DCT_ROWS);
	}
}

Handle<Value> namedWindow(const Arguments& args) {

	return proc_scope([&]() {

		args_bag bag(args);
		cv::namedWindow(bag.parse<std::string>(0, "window name"), CV_WINDOW_AUTOSIZE);

	});
}

Handle<Value> waitKey(const Arguments& args) {

	return proc_scope([&]() {

		//cv::waitKey(static_cast<int>(std::floor(cast<double>(args) + 0.5)));
		args_bag bag(args);
		cv::waitKey(bag.parse<int>(0, "wait", 0));

	});
}

Handle<Value> testObjectProperties(const Arguments& args) {

	return fun_scope([&]() -> Handle<Value> {

		auto spec = object_proxy::from_args(args, 0);

		spec.set("int", spec.get<int>("int") + 1);
		spec.set("booltrue", !spec.get<bool>("booltrue"));
		spec.set("boolfalse", !spec.get<bool>("boolfalse"));
		spec.set("boolobjtrue", !spec.get<bool>("boolobjtrue"));
		spec.set("boolobjfalse", !spec.get<bool>("boolobjfalse"));
		spec.set("string", spec.get<std::string>("string") + "x");
		spec.set("uint", spec.get<unsigned int>("uint") + 1);
		spec.set("number", spec.get<double>("number") + 1);

		auto point = spec.get<cv::Point>("point");
		point.x = point.x + 1;
		point.y = point.y + 1;
		spec.set("point1", point);

		auto point2f = spec.get<cv::Point2f>("point2f");
		point2f.x = point2f.x + 1;
		point2f.y = point2f.y + 1;
		spec.set("point2f1", point2f);

		auto size = spec.get<cv::Size>("size");
		size.width = size.width + 1;
		size.height = size.height + 1;
		spec.set("size1", size);

		auto size2f = spec.get<cv::Size2f>("size2f");
		size2f.width = size2f.width + 1;
		size2f.height = size2f.height + 1;
		spec.set("size2f1", size2f);

		auto rect = spec.get<cv::Rect>("rect");
		rect.x = rect.x + 1;
		rect.y = rect.y + 1;
		rect.width = rect.width + 1;
		rect.height = rect.height + 1;
		spec.set("rect1", rect);

		auto range = spec.get<cv::Range>("range");
		range.start = range.start + 1;
		range.end = range.end + 1;
		spec.set("range1", range);

		auto rr = spec.get<cv::RotatedRect>("rr");
		rr.angle = rr.angle + 1;
		rr.center.x = rr.center.x + 1;
		rr.center.y = rr.center.y + 1;
		rr.size.width = rr.size.width + 1;
		rr.size.height = rr.size.height + 1;
		spec.set("rr1", rr);

		auto vec = spec.get< std::vector<int> >("vec");
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			++*it;
		}
		spec.set("vec1", vec);

		return args[0];

	});
}

Handle<Value> createMat(const Arguments& args) {
	HandleScope scope;
	return scope.Close(Mat::newInstance(args));
}

void init(Handle<Object> target) {
	exposeConstants(target);
	cv::exposeConstants(target);
	Mat::init();

	NODE_SET_METHOD(target, "testObjectProperties", testObjectProperties);
	NODE_SET_METHOD(target, "namedWindow", namedWindow);
	NODE_SET_METHOD(target, "waitKey", waitKey);
	NODE_SET_METHOD(target, "createMat", createMat);
	NODE_SET_METHOD(target, "imshow", Mat::imshow);
	NODE_SET_METHOD(target, "imread", Mat::imread);
	NODE_SET_METHOD(target, "cvtColor", Mat::cvtColor);
}

NODE_MODULE(opencv2, init)