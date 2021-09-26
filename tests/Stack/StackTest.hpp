#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include <iostream>
# include <stack>
# include "Utils.hpp"

# include "Stack.hpp"

template <typename T>
void			print_stack(T v);
int				test_stack(void);
std::stack<int>	create_std_test_stack();
ft::Stack<int>	create_ft_test_stack();
void			size_check(ft::Stack<int> ft, std::stack<int> std);
void			empty_check(ft::Stack<int> ft, std::stack<int> std);
void			top_check(ft::Stack<int> ft, std::stack<int> std);
void			equality_check(ft::Vector<int> ft, std::vector<int> std);
void			inequality_check(ft::Vector<int> ft, std::vector<int> std);
void			greater_than_check(ft::Vector<int> ft, std::vector<int> std);
void			less_than_check(ft::Vector<int> ft, std::vector<int> std);
void			greater_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std);
void			less_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std);


#endif