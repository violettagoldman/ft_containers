#ifndef REVERSE_VECTOR_ITERATOR_HPP
# define REVERSE_VECTOR_ITERATOR_HPP

# include "VectorIterator.hpp"

namespace ft
{
	template <class T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

			ReverseVectorIterator(void)
			{};

			ReverseVectorIterator(const ReverseVectorIterator &other)
			{
				*this = other;
			};

			ReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			~ReverseVectorIterator(void)
			{};

			ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			ReverseVectorIterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			};

			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			};

			ReverseVectorIterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			};

			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr++;
				rteurn (tmp);
			};

			ReverseVectorIterator operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			};

			ReverseVectorIterator operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};

			bool	operator==(const ReverseVectorIterator &other) const
			{
				return (this->_ptr == other._ptr);
			};

			bool	operator!=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr != other._ptr);
			};

			bool	operator>(const ReverseVectorIterator &other) const
			{
				return (this->_ptr > other._ptr);
			};

			bool	operator>=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr >= other._ptr);
			};

			bool	operator<(const ReverseVectorIterator &other) const
			{
				return (this->_ptr < other._ptr);
			};

			bool	operator<=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr <= other._ptr);
			};

			value_type	&operator*(void)
			{
				return (*this->_ptr);
			};

			value_type	*operator->(void)
			{
				return (this->_ptr);
			};

			ReverseVectorIterator	operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};

			ReverseVectorIterator	operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};

			value_type &operator[](int n) const
			{
				return (*(*this - n));
			};
	};
}

#endif