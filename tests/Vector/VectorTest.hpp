#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include <iostream>
# include <vector>
# include "Utils.hpp"

# include "Vector.hpp"

template <typename T>
void	print_vector(T v);
int		test_vector(void);
std::vector<int> create_std_test_vector();
ft::Vector<int> create_ft_test_vector();
void	size_check(ft::Vector<int> ft, std::vector<int> std);
void	empty_check(ft::Vector<int> ft, std::vector<int> std);
void	max_size_check(ft::Vector<int> ft, std::vector<int> std);
void	resize_check(ft::Vector<int> ft, std::vector<int> std);
void	access_check(ft::Vector<int> ft, std::vector<int> std);
void	front_check(ft::Vector<int> ft, std::vector<int> std);
void	back_check(ft::Vector<int> ft, std::vector<int> std);
void	insert_check(ft::Vector<int> ft, std::vector<int> std);
void	erase_check(ft::Vector<int> ft, std::vector<int> std);
void	clear_check(ft::Vector<int> ft, std::vector<int> std);
void	swap_check(ft::Vector<int> ft, std::vector<int> std);
void	equality_check(ft::Vector<int> ft, std::vector<int> std);
void	inequality_check(ft::Vector<int> ft, std::vector<int> std);
void	greater_than_check(ft::Vector<int> ft, std::vector<int> std);
void	less_than_check(ft::Vector<int> ft, std::vector<int> std);
void	greater_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std);
void	less_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std);


#endif