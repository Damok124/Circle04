#include "Human.hpp"

Human::Human(std::string name, char color_eyes, int height)
	: name(name), color_eyes(color_eyes), height(height)
{
	/*this->name = name;
	this->color_eyes = color_eyes;
	this->height = height;*/

	//imc = weight / height;
}

Human::Human(const Human &human_to_copy)
{
	*this = human_to_copy;
}

Human&	operator=(const Human &human_to_copy)
{
	this->name = human_to_copy.name;
	this->color_eyes = human_to_copy.color_eyes;
}

Human::~Human()
{
}

void	Human::operator++()
{
	age++;
}

int	Human::calculImc()
{
	return (height / weight);
}


// Human::Human(std::string name, char color_eyes, int height)
// 	: name(name), color_eyes(color_eyes), height(height)
// {
// }

// Human::Human(std::string name, char color_eyes, int height)
// {
// 	this->name = name;
// 	this->color_eyes = color_eyes;
// 	this->height = height;

// 	imc = weight / height;
// }
