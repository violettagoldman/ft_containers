#ifndef CONST_REVERSE_VECTOR_ITERATOR_HPP
# define CONST_REVERSE_VECTOR_ITERATOR_HPP

# include "ReverseVectorIterator.hpp"

namespace ft
{
	template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

			ConstReverseVectorIterator(void)
			{};

			ConstReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
			{
				*this = other;
			};

			~ConstReverseVectorIterator(void)
			{};

			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			const value_type &operator*(void)
			{
				return (*this->_ptr);
			};

			const value_type &operator[](int n) const
			{
				return (*(*this - n));
			}
	};
}

#endif