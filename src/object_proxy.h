#define BUILDING_NODE_EXTENSION

#ifndef OBJECT_PROXY_H
#define OBJECT_PROXY_H

#include <string>
#include "node_inc.h"

class object_proxy {
public:
	static object_proxy from_args(const v8::Arguments& args, int index);
	static object_proxy from_object(v8::Handle< v8::Object > object);
	~object_proxy();
	template <typename T>
	T get(const std::string& prop_name) const {
		auto prop = get_val(prop_name);
		return help::js<T>(prop).parse(prop_name);
	}
	template <typename T>
	void set(const std::string& prop_name, T v) {
		obj->Set(String::NewSymbol(prop_name.c_str()), help::js<T>::to_handle(v));
	}
	object_proxy get_object(const std::string& prop_name);
	bool has(const std::string& prop_name) const;
	bool is_valid() const;
private:
	object_proxy(const v8::Arguments& args, int index);
	object_proxy(v8::Handle< v8::Object > object);
	v8::Local<v8::Value> object_proxy::get_val(const std::string& prop_name) const;
	v8::Persistent<v8::Object> obj;
};

#endif