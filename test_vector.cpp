#include "test.hpp"

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

void swap_test_vector() {
	std::cout << "\n----------swap_VECTOR--------------\n";

	NAME_SPACE::vector<int> res;
	NAME_SPACE::vector<int> myvect;
//	std::cout << "\n tmp, size= " << tmp.size() << ",cap=" << tmp.capacity() << "\n";

	NAME_SPACE::vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
	myvect.assign(11000000, 11);

	res.push_back(myvect[2]);
	res.push_back(myvect.size());
	res.push_back(myvect.capacity());
	long *adr1 = reinterpret_cast<long *>(&myvect);
	long *adr2 = reinterpret_cast<long *>(&tmp);

	std::cout << "\n myvector, size= " << myvect.size() << ", capacity=" << myvect.capacity() << "\n";
	std::cout << "\n tmp, size= " << tmp.size() << ",capacity=" << tmp.capacity() << "\n";
	myvect.swap(tmp);
	std::cout << "\n myvector after myvector.swap(tmp), size= " << myvect.size() << ",capacity=" << myvect.capacity() << "\n";

	if (reinterpret_cast<long *>(&myvect) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		res.push_back(1);

	res.push_back(myvect[2]);
	res.push_back(myvect.size());
	res.push_back(myvect.capacity());

	std::cout << "\n tmp3, size= " << tmp3.size() << ",capacity=" << tmp3.capacity() << "\n";
	myvect.swap(tmp3);
	std::cout << "\n myvector after myvector.swap(tmp3), size= " << myvect.size() << ",capacity=" << myvect.capacity() << "\n";
	std::cout << "\n tmp3 after myvector.swap(tmp3) size= " << tmp3.size() << ",capacity=" << tmp3.capacity() << "\n";

	res.push_back(myvect[2]);
	res.push_back(myvect.size());
	res.push_back(myvect.capacity());

//	swap(myvect, tmp3);
//
//	std::cout << "\n myvector after myvector.swap(tmp3), size= " << myvect.size() << ",capacity=" << myvect.capacity() << "\n";
//	std::cout << "\n tmp3 after myvector.swap(tmp3), size= " << tmp3.size() << ",capacity=" << tmp3.capacity() << "\n";
//
//	res.push_back(myvect[2]);
//	res.push_back(myvect.size());
//	res.push_back(myvect.capacity());
//
//	std::cout << "\n tmp4, size= " << tmp4.size() << ",cap=" << tmp4.capacity() << "\n";
//
//	swap(myvect, tmp4);
//	std::cout << "\n myvector after myvector.swap(tmp4), size= " << myvect.size() << ",cap=" << myvect.capacity() << "\n";
//	std::cout << "\n tmp4 after myvector.swap(tmp4), size= " << tmp4.size() << ",cap=" << tmp4.capacity() << "\n";
//
//	res.push_back(myvect[2]);
//	res.push_back(myvect.size());
//	res.push_back(myvect.capacity());

	std::cout << "vect_res\n";
	for (unsigned long i = 0; i < res.size(); i++) {
		std::cout << res[i] << "\n";
	}



//
//	std::vector<int> v, std;
//	ft_vector.assign(11000000, 11);
////	ft::vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
//	v.push_back(ft_vector[2]);
//	v.push_back(ft_vector.size());
//	v.push_back(ft_vector.capacity());

//	long *adr1 = reinterpret_cast<long *>(&ft_vector);
//	long *adr2 = reinterpret_cast<long *>(&tmp);
//	std::cout << "\n vector, size= " << ft_vector.size() << ",cap=" << ft_vector.capacity() << "\n";
//	std::cout << "\n tmp, size= " << tmp.size() << ",cap=" << tmp.capacity() << "\n";
//	ft_vector.swap(tmp);
//	std::cout << "\n vector/tmp, size= " << ft_vector.size() << ",cap=" << ft_vector.capacity() << "\n";
//
//	if (reinterpret_cast<long *>(&ft_vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
//		v.push_back(1);
//
//	v.push_back(ft_vector[2]);
//	v.push_back(ft_vector.size());
//	v.push_back(ft_vector.capacity());
//	std::cout << "\n tmp3, size= " << tmp3.size() << ",cap=" << tmp3.capacity() << "\n";
//	ft_vector.swap(tmp3);
//	std::cout << "\n vector/tmp3, size= " << ft_vector.size() << ",cap=" << ft_vector.capacity() << "\n";
//	std::cout << "\n tmp3, size= " << tmp3.size() << ",cap=" << tmp3.capacity() << "\n";

////
//	v.push_back(ft_vector[2]);
//	v.push_back(ft_vector.size());
//	v.push_back(ft_vector.capacity());
//	std::cout << "\n tmp2, size= " << tmp2.size() << ",cap=" << tmp2.capacity() << "\n";
//
//	std::swap(ft_vector, tmp2);
//	std::cout << "\n vector/tmp2, size= " << ft_vector.size() << ",cap=" << ft_vector.capacity() << "\n";
//	std::cout << "\n tmp22, size= " << tmp2.size() << ",cap=" << tmp2.capacity() << "\n";
//	v.push_back(ft_vector[2]);
//	v.push_back(ft_vector.size());
//	v.push_back(ft_vector.capacity());
//	std::cout << "\n tmp4, size= " << tmp4.size() << ",cap=" << tmp4.capacity() << "\n";
//
//	std::swap(ft_vector, tmp4);
//	std::cout << "\n vector/tmp4, size= " << ft_vector.size() << ",cap=" << ft_vector.capacity() << "\n";
//
//	v.push_back(ft_vector[2]);
//	v.push_back(ft_vector.size());
//	v.push_back(ft_vector.capacity());
//	std::cout << "ft aft(swap) \n";
//	for (unsigned long i = 0; i < v.size(); i++) {
//		std::cout << v[i] << "\n";
//	}

//	std::vector<int> std_vector;
//	std_vector.assign(11000000, 11);
//	std::vector<int> tmp_std(5000000, 5), tmp2_std(10000000, 10), tmp3_std(15000000, 15), tmp4_std(30000000, 30);
//	std.push_back(std_vector[2]);
//	std.push_back(std_vector.size());
//	std.push_back(std_vector.capacity());
//	long *adr1_std = reinterpret_cast<long *>(&ft_vector);
//	long *adr2_std = reinterpret_cast<long *>(&tmp_std);
//	std::cout << "\n vector, size= " << std_vector.size() << ",cap=" << std_vector.capacity() << "\n";
//
//	std_vector.swap(tmp_std);
//	if (reinterpret_cast<long *>(&std) == adr1_std && reinterpret_cast<long *>(&tmp_std) == adr2_std)
//		std.push_back(1);
//	std.push_back(std_vector[2]);
//	std.push_back(std_vector.size());
//	std.push_back(std_vector.capacity());
//	std_vector.swap(tmp3_std);
//	std.push_back(std_vector[2]);
//	std.push_back(std_vector.size());
//	std.push_back(std_vector.capacity());
//	std::swap(std_vector, tmp2_std);
//	std.push_back(std_vector[2]);
//	std.push_back(std_vector.size());
//	std.push_back(std_vector.capacity());
//	std::swap(std_vector, tmp4_std);
//	std.push_back(std_vector[2]);
//	std.push_back(std_vector.size());
//	std.push_back(std_vector.capacity());
//
//	std::cout << "std aft(swap) \n";
//	for (unsigned long i = 0; i < std.size(); i++) {
//		std::cout << std[i] << "\n";
//	}
//	return v;
}

template <typename T>
std::vector<int> insert_test_single(ft::vector<T> vector) {
	std::vector<int> v;
	vector.assign(260000, 1);
	v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::unique_ptr<B> k2(new B(3));
	std::unique_ptr<B> k3(new B(4));
	std::unique_ptr<B> k4(new B(-1));
	ft::vector<A> vv;
	ft::vector<B*> v1;

	std::vector<A> std_vv;
	std::vector<B*> std_v1;

	v1.push_back(&(*k2));
	v1.push_back(&(*k3));
	v1.push_back(&(*k4));
	std::cout << "bef ft" << "\n";
	for (unsigned long i = 0; i < v.size(); i++){
		std::cout << v[i] << "\n";
	}
	try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
	catch (...) {
		v.push_back(vv.size());
		v.push_back(vv.capacity());
		std::cout << "kek ft" << "\n";
	}
	std::cout << "aft ft" << "\n";
	for (unsigned long i = 0; i < v.size(); i++){
		std::cout << v[i] << "\n";
	}

	std_v1.push_back(&(*k2));
	std_v1.push_back(&(*k3));
	std_v1.push_back(&(*k4));

	std::cout << "bef std" << "\n";
	for (unsigned long i = 0; i < std_v1.size(); i++){
		std::cout << std_v1[i] << "\n";
	}
	try { std_vv.insert(std_vv.begin(), std_v1.begin(), std_v1.end()); }
	catch (...) {
		v.push_back(std_vv.size());
		v.push_back(std_vv.capacity());
		std::cout << "kek std" << "\n";
	}
	return v;
}


void insert_test_single(){
	ft::vector<int> ft_v, ft_v_tmp, vector;
	ft::vector<int>::iterator ft_it;
	std::vector<int> std_v, std_v_tmp;


//	for (int i = 0; i < 8; i++)
//		ft_v.push_back(i);
//	for (int i = 0; i < 8; i++)
//		ft_v_tmp.push_back(i+10);
//
//
//
//	std::cout << "ret ft:" << *ft_v.insert((ft_v.end() - 2), 42) << "\n";
//	ft_v.insert(ft_v.end(), ft_v_tmp.begin(), ft_v_tmp.end());
//
//	for (unsigned long i = 0; i < ft_v.size(); i++)
//		std::cout << ft_v[i] << '\n';
//
//	std::cout << "STD" << '\n';
//	for (unsigned long i = 0; i < 8; i++)
//		std_v.push_back(i);
//	for (unsigned long i = 0; i < 8; i++)
//		std_v_tmp.push_back(i+10);
//
//	std::cout << "ret std:" << *std_v.insert((std_v.end() - 2), 42) << "\n";
//	for (unsigned long i = 0; i < std_v.size(); i++)
//		std::cout << std_v[i] << '\n';

	std::vector<int> v;
	vector.assign(26000000, 1);
	v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::unique_ptr<B> k2(new B(3));
	std::unique_ptr<B> k3(new B(4));
	std::unique_ptr<B> k4(new B(-1));
	ft::vector<A> vv;
	ft::vector<B*> v1;
	v1.push_back(&(*k2));
	v1.push_back(&(*k3));
	v1.push_back(&(*k4));
	try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
	catch (...) {
		v.push_back(vv.size());
		v.push_back(vv.capacity());
	}
	std::cout << "\n" << "bef v ft:" << "\n";
	for (unsigned long i = 0; i < v.size(); i++) {
		std::cout << v[i] << "\n";
	}
}


template <typename T>
std::vector<int> insert_fill(ft::vector<T> vector) {

	////MY_TEST
//	std::vector<int> std_v, std_tmp;
//	ft::vector<int> tmp;
//	vector.rend();
//	for (int i = 0; i < 4; i++)
//		tmp.push_back(i);
////	for (int i = 0; i < tmp.size(); i++)
////		std::cout << tmp[i] << '\n';
////	std::cout << *(tmp.end() - 1) << '\n';
//	tmp.insert(tmp.end() - 2, 4, 21);
//	for (unsigned long i = 0; i < tmp.size(); i++)
//		std::cout << tmp[i] << '\n';
//
//	std::cout << "STD" << '\n';
//	for (unsigned long i = 0; i < 4; i++)
//		std_tmp.push_back(i);
//	std_tmp.insert(std_tmp.end() - 2, 4, 21);
//	for (unsigned long i = 0; i < std_tmp.size(); i++)
//		std::cout << std_tmp[i] << '\n';


	////TEST_TEST
	vector.size();
	std::vector<int> v, std_tmp;
	ft::vector<int> tmp, vect_ft_copy;
	tmp.assign(260000, 21);
//	for (unsigned long i = 0; i < 12; i++)
//		tmp.push_back(i);
	vect_ft_copy.assign(220000, 42);
//	for (unsigned long i = 0; i < 10; i++)
//		vect_ft_copy.push_back(i+20);
	vect_ft_copy.insert(vect_ft_copy.end() - 140000, tmp.begin(), tmp.end());
	v.push_back(vect_ft_copy[3]);
	v.push_back(vect_ft_copy.size());
	v.push_back(vect_ft_copy.capacity());
//	std::cout << "\n" << " aft v ft:" << "\n";
	for (unsigned long i = 0; i < vect_ft_copy.size(); i++) {
		std::cout << vect_ft_copy[i] << "\n";
	}

	//std
	std_tmp.assign(26000000, 21);

//	for (unsigned long i = 0; i < 12; i++)
//		std_tmp.push_back(i);

	v.assign(22000000, 42);

//	for (unsigned long i = 0; i < 10; i++)
//		v.push_back(i+20);
	v.insert(v.end() - 14000000, std_tmp.begin(), std_tmp.end());
//	std::cout << "\n" << " aft v std:" << "\n";
//	for (unsigned long i = 0; i < vect_ft_copy.size(); i++) {
//		std::cout << vect_ft_copy[i] << "\n";
//	}

	return v;
}

void insert_test_range(){
	std::vector<int> v;
	ft::vector<int> tmp, vector;
	tmp.assign(26000000, 1);
	vector.assign(22000000, 1);
	vector.insert(vector.end() - 14000000, tmp.begin(), tmp.end());
	v.push_back(vector[3]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::cout << "\n" << "bef v ft:" << "\n";
	for (unsigned long i = 0; i < v.size(); i++) {
		std::cout << v[i] << "\n";
	}
}

void testVector_old()
{
	ft::vector<int> vect;
	ft::vector<int> vect_2;

	std::vector<int> std_vect;
	ft::vector<int>::reverse_iterator r_it;
	std::vector<int>::reverse_iterator stl_r_it;

//	constructor_test(vect);

	std::vector<int> v;
	for (int i = 0; i < 8; ++i)
		vect.push_back(i);
	for (int i = 0; i < 8; ++i)
		vect_2.push_back(i);
//	std::cout << (vect > vect_2);
	for (int i = 0; i < 8; ++i)
		std_vect.push_back(i);

// TEST ERASE
	ft::vector<int>::iterator ft_it_1, ft_it_2;
	std::vector<int>::iterator std_it_1, std_it_2;
	ft_it_1 = vect.begin() + 2;
	ft_it_2 = vect.end() - 2;
	std_it_1 = std_vect.begin() + 2;
	std_it_2 = std_vect.end() - 2;

//	std::cout << "vect.er " << *(vect.erase(ft_it_1, ft_it_2)) << '\n';
//	std::cout << "std_vect_er " << *(std_vect.erase(std_it_1, std_it_2)) << '\n';
	vect.erase(vect.begin() + 3);

	for (unsigned long i = 0; i < vect.size(); i++)
		std::cout << vect[i] << '\n';
	std::cout << '\n';
	for (unsigned long i = 0; i < std_vect.size(); i++)
		std::cout << std_vect[i] << '\n';

//	insert_fill(vect);
//	insert_test_single();
//	insert_test_range();
//	insert_test_1(vect);
//	swap_test_vector(vect);

//	it = vect.begin();
//
//	v.push_back(*(++it));
//	v.push_back(*(--it));
//	vect.push_back(*(it + 1));
//
//	v.push_back(*(it + 1));
//	it += 1;
//	v.push_back(*(it - 1));
//	it -= 1;
//	v.push_back(*it);

	r_it = vect.rend();
	stl_r_it = std_vect.rend();
//	std::cout << *r_it;
//	std::cout << *stl_r_it;

///////

//	ft::vector<char> *test_default = new ft::vector<char>();
//	ft::vector<int> *testVector = new ft::vector<int>(10);
//	ft::vector<int> *testVector_assign = new ft::vector<int>(14);
//	std::vector<int> *stlVector = new std::vector<int>(10);
//	std::vector<int> *stlVector = new std::vector<int>(10);
	//COPY
//		ft::vector<char>::iterator it = test_default->end();
//	testVector->swap(testVector_assign);
//    std::cout << it << std::endl;

/*////TEST
	std::cout << "-----FT::VECTOR.SIZE before ASSIGN = " << testVector_assign->size() << std::endl;
	std::cout << "-----FT::VECTOR.CAPACITY before ASSIGN = " << testVector_assign->capacity() << std::endl;
	testVector_assign = testVector;
	std::cout << "-----FT::VECTOR.SIZE after ASSIGN = " << testVector_assign->size() << std::endl;
	std::cout << "-----FT::VECTOR.CAPACITY after ASSIGN = " << testVector_assign->capacity() << std::endl;
	//ASSIGN

	std::cout << "-----FT::VECTOR.SIZE  = " << testVector->size() << std::endl;
	std::cout << "-----FT::VECTOR.PUSH_BACK(123/1/23/0)" << std::endl;
	testVector->push_back(123);
	testVector->push_back(1);
	testVector->push_back(23);
	testVector->push_back(0);
	std::cout << "-----FT::VECTOR.SIZE  = " << testVector->size() << std::endl;
	std::cout << "-----FT::VECTOR.RESIZE(2)" << std::endl;
	testVector->resize(2);
	std::cout << "-----FT::VECTOR.SIZE  = " << testVector->size() << std::endl;
	std::cout << "-----FT::VECTOR.CAPACITY  = " << testVector->capacity() << std::endl;
	//CLEAR
	testVector->clear();
	std::cout << "-----FT::VECTOR.SIZE  = " << testVector->size() << std::endl;
	//CAPACITY
	std::cout << "-----FT::VECTOR.CAPACITY  = " << testVector->capacity() << std::endl;

	//RESERVE
	//POP_BACK
	//[]/const[]
	//at

	//SWAP

	std::cout << "-----FT::VECTOR.MAX_SIZE  = " << testVector->max_size() << std::endl;
	std::cout << "-----STL::VECTOR.MAX_SIZE  = " << stlVector->max_size() << std::endl;
*/


}

void test_constructors(){
	std::cout << "\n----------constructor(default)_VECTOR--------------\n";
	NAME_SPACE::vector<int> vect_def;
	std::cout << "vector_default.size = " << vect_def.size() << "\n";
	std::cout << "vector_default.capacity = " << vect_def.capacity() << "\n";
	std::cout << "\n----------constructor(fill)_VECTOR--------------\n";
	NAME_SPACE::vector<int> vect_fill(5, 21);
	std::cout << "vector_fill\n";
	for (unsigned long i = 0; i < vect_fill.size(); i++){
		std::cout << vect_fill[i] << "\n";
	}
	std::cout << "vector_fill.size = " << vect_fill.size() << "\n";
	std::cout << "vector_fill.capacity = " << vect_fill.capacity() << "\n";
	std::cout << "\n----------constructor(range)_VECTOR--------------\n";
	NAME_SPACE::vector<int> vect_range(vect_fill.begin(), vect_fill.end());
	std::cout << "vector_range(vector_fill.begin(), vector_fill.end())\n";
	std::cout << "vect_fill\n";
	for (unsigned long i = 0; i < vect_fill.size(); i++){
		std::cout << vect_fill[i] << "\n";
	}
	std::cout << "vector_fill.size = " << vect_fill.size() << "\n";
	std::cout << "vector_fill.capacity = " << vect_fill.capacity() << "\n";

	std::cout << "\n----------constructor(copy)_VECTOR--------------\n";
	std::cout << "vector_range.push_back(42) x 5\n";
	for (int i = 0; i < 5; i++){
		vect_range.push_back(42);
	}
	NAME_SPACE::vector<int> vect_copy(vect_range);
	std::cout << "vector_copy\n";
	for (unsigned long i = 0; i < vect_copy.size(); i++){
		std::cout << vect_copy[i] << "\n";
	}
}

void test_operator_assign(){
	std::cout << "\n----------operator_assign_VECTOR--------------\n";

	NAME_SPACE::vector<int> foo (3,21);
	NAME_SPACE::vector<int> bar (5,42);

	std::cout << "\nvector_foo\n";
	for (unsigned long i = 0; i < foo.size(); i++){
		std::cout << foo[i] << "\n";
	}

	std::cout << "\nvector_bar\n";
	for (unsigned long i = 0; i < bar.size(); i++){
		std::cout << bar[i] << "\n";
	}

	std::cout << "\nbar = foo\n";
	bar = foo;

	std::cout << "\nvector_foo\n";
	for (unsigned long i = 0; i < foo.size(); i++){
		std::cout << foo[i] << "\n";
	}

	std::cout << "\nvector_bar\n";
	for (unsigned long i = 0; i < bar.size(); i++){
		std::cout << bar[i] << "\n";
	}

	std::cout << "\nfoo = vector(default)\n\n";
	foo = NAME_SPACE::vector<int>();

	std::cout << "vector_foo.size: " << int(foo.size()) << '\n';
	std::cout << "vector_bar.size: " << int(bar.size()) << '\n';
}

void test_vector_iterators(){
	std::cout << "\n----------iterator_VECTOR--------------\n";

	NAME_SPACE::vector<int> myvector;

	for (int i = 0; i < 10; i++){
		myvector.push_back(i);
	}

	NAME_SPACE::vector<int>::iterator iter = myvector.begin();
	std::cout << "iter.begin= " << *iter << "\n";
	std::cout << "++iter= " << *(++iter) << "\n";
	std::cout << "++iter= " << *(++iter) << "\n";
	std::cout << "++iter= " << *(++iter) << "\n";
	std::cout << "--iter= " << *(--iter) << "\n";
	std::cout << "--iter= " << *(--iter) << "\n";
	std::cout << "iter++= " << *(iter++) << "\n";
	std::cout << "iter= " << *(iter) << "\n";

	std::cout << "\n----------reverse_iterator_VECTOR--------------\n";

	NAME_SPACE::vector<int>::reverse_iterator reverse_iter = myvector.rbegin();
	std::cout << "reverse_iter.rbegin= " << *reverse_iter << "\n";

	NAME_SPACE::vector<int>::const_reverse_iterator const_reverse_iter = myvector.rbegin();

	std::cout << "const_reverse_iter.rbegin= " << *const_reverse_iter << "\n";
	std::cout << "++const_reverse_iter= " << *(++const_reverse_iter) << "\n";
	std::cout << "++const_reverse_iter= " << *(++const_reverse_iter) << "\n";
	std::cout << "++const_reverse_iter= " << *(++const_reverse_iter) << "\n";
	std::cout << "--const_reverse_iter= " << *(--const_reverse_iter) << "\n";
	std::cout << "--const_reverse_iter= " << *(--const_reverse_iter) << "\n";
	std::cout << "const_reverse_iter++= " << *(const_reverse_iter++) << "\n";
	std::cout << "const_reverse_iter= " << *(const_reverse_iter) << "\n";

}

void test_vector_capacity(){
	NAME_SPACE::vector<int> myvector (8,21);
	std::cout << "\n----------capacity_VECTOR--------------\n";
	std::cout << "myvector.size before = " << myvector.size() << "\n";
	std::cout << "myvector.capacity before = " << myvector.capacity() << "\n";
	myvector.pop_back();
	myvector.pop_back();
	myvector.pop_back();
	std::cout << "myvector.size after pop_back x 3 = " << myvector.size() << "\n";
	std::cout << "myvector.capacity after pop_back x 3 = " << myvector.capacity() << "\n";
	std::cout << "myvector.max_size = " << myvector.max_size() << "\n";
	std::cout << "myvector.resize(20)\n";
	myvector.resize(20);
	std::cout << "myvector.size after resize(20) = " << myvector.size() << "\n";
	std::cout << "myvector.capacity after resize(20) = " << myvector.capacity() << "\n";
	std::cout << "myvector.empty = " << myvector.empty() << "\n";
	myvector.clear();
	std::cout << "myvector.empty after clear = " << myvector.empty() << "\n";
	std::cout << "myvector.size after clear = " << myvector.size() << "\n";
	std::cout << "myvector.capacity after clear = " << myvector.capacity() << "\n";
	myvector.reserve(42);
	std::cout << "myvector.capacity after reserve(42) = " << myvector.capacity() << "\n";
}

void test_vector_access(){
	std::cout << "\n----------access_VECTOR--------------\n";

	NAME_SPACE::vector<int> myvector;
	for (int i = 0; i < 12; i++){
		myvector.push_back(i);
	}
	std::cout << "myvector\n";
	for (unsigned long i = 0; i < myvector.size(); i++){
		std::cout << myvector[i] << "\n";
	}
	std::cout << "myvector[4] = " << myvector[4] << "\n";
	std::cout << "myvector[5 - 3] = " << myvector[5 - 3] << "\n";
	std::cout << "myvector.at(6) = " << myvector.at(6) << "\n";
	try{
		std::cout << "myvector.at(21) = " << myvector.at(21) << "\n";
	}
	catch (...){
		throw ;
	}
	std::cout << "myvector.front() -= myvector.back()\n";
	myvector.front() -= myvector.back();
	std::cout << "myvector.front() = " << myvector.front() << "\n" ;
}

void test_vector_front_back(){

	NAME_SPACE::vector<int> myvector;
	for (int i = 0; i < 12; i++){
		myvector.push_back(i);
	}

	std::cout << "\nmyvector.front() = " << myvector.front() << "\n" ;
	std::cout << "\nmyvector.back() = " << myvector.back() << "\n" ;

	std::cout << "myvector.front() -= myvector.back()\n";
	myvector.front() -= myvector.back();

//	NAME_SPACE::vector<int> vector_ub;
//	std::cout << "vector_ub.front() = " << vector_ub.front() << "\n" ; //UB
}

void test_vector_assign(){
	std::cout << "\n----------assign_VECTOR--------------\n";

	NAME_SPACE::vector<int> vect_fill;
	NAME_SPACE::vector<int> vect_range;
	NAME_SPACE::vector<int> vect_arr;

	vect_fill.assign (7,42);             // 7 ints with a value of 100
	std::cout << "vect_fill.assign(7,42)\n";
	for (unsigned long i = 0; i < vect_fill.size(); i++){
		std::cout << vect_fill[i] << "\n";
	}

	NAME_SPACE::vector<int>::iterator it;
	it=vect_fill.begin()+1;

	vect_range.assign (it,vect_fill.end()-1); // the 5 central values of first
	std::cout << "vect_range.assign(it(v_fill.begin, fill.end()-1)\n";
	for (unsigned long i = 0; i < vect_range.size(); i++){
		std::cout << vect_range[i] << "\n";
	}

	int myints[] = {17,7,4};
	vect_arr.assign (myints,myints+3);   // assigning from array.

	std::cout << "vect_range.assign(arr[17,7,4], arr + 3)\n";
	for (unsigned long i = 0; i < vect_arr.size(); i++){
		std::cout << vect_arr[i] << "\n";
	}

	std::cout << "vect_fill.size: " << int (vect_fill.size()) << '\n';
	std::cout << "vect_range.size: " << int (vect_range.size()) << '\n';
	std::cout << "vect_arr.size: " << int (vect_arr.size()) << '\n';
}

void test_vector_push_back(){

	std::cout << "\n----------push_back_VECTOR--------------\n";
	NAME_SPACE::vector<int> myvect;
	std::cout << "myvect.push_back(21)\n";
	myvect.push_back(21);
	std::cout << "myvect.push_back(42)\n";
	myvect.push_back(42);
	for (unsigned long i = 0; i < myvect.size(); i++){
		std::cout << myvect[i] << "\n";
	}
	std::cout << "\n----------pop_back_VECTOR--------------\n";

	std::cout << "myvect.pop_back()\n";
	myvect.pop_back();
	for (unsigned long i = 0; i < myvect.size(); i++){
		std::cout << myvect[i] << "\n";
	}
	std::cout << "myvect.size = " << myvect.size() << "\n";
}

void test_insert_vector(){
	std::cout << "\n----------insert_VECTOR--------------\n";

	NAME_SPACE::vector<int> myvector;
	NAME_SPACE::vector<int>::iterator it;

	for (int i = 0; i < 10; i++){
		myvector.push_back(i);
	}

	std::cout << "myvector: ";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	it = myvector.begin();

	it = myvector.insert ( it , 200 ); //ok

	std::cout << "it = " << *it << "\n";

	std::cout << myvector.size() << "\n";
	myvector.insert (it + 2,2,300); //fill, ok

	std::cout << "myvector after insert(fill)(it + 2, 2, 300):";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	NAME_SPACE::vector<int> vect_2 (2, 400);
	myvector.insert (it + 2, vect_2.begin(), vect_2.end()); //range, ok

	std::cout << "vect_2:";
	for (it = vect_2.begin(); it < vect_2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "myvector after insert(range)(vect_1.it(begin) + 2, vect_2.begin, vect_2.end):";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	int myarray [] = { 501,502,503 };

	std::cout << "my_arr:";
	for (int i = 0; i < 3; i++)
		std::cout << ' ' << myarray[i];
	std::cout << '\n';

	myvector.insert (myvector.begin(), myarray, myarray + 3);

	std::cout << "myvector after insert(range)(begin, my_arr, my_arr + 3):";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_erase_vector(){
	std::cout << "\n----------erase_VECTOR--------------\n";

	NAME_SPACE::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=0; i<=10; i++) myvector.push_back(i);

	std::cout << "myvector:";
	for (unsigned i = 0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	std::cout << "myvector after erase(pos)(begin + 5):";
	for (unsigned i = 0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector after erase(range)(begin, begin + 3):";
	for (unsigned i = 0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void test_clear_vector(){
	std::cout << "\n----------clear_VECTOR--------------\n";

	NAME_SPACE::vector<int> myvector;

	for (int i = 0; i < 10; i++){
		myvector.push_back(i);
	}

	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "\nmyvector.clear()\n";
	myvector.clear();

	std::cout << "myvector:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "myvector.size: " << myvector.size() << ", myvector.capacity: " << myvector.capacity() << "\n";

	std::cout << "\nmyvector fill\n";

	myvector.push_back (1101);
	myvector.push_back (2202);


	std::cout << "myvector:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "myvector.size: " << myvector.size() << ", myvector.capacity: " << myvector.capacity() << "\n";
}

void test_vector(){
	std::cout << "**//------------------VECTOR------------------//**" << std::endl;
	test_constructors();
	test_operator_assign();
	test_vector_iterators();
	test_vector_capacity();
	try{
		test_vector_access();
	}
	catch (std::exception ex){
		std::cerr << ex.what();
	}
	test_vector_front_back();
	test_vector_assign();
	test_vector_push_back();
	test_insert_vector();
	test_erase_vector();
	swap_test_vector();
	test_clear_vector();
}


/*
 * constructor+
 * operator=+
 * iterators+
 * 		#begin, end
 * 		#rbegin, rend
 * capacity+
 * 		#size
 * 		#max_size
 * 		#resize
 * 		#capacity
 * 		#empty
 * 		#reserve
 * access+
 * 		#operator[]
 * 		#at
 * 		#front
 * 		#back
 * modifiers
 * 		#assign range, fill
 * 		#push_back
 * 		#pop_back
 * 		#insert single, fill, range +
 * 		#erase+
 * 		#swap+
 * 		#clear +
 */
