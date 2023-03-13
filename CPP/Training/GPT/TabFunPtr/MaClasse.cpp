#include "MaClasse.hpp"

MaClasse::MaClasse() {
	m_func[0] = &MaClasse::func1;
	m_func[1] = &MaClasse::func2;
	m_func[2] = &MaClasse::func3;
	m_func[3] = &MaClasse::func4;
}

MaClasse::~MaClasse()
{
}

void MaClasse::func1(void)
{
	std::cout << "Fonction 1" << std::endl;
}

void MaClasse::func2(void)
{
	std::cout << "Fonction 2" << std::endl;
}

void MaClasse::func3(void)
{
	std::cout << "Fonction 3" << std::endl;
}

void MaClasse::func4(void)
{
	std::cout << "Fonction 4" << std::endl;
}

void (MaClasse::*MaClasse::getFunction(int index))(void)
{
	return m_func[index];
}
