#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

#include <string>
#include <iostream>

namespace ft{ //302

////STRUCT
	template <typename A, typename R>
	struct unary_function{
		typedef A argumentType;
		typedef R resultType;
	};

	template <typename A1, typename A2, typename R> //303
	struct binary_function{
		typedef A1 first_arg_type;
		typedef A2 second_arg_type;
		typedef R result_type;
	};

	template <typename T> //303
	struct negate : unary_function<T, T> {
		T operator()(const T& x) const{
			return (-x);
		}
	};
////FUNC
	template <typename T>
	struct plus : binary_function<T, T, T> {
		T operator()(const T& x, const T& y) const{
			return (x + y);
		}
	};

	template <typename T> //311
	struct equal_to : public binary_function<<T, T, bool>{
		bool operator()(const T& x, const T& y) const{
			return (x == y);
		}
	};

	template <typename T> //322
	struct not_equal_to : public binary_function<<T, T, bool>{
		bool operator()(const T& x, const T& y) const{
			return (x != y);
		}
	};
////CLASS
}
	/* //306
	 * minus
	 * multiples
	 * divides
	 * modulus

	 * not_equal_to
	 * greater
	 * less
	 * greater_equal
	 * less_equal
	 * logical_and
	 * logical_or
	 * logical_not
	 * unary_negate //324
	 * binary_negate
	 * binder1st
	 * binder2st
	 * pointer_to_unary_function
	 * pointer_to_binary_function
	 * mem_fun_t
	 * mem_fun1_t
	 * const_mem_fun_t
	 * constmem_funl_t
	 * mem_fun_ref_t
	 * mem_fun1_ref_t
	 * const_mem_fun_ref_t
	 * const_mem_fun1_ref_t
	 */
#endif
