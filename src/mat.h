#define BUILDING_NODE_EXTENSION

#ifndef MAT_H
#define MAT_H

#include "node_inc.h"
#include <opencv2/core/core.hpp>
#include "object_proxy.h"

class Mat : public node::ObjectWrap {
public:
	static void init();
	static v8::Handle<v8::Value> newInstance(const v8::Arguments& args);
	static v8::Handle<v8::Value> imshow(const v8::Arguments& args);
	static v8::Handle<v8::Value> imread(const v8::Arguments& args);
	static v8::Handle<v8::Value> cvtColor(const v8::Arguments& args);

private:
	Mat(cv::Mat);
	~Mat();

	static v8::Persistent<v8::Function> constructor;
	static v8::Handle<v8::Value> funcTemplate(const v8::Arguments& args);
	static Mat* fromSpec(object_proxy spec);
	static v8::Handle<v8::Value> wrapFresh(cv::Mat newMat);

	cv::Mat m;
};


	
#endif