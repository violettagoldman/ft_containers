#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <limits>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T>>

	class Vector
	{
		public:
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T&			reference;
			typedef const T& 	const_reference;
			typedef T* 			pointer;
			typedef const T* 	const_pointer;
			typedef ft::VectorIterator<T> iterator;
			typedef ft::ConstVectorIterator<T> const_iterator;
			typedef ft::ReverseVectorIterator<T> reverse_iterator;
			typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;
			typedef ft::IteratorTraitsVectorIterator<T> difference_type;
			typedef unsigned long size_type;
	}
}

#endif