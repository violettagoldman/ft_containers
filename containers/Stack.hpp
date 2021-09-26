#ifndef STACK_HPP
# define STACK_HPP


# include <iostream>
# include <memory>
# include <limits>

# include "Vector.hpp"
# include "Utilities.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
		public:
			typedef	T				value_type;
			typedef Container		container_type;
			typedef unsigned int	size_type;
		
		protected:
			container_type c;

		public:
			explicit	Stack(const container_type &ctnr = container_type()) : c(ctnr)
			{
			};

			Stack &operator=(const Stack &other)
			{
				this->c = other.c;
				return (*this);
			};

			bool		empty(void) const
			{
				return (c.empty());
			};

			size_type 	size(void) const
			{
				return (c.size());
			};

			value_type	&top(void)
			{
				return (c.back());
			};

			const		value_type &top(void) const
			{
				return (c.back());
			};

			void		push(const value_type &value)
			{
				c.push_back(value);
			};

			void		pop(void)
			{
				c.pop_back();
			};

		private:
			template <class A, class B>
			friend bool	operator==(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator!=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator>(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator>=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
	};

	template <class T, class Container>
	bool	operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool	operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};

	template <class T, class Container>
	bool	operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};

	template <class T, class Container>
	bool	operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};

	template	<class T, class Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};

	template <class T, class Container>
	bool	operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
}

#endif
