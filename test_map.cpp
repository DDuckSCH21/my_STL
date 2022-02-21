#include "test.hpp"

void operators_comparisons_test(){
	std::cout << "\n--------operators_comparisons_MAP--------\n";

	NAME_SPACE::map<int, int> map_1;
	NAME_SPACE::map<int, int> map_2;

	map_1[10] = 10;
	map_1[36] = 36;
	map_1[8] = 8;

	map_2[1] = 1;
	map_2[3] = 3;
	map_2[100] = 100;

	std::cout << "map_1:\n";
	for (NAME_SPACE::map<int,int>::iterator it=map_1.begin(); it!=map_1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\nmap_2:\n\n";
	for (NAME_SPACE::map<int,int>::iterator it=map_2.begin(); it!=map_2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "map_1 < map_2 is: " << (map_1 < map_2) << "\n";
	std::cout << "map_1 > map_2 is: "  << (map_1 > map_2) << "\n";
	std::cout << "map_1 == map_2 is: " << (map_1 == map_2) << "\n";
	std::cout << "map_1 != map_2 is: " << (map_1 != map_2) << "\n";
	std::cout << "map_1 <= map_2 is: " << (map_1 <= map_2) << "\n";
	std::cout << "map_1 >= map_2 is: " << (map_1 >= map_2) << "\n";
}


template <class T, class V>
void copy_constructor_test(NAME_SPACE::map<T, V> mp) {

	std::cout << "\n--------copy_constructor_MAP--------------\n";

	for (int i = 0, j = 10; i < 10; ++i, ++j) {
		mp.insert(NAME_SPACE::make_pair(i, j));
	}

	std::cout << "---map_original\n";
	for(unsigned long i = 0; i < mp.size(); i++){
		std::cout << mp[i] << "\n";
	}

	NAME_SPACE::map<int, int> map_copy(mp.begin(), mp.end());

	std::cout << "---map_copy(map_orig.begin, map_orig.end)\n";
	for(unsigned long i = 0; i < map_copy.size(); i++){
		std::cout << map_copy[i] << "\n";
	}

	NAME_SPACE::map<int, int>::iterator it_copy = map_copy.begin();

	std::cout << "kek_1\n";
	map_copy.erase(it_copy, map_copy.end());
	std::cout << "kek_2\n";

	std::cout << "---map_original after map_copy.erase\n";
	for(unsigned long i = 0; i < mp.size(); i++){
		std::cout << mp[i] << "\n";
	}

	std::cout << "---map_copy after map_copy.erase\n";
	for(unsigned long i = 0; i < map_copy.size(); i++){
		std::cout << map_copy[i] << "\n";
	}
}

void operator_assign_test(){
	NAME_SPACE::map<int, std::string> map_orig, map_assign;

	std::cout << "\n----------operator_assign_MAP--------------\n";

	std::string arr_string[] = {"Kek_begin", "Kek_2", "Kek_3", "Kek_4", "Kek_5", "Kek_end"};

	//fill
	for (int i = 0; i < 6; i++){
		map_orig[i] = arr_string[i];
	}

	std::cout << "---map_orig\n";
	for(unsigned long i = 0; i < map_orig.size(); i++){
		std::cout << map_orig[i] << "\n";
	}

	map_assign = map_orig;

	std::cout << "---map_orig after assign\n";
	for(unsigned long i = 0; i < map_orig.size(); i++){
		std::cout << map_orig[i] << "\n";
	}

	std::cout << "---map_copy after assign\n";
	for(unsigned long i = 0; i < map_assign.size(); i++){
		std::cout << map_assign[i] << "\n";
	}

	map_orig.erase(map_orig.begin(), map_orig.end());

	std::cout << "---map_orig after map_copy.erase\n";
	for(unsigned long i = 0; i < map_orig.size(); i++){
		std::cout << map_orig[i] << "\n";
	}

	std::cout << "---map_copy after map_copy.erase\n";
	for(unsigned long i = 0; i < map_assign.size(); i++){
		std::cout << map_assign[i] << "\n";
	}
}

void iterators_test(){
	std::cout << "\n----------iterators_MAP--------------\n";

	NAME_SPACE::map<int, std::string> map_orig;

	map_orig[2] = "2";
	map_orig[45] = "45";
	map_orig[23] = "23";
	map_orig[13] = "13";
	map_orig[67] = "67";
	map_orig[1] = "1";
	map_orig[14] = "14";
	map_orig[1] = "1_1";

	NAME_SPACE::map<int, std::string>::iterator iter = map_orig.begin();

	std::cout << "iter.begin= " << (iter->second) << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	++iter;
	std::cout << "++iter= " << iter->second << "\n";
	std::cout << "--iter= " << (--iter)->second << "\n";
	std::cout << "--iter= " << (--iter)->second << "\n";
	std::cout << "iter++= " << (iter++)->second << "\n";
	std::cout << "iter= " << (iter)->second << "\n";
	std::cout << "\n-------reverse_iterators_MAP-----------\n";

	NAME_SPACE::map<int, std::string>::reverse_iterator reverse_iter = map_orig.rbegin();

	std::cout << "reverse_iter.rbegin= " << (reverse_iter->second) << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	++reverse_iter;
	std::cout << "++reverse_iter= " << reverse_iter->second << "\n";
	std::cout << "--reverse_iter= " << (--reverse_iter)->second << "\n";
	std::cout << "--reverse_iter= " << (--reverse_iter)->second << "\n";
	std::cout << "reverse_iter++= " << (reverse_iter++)->second << "\n";
	std::cout << "reverse_iter= " << (reverse_iter)->second << "\n";
}


void capacity_test(){
	std::cout << "\n----------capacity_MAP--------------\n";

	NAME_SPACE::map<int, int> my_map;

	std::cout << "my_map.empty before fill= " << my_map.empty() << "\n";

	//fill
	for (int i = 0; i < 45; i++){
		my_map[i] = i * 2;
	}

	std::cout << "my_map.empty after fill= " << my_map.empty() << "\n";
	std::cout << "my_map.size= " << my_map.size() << "\n";
	std::cout << "my_map.max_size= " << my_map.max_size() << "\n";
}

	void access_test(){
	std::cout << "\n----------access_MAP----------------\n";
	NAME_SPACE::map<int, int> my_map;

	my_map[2] = 2;
	my_map[45] = 45;
	my_map[23] = 23;
	my_map[13] = 13;
	my_map[67] = 67;
	my_map[1] = 1;
	my_map[14] = 14;
	my_map[1] = 42;

	try{
		std::cout << "map.at(23): " << my_map.at(23) << "\n";
		std::cout << "map.at(21) non range: " << my_map.at(21) << "\n";
	}
	catch (...){
		throw ;
	}

//
}

void insert_test(){
	std::cout << "\n--------------insert_MAP--------------\n";

	NAME_SPACE::map<char,int> mymap;

	std::cout << "\n-------insert_single(pair)_MAP----------\n";

	mymap.insert ( NAME_SPACE::pair<char,int>('a',100) );
	mymap.insert ( NAME_SPACE::pair<char,int>('z',200) );

	NAME_SPACE::pair<NAME_SPACE::map<char,int>::iterator,bool> ret;

	ret = mymap.insert ( NAME_SPACE::pair<char,int>('z',500) ); //second==false else "z" is existed

	if (ret.second==false) {
		std::cout << "element 'z' est' uzhe\n";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	NAME_SPACE::map<char,int>::iterator it = mymap.begin();

	std::cout << "mymap after insert pair (z, 500):\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n-------insert_position_MAP(it, pair)--------\n";

	mymap.insert (it, NAME_SPACE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, NAME_SPACE::pair<char,int>('c',400));  // no max efficiency inserting
	// showing contents:
	std::cout << "mymap after insert in it.begin - 'b'(300) and 'c'(400):\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n-------insert_range_MAP(it, it)-----------\n";

	NAME_SPACE::map<char,int> anothermap;

	anothermap.insert(mymap.begin(),mymap.find('c'));

	std::cout << "anothermap after insert (mymap.begin, mymap.find('c'):\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void erase_test(){
	NAME_SPACE::map<char,int> mymap;
	NAME_SPACE::map<char,int>::iterator it;

	std::cout << "\n-----------------erase_MAP-----------------\n";
	// insert some values:

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	std::cout << "mymap before erase:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n///--------erase_iterator_MAP----------///\n";



	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << "mymap after erase(iteratpr(find('b')):\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n///--------erase_key_MAP----------///\n";

	mymap.erase ('c');                  // erasing by key

	std::cout << "mymap after erase(key('c'):\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n///--------erase_range_MAP----------///\n";

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	std::cout << "mymap after erase(range(iter(find('e')), end()))):\n";

	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void swap_test_map(){
	std::cout << "\n-----------------swap_MAP-----------------\n";

	NAME_SPACE::map<char,int> map_1,map_2;

	map_1['x']=100;
	map_1['y']=200;

	map_2['a']=11;
	map_2['b']=22;
	map_2['c']=33;

	std::cout << "map_1 before swap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=map_1.begin(); it != map_1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "map_2 before swap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=map_2.begin(); it != map_2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	map_1.swap(map_2);

	std::cout << "map_1 after swap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=map_1.begin(); it != map_1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "map_2 after swap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=map_2.begin(); it != map_2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void clear_test(){
	NAME_SPACE::map<char,int> mymap;
	std::cout << "\n-----------------clear_MAP-----------------\n";

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap before clear:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "mymap.size = " << mymap.size() << "\n";

	mymap.clear();

	std::cout << "mymap after clear:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "mymap.size = " << mymap.size() << "\n";

}

void compare_test(){
	std::cout << "\n-----------------key_compare_MAP-----------------\n";

	NAME_SPACE::map<char,int> mymap;

	NAME_SPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap for key_compare:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	NAME_SPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << "\n-----------------value_compare_MAP-----------------\n";

	NAME_SPACE::map<char,int> mymap_2;

	mymap_2['x']=1001;
	mymap_2['y']=2002;
	mymap_2['z']=3003;

	std::cout << "mymap for value_compare:\n";

	NAME_SPACE::pair<char,int> highest_value = *mymap_2.rbegin();          // last element

	NAME_SPACE::map<char,int>::iterator it_val = mymap_2.begin();
	do {
		std::cout << it_val->first << " => " << it_val->second << '\n';
	} while ( mymap_2.value_comp()(*it_val++, highest_value) );
}

void operations_test(){

	std::cout << "\n-----------------find_MAP-----------------\n";

	NAME_SPACE::map<char,int> mymap;
	NAME_SPACE::map<char,int>::iterator iter;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	std::cout << "mymap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "find('a') => " << mymap.find('a')->second << '\n';

	std::cout << "\nmymap if iter != end - erase(iter):\n";

	iter = mymap.find('b');
	if (iter != mymap.end())
		mymap.erase (iter);

	std::cout << "mymap before find and erase:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n-----------------count_MAP-----------------\n";

	std::cout << "count('c'): " << mymap.count('c') << "\n";
	std::cout << "count('u'): " << mymap.count('u') << "\n";

}

void lower_upper_bound_test(){

	std::cout << "\n-----------------find_MAP-----------------\n";

	NAME_SPACE::map<char, int> mymap;
	NAME_SPACE::map<char,int>::iterator itlow,itup;

	mymap['1']=1;
	mymap['3']=3;
	mymap['2']=2;
	mymap['5']=5;
	mymap['8']=8;
	mymap['4']=4;
	mymap['7']=7;
	mymap['9']=9;
	mymap['6']=6;

	std::cout << "mymap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "iter_low = lower_bound(3):\n";
	itlow=mymap.lower_bound ('3');  // itlow points to b
	std::cout << "iter_up = upper_bound(7):\n";
	itup=mymap.upper_bound ('7');   // itup points to e (not 7!)

	mymap.erase(itlow,itup);
	std::cout << "mymap after erase(it_low, it_up):\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void equal_range_test(){
	std::cout << "\n-----------------equal_range_MAP-----------------\n";

	NAME_SPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['f']=35;
	mymap['e']=40;
	mymap['r']=45;
	mymap['d']=55;

	std::cout << "mymap:\n";
	for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	NAME_SPACE::pair<NAME_SPACE::map<char,int>::iterator,NAME_SPACE::map<char,int>::iterator> ret;

	ret = mymap.equal_range('b');

	std::cout << "equal_range(b).first: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "equal_range(b).second: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

	void test_map(){
		std::cout << "**//------------------MAP------------------//**" << std::endl;
	NAME_SPACE::map<int, int> my_map;
	NAME_SPACE::map<int, int>::iterator it;
//	it->first = 1;

	copy_constructor_test(my_map);
	operator_assign_test();
	iterators_test();
	capacity_test();
	try{
		access_test();
	}
	catch( std::exception ex){
		std::cerr << ex.what();
	}
	insert_test();
	erase_test();
		swap_test_map();
	clear_test();
	compare_test();
	operations_test();
	lower_upper_bound_test();
	equal_range_test();
	operators_comparisons_test();
	}

	/*
	 * constructs+
	 * assign+
	 * iterators+
	 * capacity+
	 * access+
	 * 		#[]
	 * 		#at
	 * modifers
	 * 		#insert single, hint, range +
	 * 		#erase iter, key, range +
	 * 		#swap+
	 * 		#clear+
	 * observers
	 * 		#key_comp+
	 * 		#value_comp+
	 * operations
	 * 		#find+
	 * 		#count+
	 * 		#lowerbound+
	 * 		#upperbound+
	 * 		#equal_range+
	 */