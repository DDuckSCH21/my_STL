#ifndef FT_CONTAINERS_UTLIUTY_HPP
# define FT_CONTAINERS_UTLIUTY_HPP

namespace ft{

//	template<typename T, typename U> //57
//	struct pair{
////	class pair{
//	public:
//		typedef T first_type;
//		typedef U second_type;
//		first_type first;
//		second_type second;
//
//		pair() : first(first_type(), second(second_type())) {} //https://disk.yandex.ru/d/czvF_zVWbVn7gQ 3:01
//
//		template<typename T1, typename U1> //хз зачем
//		explicit pair(const pair<T1, U1> &pair) : first(static_cast<T1>(pair.first)), second(static_cast<U1>(pair.second)){} //explict - auto IDE
//
//		pair(const first_type &x, const second_type &y) : first(x), second(y){}
//
//		pair &operator=(const pair &assign){
//			this->first = assign.first;
//			this->second = assign.second;
//			return (*this);
//		}
//	};

	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair()
		: first(),
		second() {}

		template <class U, class V>
		pair(const pair<U, V> &pr)
			: first(pr.first),
			second(pr.second) {}

		pair(const pair & pr)
			: first(pr.first),
			second(pr.second) {}

		pair(const first_type &a, const second_type &b)
			: first(a),
			second(b) {}

		pair &operator=(const pair &pr) {
			if (*this == pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return lhs.first < rhs.first ||
			   (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (ft::pair<T1, T2>(x, y));
	}

	template <typename inIt1, typename inIt2> //todo: need arg Compare??
	bool lexicographical_compare(inIt1 first_1, inIt1 last_1, inIt2 first_2, inIt2 last_2){
	    while (first_1 != last_1) {
	        if (first_2 == last_2 || *first_2 < *first_1)
	            return (false);
	        else if (*first_1 < *first_2)
	            return (true);
	        ++first_1;
	        ++first_2;
	    }
	    return (first_2 != last_2);
	}

	template <class inIt1, class inIt2>
	        bool equal ( inIt1 frst1, inIt1 lst1, inIt2 frst2 )
	        {
	            while (frst1!=lst1) {
	                if (!(*frst1 == *frst2))
	                    return (false);
	                ++frst1;
	                ++frst2;
	            }
	            return (true);
	        }

    template<bool Condition, typename T = void> struct enable_if {};
    template<typename T> struct enable_if<true, T> { typedef T type; };



////TRAITS
	class output_iterator_tag{};

	class input_iterator_tag{};

	class forward_iterator_tag{};

	class bidirectional_iterator_tag{};

	class random_access_iterator_tag{};

////TRAITS
	template <typename iterator>
	struct iterator_traits
	{
	public:
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	template <typename T>
	class iterator_traits<T*>
	{
	public:
		typedef ptrdiff_t		difference_type;
		typedef T 				value_type;
		typedef T*				pointer;
		typedef T&				reference;
//		typedef	ft::random_access_iterator_tag iterator_category;
		typedef	std::random_access_iterator_tag iterator_category; //for TEST

	};

	template <typename T>
	class iterator_traits<const T*>
	{
	public:
		typedef ptrdiff_t		difference_type;
		typedef const T			value_type;
		typedef const T*		pointer;
		typedef const T&		reference;
//		typedef	ft::random_access_iterator_tag iterator_category;
		typedef	std::random_access_iterator_tag iterator_category; //for TEST

	};
////TRAITS_end

////IS_INTEGRAL
	template <class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T () const {
			return v;
		}
	};

template <typename T> struct is_integral		: public ft::integral_constant<T, false> {};
template <> struct is_integral<bool>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<char>			: public ft::integral_constant<char, true> {};
template <> struct is_integral<signed char>			: public ft::integral_constant<signed char, true> {};
template <> struct is_integral<unsigned char>	: public ft::integral_constant<unsigned char, true> {};
template <> struct is_integral<wchar_t>			: public ft::integral_constant<wchar_t, true> {};
//NO_HAS_CHAR8_T
//template <> struct is_integral<char8_t>		: public ft::integral_constant<char8_t, true> {};
//HAS_NO_UNICODE_CHARS
template <> struct is_integral<char16_t>		: public ft::integral_constant<char16_t, true> {};
template <> struct is_integral<char32_t>		: public ft::integral_constant<char32_t, true> {};
//HAS_NO_UNICODE_CHARS
template <> struct is_integral<short>			: public ft::integral_constant<short, true> {};
template <> struct is_integral<unsigned short>	: public ft::integral_constant<unsigned short, true> {};
template <> struct is_integral<int> 			: public ft::integral_constant<int, true> {};
template <> struct is_integral<unsigned int>	: public ft::integral_constant<unsigned int, true> {};
template <> struct is_integral<long>			: public ft::integral_constant<long, true> {};
template <> struct is_integral<unsigned long>	: public ft::integral_constant<long, true> {};
template <> struct is_integral<long long>		: public ft::integral_constant<long, true> {};
template <> struct is_integral<unsigned long long>	: public ft::integral_constant<long, true> {};
//HAS_NO_INT128
template <> struct is_integral<__int128_t>		: public ft::integral_constant<__int128_t, true> {};
template <> struct is_integral<__uint128_t>		: public ft::integral_constant<__uint128_t, true> {};

//	template<class T> struct remove_const { typedef T type; }; костыль для копирования rand_iter - не помог
}

#endif
