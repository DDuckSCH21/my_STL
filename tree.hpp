#ifndef AVLTREE_H
# define AVLTREE_H

#include "utliuty.hpp"
#include "iterator.hpp"

template<class Content>
struct Node{
public:
	explicit Node(Content *cont_val = 0)
		: content(cont_val), //-
		parent(0),
		left(0),
		right(0),
		is_black(false), //-
		is_nil(0){} //-

	Content	*content;
	Node*	parent;
	Node*	left;
	Node*	right;
	bool	is_black;
	bool	is_nil;

	Node(Node const& node_exmpl) {
		is_black = node_exmpl.is_black;
		content = node_exmpl.content;
		parent = node_exmpl.parent;
		is_nil = node_exmpl.is_nil;
		right = node_exmpl.right;
		left = node_exmpl.left;
	};

	Node& operator=(const Node& assign){
		is_black = assign.is_black;
		content = assign.content;
		is_nil = assign.is_nil;
		parent = assign.parent;
		right = assign.right;
		left = assign.left;
		return *this;
	}
	virtual ~Node(){}
};

namespace ft{
	template<class T>
	struct remove_const {
		typedef T type;
	};

	template<class T>
	struct remove_const <const T> {
		typedef T type;
	};
}

template<typename T>
class map_iterator {
public:
	typedef std::bidirectional_iterator_tag						iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type		value_type;
	typedef typename ft::iterator_traits<T*>::reference			reference;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef Node<typename ft::remove_const<value_type>::type >* node_pointer;

private:
	node_pointer _node;
	node_pointer _last; //+

////CONSTRUCT
public:
	map_iterator() {}

	map_iterator(void *node): _node(static_cast<node_pointer>(node)) {} //No explict,

	map_iterator(const map_iterator<typename ft::remove_const<value_type>::type > & other) {
		*this = other;
	}

	map_iterator& operator=(const map_iterator<typename ft::remove_const<value_type>::type>& assign) {
		_node = assign.node();
		return (*this);
	}

	reference operator*() const {
		return *(_node->content);
	}

	pointer operator->() const {
		return (_node->content);
	}

	map_iterator& operator++() {
		if (_node->right && !_node->right->is_nil) {
			_node = _min_node(_node->right);
		}
		else {
			node_pointer node_parent = _node->parent;
			while (node_parent != NULL && _node == node_parent->right) {
				_node = node_parent;
				node_parent = node_parent->parent;
			}
			_node = node_parent;
		}
		return (*this);
	}

	map_iterator operator++(int) {
		map_iterator<value_type> temp = *this;
		if (!_node->right->is_nil) {
			_node = _min_node(_node->right);
		}
		else {
			node_pointer node_parent = _node->parent;
			while (node_parent != NULL && _node == node_parent->right) {
				_node = node_parent;
				node_parent = node_parent->parent;
			}
			_node = node_parent;
		}
		return temp;
	}

	map_iterator& operator--() {
		if (_node->left && !_node->left->is_nil) {
			_node = _max_node(_node->left);
		}
		else {
			node_pointer node_parent = _node->parent;
			while (node_parent != NULL && _node == node_parent->left) {
				_node = node_parent;
				node_parent = node_parent->parent;
			}
			_node = node_parent;
		}
		return *this;

	}

	map_iterator operator--(int) {
		map_iterator<value_type> temp = *this;
		if (_node->left && !_node->left->is_nil) {
			_node = _max_node(_node->left);
		}
		else {
			node_pointer node_parent = _node->parent;
			while (node_parent != NULL && _node == node_parent->left) {
				_node = node_parent;
				node_parent = node_parent->parent;
			}
			_node = node_parent;
		}
		return temp;
	}

	node_pointer node() const {
		return (_node);
	}

private:

	node_pointer _min_node(node_pointer n) const {
		while(n->left != NULL && !n->left->is_nil)
			n = n->left;
		return n;
	}

	node_pointer _max_node(node_pointer n) const {
		while (!n->right->is_nil)
			n = n->right;
		return n;
	}
};

template<typename A, typename B>
bool operator==(const map_iterator<A> & lhs, const map_iterator<B> & rhs){
	return (lhs.node() == rhs.node());
}

template<typename A, typename B>
bool operator!=(const map_iterator<A> & lhs, const map_iterator<B> & rhs){
	return (lhs.node() != rhs.node());
}

