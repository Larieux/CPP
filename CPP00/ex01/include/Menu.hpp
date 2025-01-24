
#include <iostream>
#include "PhoneBook.hpp"

enum Roles
{
	init,
	menu,
	end
};

class Menu {

public:

	Menu( void );
	~Menu( void );

	bool		ft_isnum(std::string line) const;
	std::string	ft_getline(std::string prompt) const;
	void		add_contact(PhoneBook *phone_book);
	void		search_contact(PhoneBook phone_book) const;
	void		show_menu(Roles role) const;

}
