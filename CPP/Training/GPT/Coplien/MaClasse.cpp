#include "MaClasse.hpp"
#include <iostream>

MaClasse::MaClasse() : m_data(NULL), m_size(0)
{
	std::cout << "Constructeur par défaut" << std::endl;
}

MaClasse::MaClasse(const MaClasse& other) : m_size(other.m_size)
{
	m_data = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
	std::cout << "Constructeur de copie" << std::endl;
}

MaClasse& MaClasse::operator=(const MaClasse& other)
{
	if (this != &other)
	{
		delete[] m_data;
		m_size = other.m_size;
		m_data = new int[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}
	std::cout << "Opérateur d'affectation" << std::endl;
	return *this;
}

MaClasse::~MaClasse()
{
	delete[] m_data;
	std::cout << "Destructeur" << std::endl;
}
