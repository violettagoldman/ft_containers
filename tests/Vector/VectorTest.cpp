#include "VectorTest.hpp"

template <typename T>
void print_vector(T v)
{
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

template <typename T>
bool	operator==(ft::Vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size() || a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

ft::Vector<int> create_ft_test_vector()
{
	ft::Vector<int> ft_v;

	ft_v.push_back(1);
	ft_v.push_back(2);
	ft_v.push_back(3);
	ft_v.push_back(3);
	ft_v.pop_back();
	print_vector(ft_v);
	return (ft_v);
}

std::vector<int> create_std_test_vector()
{
	std::vector<int> std_v;

	std_v.push_back(1);
	std_v.push_back(2);
	std_v.push_back(3);
	std_v.push_back(3);
	std_v.pop_back();
	print_vector(std_v);
	return (std_v);
}

void	size_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Size", ft.size() == std.size());
}

void	empty_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Empty", ft.empty() == std.empty());
}

void	max_size_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Max size", ft.max_size() == std.max_size());
}

void	resize_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft.resize(10, 1);
	std.resize(10, 1);
	check("Resize", ft == std);
}

void	access_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Access operator", ft[0] == std[0]);
}

void	front_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Front", ft.front() == std.front());
}

void	back_check(ft::Vector<int> ft, std::vector<int> std)
{
	check("Back", ft.back() == std.back());
}

void	insert_check(ft::Vector<int> ft, std::vector<int> std)
{
	int arr[] = {1, 2, 3};

	ft.insert(ft.begin(), 1);
	ft.insert(ft.end(), 2);
	ft.insert(ft.begin() + 1, arr, arr + 3);
	std.insert(std.begin(), 1);
	std.insert(std.end(), 2);
	std.insert(std.begin() + 1, arr, arr + 3);
	check("Insert", ft == std);
}

void	erase_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft.erase(ft.begin() + 2);
	std.erase(std.begin() + 2);
	check("Erase", ft == std);
}

void	clear_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft.clear();
	std.clear();
	check("Clear", ft == std);
}

void	swap_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;
	ft_1.push_back(3);
	ft_1.push_back(4);
	ft_1.push_back(6);
	ft_1.push_back(8);
	std_1.push_back(3);
	std_1.push_back(4);
	std_1.push_back(6);
	std_1.push_back(8);
	ft.swap(ft_1);
	std.swap(std_1);
	check("Swap", ft == std);
}

void	equality_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("==", (ft == ft_1) == (std == std_1));
}

void	inequality_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("!=", (ft != ft_1) == (std != std_1));
}

void	greater_than_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check(">", (ft > ft_1) == (std > std_1));
}

void	less_than_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("<", (ft < ft_1) == (std < std_1));
}

void	greater_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check(">=", (ft >= ft_1) == (std >= std_1));
}

void	less_than_or_equal_check(ft::Vector<int> ft, std::vector<int> std)
{
	ft::Vector<int> ft_1;
	std::vector<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("<=", (ft <= ft_1) == (std <= std_1));
}


int		test_vector(void)
{
	ft::Vector<int> ft;
	std::vector<int> std;

	std::cout << "ft_vector: ";
	ft = create_ft_test_vector();
	std::cout << "std_vector: ";
	std = create_std_test_vector();
	size_check(ft, std);
	empty_check(ft, std);
	max_size_check(ft, std);
	resize_check(ft, std);
	access_check(ft, std);
	front_check(ft, std);
	back_check(ft, std);
	insert_check(ft, std);
	erase_check(ft, std);
	clear_check(ft, std);
	swap_check(ft, std);
	equality_check(ft, std);
	inequality_check(ft, std);
	greater_than_check(ft, std);
	less_than_check(ft, std);
	greater_than_or_equal_check(ft, std);
	less_than_or_equal_check(ft, std);
	return (0);
}