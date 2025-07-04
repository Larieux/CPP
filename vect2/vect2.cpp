#include "vect2.hpp"

vect2::vect2()
{
    num[0] = 0;
    num[1] = 0;
}

vect2::vect2( const int first, const int second )
{
    num[0] = first;
    num[1] = second;
}

vect2::vect2( const vect2 &src )
{
    num[0] = src.getFirst();
    num[1] = src.getSecond();
}

vect2::~vect2()
{
}


vect2 &vect2::operator=( const vect2 &src )
{
    if ( *this != src )
    {
        num[0] = src.getFirst();
        num[1] = src.getSecond();
    }
    return ( *this );
}


vect2 &vect2::operator+( const vect2 &src )
{
    num[0] += src.getFirst();
    num[1] += src.getSecond();
    return (*this);
}

vect2 &vect2::operator-( const vect2 &src )
{
    num[0] -= src.getFirst();
    num[1] -= src.getSecond();
    return (*this);
}

vect2 &vect2::operator*( const vect2 &src )
{
    num[0] *= src.getFirst();
    num[1] *= src.getSecond();
    return (*this);
}

vect2 vect2::operator+( const vect2 &src ) const
{
    return (vect2(num[0] + src.getFirst(), num[1] + src.getSecond()));
}

vect2 vect2::operator-( const vect2 &src ) const
{
    return (vect2(num[0] - src.getFirst(), num[1] - src.getSecond()));
}

vect2 vect2::operator*( const vect2 &src ) const
{
    return (vect2(num[0] * src.getFirst(), num[1] * src.getSecond()));
}


vect2 vect2::operator+( const int number ) const
{
    return (vect2(num[0] + number, num[1] + number));
}

vect2 vect2::operator-( const int number ) const
{
    return (vect2(num[0] - number, num[1] - number));
}

vect2 vect2::operator*( const int number ) const
{
    return (vect2(num[0] * number, num[1] * number));
}


vect2 vect2::operator-()
{
    return (vect2(num[0] * -1, num[1] * -1));
}

vect2 vect2::operator++()
{
    vect2 *tmp;
    tmp = this;
    num[0] += 1;
    num[1] += 1;
    return (*tmp);
}

vect2 vect2::operator--()
{
    vect2 *tmp;
    tmp = this;
    num[0] -= 1;
    num[1] -= 1;
    return (*tmp);
}

vect2 &vect2::operator++( int number )
{
    (void)num;
    num[0] += 1;
    num[1] += 1;
    return (*this);
}

vect2 &vect2::operator--( int number )
{
    (void)num;
    num[0] -= 1;
    num[1] -= 1;
    return (*this);
}

vect2 vect2::operator+=( const vect2 &src )
{
    num[0] += src.getFirst();
    num[1] += src.getSecond();
    return (*this);
}

vect2 vect2::operator-=( const vect2 &src )
{
    num[0] -= src.getFirst();
    num[1] -= src.getSecond();
    return (*this);
}

vect2 vect2::operator*=( const vect2 &src )
{
    num[0] *= src.getFirst();
    num[1] *= src.getSecond();
    return (*this);
}

vect2 vect2::operator+=( const int number )
{
    num[0] += number;
    num[1] += number;
    return (*this);
}

vect2 vect2::operator-=( const int number )
{
    num[0] -= number;
    num[1] -= number;
    return (*this);
}

vect2 vect2::operator*=( const int number )
{
    num[0] *= number;
    num[1] *= number;
    return (*this);
}


int vect2::operator[]( const int number ) const
{
    return (num[number]);
}

int &vect2::operator[]( const int number )
{
    return (num[number]);
}

bool vect2::operator==( const vect2 &src ) const
{
    if (num[0] == src.getFirst() && num[1] == src.getSecond())
        return (true);
    else
        return (false);
}

bool vect2::operator!=( const vect2 &src ) const
{
    if (num[0] == src.getFirst() && num[1] == src.getSecond())
        return (false);
    else
        return (true);
}


int vect2::getFirst() const
{
    return(num[0]);
}

int vect2::getSecond() const
{
    return(num[1]);
}

void    vect2::setFirst( const int number )
{
    num[0] = number;
}

void    vect2::setSecond( const int number )
{
    num[1] = number;
}



std::ostream &operator<<( std::ostream &out, vect2 const &src )
{
    out << "{" << src.getFirst() << ", " << src.getSecond() << "}" << std::endl;
    return (out);
}

vect2 operator+( const int number, const vect2 &src )
{
    return (vect2(src.getFirst() + number, src.getSecond() + number));
}

vect2 operator-( const int number, const vect2 &src )
{
    return (vect2(src.getFirst() - number, src.getSecond() - number));
}

vect2 operator*( const int number, const vect2 &src )
{
    return (vect2(src.getFirst() * number, src.getSecond() * number));
}
