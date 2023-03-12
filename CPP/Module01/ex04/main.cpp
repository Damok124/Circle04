/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:54:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/12 11:28:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	my_sed(char **argv, std::ifstream& infile, std::ofstream& outfile)
{
	std::string		old_str = argv[2];
	std::string		new_str = argv[3];
	std::string		all;
	size_t			pos = 0;

	getline(infile, all, '\0');
	while (pos != std::string::npos)
	{
		pos = all.find(old_str);
		outfile << all.substr(0, pos);
		if (pos != std::string::npos)
		{
			outfile << new_str;
			pos += old_str.length();
			all = all.substr(pos, std::string::npos);
		}
	}
}

void	print_error(std::string str)
{
	std::cout << "Error : " << str << std::endl;
}

int	my_sed_parsing(char **args, std::ifstream& src, std::ofstream& dest)
{
	std::string filename = args[1];
	std::string old_str = args[2];
	std::string name;
	int	check = 1;

	if (filename.length() == 0)
	{
		print_error("you need to specify a valid filename.");
		check = 0;
	}
	if (old_str.length() == 0)
	{
		print_error("you need to specify what sequence of characters you want to replace.");
		check = 0;
	}
	if (check)
	{
		src.open(filename);
		filename += ".replace";
		if (src.is_open())
		{
			dest.open(filename);
			if (!dest.is_open())
			{
				src.close();
				print_error("cannot create/open/write this outfile. Aborting");
				check = 0;
			}
		}
		else
		{
			print_error("cannot open the infile. Aborting.");
			check = 0;
		}

	}
	return (check);
}

int	main(int ac, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (ac == 4)
	{
		if (my_sed_parsing(argv, infile, outfile))
		{
			my_sed(argv, infile, outfile);
		}
	}
	else
		print_error("Wrong number of arguments.");
	return (0);
}


/*
Create a program that takes three parameters in the following order: a filename and two strings, s1 and s2.

It will open the file <filename>
and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.

Using C file manipulation functions is forbidden and will be considered cheating.
All the member functions of the class std::string are allowed, except replace. Use them wisely!

Handle unexpected inputs and errors.
tests to ensure your program works as expected.
*/
