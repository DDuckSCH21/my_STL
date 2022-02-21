#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP


//#include "utliuty.hpp"
#include "iterator.hpp"
#include <iterator>
#include <iostream>

namespace ft {
	template<typename T, typename A = std::allocator <T> >
	class vector {
	public:
		typedef T value_type;  //in std lib - private
		typedef A allocator_type; //std:allocator //356
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::pointer pointer;
		typedef typename A::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;

	protected:
//		typedef size_t	size_type; //Заменить тип на нормальный наследуемый

////VECTOR
	protected:
		allocator_type _alloc; //+
		pointer _arr; //+
		size_type _size;
		size_type _capacity;//+

////METHODS
	public:
		//default
		explicit vector(const allocator_type& allocator = allocator_type()) :
				_alloc(allocator),
				_arr(nullptr),
				_size(0),
				_capacity(0)
				{}

		//fill
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &allocator = allocator_type()) :
				_alloc(allocator),
				_size(n),
				_capacity(n) {
			_arr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_arr + i, val);
		}

		//range
		template<typename inIt>
		vector(inIt frst, inIt lst, const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<!std::is_integral<inIt>::value>::type * = 0) : _alloc(alloc) {
			if (frst > lst)
				throw std::length_error("vector");
			_size = lst - frst;
			_capacity = _size;
			_arr = _alloc.allocate(_capacity);
			for (difference_type i = 0; i < static_cast<difference_type>(_size); i++)
				_alloc.construct(_arr + i, *(frst + i));
		}

//		assign
		vector &operator=(const vector &assign) {
			if (this == &assign)
				return (*this);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_size = assign.size();
			if (_capacity < _size) {
				if (_capacity != 0)
					_alloc.deallocate(_arr, _capacity);
				_capacity = _size;
				_arr = _alloc.allocate(_capacity);
			}
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(_arr + i, assign[i]);
			}
			return (*this);
		}

		//copy
		vector(const vector &copy) : _size(0), _capacity(0) {
			*this = copy;
		}

		//destructor
		~vector() {
			this->clear();
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
		}

////ITERATORS
	public:
