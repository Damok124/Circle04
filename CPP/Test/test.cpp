#include <iostream>

class Test {
	public :
		Test();
		~Test();

		void	setState(std::string const str);
		std::string getState(void) const;
	private :
		std::string state;
};

Test::Test()
{
	std::cout << "test constructor called" << std::endl;
}

Test::~Test()
{
	std::cout << "test destructor called" << std::endl;
}

void	Test::setState(std::string const str)
{
	state = str;
}

std::string	Test::getState(void) const
{
	return (state);
}

//-------------------------------------------------------------

class Tester {
	public :
		Tester();
		~Tester();

		void	setTab(Test const* ptr, int i);
		Test*	getTab(int i) const;
	private :
		Test* tab[5];
};

Tester::Tester()
{
	std::cout << "tester constructor called" << std::endl;
	for (int i = 0; i < 5; i++)
		tab[i] = NULL;
}

Tester::~Tester()
{
	std::cout << "tester destructor called" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << std::endl;
		if (tab[i])
			delete tab[i];
	}
}

void	Tester::setTab(Test const* ptr, int i)
{
	tab[i] = (Test*)ptr;
}

Test*	Tester::getTab(int i) const
{
	return (tab[i]);
}

//-------------------------------------------------------------

int main(void)
{
	Tester	one;
	Test*	two = new Test();
	Test*	three;
	two->setState("good news");
	one.setTab(two, 2);
	three = one.getTab(2);
	std::cout << three->getState() << std::endl;
	// delete two;
	return (0);
}
