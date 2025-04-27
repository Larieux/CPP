#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	_type = "WrongCat";

	std::cout	<< "There's a "
				<< _type
				<< " in these woods..."
				<< std::endl;

	return ;
}

WrongCat::WrongCat( const WrongCat &src )
{
	_type = src._type;

	std::cout	<< "there's another "
				<< _type
				<< " in these woods...\n"
				<< "look at how cute they are!\n"
				<< std::endl;

	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I wonder where they've all went...\n"
				<< "I guess cats just have their own ways, am I right?"
				<< std::endl;

	return ;
}


WrongCat &WrongCat::operator= ( const WrongCat &src )
{
	std::cout	<< "That "
				<< _type
				<< " is turning into that "
				<< src._type
				<< ".\n"
				<< " Marvel at the wonders of regular nature! "
				<< std::endl;

	_type = src._type;

	return ( *this );
}

void	WrongCat::makeSound( void ) const
{
	std::cout	<< "BARK!! BARK! BARK! BARK!!!\n"
				<< "That's a mimic! let's kill it!\n"
				<< std::endl;
	return ;
}
