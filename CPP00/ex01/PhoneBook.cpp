#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
 

class PhoneBook {

private:

	Contact	my_contact[8];

public:

	Contact	getContact() const;
	void	addContact();

}

#endif