//  protected:
		typedef random_access_iterator<value_type> iterator;
		typedef random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


		typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //T3

	public:
		iterator begin() {
			return (iterator(_arr));
		}

		const_iterator begin() const {
			return (const_iterator(_arr));
		}

		iterator end() {
			return (iterator(_arr + _size));
		}

		const_iterator end() const {
			return (const_iterator(_arr + _size));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

////ACCESS
	public:
		T &operator[](size_type i) {
			return (_arr[i]);
		}

		const T &operator[](size_type i) const {
			return (_arr[i]);
		}

		T &at(size_type i) {
			if (i >= _size)
				throw std::out_of_range("Exception: AT.out_of_range");
			return (_arr[i]);
		}

		reference front() {
			return (_arr[0]);
		}

		const_reference front() const {
			return (_arr[0]);
		}

		reference back() {
			return (_arr[_size - 1]);
		}

		const_reference back() const {
			return (_arr[_size - 1]);
		}

////CAPACITY
		void reserve(size_type n) //reserve on ALLOCATOR
		{
			pointer new_arr;
			if (n <= _capacity) return;
			new_arr = _alloc.allocate(n);
			size_type i = 0;

			try {
				for (; i < _size; ++i)
					_alloc.construct(new_arr + i, *(_arr + i)); // Модный placement new
			} catch (std::exception &except) {
				for (size_type j = 0; j < i; ++j)
					_alloc.destroy(new_arr + i);
				_alloc.deallocate(new_arr, n);
				throw;
			}
			for (size_type i = 0; i < _size; ++i)
				_alloc.destroy(_arr + i);
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
		}

		size_type size() const {
			return (_size);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}

		void resize(size_t n, const T &val = T()) {
			if (n > _size) {
				if (n > _capacity) {
					if ((_capacity * 2) > n)
						reserve(_capacity * 2);
					else
						reserve(n);
				}
				for (size_type i = _size; i < n; i++) {
					_alloc.construct(_arr + i, val);
					_size++;
//					new(_arr + i) T(val); //V0
				}
			} else if (n < _size) {
				while (_size != n) { // norm idea)
					_alloc.destroy(_arr + (--_size));
//					(_arr + --_size)->~T(); //V0
				}
			}
		}

		size_type capacity() const {
			return (_capacity);
		}

		bool empty() const{
			return (!(_size));
		}
////MODIFIERS

		template<typename inIt>
		//range
		void assign(inIt first, inIt last, typename ft::enable_if<!std::is_integral<inIt>::value>::type * = 0) {
			if (first > last)
				throw;
			difference_type n = last - first;
			clear();
			if (n > static_cast<difference_type>(_capacity)) {
				_alloc.deallocate(_arr, _capacity);
				_arr = _alloc.allocate(n);
				_capacity = n;
			}
			iterator ptr = begin();
			for (; first < last; first++) {
				_alloc.construct(&(*ptr), *first);
				ptr++;
			}
			_size = n;
		}

		//fill
		void assign(size_type n, const value_type &val) {
			clear();
			if (n > _capacity) {
				_alloc.deallocate(_arr, _capacity);
				_arr = _alloc.allocate(n);
				_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_arr + i, val);
			_size = n;
		}

		void push_back(const T &val) {
			if (_capacity == _size) {
				if (_capacity != 0)
					reserve(_size * 2);
				else
					reserve(1);
			}
			_alloc.construct(_arr + _size, val);
			_size++;
		}

		void pop_back() {
			_alloc.destroy(_arr + _size - 1);
			_size--;
		}

//insert
//TODO: написать insert
/*
 * C98
 * 	single element (1)
		iterator insert (iterator position, const value_type& val);
	fill (2)
    	void insert (iterator position, size_type n, const value_type& val);
	range (3)
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

*/
		//single
		iterator insert(iterator position, const value_type& value){
			iterator res = position;
//			std::cout << "single" << "\n";

			if (position < begin() || position > end())
				throw std::logic_error("error insert logic");
			iterator pos = begin();
			size_type i = 0;
			if (_capacity < _size + 1)
				reserve(_size* 2);
			for (; pos != position; i++)
				pos++;
			for (size_type j = _size + 1; i < j; j--) {
				_alloc.destroy(_arr + j - 1); // -1
				_alloc.construct(_arr + j, *(_arr + j - 1)); // -1
			}
			if (_size > 0)
				_alloc.destroy(_arr + i);
			_alloc.construct(_arr + i, value);
			_size += 1;
			return(begin() + i);
		}

		//fill
		void insert(iterator position, size_type n, const value_type& value){
			difference_type begin_pos = distance(begin(), position);
			difference_type tmp_size = _size - begin_pos;
//			std::cout << "fill" << "\n";
			if (n == 0)
				return ;
			else if (n > max_size() - _size)
				throw std::length_error("error insert length");
			if (_capacity < _size + n) {
				if (_capacity * 2 >= _size + n) // for test
					reserve(_capacity * 2);
				else
					reserve(_size + n);
			}
			if (_size > 0) {
				if (begin_pos == 0){
					for (difference_type i = _size; i > 0; i--) {
						_alloc.construct(_arr + i + n - 1, *(_arr + (--tmp_size)));
					}
				}
				else {
					for (difference_type i = _size - begin_pos; i > 0; i--) {
						_alloc.construct(_arr + i + n + begin_pos - 1, *(_arr + i + n - 1));
					}
				}
				}
			for (size_type i = 0; i < n; i++) {
				if (_size > 0)
					_alloc.destroy(_arr + begin_pos + i); // -1
				_alloc.construct(_arr + begin_pos + i, value); // -1
			}
			_size += n;
		}

//		range
		template <typename InIt>
		void insert (iterator position, InIt first, InIt last, typename enable_if<!is_integral<InIt>::value>::type* = 0) {
			size_type begin_pos = static_cast<size_type>(position - begin());
			difference_type tmp_size = _size - begin_pos;

//			std::cout << "range" << "\n";
			size_type n = static_cast<size_type>(last - first);
			int error_count = 0;
			if (_capacity < _size + n) {
				if (_capacity * 2 >= _size + n) // for test
					reserve(_capacity * 2);
				else
					reserve(_size + n);
			}
			if (_size > 0) {
				if (begin_pos == 0){
					for (difference_type i = _size; i > 0; i--) {
						_alloc.construct(_arr + i + n - 1, *(_arr + (--tmp_size)));
					}
				}
				else {
					for (difference_type i = _size - begin_pos; i > 0; i--) {
						_alloc.construct(_arr + i + n + begin_pos - 1, *(_arr + i + n - 1));
					}
				}
			}
			try {
				for (size_type i = 0; i < n; i++) {
					if (_size > 0)
						_alloc.destroy(_arr + begin_pos + i);
					_alloc.construct(_arr + begin_pos + i, *first++);
					error_count++;
				}
			}
			catch (...){
				for (int i = 0; i < error_count; i++)
					_alloc.destroy(_arr + begin_pos + i);
				_alloc.deallocate(_arr, _capacity);
				_capacity = 0;
				throw std::logic_error("error insert magic");
			}
			_size += n;
		}

//erase
		iterator erase(iterator position) {
			iterator tmp = position;
			iterator pos = begin();
			size_type i = 0;
			for (; pos != position; pos++)
				i++;
			for (; i < _size - 1; i++) {
				_alloc.destroy(_arr + i);
				_alloc.construct(_arr + i, *(_arr + i + 1));
			}
			_size--;
			_alloc.destroy(_arr + _size - 1);
			return (tmp);
		}

//erase(range)
		iterator erase(iterator first, iterator last) {
			difference_type begin_first = distance(begin(), first);
			difference_type dist_del = distance(first, last);
			difference_type last_end = distance(last, end());
			size_type post_size = begin_first + last_end;

			for (difference_type i = 0; i < dist_del; i++) {
				_alloc.destroy(&(*(first + i)));
			}
			size_type indent = begin_first;
			for (difference_type i = 0; i < last_end; i++) {
				_alloc.construct(_arr + begin_first, *(_arr + dist_del + indent));
				_alloc.destroy(_arr + (indent + dist_del));
				begin_first++;
				dist_del++;
			}
			_size = post_size;
			return (iterator(_arr + indent));
		}

//swap V1
		void swap(vector& x){
			if (x == *this)
				return ;
			allocator_type tmp_alloc = x._alloc;
			pointer 		tmp_arr = x._arr;
			size_type		tmp_size = x._size;
			size_type		tmp_capacity = x._capacity;

			x._alloc = _alloc;
			x._arr = _arr;
			x._size = _size;
			x._capacity = _capacity;

			_alloc = tmp_alloc;
			_arr = tmp_arr;
			_size = tmp_size;
			_capacity = tmp_capacity;
		}
//V2
//		void swap(vector& x){
//			vector temp = *this;
//			*this = x;
//			x = temp;
//		}


		void clear() { // дестроит только size
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_size = 0;
		}
	};


////OPERATORS
	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs,
					 const vector<T,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < rhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template<typename T1>
	bool operator!=(ft::vector<T1> const &lhs, ft::vector<T1> const &rhs) {
		return (!(lhs == rhs));
	}

	template<typename T, typename A>
	bool operator!=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {
		return (!(rhs == lhs));
	}

	template<typename T, typename A>
	bool operator<(vector<T, A> const &lhs, vector<T, A> const &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<typename T, typename A>
	bool operator>(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {
		return (rhs < lhs);
	}

	template<typename T, typename A>
	bool operator<=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {
		return (!(rhs < lhs));
	}

	template<typename T, typename A>
	bool operator>=(const ft::vector<T, A> &lhs, const ft::vector<T, A> &rhs) {
		return (!(rhs > lhs));
	}


}

////SWAP
//template<typename T, typename A>
//void swap(ft::vector<T, A> &lhs, ft::vector<T, A> &rhs) {
//	lhs.swap(rhs); ////todo: NEED vector.swap
//}

template<typename T, typename A>
void swap(ft::vector<T,A>& lhs, ft::vector<T,A>& rhs)
{
	ft::vector<T,A> temp = lhs;
	lhs = rhs;
	rhs = temp;
}

#endif
// T2 - size_type
