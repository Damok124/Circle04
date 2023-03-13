#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <string>

class Human
{
	public:
		Human();// constructeur par defaut
		Human	&operator=(const Human &human_to_copy);//opérateur =
		Human(const Human &human_to_copy);//constructeur par copie
		~Human();//destructeur// les 4 forment la forme coplienne

		Human(std::string name, char color_eyes, int height);//constructeur surchargé
		void	operator++();

		void eat(int nb_aliments);
		void eat(std::string plat, int);
		char		getColorEyes();
		//int	getImc();
		int	calculImc();
		void	setColorEyes(char new_color);

	private:
		std::string _name;
		char 		_color_eyes;
		int			_height;
		int	age;
};

#endif
