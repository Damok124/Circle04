/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:46:57 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/28 18:23:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void	print_phonebook(void);
		void	print_line_contact(int index);
		void	print_full_contact(int index);
		void	print_columns(std::string str);
		void	search_contact(void);
		Contact	add_contact();
		void	get_contact(int index);
		void	set_contact(Contact contact, int index);

	private:
		Contact _contacts[8];
};

#endif
