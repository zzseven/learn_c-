 ///
 /// @file    mystring.h
 /// @author  zzseven
 /// @date    2016-03-05 08:59:27
 ///

#ifndef __MYSTRING_H__




class String {
public:
	String();
	String(const char * pstr);
	String(const String& lhs);
	~String();
	String &operator=(const String & lhs);
	String &operator=(const char * pstr);

	String &operator+=(const String & lhs);
	String &operator+=(const char * pstr);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String & lhs, const String & rhs);
	friend bool operator!=(const String & lhs, const String & rhs);

	friend bool operator<(const String & lhs, const String & rhs);
	friend bool operator>(const String & lhs, const String & rhs);
	friend bool operator<=(const String & lhs, const String & rhs);
	friend bool operator>=(const String & lhs, const String & rhs);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char *pstr_;
};

String operator+(const String & lhs, const String & rhs);
String operator+(const String & lhs, const char * pstr);
String operator+(const char * pstr, const String & rhs);

//#endif
