#ifndef ERROR_H
#define ERROR_H

namespace help {
	class error : public std::exception {
	public:

		error(const std::string& message) : message_(message) {};

		virtual const char* what() const {
			return message_.c_str();
		};

	private:
		std::string message_;
	};

	class range_error : public error { // representing an error that occurs when a numeric variable or parameter is outside of its valid range
	public:

		range_error(const std::string& message) : error(message) {}

	};

	class syntax_error : public error { // representing a syntax error that occurs while parsing code
	public:

		syntax_error(const std::string& message) : error(message) {}

	};

	class reference_error : public error { // representing an error that occurs when de-referencing an invalid reference
	public:

		reference_error(const std::string& message) : error(message) {}

	};

	class type_error : public error { // representing an error that occurs when a variable or parameter is not of a valid type
	public:

		type_error(const std::string& message) : error(message) {}

	};

};

#endif