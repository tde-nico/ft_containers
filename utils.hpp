#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>

namespace ft
{
	// enable_if

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// is_integral

	template <class _Tp>	struct is_integral					: public std::false_type {};
	template <>				struct is_integral<bool>			: public std::true_type {};
	template <>			struct is_integral<char>				: public std::true_type {};
	template <>			struct is_integral<signed char>			: public std::true_type {};
	template <>			struct is_integral<unsigned char>		: public std::true_type {};
	template <>			struct is_integral<wchar_t>				: public std::true_type {};
	template <>			struct is_integral<char16_t>			: public std::true_type {};
	template <>			struct is_integral<char32_t>			: public std::true_type {};
	template <>			struct is_integral<short>				: public std::true_type {};
	template <>			struct is_integral<unsigned short> 		: public std::true_type {};
	template <>			struct is_integral<int>					: public std::true_type {};
	template <>			struct is_integral<unsigned int>		: public std::true_type {};
	template <>			struct is_integral<long>				: public std::true_type {};
	template <>			struct is_integral<unsigned long>		: public std::true_type {};
	template <>			struct is_integral<long long>			: public std::true_type {};
	template <>			struct is_integral<unsigned long long>	: public std::true_type {};
	template <>			struct is_integral<__int128_t>			: public std::true_type {};
	template <>			struct is_integral<__uint128_t>			: public std::true_type {};

	// equal

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	// lexicographical_compare

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2,
								 Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	// pair

	template <class _T1, class _T2>
	struct pair
	{
		typedef _T1 first_type;
		typedef _T2 second_type;

		_T1 first;
		_T2 second;

		pair() : first(), second() {}
		pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

		template <class _U1, class _U2>
		pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

		pair& operator=(pair const& __p) {
			first = __p.first;
			second = __p.second;
			return *this;
		}
		template <class T1, class T2>
		friend bool operator== (const pair<T1,T2>& x, const pair<T1,T2>& y);
		template <class T1, class T2>
		friend bool operator<  (const pair<T1,T2>& x, const pair<T1,T2>& y);
		
		void swap(pair& __t){
		std::swap(first, __t.first);
		std::swap(second, __t.second);
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
		return x.first==y.first && x.second==y.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
		return !(x == y);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
	 	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
		return !(y < x);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
		return y < x;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{
		return !(x < y);		
	}

	// make_pair

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}

}

#endif