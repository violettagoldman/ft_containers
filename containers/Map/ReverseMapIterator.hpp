#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

namespace ft
{
	template <class K, class T>
	class ReverseMapIterator
	{
		public:
			typedef std::pair<K, T>		value_type;
			typedef std::pair<K, T>&	reference;
			typedef BiNode<K, T>*		pointer;

		protected:
			pointer _ptr;

		private:
			pointer _successor(pointer ptr)
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
			ReverseMapIterator(void) : _ptr(0) {};

			ReverseMapIterator(const pointer ptr) : _ptr(ptr) {};

			ReverseMapIterator(const ReverseMapIterator &other)
			{
				*this = other;
			};

			ReverseMapIterator	&operator=(const ReverseMapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};

			pointer	node(void)
			{
				return (_ptr);
			};

			value_type	&operator*(void)
			{
				return (_ptr->pair);
			};

			value_type	*operator->(void)
			{
				return (&_ptr->pair);
			};

			bool	operator==(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};

			bool	operator!=(const ReverseMapIterator<K, T> &other)
			{
				return (!(*this == other));
			};

			bool	operator>(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};

			bool	operator<(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};

			bool	operator>=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};

			bool	operator<=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			};

			ReverseMapIterator	&operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};

			ReverseMapIterator	&operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};

			ReverseMapIterator	operator++(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};

			ReverseMapIterator	operator--(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
};

#endif