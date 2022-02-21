#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "utliuty.hpp"

namespace ft{ //https://www.cplusplus.com/reference/iterator/iterator/
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

////RANDOM_ACCESS
	template <typename T> //for vector
	class random_access_iterator {
//	class random_access_iterator : std::iterator<ft::random_access_iterator_tag, T>{
//	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>{
	public:

		typedef typename iterator_traits<T*>::difference_type	difference_type;
		typedef typename iterator_traits<T*>::value_type		value_type;
//		typedef T* 												pointer;
		typedef typename iterator_traits<T*>::pointer			pointer;
		typedef T*												iterator_type;
		typedef typename iterator_traits<T*>::reference			reference;
		typedef typename iterator_traits<T*>::iterator_category	iterator_category;

	protected:
		pointer _pointer;

	public:
		random_access_iterator() : _pointer(nullptr){}
		explicit random_access_iterator(pointer x) : _pointer(x){}
		virtual ~random_access_iterator(){}

		random_access_iterator(const random_access_iterator& copy) : _pointer(copy._pointer){}

		template<class Kek>
		struct my_remove_const {
			typedef Kek type;
		};

		template<class Kek>
		struct my_remove_const <const Kek> {
			typedef Kek type;
		};

		random_access_iterator<value_type> & operator=(random_access_iterator<typename my_remove_const<value_type>::type > const & src) {
			_pointer = &(*src);
			return *this;
		}

		//OPERATORS

		pointer base() const{
			return (_pointer);
		}

		reference operator*() const{
			return (*_pointer);
		}

		pointer operator->(){
			return (_pointer);
		}

		random_access_iterator& operator++(){
			++_pointer;
			return (*this);
		}

		random_access_iterator operator++(int){
			random_access_iterator iter(*this);
			++(*this);
			return iter;
		}

		random_access_iterator& operator--(){
			--_pointer;
			return (*this);
		}

		random_access_iterator operator--(int){
			random_access_iterator iter(*this);
			--(*this);
			return iter;
		}

		random_access_iterator operator+(difference_type x) const {
			random_access_iterator iter(*this);
			iter += x;
			return iter;
		}

		random_access_iterator operator-(difference_type x) const{
			return (*this + (-x));
		}

		random_access_iterator& operator+=(const difference_type x){
			_pointer += x;
			return (*this);
		}

		random_access_iterator& operator-=(const difference_type x){
			_pointer -= x;
			return (*this);
		}

		reference operator[](difference_type x) {
			return (*(_pointer + x));
		}
	};

	//NO_MEMB_RANDOM

	template<typename T1, typename T2>
	bool operator==(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){
			return (lhs.base() == rhs.base());
		}

	template<typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1> lhs, const random_access_iterator<T2> rhs){
		return (!(lhs == rhs));
	}

	template<typename T1, typename T2>
	bool operator<(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>(const random_access_iterator<T1> lhs, const random_access_iterator<T2> rhs){
		return (rhs < lhs);
	}

	template<typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1> lhs, const random_access_iterator<T2> rhs){
		return (!(rhs < lhs));
	}

	template<typename T1, typename T2>
	bool operator>=(const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs){
		return (!(rhs > lhs));
	}

	template<typename T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n,
			typename ft::random_access_iterator<T>& rai){
		return (&(*rai) + n);
	}

	template<typename Iter_1, typename Iter_2> //1622 iterator
	typename random_access_iterator<Iter_1>::difference_type operator-(const random_access_iterator<Iter_1> &lhs, const random_access_iterator<Iter_2> &rhs)	{
		return (lhs.base() - rhs.base());
	}

	template <typename Iter> //1636 iterator
	random_access_iterator<Iter> operator+(typename random_access_iterator<Iter>::difference_type n, random_access_iterator<Iter> x){
		x += n;
		return (x);
	}
////RANDOM_ACCESS_end

////REVERSE
	template<typename T>
	class reverse_iterator {
	public:
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::iterator_category iterator_category;
		typedef T iterator_type;

	protected:

		iterator_type _pointer;

	public:
		reverse_iterator() : _pointer() {}
		explicit reverse_iterator(iterator_type x) : _pointer(x){}
		virtual ~reverse_iterator(){}

		iterator_type base() const{
			return (_pointer);
		}

		template <class _Up>
		reverse_iterator& operator=(const reverse_iterator<_Up>& __u) {
			_pointer = __u.base();
			return *this;
		}

		template<typename Iterator>
		reverse_iterator (const reverse_iterator<Iterator> &rev_it){
			_pointer = rev_it.base();

		}

		reference operator*() const{
			iterator_type tmp(_pointer);
			return (*(--tmp));
		}


		reverse_iterator operator+(difference_type x) const {
			return (reverse_iterator(_pointer - x));
		}

		reverse_iterator operator-(difference_type x) const {
			return (reverse_iterator(_pointer + x));
		}

		reverse_iterator &operator++(){
			--_pointer;
			return (*this);
		}

		reverse_iterator &operator--(){
			++_pointer;
			return (*this);
		}

		reverse_iterator operator++(int){ //maybe const?
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		reverse_iterator operator--(int){
			reverse_iterator tmp = *this;
			--(*this);
//			++_pointer;
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type x){
			_pointer -= x;
			return (*this);
		}

		reverse_iterator &operator-=(difference_type x){
			_pointer += x;
			return (*this);
		}

		pointer operator->() const {
			return (&(operator*()));
		}

		reference operator[](difference_type x) const{
			return (_pointer[-x - 1]);
		}
	};

	//NO_MEMB_REVERSE

	template <typename T>
	bool operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T1, typename T2>
	bool operator==(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	bool operator<(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	bool operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T>
	bool operator>(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	bool operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	bool operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& rev_it){
		return(rev_it + n);
	}

	template <typename T>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs){
		return(lhs.base() - rhs.base());
	}

	template <class InIt>
	typename iterator_traits<InIt>::difference_type distance(InIt first, InIt last){
		return (last - first);
	}

////REVERSE_end
}
#endif


////todo: Нет преобразования random_access_iterator в const в v.push_back(*(vector.rend() - 2)); return (*(--tmp)); random_acc