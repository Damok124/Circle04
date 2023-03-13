#include "MyClass.hpp"
#include <stdexcept>

std::string const* MyClass::get() const {
	return m_data;
}

void MyClass::set(int index, const std::string& value) {
	if (index < 0 || index >= 10) {
		throw std::out_of_range("Index out of range.");
	}
	m_data[index] = value;
}
