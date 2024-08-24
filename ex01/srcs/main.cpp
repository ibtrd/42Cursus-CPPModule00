/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:18:25 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/24 23:07:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	std::cout << "> ";
	std::getline(std::cin, input);
	while (!std::cin.eof() && input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			phonebook.add();
		else if (!input.compare("SEARCH"))
			phonebook.search();
		else
			std::cout << input << ": Invalid command" << std::endl;
		if (!std::cin.eof())
			std::cout << "> ";
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
		std::cout << "EXIT" << std::endl;
}
