#pragma once

#include <iostream>
#include "iterator.hpp"
#include "tree_algo.hpp"

namespace ft
{
	// Tree Iterator
	template <class T> struct Node;
	template <class _Tp> class set_iterator;
	template <class _Tp>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef struct  Node<_Tp>	_Node;
		typedef _Node*				nodeptr;
		nodeptr						current;
	public:
		typedef _Tp					value_type;
		typedef _Tp&				reference;
		typedef _Tp*				pointer;

		tree_iterator(): current(NULL) {}
		explicit tree_iterator(const nodeptr& __p): current(__p) {}
		tree_iterator(const tree_iterator& t): current(t.base()) {}
		tree_iterator(tree_iterator& t): current(t.base()) {}

		tree_iterator& operator=(const _Node& t)
		{
			current = t;
			return *this;
		}

		tree_iterator& operator=(const tree_iterator& t)
		{
			current = t.base();
			return *this;
		}

		nodeptr base() const
		{
			return (nodeptr)current;
		}

		reference operator*() const
		{
			return  current->pair;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		tree_iterator& operator++()
		{ 
			current = static_cast<nodeptr>(next_iter(current));
			return *this;
		}

		tree_iterator operator++(int)
		{
			tree_iterator __t(*this);
			++(*this);
			return __t;
		}

		tree_iterator& operator--()
		{
			current = prev_iter(current);
			return *this;
		}

		tree_iterator operator--(int)
		{
			tree_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const tree_iterator& __x, const tree_iterator& __y)
		{
			return __x.current == __y.current;
		}

		friend bool operator!=(const tree_iterator& __x, const tree_iterator& __y)
		{
			return !(__x == __y);
		}

		~tree_iterator(){}
	};

	// Const Tree Iterator

	template <class _Tp>
	class const_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef Node<_Tp>		_Node;
		typedef const _Node*	nodeptr;
		nodeptr					current;
	public:
		typedef _Tp				value_type;
		typedef _Tp&			reference;
		typedef const _Tp*		const_pointer;
		typedef const _Tp&		const_reference;
	
		const_tree_iterator(): current(NULL) {}
		const_tree_iterator(nodeptr &__p): current(__p) {}
		const_tree_iterator(_Node* __p): current(__p) {}

		const_tree_iterator(const const_tree_iterator& t): current(t.base()) {}
		const_tree_iterator(const tree_iterator<_Tp>& t): current(t.base()) {}

		const_tree_iterator& operator=(const _Node& t)
		{
			current = t.base();
			return *this;
		}

		
		nodeptr base() const
		{
			return current;
		}

		nodeptr	base()
		{
			return current;
		}

		const_reference operator*() const
		{
			return  current->pair;
		}

		const_pointer operator->() const
		{
			return  &(operator*());
		}

		const_tree_iterator& operator++()
		{
			current = static_cast<nodeptr>(next_iter(current));
			return *this;
		}

		const_tree_iterator operator++(int)
		{
			const_tree_iterator __t(*this);
			++(*this);
			return __t;
		}

		const_tree_iterator& operator--()
		{
			current = static_cast<nodeptr>(prev_iter(current));
			return *this;
		}

		const_tree_iterator operator--(int)
		{
			const_tree_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const const_tree_iterator& __x, const const_tree_iterator& __y)
		{
			return __x.current == __y.current;
		}

		friend bool operator!=(const const_tree_iterator& __x, const const_tree_iterator& __y)
		{
			return !(__x == __y);
		}

		~const_tree_iterator(){}
	};

	// Set Iterator

	template <class _Tp>
	class set_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef Node<_Tp>		_Node;
		typedef _Node*			nodeptr;
		nodeptr					current;
	public:
		typedef _Tp				value_type;
		typedef _Tp&			reference;
		typedef const _Tp*		const_pointer;
		typedef const _Tp&		const_reference;
	
		explicit set_iterator(): current(NULL) {}
		explicit set_iterator(_Node& newnode): current(&newnode) {}
		explicit set_iterator(const _Node& newnode): current((_Node*)&newnode) {}

		set_iterator(nodeptr newptr): current(newptr) {}
		set_iterator(set_iterator& it): current(NULL)
		{
			*this = it;
		} 
		set_iterator(const set_iterator& it): current(NULL)
		{
			*this = it;
		}

		set_iterator& operator=(const _Node& t)
		{
			current = t.base();
			return *this;
		}
		
		nodeptr base() const
		{
			return current;
		}

		const nodeptr base()
		{
			return current;
		}

		const_reference operator*() const
		{
			return  current->pair;
		}

		const_pointer operator->() const
		{
			return  &(operator*());
		}

		set_iterator& operator++()
		{
			current = static_cast<nodeptr>(next_iter(current));
			return *this;
		}

		set_iterator operator++(int)
		{
			set_iterator __t(*this);
			++(*this);
			return __t;
		}

		set_iterator& operator--()
		{
			current = static_cast<nodeptr>(prev_iter(current));
			return *this;
		}

		set_iterator operator--(int)
		{
			set_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const set_iterator& __x, const set_iterator& __y)
		{
			return __x.current == __y.current;
		}
		
		friend bool operator!=(const set_iterator& __x, const set_iterator& __y)
		{
			return !(__x == __y);
		}

		~set_iterator(){}
	};

}
