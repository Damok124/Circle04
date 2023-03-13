#ifndef MACLASSE_HPP
#define MACLASSE_HPP

#include <iostream>

class MaClasse {
public:
	MaClasse();//constructeur
	~MaClasse();//destructeur
	void (MaClasse::*getFunction(int index))(void);
	//
private:
	void (MaClasse::*m_func[4])(void);

	void func1(void);
	void func2(void);
	void func3(void);
	void func4(void);
};

#endif // MACLASSE_HPP
