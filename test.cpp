#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include "map"
	#include "stack"
	#include "vector"
	#include "set"
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	/******************** VECTOR ********************/

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	std::cout << "\n\n\t\tVECTOR\n" << std::endl;
	ft::vector<int>::iterator t1;

	ft::vector<int> v1(5,100);
	std::cout << "size : " << v1.size() << std::endl;
	std::cout << "max_size : " << v1.max_size() << std::endl;
	for(t1 = v1.begin(); t1 != v1.end(); ++t1)
		std::cout << "v1: " << *t1 << std::endl;

	std::cout << "\n\n\tCOPY CONSTRUCTOR\n" << std::endl;
	ft::vector<int> v2(v1);
	std::cout << "size : " << v2.size() << std::endl;
	std::cout << "max_size : " << v2.max_size() << std::endl;
	for(t1 = v2.begin(); t1 != v2.end(); ++t1)
		std::cout << "v2: " << *t1 << std::endl;

	std::cout << "\n\n\tASSIGN\n" << std::endl;
	v1.assign(20, 20);
	std::cout << "size : " << v1.size() << std::endl;
	std::cout << "max_size : " << v1.max_size() << std::endl;
	for(t1 = v1.begin(); t1 != v1.end(); ++t1)
		std::cout << "v1: " << *t1 << std::endl;

	std::cout << "\n\n\tERASE\n" << std::endl;
	v2.erase(v2.begin());
	std::cout << "size : " << v2.size() << std::endl;
	std::cout << "max_size : " << v2.max_size() << std::endl;
	for(t1 = v2.begin(); t1 != v2.end(); ++t1)
		std::cout << "v2: " << *t1 << std::endl;
	v2.erase(++(v2.begin()), ++(++(v2.begin())));
	std::cout << "size : " << v2.size() << std::endl;
	std::cout << "max_size : " << v2.max_size() << std::endl;
	for(t1 = v2.begin(); t1 != v2.end(); ++t1)
		std::cout << "v2: " << *t1 << std::endl;
	
	std::cout << "\n\n\tOPERATORS\n" << std::endl;
	std::cout << "v2 at(5) = " << v2.at(2) << std::endl;
	std::cout << "v2 [9] = " << v2[9] << std::endl;
	std::cout << "v2 front = " << v2.front() << std::endl;
	std::cout << "v2 back = " << v2.back() << std::endl;
	
	std::cout << "\n\n\tSWAP\n" << std::endl;
	v1.swap(v2);
	std::cout << "size : " << v1.size() << std::endl;
	std::cout << "max_size : " << v1.max_size() << std::endl;
	for(t1 = v1.begin(); t1 != v1.end(); ++t1)
		std::cout << "v1: " << *t1 << std::endl;
	std::cout << "\n\n";
	std::cout << "size : " << v2.size() << std::endl;
	std::cout << "max_size : " << v2.max_size() << std::endl;
	for(t1 = v2.begin(); t1 != v2.end(); ++t1)
		std::cout << "v2: " << *t1 << std::endl;

	std::cout << std::endl;

	/******************** MAP ********************/
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}

	std::cout << std::endl;

	std::cout << "\n\n\t\tMAP\n" << std::endl;

	ft::map<int, std::string> map1;
	map1.insert(ft::pair<int, std::string>(1, "a"));
	map1.insert(ft::pair<int, std::string>(2, "b"));
	map1.insert(ft::pair<int, std::string>(3, "c"));
	map1.insert(ft::pair<int, std::string>(4, "d"));
	map1.insert(ft::pair<int, std::string>(5, "e"));
	map1.insert(ft::pair<int, std::string>(6, "f"));
	map1.insert(ft::pair<int, std::string>(7, "g"));
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;
	ft::map<int, std::string>::iterator it;
	for(it = map1.begin(); it != map1.end(); ++it)
		std::cout << "map1 key = " << it->first << "  value = " << it->second << std::endl;

	std::cout << "\n\n\tOPERATOR[] \n" << std::endl;
	map1[6] = "changed";
	map1[2] = "changed";
	map1[10] = "added with operator[]";
	for(it = map1.begin(); it != map1.end(); ++it)
		std::cout << "map1 key = " << it->first << "  value = " << it->second << std::endl;

	std::cout << "\n\n\tCOPY COSTRUCTOR \n" << std::endl;
	ft::map<int, std::string> map2(map1);
	std::cout << "size : " << map2.size() << std::endl;
	std::cout << "max_size : " << map2.max_size() << std::endl;
	for(it = map2.begin(); it != map2.end(); ++it)
		std::cout << "map2 key = " << it->first << "  value = " << it->second << std::endl;

	std::cout << "\n\n\tERASE \n" << std::endl;
	map1.erase(map1.begin(), ++(++(map1.begin())));
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;
	for(it = map1.begin(); it != map1.end(); ++it)
		std::cout << "map1 key = " << it->first << "  value = " << it->second << std::endl;

	std::cout << "\n\n\tSWAP\n" << std::endl;
	ft::map<int, std::string> map3(map2);
	map3.find(5)->second = "changed with find()";
	map3.lower_bound(9)->second = "changed with lower()";
	map3.swap(map2);
	it = map2.begin();
	ft::map<int, std::string>::iterator it2;
	for(it = map2.begin(); it != map2.end(); ++it)
		std::cout << "map2 key = " << it->first << "  value = " << it->second << std::endl;
	std::cout << std::endl;
	for(it2 = map3.begin(); it2 != map3.end(); ++it2)	
		std::cout << "map3 key = " << it2->first << "  value = " << it2->second << std::endl;

	std::cout << std::endl;

	/******************** STACK ********************/

	std::cout << std::endl;

	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	ft::stack<int, ft::vector<int> > s1 (v1);

	std::cout << "size : " << s1.size() << std::endl;
	while(s1.size() != 0)
	{
		std::cout << "s1 : " << s1.top() << std::endl;
		s1.pop();
	}

	std::cout << std::endl;

	/******************** SET ********************/

	std::cout << std::endl;

	std::cout << "\n\n\t\tSET\n" << std::endl;

	std::cout << std::endl;

	ft::set<int> set1;
	set1.insert(100);
	set1.insert(200);
	set1.insert(300);
	set1.insert(400);
	set1.insert(500);
	set1.insert(600);
	set1.insert(700);
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;
	ft::set<int>::iterator ite;
	for(ite = set1.begin(); ite != set1.end(); ++ite)
		std::cout << "set1 = " << *ite << std::endl;

	std::cout << "\n\n\tCOPY COSTRUCTOR \n" << std::endl;
	ft::set<int> set2(set1);
	std::cout << "size : " << set2.size() << std::endl;
	std::cout << "max_size : " << set2.max_size() << std::endl;
	for(ite = set2.begin(); ite != set2.end(); ++ite)
		std::cout << "set2 = " << *ite << std::endl;

	std::cout << "\n\n\tERASE \n" << std::endl;
	set1.erase(set1.begin(), ++(++(set1.begin())));
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;
	for(ite = set1.begin(); ite != set1.end(); ++ite)
		std::cout << "set1 = " << *ite << std::endl;

	std::cout << "\n\n\tSWAP\n" << std::endl;
	ft::set<int> set3;
	set3.insert(1);
	set3.insert(2);
	set3.insert(3);
	set3.insert(4);
	set3.insert(5);
	set3.insert(6);
	set3.insert(7);
	set3.swap(set2);

	std::cout << "size : " << set2.size() << std::endl;
	std::cout << "max_size : " << set2.max_size() << std::endl;
	for(ite = set2.begin(); ite != set2.end(); ++ite)
		std::cout << "set2 = " << *ite << std::endl;
	std::cout << std::endl;
	for(ite = set3.begin(); ite != set3.end(); ++ite)
		std::cout << "set3 = " << *ite << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}
