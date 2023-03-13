#include "MaClasse.hpp"

void useFunction(MaClasse& obj, int index)
{
	void (MaClasse::*quoi)() = obj.getFunction(index);
	(obj.*quoi)();
}

int main(void)
{
	MaClasse obj;
	useFunction(obj, 0);
	useFunction(obj, 1);
	useFunction(obj, 2);
	useFunction(obj, 3);
	return 0;
}
