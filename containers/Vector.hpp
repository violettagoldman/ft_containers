#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <limits>

# include "Utilities.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >

	class Vector
	{
		public:
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef unsigned long			size_type;
			typedef int						difference_type;
			typedef T&						reference;
			typedef const T& 				const_reference;
			typedef T* 						pointer;
			typedef const T* 				const_pointer;
			typedef ft::VectorIterator<T>	iterator;
			// typedef ft::ConstVectorIterator<T> const_iterator;
			// typedef ft::ReverseVectorIterator<T> reverse_iterator;
			// typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;
		private:
			size_type		_len;
			size_type		_capacity;
			pointer			_arr;
			allocator_type	_alloc;
		public:
			/*
				Constructors
			*/

			// default
			explicit Vector(const allocator_type &allocator = allocator_type()) : _len(0), _capacity(0), _arr(0)
			{
				_arr = _alloc.allocate(0);
			};

			// fill
			Vector(size_type n, const_reference val = value_type(), const allocator_type &allocator = allocator_type()) : _len(0), _capacity(0), _arr(0), _alloc(allocator)
			{
				_arr = _alloc.allocate(0);
				assign(n, val);
			};

			// range
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last, const allocator_type &allocator = allocator_type()) : _len(0), _capacity(0), _arr(0), _alloc(allocator)
			{
				_arr = _allocator.allocate(0);
				assign(first, last);
			};

			// copy
			Vector(const Vector &x) : _len(x._len), _capacity(x._capacity), _arr(x._arr), _alloc(x._alloc)
			{
				*this = x;
			};

			/*
				Destructor
			*/
			~Vector(void)
			{
				_alloc.deallocate(_arr, _capacity);
			};

			/*
				Operator=
			*/
			Vector	&operator=(const Vector &x)
			{
				if (_arr != 0)
					_alloc.deallocate(_arr, _capacity);
				_alloc = x._alloc;
				_capacity = 0;
				_len = 0;
				_arr = _alloc.allocate(0);
				assign(x.begin(), x.end());
				return (*this);
			};

			/*
				Iterators
			*/
			iterator begin(void)
			{
				return (iterator(_arr));
			};

			const_iterator begin(void) const
			{
				return (const_iterator(_arr));
			};

			iterator end(void)
			{
				return (iterator(_arr + _len));
			};

			const_iterator end(void) const
			{
				return (const_iterator(_arr + _len));
			};

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(_arr + _len - 1));
			};

			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(_arr + _len - 1));
			};

			reverse_iterator rend(void)
			{
				return (reverse_iterator(_arr - 1));
			};

			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(_arr - 1));
			};

			/*
				Capacity
			*/
			size_type size(void) const
			{
				return (_len);
			};

			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			};

			void resize(size_type n, value_type val = value_type())
			{
				while (n < _len)
					pop_back();
				while (n > _len)
					push_back(val);
			};

			size_type capacity(void) const
			{
				return (_capacity);
			};

			bool empty(void) const
			{
				return (_len == 0);
			};

			void reserve(size_type n)
			{
				if (n > _capacity)
				{
					size_type i = -1;
					pointer	tmp;
					tmp = _alloc.allocate(n);
					_capacity = n;
					while (++i < _len)
						tmp[i] = _arr[i];
					_alloc.deallocate(_container, _container_size);
					_arr = tmp;
				}
			};

			/*
				Element access
			*/
			reference operator[](size_type n)
			{
				return (_arr[n]);
			};

			const_reference operator[](size_type n) const
			{
				return (_arr[n]);
			};

			reference at(size_type n)
			{
				if (n >= _len || n < 0)
					throw std::out_of_range("index out-of-bounds");
				return _arr[n];
			};

			const_reference at(size_type n) const
			{
				if (n >= _container_length || n < 0)
					throw std::out_of_range("index out-of-bounds");
				return _arr[n];
			};

			reference front(void)
			{
				return _arr[0];
			};

			const_reference front(void) const
			{
				return _arr[0];
			};

			reference back(void)
			{
				return _arr[_len - 1];
			};

			const_reference back(void) const
			{
				return _arr[_len - 1];
			};

			/*
				Modifiers
			*/
			// range
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			};

			// fill
			void assign(size_type n, const value_type &val)
			{
				clear();
				insert(begin(), n, val);
			};

			void push_back(const value_type &val)
			{
				if (_len + 1 > _capacity)
					reserve(_len * 2);
				_arr[_len++] = val;
			};

			void pop_back(void)
			{
				if (_len)
					_arr[--_len] = value_type();
			};

			// signle element
			iterator insert(iterator position, const value_type &val)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _len)
					i++;
				if (_capacity < _len * 2)
					reserve(_len * 2);
				// TODO check if it works with _len
				size_type j = _capacity - 1;
				while (j > i)
				{
					_arr[j] = _arr[j - 1];
					j--;
				}
				_arr[i] = val;
				_len++;
				return (iterator(&_arr[i]));
			};

			// fill
			void insert(iterator position, size_type n, const value_type &val)
			{
				while (n--)
					position = insert(position, val);
			};

			// range
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first) + 1;
					++first;
				}
			};

			iterator erase(iterator position)
			{
				iterator current = position;
				while (current + 1 != end())
				{
					*current = *(current + 1);
					current++;
				}
				--_len;
				return (iterator(position));
			};

			iterator erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					last--;
				}
				return (iterator(first));
			};

			void swap(Vector &x)
			{
				ft::swap_ref(_arr, x._arr);
				ft::swap_ref(_capacity, x._capacity);
				ft::swap_ref(_len, x._len);
			};

			void clear(void)
			{
				erase(begin(), end());
			};

			/*
				Allocator
			*/
			allocator_type get_allocator() const
			{
				return (_alloc);
			};
	};
}

#endif