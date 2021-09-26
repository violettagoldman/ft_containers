#ifndef CONST_MAP_ITERATOR_HPP
# define CONST_MAP_ITERATOR_HPP

# include "Utilities.hpp"

namespace ft
{
	template <class K, class T>
	class ConstMapIterator
	{
		public:
			typedef std::pair<K, T>		value_type;
			typedef std::pair<K, T>&	reference;
			typedef BiNode<K, T>*		pointer;

		protected:
			pointer	_ptr;

		private:
			pointer	_successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};

			pointer _predecessor(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};

		public:
			ConstMapIterator(void) : _ptr(0) {};

			ConstMapIterator(const pointer ptr) : _ptr(ptr) {};

			ConstMapIterator(const ConstMapIterator &other)
			{
				*this = other;
			};

			ConstMapIterator	&operator=(const ConstMapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};

			pointer	node(void)
			{
				return (_ptr);
			};

			value_type	&operator*(void) const
			{
				return (_ptr->pair);
			};

			value_type	*operator->(void) const
			{
				return (&_ptr->pair);
			};

			bool	operator==(const ConstMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};

			bool	operator!=(const ConstMapIterator<K, T> &other)
			{
				return (!(*this == other));
			};

			bool	operator>(const ConstMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};

			bool	operator<(const ConstMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};

			bool	operator>=(const ConstMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};

			bool	operator<=(const ConstMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			};

			ConstMapIterator	&operator++(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};

			ConstMapIterator	&operator--(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};

			ConstMapIterator	operator++(int)
			{
				ConstMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};

			ConstMapIterator	operator--(int)
			{
				ConstMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
};

# endif