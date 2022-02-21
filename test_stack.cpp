#include "test.hpp"


void test_stack(){
	std::cout << "**//------------------STACK------------------//**" << std::endl;
	std::cout << "\n-----------------constructors_STACK-----------------\n";

	NAME_SPACE::vector<int> myvector (2,200);        // vector with 2 elements

	std::cout << "default stack \"first\"\n";
	NAME_SPACE::stack<int> first;                    // empty stack
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "second(myvector)\n";
	NAME_SPACE::stack<int, NAME_SPACE::vector<int> > second (myvector);         // stack initialized to copy of vector
//	std::stack<int,std::vector<int> > third;  // empty stack using vector

	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "stack::vector third\n";
	NAME_SPACE::stack<int,NAME_SPACE::vector<int> > third;  // empty stack using vector
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "stack::vector fourth(myvector)\n";
	NAME_SPACE::stack<int,NAME_SPACE::vector<int> > fourth (myvector);
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout << "\n-----------------empty_STACK-----------------\n";
	std::cout << "first.empty: " << first.empty() << '\n';
	std::cout << "second.empty: " << second.empty() << '\n';
	std::cout << "\n-----------------size_STACK-----------------\n";
	std::cout << "second.push(i)x5\n";
	for (int i = 0; i < 5; i++) second.push(i);
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "second.pop()x2\n";
	second.pop();
	second.pop();
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "\n-----------------top_STACK-----------------\n";
	std::cout << "second.top: " << second.top() << '\n';
	std::cout << "second.top() \"-= 6\"\n";
	second.top() -= 6;
	std::cout << "second.top: " << second.top() << '\n';
	std::cout << "\n-----------------push_STACK-----------------\n";
	std::cout << "second.push(42)\n";
	second.push(42);
	std::cout << "second:";
	while (!second.empty())
	{
		std::cout << ' ' << second.top();
		second.pop();
	}
	std::cout << '\n';
	std::cout << "\n-----------------pop_STACK-----------------\n";
	std::cout << "second.size: " << second.size() << '\n';
	std::cout << "second.push(21)\n";
	std::cout << "second.push(42)\n";
	std::cout << "second.push(33)\n";
	std::cout << "second.push(88)\n";
	second.push(21);
	second.push(42);
	second.push(33);
	second.push(88);
	std::cout << "second.size: " << second.size() << '\n';
	std::cout << "second.pop()x2\n";
	second.pop();
	second.pop();
	std::cout << "second.size: " << second.size() << '\n';
	std::cout << "second:";
	while (!second.empty())
	{
		std::cout << ' ' << second.top();
		second.pop();
	}
	std::cout << '\n';
}


//void testStack(void)
//{
//	std::cout << "**//------------------STACK------------------//**" << std::endl;
//	ft::stack<int> *ft_stack_heap = new ft::stack<int>; //for test leaks
//	ft::stack<int> ft_stack_stack;
//	std::stack<int> std_stack_stack;
//	std::cout << "-----FT::STACK.EMPTY = " << ft_stack_stack.empty() << std::endl;
//	std::cout << "----STL::STACK.EMPTY = " << std_stack_stack.empty() << std::endl << std::endl;
//	std::cout << "--------------STACK.PUSH.SIZE--------------" << std::endl;
//	for (int i = 0; i < 10; i++)
//	{
//		ft_stack_stack.push(i + 23);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		std_stack_stack.push(i + 23);
//	}
//	std::cout << "-----FT::STACK.SIZE  = " << ft_stack_stack.size() << std::endl;
//	std::cout << "----STL::STACK.SIZE  = " << std_stack_stack.size() << std::endl << std::endl;
//	std::cout << "-----FT::STACK.EMPTY = " << ft_stack_stack.empty() << std::endl;
//	std::cout << "----STL::STACK.EMPTY = " << std_stack_stack.empty() << std::endl << std::endl;
//	std::cout << "---------------STACK.TOP.POP---------------" << std::endl;
//	std::cout << "-----FT::STACK: " << std::endl;
//	while (!ft_stack_stack.empty())
//	{
//		std::cout << ft_stack_stack.top() << " ";
//		ft_stack_stack.pop();
//	}
//	std::cout << std::endl;
//	std::cout << "----STL::STACK: " << std::endl;
//	while (!std_stack_stack.empty())
//	{
//		std::cout << std_stack_stack.top() << " ";
//		std_stack_stack.pop();
//	}
//	std::cout << std::endl << std::endl;
//
//	std::cout << "-----FT::STACK.SIZE  = " << ft_stack_stack.size() << std::endl;
//	std::cout << "----STL::STACK.SIZE  = " << std_stack_stack.size() << std::endl;
//	std::cout << std::endl;
//	std::cout << "-----FT::STACK.EMPTY = " << ft_stack_stack.empty() << std::endl;
//	std::cout << "----STL::STACK.EMPTY = " << std_stack_stack.empty() << std::endl;
//
//
//	std::cout << "----------STACK.COMPARE_OPERATION----------" << std::endl;
//	ft::stack<int> ft_stack_comp1;
//	ft::stack<int> ft_stack_comp2;
//	std::stack<int> stl_stack_comp1;
//	std::stack<int> stl_stack_comp2;
//
//	std::cout << "-----FT::STACK.==: " << (ft_stack_comp1 == ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.==: " << (stl_stack_comp1 == stl_stack_comp2) << std::endl << std::endl;
//
//	std::cout << "-----FT::STACK.>: " << (ft_stack_comp1 > ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.>: " << (stl_stack_comp1 > stl_stack_comp2) << std::endl << std::endl;
//
//	ft_stack_comp2.push(42);
//	stl_stack_comp2.push(42);
//
//	std::cout << "-----FT::STACK.>=: " << (ft_stack_comp1 >= ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.>=: " << (stl_stack_comp1 >= stl_stack_comp2) << std::endl << std::endl;
//
//	std::cout << "-----FT::STACK.<: " << (ft_stack_comp1 < ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.<: " << (stl_stack_comp1 < stl_stack_comp2) << std::endl << std::endl;
//
//	std::cout << "-----FT::STACK.<=: " << (ft_stack_comp1 <= ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.<=: " << (stl_stack_comp1 <= stl_stack_comp2) << std::endl << std::endl;
//
//	std::cout << "-----FT::STACK.!=: " << (ft_stack_comp1 != ft_stack_comp2) << std::endl;
//	std::cout << "-----STL::STACK.!=: " << (stl_stack_comp1 != stl_stack_comp2) << std::endl << std::endl;
//	delete ft_stack_heap;
//}