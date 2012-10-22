#define BUILDING_NODE_EXTENSION

#ifndef HELP_H
#define HELP_H

#include <vector>
#include <node_inc.h>
#include <boost/lexical_cast.hpp>
#include <boost/any.hpp>
#include "error.h"

namespace help {
	void alert(const std::string& argName, const std::string& msg);

	template <typename T>
	class js_base {
	public:
		typedef std::string (*f)();
		js_base(v8::Handle<v8::Value> argv) : v(argv) {}
		bool is_valid() {
			return !v.IsEmpty() && is_type();
		}
		T parse(const std::string& argName, T def) {
			return v.IsEmpty() || v->IsUndefined() ? def : parse(argName);
		}
		T parse(const std::string& argName) {
			return parse_impl(argName);
		}
		// template <typename Function>
		// T parse(Function get_argname) {
		// 	return parse_impl(get_argname());
		// }
		static v8::Handle<v8::Value> to_handle(const T& val);
	protected:
		v8::Handle<v8::Value> v;
	private:
		virtual T parse_impl(const std::string& argName) = 0;
		virtual bool is_type() = 0;
	};

	template <typename T>
	class js : public js_base<T> {
	};

	template<>
	class js<int> : public js_base<int> {
	public:
		js<int>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const int& val) {
			return v8::Int32::New(val);
		}
	private:
		virtual int parse_impl(const std::string& argName) {
			static const std::string msg = "a 32-bit signed integer";
			if (!is_valid())
				alert(argName, msg);
			return v->Int32Value();
		}
		virtual bool is_type() {
			return v->IsInt32();
		}
	};

	template<typename T>
	class js< std::vector<T> > : public js_base< std::vector<T> > {
	public:
		js< std::vector<T> >(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const std::vector<T> & val) {
			v8::HandleScope scope;
			auto vals_handle = v8::Array::New(static_cast<int>(val.size()));
			uint32_t i = 0;
			for (auto it = val.begin(); it != val.end(); ++it) {
				vals_handle->Set(i, js<T>::to_handle(*it));
				++i;
			}
			return scope.Close(vals_handle);
		}
	private:
		virtual std::vector<T>  parse_impl(const std::string& argName) {
			static const std::string msg = "an array";
			if (!is_valid())
				alert(argName, msg);

			std::vector<T> values;
			auto vals_handle = v8::Array::Cast(*v);
			uint32_t len = vals_handle->Length();
			for (uint32_t i = 0; i < len; ++i) {
				values.push_back(js<T>(vals_handle->Get(i)).parse("item " + boost::lexical_cast< std::string >(i)));
				// values.push_back(js<T>(vals_handle->Get(i)).parse_f([=]()->std::string {
				// 	return "item " + boost::lexical_cast< std::string >(i);
				// }));
			}
			return values;
		}
		virtual bool is_type() {
			return v->IsArray();
		}
	};

	template<>
	class js<double> : public js_base<double> {
	public:
		js<double>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const double& val) {
			return v8::Number::New(val);
		}
	private:
		virtual double parse_impl(const std::string& argName) {
			static const std::string msg = "a number";
			if (!is_valid())
				alert(argName, msg);
			return v->NumberValue();
		}
		virtual bool is_type() {
			return v->IsNumber();
		}
	};

	template<>
	class js<float> : public js_base<float> {
	public:
		js<float>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const float& val) {
			return v8::Number::New(val);
		}
	private:
		virtual float parse_impl(const std::string& argName) {
			static const std::string msg = "a number";
			if (!is_valid())
				alert(argName, msg);
			return static_cast<float>(v->NumberValue());
		}
		virtual bool is_type() {
			return v->IsNumber();
		}
	};

	template<>
	class js<unsigned int> : public js_base<unsigned int> {
	public:
		js<unsigned int>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const unsigned int& val) {
			return v8::Uint32::New(val);
		}
	private:
		virtual unsigned int parse_impl(const std::string& argName) {
			static const std::string msg = "a 32-bit unsigned integer";
			if (!is_valid())
				alert(argName, msg);
			return v->Uint32Value();
		}
		virtual bool is_type() {
			return v->IsUint32();
		}
	};

	template<>
	class js<bool> : public js_base<bool> {
	public:
		js<bool>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const bool& val) {
			return v8::Boolean::New(val);
		}
	private:
		virtual bool parse_impl(const std::string& argName) {
			static const std::string msg = "a boolean";
			if (!is_valid())
				alert(argName, msg);
			return v->BooleanValue();
		}
		virtual bool is_type() {
			return v->IsBoolean() || v->IsBooleanObject();
		}
	};

	template<>
	class js<std::string> : public js_base<std::string> {
	public:
		js<std::string>(v8::Handle<v8::Value> argv) : js_base(argv) {}
		static v8::Handle<v8::Value> to_handle(const std::string& val) {
			return v8::String::New(val.c_str());
		}
	private:
		virtual std::string parse_impl(const std::string& argName) {
			static const std::string msg = "a string";
			if (!is_valid())
				alert(argName, msg);
			v8::String::Utf8Value s(v->ToString());
			return std::string(*s);
		}
		virtual bool is_type() {
			return v->IsString() || v->IsStringObject();
		}
	};

	class args_bag {
	public:
		args_bag(const v8::Arguments& a) : m_a(a) {

		}
		template<typename T>
		T parse(int i, const std::string& parName) const {
			if (m_a.Length() < i + 1)
				throw help::range_error("Need at least " + boost::lexical_cast< std::string >(i + 1) + " parameters");
			return js<T>(m_a[i]).parse(parName);
		}		
		template<typename T>
		T parse(int i, const std::string& parName, T def) const {
			return js<T>(m_a[i]).parse(parName, def);
		}		
	private:
		const v8::Arguments& m_a;
	};

	template<typename T>
	typename T* unwrap(const v8::Arguments& args, int index, const std::string& prototypeName) {

		if (args.Length() < index + 1)
			throw help::range_error("Need at least " + boost::lexical_cast< std::string >(index + 1) + " parameters");
		auto arg = args[index];
		if (!arg->IsObject())
			throw help::type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] must be an object");

		auto handle = arg->ToObject();

		if (handle.IsEmpty())
			throw reference_error("Argument[" + boost::lexical_cast<std::string>(index) + "] handle is empty");
		if (handle->InternalFieldCount() <= 0)
			throw reference_error("Argument[" + boost::lexical_cast<std::string>(index) + "] handle has no fields");
		v8::String::Utf8Value val(handle->ObjectProtoToString());
		std::string proto(*val);
		if (proto != "[object " + prototypeName + "]")
			throw type_error("Argument[" + boost::lexical_cast<std::string>(index) + "] must have prototype " + prototypeName);

		try {
			v8::TryCatch try_catch;

			T* ptr = node::ObjectWrap::Unwrap<T>(handle);

			if (try_catch.HasCaught() || !ptr)
				throw help::reference_error("Argument[" + boost::lexical_cast<std::string>(index) + "] could not be unwrapped");
			return ptr;

		} catch (...) {
			throw help::error("Argument could not be unwrapped");
		}

	}

	template <class Function>
	v8::Handle<v8::Value> try_scope(Function fun) {

		v8::Handle<v8::Value> error;
		try {

			return fun();

		} catch (const range_error& e) {

			std::cout << e.what() << std::endl;
			error = v8::Exception::RangeError(v8::String::New(e.what()));

		} catch (const syntax_error& e) {

			std::cout << e.what() << std::endl;
			error = v8::Exception::SyntaxError(v8::String::New(e.what()));

		} catch (const reference_error& e) {

			std::cout << e.what() << std::endl;
			error = v8::Exception::ReferenceError(v8::String::New(e.what()));

		} catch (const type_error& e) {

			std::cout << e.what() << std::endl;
			error = v8::Exception::TypeError(v8::String::New(e.what()));

		} catch (const std::exception& e) {

			std::cout << e.what() << std::endl;
			error = v8::Exception::Error(v8::String::New(e.what()));

		} catch (...) {

			std::cout << "Unknown exception" << std::endl;
			error = v8::Exception::Error(v8::String::New("Unknown exception"));

		}
		return v8::ThrowException(error);
	}

	template <class Function>
	v8::Handle<v8::Value> fun_scope(Function fun) {
		return try_scope([&]()->v8::Handle<v8::Value> {

			v8::HandleScope scope;
			return scope.Close(fun());
		});
	}

	template <class Procedure>
	v8::Handle<v8::Value> proc_scope(Procedure proc) {
		return fun_scope([&]()->v8::Handle<v8::Value> {

			proc();
			return v8::Undefined();
		});
	}
};

#endif