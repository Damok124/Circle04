#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <string>

class MyClass {
public:
	const std::string* get() const;

	void set(int index, const std::string& value);

private:
	std::string m_data[10];
};

#endif // MYCLASS_HPP
