#define BUILDING_NODE_EXTENSION

#ifndef CV_TYPES_H
#define CV_TYPES_H

#include "help.h"
#include "object_proxy.h"
#include <opencv2/core/core.hpp>

namespace help {
	template<typename T>
	class jso_variable {
		static void set(object_proxy& o, const T& val);
		static T get(object_proxy& o, const std::string& argName);
	};

	// Factored out common functionality in js<cv::x> instantiations out into jso_common with variabilities into jso_variable
	template<typename T>
	class jso_common : public js_base<T> {
	public:
		jso_common(v8::Handle<v8::Value> argv) : js_base<T>(argv) {}
		static v8::Handle<v8::Value> to_handle(const T& val) {

			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			auto o = object_proxy::from_object(obj);
			jso_variable<T>::set(o, val);
			return scope.Close(obj);
		}
	private:
		virtual T parse_impl(const std::string& argName) {
			
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			auto o = object_proxy::from_object(obj);

			return jso_variable<T>::get(o, argName);
		}
		virtual bool is_type() {
			return v->IsObject();
		}
	};

	template<>
	class js<cv::Point> : public jso_common<cv::Point> {
	public:
		js<cv::Point>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Point> {
	public:
		static void set(object_proxy& o, const cv::Point& val) {
			o.set<int>("x", val.x);
			o.set<int>("y", val.y);
		}
		static cv::Point get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Point with int properties x, y";
			if (!o.is_valid() || !o.has("x") || !o.has("y"))
				alert(argName, msg);

			cv::Point val;
			val.x = o.get<int>("x");
			val.y = o.get<int>("y");
			return val;
		}
	};

	template<>
	class js<cv::Point2f> : public jso_common<cv::Point2f> {
	public:
		js<cv::Point2f>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Point2f> {
	public:
		static void set(object_proxy& o, const cv::Point2f& val) {
			o.set<float>("x", val.x);
			o.set<float>("y", val.y);
		}
		static cv::Point2f get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Point2f with float properties x, y";
			if (!o.is_valid() || !o.has("x") || !o.has("y"))
				alert(argName, msg);

			cv::Point2f val;
			val.x = o.get<float>("x");
			val.y = o.get<float>("y");
			return val;
		}
	};

	template<>
	class js<cv::Size> : public jso_common<cv::Size> {
	public:
		js<cv::Size>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Size> {
	public:
		static void set(object_proxy& o, const cv::Size& val) {
			o.set<int>("width", val.width);
			o.set<int>("height", val.height);
		}
		static cv::Size get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Size with int properties width, height";
			if (!o.is_valid() || !o.has("width") || !o.has("height"))
				alert(argName, msg);

			cv::Size val;
			val.width = o.get<int>("width");
			val.height = o.get<int>("height");
			return val;
		}
	};

	template<>
	class js<cv::Size2f> : public jso_common<cv::Size2f> {
	public:
		js<cv::Size2f>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Size2f> {
	public:
		static void set(object_proxy& o, const cv::Size2f& val) {
			o.set<float>("width", val.width);
			o.set<float>("height", val.height);
		}
		static cv::Size2f get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Size2f with float properties width, height";
			if (!o.is_valid() || !o.has("width") || !o.has("height"))
				alert(argName, msg);

			cv::Size2f val;
			val.width = o.get<float>("width");
			val.height = o.get<float>("height");
			return val;
		}
	};

	template<>
	class js<cv::Rect> : public jso_common<cv::Rect> {
	public:
		js<cv::Rect>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Rect> {
	public:
		static void set(object_proxy& o, const cv::Rect& val) {
			o.set<int>("x", val.x);
			o.set<int>("y", val.y);
			o.set<int>("width", val.width);
			o.set<int>("height", val.height);
		}
		static cv::Rect get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Rect with int properties x, y, width, height";
			if (!o.is_valid() || !o.has("width") || !o.has("height") || !o.has("x") || !o.has("y"))
				alert(argName, msg);

			cv::Rect val;
			val.x = o.get<int>("x");
			val.y = o.get<int>("y");
			val.width = o.get<int>("width");
			val.height = o.get<int>("height");
			return val;
		}
	};

	template<>
	class js<cv::Range> : public jso_common<cv::Range> {
	public:
		js<cv::Range>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::Range> {
	public:
		static void set(object_proxy& o, const cv::Range& val) {
			o.set<int>("start", val.start);
			o.set<int>("end", val.end);
		}
		static cv::Range get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a Range with int properties start, end";
			if (!o.is_valid() || !o.has("start") || !o.has("end"))
				alert(argName, msg);

			cv::Range val;
			val.start = o.get<int>("start");
			val.end = o.get<int>("end");
			return val;
		}
	};

	template<>
	class js<cv::RotatedRect> : public jso_common<cv::RotatedRect> {
	public:
		js<cv::RotatedRect>(v8::Handle<v8::Value> argv) : jso_common(argv) {}
	};

	template<>
	class jso_variable<cv::RotatedRect> {
	public:
		static void set(object_proxy& o, const cv::RotatedRect& val) {
			o.set<float>("angle", val.angle);
			o.set<cv::Point2f>("center", val.center);
			o.set<cv::Size2f>("size", val.size);
		}
		static cv::RotatedRect get(const object_proxy& o, const std::string& argName) {
			static const char* msg = "a RotatedRect with float angle, Point2f center, Size2f size";
			if (!o.is_valid() || !o.has("angle") || !o.has("center") || !o.has("size"))
				alert(argName, msg);

			cv::RotatedRect val;
			val.angle = o.get<float>("angle");
			val.center = o.get<cv::Point2f>("center");
			val.size = o.get<cv::Size2f>("size");
			return val;
		}
	};


}

#endif