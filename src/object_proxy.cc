#define BUILDING_NODE_EXTENSION

#include "object_proxy.h"
#include <boost/lexical_cast.hpp>
#include "error.h"
#include "help.h"

using namespace v8;

object_proxy object_proxy::from_args(const v8::Arguments& args, int index) {
	return object_proxy(args, index);
}

object_proxy object_proxy::from_object(v8::Handle< v8::Object > object) {
	return object_proxy(object);
}

object_proxy::object_proxy(const Arguments& args, int index) {
	if (args.Length() <= index)
		throw help::range_error("Need at least " + boost::lexical_cast< std::string >(index + 1) + " parameter" + (index == 0 ? "" : "s"));
	auto arg = args[index];
	if (!arg->IsObject()) 
		throw help::type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] must be an object");
	obj = Persistent<Object>::New(arg->ToObject());
}

object_proxy::object_proxy(v8::Handle<v8::Object> object) {
	obj = Persistent<Object>::New(object);
}

object_proxy::~object_proxy() {
	obj.Dispose();
}

Local<Value> object_proxy::get_val(const std::string& prop_name) const {
	auto prop = obj->Get(String::NewSymbol(prop_name.c_str()));
	if (prop.IsEmpty() || prop->IsUndefined() || prop->IsNull())
		throw help::reference_error(prop_name + " does not exist");	
	return prop;
}

object_proxy object_proxy::get_object(const std::string& prop_name) {
	auto prop = get_val(prop_name);
	if (!prop->IsObject())
		throw help::type_error(prop_name + " must be an object");
	return from_object(prop->ToObject());
}

bool object_proxy::has(const std::string& prop_name) const {
	auto prop = obj->Get(String::NewSymbol(prop_name.c_str()));
	return !prop.IsEmpty() && !prop->IsUndefined();
}

bool object_proxy::is_valid() const {
	return !obj.IsEmpty() && !obj->IsUndefined();
}

