#include "MyClass.hpp"
#include <iostream>

int main() {
	MyClass obj;

	// Test de la méthode get
	std::string const* data = obj.get();
	for (int i = 0; i < 10; i++) {
		std::cout << "data[" << i << "] = " << data[i] << std::endl;
	}

	// Test de la méthode set
	obj.set(0, "Hello");
	obj.set(9, "World");

	data = obj.get();
	for (int i = 0; i < 10; i++) {
		std::cout << "data[" << i << "] = " << data[i] << std::endl;
	}

	// Test de la gestion d'erreur de la méthode set
	try {
		obj.set(10, "Invalid index");
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
