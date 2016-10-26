#include <iostream>

#include "checked.h"
using namespace std;

template <typename T>
void check_type(string type) {
	cout << type << " ";
	
	T c1, v1;
	c1 = 0;
	
	do{
		v1 = 0;
		do {
			long long res = (long long)c1 + (long long)v1;
			bool overflow;
			
			// +
			
			overflow = 0;
			checked<T> c(c1), v(v1), ans;
			
			try{
				ans = c + v;
			} catch (const char * str) {
				overflow = 1;
			}
			
			if ((res != (T)(c1 + v1) ) ^ (overflow == 1)) {
				cout << "\nError!\n";
				cout << overflow << "\n";
				cout << (long long)c1 << " + " << (long long)v1 << " !!!\n";
				
				return;
			}
			
			// -
			
			overflow = 0;
			res = (long long)c1 - (long long)v1;
			try{
				ans = c - v;
			} catch (const char * str) {
				overflow = 1;
			}
			
			if ((res != (T)(c1 - v1) ) ^ (overflow == 1)) {
				cout << "\nError!\n";
				cout << overflow << "\n";
				cout << (long long)c1 << " - " << (long long)v1 << " !!!\n";
				
				return;
			}
			
			// *
			
			overflow = 0;
			res = (long long)c1 * (long long)v1;
			try{
				ans = c * v;
			} catch (const char * str) {
				overflow = 1;
			}
			
			if ((res != (T)(c1 * v1) ) ^ (overflow == 1)) {
				cout << "\nError!\n";
				cout << overflow << "\n";
				cout << (long long)c1 << " * " << (long long)v1 << " !!!\n";
				
				return;
			}
			// /
			
			bool err = 0;
			
			if (!c1 == 0) {
				if (v1 == 0) {
					err = 1;
				} else {
					err = ((long long)c1 / (long long)v1 != (T)(c1 / v1) );
				}
			}
			
			overflow = 0;
			try{
				ans = c / v;
			} catch (const char * str) {
				overflow = 1;
			}
			
			if ((err) ^ (overflow == 1)) {
				cout << "\nError!\n";
				cout << overflow << "\n";
				cout << (long long)c1 << " / " << (long long)v1 << " !!!\n";
				
				return;
			}
			
			v1++;
		} while (v1 != 0);
		
		c1++;
	} while (c1 != 0);
	
	cout << "OK\n";
}

template <typename T>
void lite_check(string type) {
	cout << type << " ";
	
	checked<T> c;
	
	cout << "OK\n";
}

int main() {
	
	check_type<char>("char");
	check_type<unsigned char>("unsigned_char");
	check_type<signed char>("signed_char");
	
	cout << "\n";
	
	lite_check<short int>("short_int");
	lite_check<unsigned short int>("unsigned_short_int");
	lite_check<signed short int>("signed_short_int");
	
	cout << "\n";
	
	lite_check<int>("int");
	lite_check<unsigned int>("unsigned_int");
	lite_check<signed int>("signed_int");
	
	cout << "\n";
	
	lite_check<long>("long");
	lite_check<signed long>("signed long");
	lite_check<unsigned long>("unsigned_long");
	
	cout << "\n";
	
	lite_check<long long>("long_long");
	lite_check<signed long long>("signed_long_long");
	lite_check<unsigned long long>("unsigned_long_long");
	
	cout << "\n";
	
	lite_check<bool>("bool");
	lite_check<unsigned>("unsigned");
	lite_check<signed>("signed");
	
	cout << "\n";
	
	checked<int> c = 0;
	
	c += 123;
	
	cout << (c + 543) << "\n";
	
	cout << (c == 123) << "\n";
	
	/**/
	
    return 0;
}
