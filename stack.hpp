#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft{
	template <typename T, typename Container = ft::vector<T> >
	class stack{
	public:
		typedef T value_type;
		typedef Container container_type;
//		typedef size_t size_type; // Container::size_type size_type;
		typedef typename Container::size_type size_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
////pointer'ов нет
	protected:
		container_type _container;
////METHODS
	public:

		stack(const container_type& ctnr = container_type()) : _container(ctnr){}

		stack(const stack &copy) : _container(copy._container) {}

		stack& operator=(const stack &assign){
			_container = assign._container;
			return (*this);
		}

		bool empty(void) const{
			return (_container.empty());
		}

		size_type size(void) const{
			return(_container.size());
		}

		value_type &top(){
			return(_container.back());
		}

		const value_type &top() const{
			return(_container.back());
		}

		void push(const value_type &val){ //https://www.cplusplus.com/reference/stack/stack/push/
			_container.push_back(val);
		}

		void pop(){
			_container.pop_back();
		}

		//emplace() C11

		template<typename T1, typename Cont>
		friend bool operator==(const stack<T1, Cont> &lhs, const stack<T1, Cont> &rhs){
			return (lhs._container == rhs._container);
		}

		template<typename T1, typename Cont>
		friend bool operator<(const stack<T1, Cont> &lhs, const stack<T1, Cont> &rhs){
			return (lhs._container < rhs._container);
		}
	};

	template<typename T, typename Cont>
	bool operator!=(const stack<T, Cont> &lhs, const stack<T, Cont> &rhs){
		return (!(lhs == rhs));
	}

	template<typename T, typename Cont>
	bool operator>(const stack<T, Cont> &lhs, const stack<T, Cont> &rhs){
		return (rhs < lhs);
	}

	template<typename T, typename Cont>
	bool operator<=(const stack<T, Cont> &lhs, const stack<T, Cont> &rhs){
		return (!(rhs < lhs));
	}

	template<typename T, typename Cont>
	bool operator>=(const stack<T, Cont> &lhs, const stack<T, Cont> &rhs){
		return (!(rhs > lhs));
	}
}

#endif
