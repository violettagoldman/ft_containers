#include "StackTest.hpp"

template <typename T>
void print_stack(T s)
{
	while (!s.empty()) 
	{
		std::cout << s.top() << "\t";
		s.pop();
	}
	std::cout << std::endl;
}

ft::Stack<int> create_ft_test_stack()
{
	ft::Stack<int> ft_s;

	ft_s.push(1);
	ft_s.push(2);
	ft_s.push(3);
	ft_s.push(3);
	ft_s.pop();
	print_stack(ft_s);
	return (ft_s);
}

std::stack<int> create_std_test_stack()
{
	std::stack<int> std_s;

	std_s.push(1);
	std_s.push(2);
	std_s.push(3);
	std_s.push(3);
	std_s.pop();
	print_stack(std_s);
	return (std_s);
}

void	size_check(ft::Stack<int> ft, std::stack<int> std)
{
	check("Size", ft.size() == std.size());
}

void	empty_check(ft::Stack<int> ft, std::stack<int> std)
{
	check("Empty", ft.empty() == std.empty());
}

void	top_check(ft::Stack<int> ft, std::stack<int> std)
{
	check("Top", ft.top() == std.top());
}

void	equality_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("==", (ft == ft_1) == (std == std_1));
}

void	inequality_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("!=", (ft != ft_1) == (std != std_1));
}

void	greater_than_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check(">", (ft > ft_1) == (std > std_1));
}

void	less_than_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("<", (ft < ft_1) == (std < std_1));
}

void	greater_than_or_equal_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check(">=", (ft >= ft_1) == (std >= std_1));
}

void	less_than_or_equal_check(ft::Stack<int> ft, std::stack<int> std)
{
	ft::Stack<int> ft_1;
	std::stack<int> std_1;

	ft_1 = ft;
	std_1 = std;
	check("<=", (ft <= ft_1) == (std <= std_1));
}

int		test_stack(void)
{
	ft::Stack<int> ft;
	std::stack<int> std;

	std::cout << "ft_stack: ";
	ft = create_ft_test_stack();
	std::cout << "std_stack: ";
	std = create_std_test_stack();
	size_check(ft, std);
	empty_check(ft, std);
	top_check(ft, std);
	equality_check(ft, std);
	inequality_check(ft, std);
	greater_than_check(ft, std);
	less_than_check(ft, std);
	greater_than_or_equal_check(ft, std);
	less_than_or_equal_check(ft, std);
	return (0);
}