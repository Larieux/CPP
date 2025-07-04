#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>
#include <iomanip>

class vect2
{
public:
    vect2();
    vect2( const int first, const int second );
    vect2( const vect2 &src );
    ~vect2();

    vect2 &operator=( const vect2 &src );

    vect2 &operator+( const vect2 &src );
    vect2 &operator-( const vect2 &src );
    vect2 &operator*( const vect2 &src );
    vect2 operator+( const vect2 &src ) const;
    vect2 operator-( const vect2 &src ) const;
    vect2 operator*( const vect2 &src ) const;
    vect2 operator+( const int num ) const;
    vect2 operator-( const int num ) const;
    vect2 operator*( const int num ) const;
    vect2 operator-();
    vect2 operator++();
    vect2 operator--();
    vect2 &operator++( int num );
    vect2 &operator--( int num );
    vect2 operator+=( const vect2 &src );
    vect2 operator-=( const vect2 &src );
    vect2 operator*=( const vect2 &src );
    vect2 operator+=( const int num );
    vect2 operator-=( const int num );
    vect2 operator*=( const int num );

    int operator[]( const int num ) const;
    int &operator[]( const int num );
    bool operator==( const vect2 &src ) const;
    bool operator!=( const vect2 &src ) const;

    int getFirst() const;
    int getSecond() const;

    void    setFirst( const int num );
    void    setSecond( const int num );

protected:


private:
    int num[2];

};

std::ostream &operator<<( std::ostream &out, vect2 const &src );
vect2 operator+( const int num, const vect2 &src );
vect2 operator-( const int num, const vect2 &src );
vect2 operator*( const int num, const vect2 &src );

#endif