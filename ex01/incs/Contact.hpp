/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:35:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/18 01:11:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

enum e_key
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
	KEY_COUNT,
};

class Contact {
	public:
		Contact(void);
		
		void	edit(void);
		void	display(void) const;
		void	display_row(size_t index) const;

	private:
		static const std::string	key[KEY_COUNT];
		std::string					value[KEY_COUNT];
};

#endif /* CONTACT_HPP ******************************************************* */