#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <map>

#include "vector.hpp"
#include "stack.hpp"
#include "utliuty.hpp"
#include "iterator.hpp"
#include "map.hpp"

# ifndef NAME_SPACE
#  define NAME_SPACE ft
#  define KEK 0
# endif


template <typename T>
std::vector<int> swap_test(ft::vector<T> ft_vector);

template <typename T>
std::vector<int> insert_test_1(ft::vector<T> vector);

void insert_test_single();

template <typename T>
std::vector<int> insert_fill(ft::vector<T> vector);

void insert_test_range();

void test_vector();

template <class T, class V>
void copy_constructor_test(ft::map<T, V> mp);

////STACK
//void testStack(void);
void test_stack();

////MAP
void test_map();

#endif
