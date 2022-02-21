#ifndef MAP_HPP
# define MAP_HPP

#include "tree.hpp"
#include "utliuty.hpp"


namespace ft{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map{
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef Compare												key_compare;
		typedef pair<const Key, T>									value_type;
		typedef Allocator											allocator_type;
//		typedef std::size_t size_type;
		typedef typename allocator_type::size_type					size_type;
//		typedef std::ptrdiff_t difference_type; //Заменить на свой
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		typedef const value_type&									reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;

	////PAIR_COMP
	private:
		class pair_compare {
			key_compare _compare;

		public:
			typedef bool        result_type;
			typedef value_type  first_argument_type;
			typedef value_type  second_argument_type;

			pair_compare(const key_compare & compare) : _compare(compare) {}

			bool operator()(const value_type& x, const value_type& y) const{
				return (_compare(x.first, y.first));
			}
		};

	public:
		typedef pair_compare value_compare;
		typedef RBTree<value_type, pair_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef typename tree_type::reverse_iterator		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

//		typedef Node<typename ft::remove_const<value_type>::type > *node_pointer;

	private:
		allocator_type	_alloc;
		tree_type		_tree;
		key_compare		_compare;

/* move in Tree
		node_pointer					_root;
		node_pointer					_lastElem;
		size_type						_size;
		//alloc - est
		std::allocator<node_pointer>	_nodeAlloc;
*/

	public:
////CONSTRUCT
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _tree(tree_type(comp, alloc)), _compare(comp) {}

//		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
//				_alloc(alloc), _tree(tree_type(comp, alloc)), _compare(comp) {
//			_lastElem = createNode(ft::pair<const key_type, mapped_type>());
//			_root = _lastElem;
//			_lastElem->left = _lastElem;
//			_lastElem->right = _lastElem;
//		}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& compare = Compare(), const Allocator& alloc = Allocator()):
				_alloc(alloc),
				_tree(first, last, compare, _alloc),
				_compare(compare) {}

//		template <class InIt>
//		map(InIt first, InIt last, const key_compare& comp = key_compare(),
//			const allocator_type& alloc = allocator_type(),
//			typename ft::enable_if<!ft::is_integral<InIt>::content >::type* = 0) :
//				_size(0), _alloc(alloc), _compare(comp) {
//			_lastElem = createNode(ft::pair<const key_type, mapped_type>());
//			_root = _lastElem;
//			_lastElem->left = _lastElem;
//			_lastElem->right = _lastElem;
//			for (; first != last; ++first)
//				insert(*first);
//		}

		~map() {
			clear();
		}

		map &operator=(const map& assign){
			if (this == &assign)
				return(*this);
			map tmp(assign);
			swap(tmp);
			return *this;
		}

////ITERATORS
		iterator begin(){
			return (_tree.begin());
		}

		iterator end() {
			return (_tree.end());
		}

		reverse_iterator rbegin(){
			return(_tree.rbegin());
		}

		reverse_iterator rend(){
			return(_tree.rend());
		}

////CAPACITY
		bool empty() const{
			return (_tree.empty());
		}

		size_type size() const {
			return (_tree.size());
		}

		size_type max_size() const{
			return (_tree.max_size());
		}

////ACCESS
		mapped_type& operator[](const key_type& key){
			return (*((insert(ft::make_pair(key,mapped_type()))).first)).second;
		}

		T& at(const Key &key){
			iterator res = _tree.find(ft::make_pair(key, mapped_type()));
			if (res == _tree.end())
				throw std::out_of_range("Exception: AT.out_of_range");
			return (res->second);
		}

////MODIFIERS
		//single
		pair<iterator, bool> insert(const value_type& value){
			return (_tree.insert(value));
		}

		//hint pos
		iterator insert(iterator hint, const value_type& value){
			return (_tree.insert(hint, value));
		}

		//range
		template<class InIt>
		void insert(typename enable_if< !is_integral<InIt>::value, InIt >::type first, InIt last){
			_tree.insert(first, last);
		}

		//iterator
		void erase(iterator pos){
			_tree.erase(pos);
		}

		//key
		size_type erase(const Key& key){
			return (_tree.erase(make_pair(key, mapped_type())));
		}

		//range
		void erase(iterator first, iterator last){
			_tree.erase(first, last);
		}

		void swap(map & other){
			std::swap(_compare, other._compare);
			_tree.swap(other._tree);
		}

		void clear() {
			_tree.clear();
		}

////OBSERVERS
		value_compare value_comp() const{
			return (_tree.value_comp());
		}

		key_compare key_comp() const{
			return (_compare);
		}

////OPERATIONS
		iterator	find(const Key& key){
			return _tree.find(make_pair(key, mapped_type()));
		}

		size_type count( const Key& key ) const{
			return (_tree.count(make_pair(key, mapped_type())));
		}

		iterator lower_bound(const key_type& key){
			return (_tree.lower_bound(make_pair(key, mapped_type())));
		}

		const_iterator lower_bound(const key_type& key) const{
			return (_tree.lower_bound(make_pair(key, mapped_type())));
		}

		iterator upper_bound(const key_type& key){
			return (_tree.upper_bound(make_pair(key, mapped_type())));
		}

		const_iterator upper_bound(const key_type& key) const{
			return (_tree.upper_bound(make_pair(key, mapped_type())));
		}

		pair<iterator, iterator> equal_range(const key_type & key){
			return (_tree.equal_range(make_pair(key, mapped_type())));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type & key) const{
			return (_tree.equal_range(make_pair(key, mapped_type())));
		}

////ALLOCATOR
		allocator_type get_allocator() const{
			return (_tree.get_allocator());
		}

////OPERATORS
		template<typename _Key, typename _T, typename _Compare, typename _Alloc>
		friend bool operator==(const map<_Key, _T, _Compare, _Alloc> & lhs,
							   const map<_Key, _T, _Compare, _Alloc>& rhs);

		template<typename _Key, typename _T, typename _Compare, typename _Alloc>
		friend bool operator<(const map<_Key, _T, _Compare, _Alloc> & lhs,
							  const map<_Key, _T, _Compare, _Alloc>& rhs);

/* Move Tree
	private: //Hren'
		tree_type* createNode(const value_type& pair)
		{
			tree_type* newNode = _nodeAlloc.allocate(1);


			_alloc.construct(&newNode->content, pair);
			newNode->parent = 0;
			newNode->left = 0;
			newNode->right = 0;
			return newNode;
		}
*/
	};

	////NON-MEMBERS
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (lhs._tree == rhs._tree);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs == rhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (lhs._tree < rhs._tree);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (rhs < lhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs > rhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs < rhs);
	}


	template<typename Key, typename T, typename Compare, typename Alloc>
	void swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs){
		lhs.swap(rhs);
	}
}

#endif
