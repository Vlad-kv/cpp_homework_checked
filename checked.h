#ifndef CHECKED_H
#define CHECKED_H

#include "standart_traits.h"

template <typename T>
struct checked {
	private:
	
	typedef checked<T> MT;
	T val;
	
	static const T ZERO = (T)(0);
	
	void add(T b, unsigned) {
		if (( (T)(val + b) < val) || ( (T)(val + b) < b)) {
			throw "Owerflow";
		}
		val += b;
	}
	void add(T b, signed) {
		T res = val + b;
		if ((val > ZERO) && (b > ZERO)) {
			if ((res < val) || (res < b)) {
				throw "Owerflow";
			}
		}
		
		if ((val < ZERO) && (b < ZERO)) {
			if ((res > val) || (res > b)) {
				throw "Owerflow";
			}
		}
		
		val += b;
	}
	
	void sub(T b, unsigned) {
		if (val < b) {
			throw "Owerflow";
		}
		val -= b;
	}
	void sub(T b, signed) {
		T res = val - b;
		if ((val >= ZERO) && (b < ZERO)) {
			
			if ((-b < ZERO) || (res < val) || (res < -b)) {
				throw "Owerflow";
			}
		}
		
		if ((val <= ZERO) && (b > ZERO)) {
		
			if ((-b > ZERO) || (res > val) || (res > -b)) {
				throw "Owerflow";
			}
		}
		
		val = res;
	}
	
	void mul(T b, unsigned) {
		T res = val * b;
		
		if ((b == ZERO) || (val == ZERO)) {
			val = ZERO;
			return;
		}
		
		if (( res < val) || ( res < b)) {
			throw "Owerflow";
		}
		
		if (res / val != b) {
			throw "Owerflow";
		}
		
		val = res;
	}
	void mul(T b, signed) {
		T res = val * b;
		if ((b == ZERO) || (val == ZERO)) {
			val = ZERO;
			return;
		}
		
		if (( (val < ZERO) ^ (b < ZERO)  ) ^ (res < ZERO)) {
			throw "Owerflow";
		}
		
		if (res / val != b) {
			throw "Owerflow";
		}
		
		val = res;
	}
	
	void div(T b, unsigned) {
		if (val == ZERO) {
			return;
		}
		
		if (b == ZERO) {
			throw "Owerflow";
		}
		
		T res = val / b;
		
		checked<T> c(res);
		
		c *= b;
		
		c = checked<T>(val) - c;
		
		T rest = val - res * b;
		
		if ( (T)(c.val + res * b) != val) {
			throw "Owerflow";
		}
		
		val = res;
	}
	void div(T b, signed) {
		if (val == ZERO) {
			return;
		}
		
		if (b == ZERO) {
			throw "Owerflow";
		}
		T res = val / b;
		
		checked<T> c(res);
		
		c *= b;
		
		c = checked<T>(val) - c;
		
		if ( (T)(c.val + res * b) != val) {
			throw "Owerflow";
		}
		
		val = res;
	}
	
	public:
	
	checked(T val) :
		val(val) {
	}
	checked() :
		val(ZERO) {
	}
	
	MT& operator +=(MT b) {
		typename type_traits<T>::sign sign;
		add(b.val, sign);
		return *this;
	}
	MT& operator -=(MT b) {
		typename type_traits<T>::sign sign;
		sub(b.val, sign);
		return *this;
	}
	
	MT& operator *=(MT b) {
		typename type_traits<T>::sign sign;
		mul(b.val, sign);
		return *this;
	}
	MT& operator /=(MT b) {
		typename type_traits<T>::sign sign;
		div(b.val, sign);
		return *this;
	}
	
	MT& operator++() {
		add(1);
		return *this;
	}
	MT operator++(int) {
		return checked(*this).add(1);
	}
	MT& operator--() {
		sub(1);
		return *this;
	}
	MT operator--(int) {
		return checked(*this).sub(1);
	}
	
	
	MT friend operator+(MT a, MT b) {
		return MT(a) += b;
	}
	MT friend operator-(MT a, MT b) {
		return MT(a) -= b;
	}
	
	MT friend operator*(MT a, MT b) {
		return MT(a) *= b;
	}
	MT friend operator/(MT a, MT b) {
		return MT(a) /= b;
	}
	
	friend bool operator==(MT const& a, MT const& b) {
		return (a.val == b.val);
	}
	friend bool operator!=(MT const& a, MT const& b) {
		return (a.val != b.val);
	}
	friend bool operator<(MT const& a, MT const& b) {
		return (a.val < b.val);
	}
	friend bool operator>(MT const& a, MT const& b) {
		return (a.val > b.val);
	}
	friend bool operator<=(MT const& a, MT const& b) {
		return (a.val <= b.val);
	}
	friend bool operator>=(MT const& a, MT const& b) {
		return (a.val >= b.val);
	}
	
	std::ostream friend &operator<<(std::ostream& out, checked const& c) {
		out << c.val;
		return out;
	}
	
};

#endif // CHECKED_H
