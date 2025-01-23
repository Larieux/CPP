#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:

	Contact	my_contact[8];

public:

	Contact	getContact() const;
	void	addContact();

};

#endif
