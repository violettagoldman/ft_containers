#include "MapTest.hpp"

template <class T>
void	print_map(T map)
{
	typename T::iterator it = map.begin();
	while (it != map.end())
	{
		std::cout << it->first << ": " << it->second << "\t";
		++it;
	}
	std::cout << std::endl;
}

ft::Map<std::string, int>	create_ft_test_map()
{
	ft::Map<std::string, int> ft;
	
	ft["zero"] = 0;
	ft["one"] = 1;
	ft["two"] = 2;
	print_map(ft);
	return (ft);
}

std::map<std::string, int>	create_std_test_map()
{
	std::map<std::string, int> std;
	
	std["zero"] = 0;
	std["one"] = 1;
	std["two"] = 2;
	print_map(std);
	return (std);
}

void						size_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
	check("Size", ft.size() == std.size());
}

void						empty_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
		check("Empty", ft.empty() == std.empty());
}

void						max_size_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
		check("Max size", ft.max_size() == std.max_size());
}

void						access_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
	check("Access", ft["one"] == std["one"]);
}

void						insert_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
	ft.insert(++ft.begin(), std::make_pair("three", 3));
	std.insert(++std.begin(), std::make_pair("three", 3));

	std::cout << "Insert" << std::endl;
	check("\tzero", ft["zero"] == std["zero"]);
	check("\tone", ft["one"] == std["one"]);
	check("\ttwo", ft["two"] == std["two"]);
	check("\tthree", ft["three"] == std["three"]);
}

void						erase_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
	ft.erase(++ft.begin());
	std.erase(++std.begin());
	std::cout << "Erase" << std::cout;
	check("\tzero", ft["zero"] == std["zero"]);
	check("\tone", ft["one"] == std["one"]);
	check("\ttwo", ft["two"] == std["two"]);
	check("\tthree", ft["three"] == std["three"]);
}

void						clear_check(ft::Map<std::string, int> ft, std::map<std::string, int> std)
{
	ft.clear();
	std.clear();
	std::cout << "Clear" << std::endl;
	check("\tzero", ft["zero"] == std["zero"]);
	check("\tone", ft["one"] == std["one"]);
	check("\ttwo", ft["two"] == std["two"]);
	check("\tthree", ft["three"] == std["three"]);
}

int		test_map(void)
{
	ft::Map<std::string, int> ft;
	std::map<std::string, int> std;

	std::cout << "ft_map: ";
	ft = create_ft_test_map();
	std::cout << "std_map: ";
	std = create_std_test_map();
	size_check(ft, std);
	empty_check(ft, std);
	insert_check(ft, std);
	access_check(ft, std);
	erase_check(ft, std);
	clear_check(ft, std);
	return (0);
}