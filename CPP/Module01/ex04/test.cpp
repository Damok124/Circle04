#include <iostream>
#include <fstream>

int	main(int ac, char **argv)
{
	std::ofstream out;
	std::ifstream in;
	std::string total = "";
	std::string str;

	out.open("FINAL");
	if (out.is_open())
	{
		out << "\nCeci\nest un test.\n\n\nabc\nd\ne\nf\n0123456789";
		out.close();
	}
	return (0);
}
