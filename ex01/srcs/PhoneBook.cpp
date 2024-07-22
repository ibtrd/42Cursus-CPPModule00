/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:34:56 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/17 15:50:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

Phonebook::Phonebook(void)
: index(0), size(0)
{
	return ;
}

void Phonebook::add(void)
{
	this->contact[index].edit();
	this->index = (index + 1) % PHONEBOOK_SIZE;
	if (this->size < PHONEBOOK_SIZE)
		this->size++;
}

void Phonebook::search(void) const
{
	if (!this->size)
	{
		std::cout << "\e[31m" << "Error: Empty phonebook" << "\e[0m" << std::endl;
		return ;
	}
	this->display_sheet();

	std::string	input;
	int			index;

	std::cout << "Select INDEX to display: ";
	std::getline(std::cin, input);
	index = input[0] - '0';
	while (!std::cin.eof()
		&& input.length() != '1'
		&& (index < 0 || index > this->size - 1))
	{

		std::cout << "\e[31m" <<  input << " : Invalid INDEX" << "\e[0m\n" << "Select INDEX to display: ";
		std::getline(std::cin, input);
		index = input[0] - '0';
	}
	if (!std::cin.eof())
		this->contact[index].display();
}

void Phonebook::display_sheet(void) const
{
	std::cout << "\t┌──────────┬──────────┬──────────┬──────────┐\n";
	std::cout << "\t│     INDEX│FIRST NAME│ LAST NAME│  NICKNAME│\n";
	std::cout << "\t├──────────┼──────────┼──────────┼──────────┤\n";
	for (int i = 0; i < this->size; i++)
		this->contact[i].display_row(i);
	std::cout << "\t└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}
