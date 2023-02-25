#include <iostream>
#include <string>

void incrementation(int &nb)
{
	nb++;
	std::cout << "ref :" << &nb << std::endl;
}

int	main()
{
	int a = 4;
	int *ptr;
	ptr = &a;

	std::cout << "ptr :" << ptr << std::endl;
	std::cout << "adresse de a : " << &a << std::endl;
	incrementation(a);



	Human	boris("boris", 'b', 175);
	Human	bob("bob", 'm', 185);

	a = b;

	bob = boris;

	bob++;

	Human	clone_boris(boris);

	homme._color_eyes = 'm';

	int imc = homme.calculImc();

}

// int	main()
// {
// 	int i = 9;
// 	int j = 10;

// 	std::cout <<  "i = " << i << ", j = " << j << std::endl;

// 	std::string	str = "bonjour";

// 	std::cout << str.size() << std::endl;
// }
