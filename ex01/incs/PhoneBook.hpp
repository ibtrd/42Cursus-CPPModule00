/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:35:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/17 15:20:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PHONEBOOK_SIZE 8

class Phonebook {
	public:
		Phonebook();

		void add(void);
		void search(void) const;

	private:
		Contact	contact[PHONEBOOK_SIZE];
		int		index;
		int		size;

		void display_sheet(void) const;
};

#endif /* PHONEBOOK_HPP ***************************************************** */