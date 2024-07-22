/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:35:08 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/17 21:07:13 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

const std::string	Contact::key[KEY_COUNT] = {
	"First name", 
	"Last name",
	"Nickname",
	"Phone number",
	"Darkest secret"
};

Contact::Contact(void)
{
	return ;
}

void	Contact::edit(void)
{
	std::string	input;

	std::cout << "\e[34m" << "Enter contact informations..." << "\e[0m" << std::endl;
	for (int i = 0; i < KEY_COUNT; i++)
	{
		while (!std::cin.eof() && !input.length())
		{
			std::cout << "\t" << this->key[i] << ": ";
			std::getline(std::cin, input);
			if (!std::cin.eof() && !input.length())
				std::cout << "\e[31m" << "Error: empty field" << "\e[0m" << std::endl;
		}
		this->value[i] = input;
		input.clear();
	}
	if (std::cin.eof())
		std::cout << std::endl;
	else
		std::cout << "\e[34m" << "New contact added!" << "\e[0m" << std::endl;
}

void	Contact::display_row(size_t index) const
{
	int			cols[] = {FIRST_NAME, LAST_NAME, NICKNAME};
	std::string	buffer;
	size_t		len;
	
	std::cout << "\t│" << "         " << index;
	for (int i = 0; i < 3; i++)
	{
		buffer = this->value[cols[i]];
		len = buffer.length();
		if (len > 10)
			buffer.replace(9, len - 9, ".");
		else if (len < 10)
			buffer.insert(0, 10 - len, ' ');
		std::cout << "│" << buffer;
	}
	std::cout << "│\n";
}

void	Contact::display(void) const
{
	for (int i = 0; i < KEY_COUNT; i++)
	{
		std::cout << "\t" << this->key[i] << ": " << this->value[i];
		if (i != KEY_COUNT - 1)
			std::cout << std::endl;
		else
			std::cout << "\n";
	}
}
