#ifndef CONST_VECTOR_ITERATOR_HPP
# define CONST_VECTOR_ITERATOR_HPP

# include "VectorIterator.hpp"

namespace ft
{
	template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

			ConstVectorIterator(void)
			{};

			ConstVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};

			ConstVectorIterator(const ConstVectorIterator &other)
			{
				*this = other;
			};

			~ConstVectorIterator(void)
			{};

			ConstVectorIterator &operator=(const ConstVectorIterator &other)
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
				return (*(*this + n));
			}
	};
}

#endif