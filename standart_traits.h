#ifndef STANDART_TRAITS_H
#define STANDART_TRAITS_H

template <typename T>
struct type_traits;

// int
template <>
struct type_traits <unsigned int> {
	typedef unsigned sign;
};
template <>
struct type_traits <int> {
	typedef signed sign;
};

// char
template <>
struct type_traits <char> {
	typedef signed sign;
};
template <>
struct type_traits <unsigned char> {
	typedef unsigned sign;
};
template <>
struct type_traits <signed char> {
	typedef signed sign;
};

// short int

template <>
struct type_traits <short int> {
	typedef signed sign;
};
template <>
struct type_traits <unsigned short int> {
	typedef unsigned sign;
};

// long long

template <>
struct type_traits <long long> {
	typedef signed sign;
};
template <>
struct type_traits <unsigned long long> {
	typedef unsigned sign;
};



#endif // STANDART_TRAITS_H
