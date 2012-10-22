#define BUILDING_NODE_EXTENSION

#include "help.h"

using namespace std;

// template<typename NT>
// void help::check_type(v8::Handle< v8::Value > const& h, int index) {
	
// 	throw help::type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] unsupported type");

// }

// template<>
// void help::check_type<double>(v8::Handle< v8::Value > const& h, int index)
// {

// 	if (!h->IsNumber())
// 		throw help::type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] must be a number");

// }

// template<>
// void help::check_type<std::string>(v8::Handle< v8::Value > const& h, int index)
// {

// 	if (!h->IsString())
// 		throw help::type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] must be a string");

// }

void help::alert(const std::string& argName, const std::string& msg) {
	throw help::type_error(argName + " must be " + msg);
}

