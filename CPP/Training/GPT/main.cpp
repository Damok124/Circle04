#include "MaClasse.hpp"

void useFunction(MaClasse& obj, int index) {
	void (MaClasse::*f)() = obj.getFunction(index);
	(obj.*f)();
}

int main() {
	MaClasse obj;
	useFunction(obj, 0);
	useFunction(obj, 1);
	useFunction(obj, 2);
	useFunction(obj, 3);
	return 0;
}
