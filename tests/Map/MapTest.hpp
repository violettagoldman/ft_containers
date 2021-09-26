#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include <iostream>
# include <map>
# include "Utils.hpp"

# include "Map.hpp"

template <typename T>
void						print_map(T map);
int							test_map(void);
std::map<std::string, int>	create_std_test_map();
ft::Map<std::string, int>	create_ft_test_map();
void						size_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						empty_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						max_size_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						access_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						insert_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						erase_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						clear_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						swap_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						equality_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						inequality_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						greater_than_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						less_than_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						greater_than_or_equal_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);
void						less_than_or_equal_check(ft::Map<std::string, int> ft, std::map<std::string, int> std);


#endif