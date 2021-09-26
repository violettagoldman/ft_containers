#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <iostream>
# include <memory>
# include <limits>

namespace ft
{
	template <typename T>
	void	swap_ref(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	template <class Key, class T>
	struct	BiNode
	{
		std::pair<Key, T>	pair;
		BiNode				*left;
		BiNode				*right;
		BiNode				*parent;
		bool				end;
	};
};

#endif