/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:35:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/08/24 21:17:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PHONEBOOK_SIZE 8

class Phonebook {
	private:
		Contact	contact[PHONEBOOK_SIZE];
		int		index;
		int		size;

		void display_sheet(void) const;

	public:
		Phonebook(void);

		void add(void);
		void search(void) const;
};

#endif /* PHONEBOOK_HPP ***************************************************** */