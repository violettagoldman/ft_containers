#ifndef UTILITIES_HPP
# define UTILITIES_HPP

namespace ft
{
	template <typename T>
	void	swap_ref(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	// template <class T>
	// struct Node
	// {
	// 	T data;
	// 	Node *prev;
	// 	Node *next;
	// };
	// template <class Key, class T>
	// struct BNode
	// {
	// 	std::pair<Key, T> pair;
	// 	BNode *left;
	// 	BNode *right;
	// 	BNode *parent;
	// 	bool end;
	// };
};

#endif