////TREE
	template<class Key, class Compare = std::less <Key>, class Alloc = std::allocator <Key> >
	class RBTree {
	public:
		typedef Key											value_type;
		typedef Compare										value_compare;
		typedef Alloc										allocator_type;
		typedef typename Alloc::template
		rebind<Node<Key> >::other							node_allocator; //чтобы аллоцировать не Key, а Node
		//typedef Node_Alloc node_allocator_type;
		typedef typename node_allocator::pointer			node_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef std::ptrdiff_t								difference_type;
		typedef map_iterator<Key>							iterator;
		typedef map_iterator<const Key>						const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
//		typedef std::size_t size_type;
		typedef std::allocator_traits<allocator_type>		_node_traits;
		typedef std::allocator_traits<allocator_type>		_alloc_traits;
		typedef typename _alloc_traits::size_type			size_type;

	private:
		allocator_type _alloc_map;
		node_allocator _alloc_node;
		value_compare _compare;
		node_pointer _nil;
		node_pointer _header;
		node_pointer _root;
		size_type _size;

	public:

////CONSTRUCT
		RBTree(const Compare &comp, const allocator_type &a = allocator_type())
				: _alloc_map(a),
				_alloc_node(node_allocator()),
				_compare(comp),
				_root(0),
				_size(0) {
			init_nil_head();
			_root = _header;
		}

		RBTree() : _root(0),
				_alloc_map(allocator_type()),
				_alloc_node(node_allocator()),
				_compare(value_compare()),
				_size(0) {
			init_nil_head();
			_root = _header;
		}

		RBTree(const RBTree& src)
			:  _compare(src._compare),
			_root(NULL) {
			*this = src;
		}

		template<class InputIt>
		RBTree(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last, const value_compare& comp, const allocator_type& alloc = allocator_type())
				:	_alloc_map(alloc),
					 _alloc_node(node_allocator()),
					 _compare(comp),
					 _size(0){
			init_nil_head();
			_root = _header;
//			size_type len = last - first;
//			for (size_type i = 0; i < len; i++){
//				insert(*(++first));
//				_size++;
//			}
			for (; first != last; ++first){
				insert(*first);
			}
		}

		~RBTree() {
			clear_node(_root);
			_alloc_map.destroy(_header->content);
			_alloc_map.deallocate(_header->content, 1);
			_alloc_node.deallocate(_nil, 1);
			_alloc_node.deallocate(_header, 1);
		}

		RBTree &operator=(const RBTree &src) {
			if (this == &src)
				return *this;
			this->_alloc_node = src._alloc_node;
			this->_alloc_map = src._alloc_map;
			this->_compare = src._compare;
			if (this->_root == NULL)
				init_nil_head();
			else
				clear_node(_root);
			if (src._size == 0)
				this->_root = this->_header;
			else {
				this->_root = copy_node(src._root);
				copy_child(this->_root, src._root);
			}
			this->_size = src._size;
			return *this;
		}
////ITERATORS
		iterator end() {
			return (iterator(_header));
		}

		const_iterator end() const {
			return (const_iterator(_header));
		}

		iterator begin() {
			if (_size == 0)
				return (_header);
			else
				return (iterator(tree_min(_root)));
		}

		const_iterator begin() const {
			if (_size == 0)
				return (const_iterator(_header));
			else
				return (const_iterator(tree_min(_root)));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

////CAPACITY
		size_type size() const {
			return (_size);
		}

		size_type max_size() const {
//			return std::min<size_type>(_node_traits::max_size(_alloc_node()), std::numeric_limits<difference_type >::max());
			return (_alloc_map.max_size());
		}

		bool empty() const {
			return (_size == 0);
		}

////ACCESS
	//[] - insert(make_pair)
	//at -> find

////MODIFIERS
	//single element
	ft::pair<iterator, bool> insert(value_type const &val) {
		node_pointer find_val = search(val, _root);
		if (find_val)
			return ft::pair<iterator, bool>(iterator(find_val), false);
		node_pointer new_node = _alloc_node.allocate(1);
		_alloc_node.construct(new_node, Node<value_type>(create_value(val)));
		new_node->left = _nil;
		new_node->right = _nil;
		_insert_into_tree(new_node, _root);
		ft::pair<iterator, bool> res(iterator(new_node), true);
		_insert_fixup(new_node);
		_size++;
		new_node = tree_max(_root);
		new_node->right = _header;
		_header->parent = new_node;
		return res;
	}

	//position
	iterator insert(iterator position, const value_type &value) {
		node_pointer new_node = search(value, _root);
		if (new_node)
			return (iterator(new_node));
		new_node = _alloc_node.allocate(1);
		_alloc_node.construct(new_node, Node<value_type>(create_value(value)));
		new_node->left = _nil;
		new_node->right = _nil;
		if (position == begin()) {
			if (position != end() && _compare(value, *position))
				_insert_into_tree(new_node, tree_min(_root));
			else
				_insert_into_tree(new_node, _root);
		} else if (position == end()) {
			if (position != begin() && _compare(*(--position), value))
				_insert_into_tree(new_node, _header->parent);
			else
				_insert_into_tree(new_node, _root);
		} else
			_insert_into_tree(new_node, _root);
		_insert_fixup(new_node);
		_size++;
		node_pointer max_of_tree = tree_max(_root);
		max_of_tree->right = _header;
		_header->parent = max_of_tree;
		return (iterator(new_node));
	}

	//range
	template<class InIt>
	void insert(typename ft::enable_if<!ft::is_integral<InIt>::value, InIt>::type first, InIt last) {
		for (; first != last; ++first)
			insert(*first);
	}

	//single pos_iter
	void erase(iterator pos) {
		node_pointer y = pos.node(), x, del_node;
		del_node = y;
		bool y_flag_black = y->is_black;
		if (is_nil(y->left)) {
			x = y->right;
			transplant(y, y->right);
		}
		else if (is_nil(y->right)) {
			x = y->left;
			transplant(y, y->left);
		}
		else {
			node_pointer z = y;
			y = tree_min(z->right);
			y_flag_black = y->is_black;
			x = y->right;
			if (y->parent != z) {
				transplant(y, y->right);
				y->right = z->right;
				z->right->parent = y;
			}
			transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->is_black = z->is_black;
		}
		free_node(del_node);
		if (y_flag_black)
			_erase_fixup(x);
		_size--;
		_nil->parent = NULL;
		if (_size == 0)
			_root = _header;
		else {
			if (_size != 1)
				x = tree_max(_root);
			else
				x = _root;
			x->right = _header;
			_header->parent = x;
		}
	}

	//key_type
	size_type erase(const value_type &value) {
		node_pointer res = search(value, _root);
		if (res)
			erase(iterator(res)); //del all key
		return (res != NULL);
	}

	//range
	void erase(iterator first, iterator last) {
		while (first != last)
			erase(first++);
	}

	void swap(RBTree &other) {
		std::swap(_root, other._root);
		std::swap(_nil, other._nil);
		std::swap(_header, other._header);
		std::swap(_size, other._size);
		std::swap(_alloc_node, other._alloc_node);
		std::swap(_alloc_map, other._alloc_map);
		std::swap(_compare, other._compare);
	}

	void clear() {
		clear_node(_root);
		_root = _header;
		_header->parent = NULL;
		_size = 0;
	}

////OBSERVERS

	value_compare value_comp() const {
		return (_compare);
	}

////OPERATIONS
	iterator find(const value_type &value) {
		node_pointer find_res = search(value, _root);
		if (find_res == NULL)
			return (end());
		else
			return (iterator(find_res));
	}

	const_iterator find(const value_type &value) const {
		node_pointer find_res = search(value, _root);
		if (find_res == NULL)
			return (end());
		else
			return (const_iterator(find_res));
	}

	size_type count(const value_type &value) const {
		return (find(value) != end());
	}

	iterator lower_bound(const value_type &value) {
		iterator last = end();
		for (iterator first = begin(); first != last; ++first) {
			if (!_compare(*first, value))
				return (first);
		}
		return (last);
	}

	const_iterator lower_bound(const value_type &value) const {
		const_iterator last = end();
		for (const_iterator first = begin(); first != last; ++first) {
			if (!_compare(*first, value))
				return (first);
		}
		return (last);
	}

	iterator upper_bound(const value_type &value) {
		iterator last = end();
		for (iterator first = begin(); first != last; ++first) {
			if (_compare(value, *first))
				return (first);
		}
		return (last);
	}

	const_iterator upper_bound(const value_type &value) const {
		const_iterator last = end();
		for (const_iterator first = begin(); first != last; ++first) {
			if (_compare(value, *first))
				return (first);
		}
		return (last);
	}

	ft::pair<iterator, iterator> equal_range(const value_type &value) {
		return (ft::make_pair(lower_bound(value), upper_bound(value)));
	}

	ft::pair<const_iterator, const_iterator> equal_range(const value_type &value) const{
		return (make_pair(lower_bound(value), upper_bound(value)));
	}

////ALLOCATOR
	allocator_type get_allocator() const {
		return (_alloc_map);
	}

	private:
		void _erase_fixup(node_pointer x) {
			node_pointer brother;
			while (x != _root && x->is_black) {
				if (x == x->parent->left) {
					brother = x->parent->right;
					if (!brother->is_black) {
						brother->is_black = true;
						x->parent->is_black = false;
						_rotate_left(x->parent);
						brother = x->parent->right;
					}
					if (brother->left->is_black && brother->right->is_black) {
						brother->is_black = false;
						x = x->parent;
					} else {
						if (brother->right->is_black) {
							brother->left->is_black = true;
							brother->is_black = false;
							_rotate_right(brother);
							brother = x->parent->right;
						}
						brother->is_black = x->parent->is_black;
						x->parent->is_black = true;
						brother->right->is_black = true;
						_rotate_left(x->parent);
						x = _root;
					}
				} else {
					brother = x->parent->left;
					if (!brother->is_black) {
						brother->is_black = true;
						x->parent->is_black = false;
						_rotate_right(x->parent);
						brother = x->parent->left;
					}
					if (brother->right->is_black && brother->left->is_black) {
						brother->is_black = false;
						x = x->parent;
					} else {
						if (brother->left->is_black) {
							brother->right->is_black = true;
							brother->is_black = false;
							_rotate_left(brother);
							brother = x->parent->left;
						}
						brother->is_black = x->parent->is_black;
						x->parent->is_black = true;
						brother->left->is_black = true;
						_rotate_right(x->parent);
						x = _root;
					}
				}
			}
		}

		node_pointer tree_min(node_pointer n) const {
			while (n != NULL && !is_nil(n->left))
				n = n->left;
			return n;
		}

		node_pointer tree_max(node_pointer n) const {
			while (n != NULL && !is_nil(n->right))
				n = n->right;
			return n;
		}

		void _rotate_right(node_pointer node) {
			node_pointer y;

			y = node->left;
			node->left = y->right;
			if (!is_nil(y->right))
				y->right->parent = node;
			y->parent = node->parent;
			if (node->parent == NULL)
				_root = y;
			else if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			y->right = node;
			node->parent = y;
		}

		void _rotate_left(node_pointer node) {
			node_pointer y;

			y = node->right;
			node->right = y->left;
			if (!is_nil(y->left))
				y->left->parent = node;
			y->parent = node->parent;
			if (node->parent == NULL)
				_root = y;
			else if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			y->left = node;
			node->parent = y;
		}

		node_pointer _insert(node_pointer new_node) {
			if (_root == _header)
				_root = new_node;
			else
				_insert_to_node(_root, new_node);
			return new_node;
		}

		node_pointer _insert_to_node(node_pointer root, node_pointer new_node) {
			if (_compare(*new_node->content, *root->content)) {
				if (!is_nil(root->left))
					return (_insert_to_node(root->left, new_node));
				root->left = new_node;
			} else {
				if (!is_nil(root->right))
					return (_insert_to_node(root->right, new_node));
				root->right = new_node;
			}
			new_node->parent = root;
			return (new_node);
		}

		node_pointer _insert_into_tree(node_pointer new_node, node_pointer where) {
			if (_root == _header)
				_root = new_node;
			else
				_insert_to_node(where, new_node);
			return (new_node);
		}

		void _insert_fixup(node_pointer node) {
			if (node != _root && node->parent != _root) {
				while (node != _root && !node->parent->is_black) {
					if (node->parent == node->parent->parent->left) {
						node_pointer uncle = node->parent->parent->right;
						if (!uncle->is_black) {
							node->parent->is_black = true;
							uncle->is_black = true;
							node->parent->parent->is_black = false;
							node = node->parent->parent;
						} else {
							if (node == node->parent->right) {
								node = node->parent;
								_rotate_left(node);
							}
							node->parent->is_black = true;
							node->parent->parent->is_black = false;
							_rotate_right(node->parent->parent);
						}
					} else {
						node_pointer uncle = node->parent->parent->left;
						if (!uncle->is_black) {
							node->parent->is_black = true;
							uncle->is_black = true;
							node->parent->parent->is_black = false;
							node = node->parent->parent;
						} else {
							if (node == node->parent->left) {
								node = node->parent;
								_rotate_right(node);
							}
							node->parent->is_black = true;
							node->parent->parent->is_black = false;
							_rotate_left(node->parent->parent);
						}
					}
				}
			}
			_root->is_black = true;
		}

		bool is_nil(node_pointer node) const {
			return (node == _nil || node == _header);
		}

		void clear_node(node_pointer node) {
			if (node && !is_nil(node)) {
				clear_node(node->right);
				clear_node(node->left);
				_alloc_map.destroy(node->content);
				_alloc_map.deallocate(node->content, 1);
				_alloc_node.deallocate(node, 1);

			}
		}

		void init_nil_head() {
			_nil = _alloc_node.allocate(1);
			_alloc_node.construct(_nil, Node<Key>());
			_nil->is_black = true;
			_nil->is_nil = true;
			_header = _alloc_node.allocate(1);
			_alloc_node.construct(_header, Node<Key>());
			_header->content = _alloc_map.allocate(1);
			_alloc_map.construct(_header->content, Key());
			_header->is_black = true;
		}

		void transplant(node_pointer where, node_pointer what) {
			if (where == _root)
				_root = what;
			else if (where == where->parent->left)
				where->parent->left = what;
			else
				where->parent->right = what;
			what->parent = where->parent;
		}

		void free_node(node_pointer node) {
			_alloc_map.destroy(node->content);
			_alloc_map.deallocate(node->content, 1);
			_alloc_node.deallocate(node, 1);
		}

	pointer create_value(const value_type &value) {
		pointer new_val = _alloc_map.allocate(1);
		_alloc_map.construct(new_val, value);
		return new_val;
	}

	node_pointer copy_node(node_pointer other) {
		node_pointer new_node = _alloc_node.allocate(1);
		_alloc_node.construct(new_node, Node<Key>());
		new_node->is_black = other->is_black;
		new_node->is_nil = other->is_nil;
		if (other->content) {
			new_node->content = _alloc_map.allocate(1);
			_alloc_map.construct(new_node->content, *other->content);
		}
		return (new_node);
	}

	void copy_child(node_pointer my_node, node_pointer other) {
		if (other->left->is_nil)
			my_node->left = _nil;
		else {
			my_node->left = copy_node(other->left);
			my_node->left->parent = my_node;
			copy_child(my_node->left, other->left);
		}
		if (other->right->is_nil)
			my_node->right = _nil;
		else if (other->right->right == NULL) {
			my_node->right = _header;
			_header->parent = my_node;
		} else {
			my_node->right = copy_node(other->right);
			my_node->right->parent = my_node;
			copy_child(my_node->right, other->right);
		}
	}

	node_pointer search(const value_type &value, node_pointer node) const {
		if (!node || is_nil(node))
			return NULL;
		if (_compare(value, *node->content))
			return search(value, node->left);
		if (_compare(*node->content, value))
			return search(value, node->right);
		return node;
	}
	};

////OPERATORS NON-MEMBER
	template<typename Value, typename Compare, typename Alloc>
	bool operator<(const RBTree<Value, Compare, Alloc> &lhs, const RBTree<Value, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<typename Value, typename Compare, typename Alloc>
	bool operator>(const RBTree<Value, Compare, Alloc> &lhs, const RBTree<Value, Compare, Alloc> &rhs) {
		return (lhs < rhs);
	}


	template<typename Value, typename Compare, typename Alloc>
	bool operator==(const RBTree<Value, Compare, Alloc> &lhs, const RBTree<Value, Compare, Alloc> &rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<typename Value, typename Compare, typename Alloc>
	void swap(const RBTree<Value, Compare, Alloc> &lhs, const RBTree<Value, Compare, Alloc> &rhs) {
		lhs.swap(rhs);
	}

#endif
