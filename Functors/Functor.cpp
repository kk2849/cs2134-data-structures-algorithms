#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

template <class T>
void insertionSortPointers(vector<T>& v){ //O(N^2)
	for (int i = 1; i < v.size(); i++){
		int j = i;
		T temp = v[j];
		for (; j>0 && *temp < *v[j - 1]; j--){
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}
}

double power(int base, int exp){
	if (exp == 0)
		return 1;
	if (exp < 0)
		return 1 / power(base, -exp);
	return base* power(base, exp - 1);
}

class Elephant{
public:
	void speak(){ cout << "TOOT"; }
};
template <class T>
void sortUsingPointers(vector<T>& v){
	vector<T*> ptrVec;
	for (T& item : v)
		ptrVec.push_back(&item);
	insertionSortPointers(ptrVec);
	vector<T> temp;
	for (T* ptr : ptrVec)
		temp.push_back(*ptr);
	std::move(v, temp);
}

class ElephantWrapper{
	Elephant* ptr;
public:
	ElephantWrapper(Elephant* newptr) :ptr(newptr){}
	void sing(){ ptr->speak(); }
};

template <class T>
void makeChoirSing(vector<T>& choir){
	for (T t : choir)
		t.sing();
}

class Person{
public:
	string name;
	int age;
	Person(string newname = "", int newage = 0) :name(newname), age(newage){}
	void sing(){ cout << "La La La"; }
};

template <class T, class C>
void insertionSort(vector<T>& v, C comparator){
	for (int i = 0; i < v.size(); i++){
		int j = i;
		T temp = v[j];
		for (; j>0 && comparator(temp,v[j - 1]); j--)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}

class lessThanOnAge{
public:
	bool operator()(const Person& lhs, const Person& rhs){
		return lhs.age < rhs.age;
	}
};
class lessThanOnName{
public:
	bool operator()(const Person& lhs, const Person& rhs){
		return lhs.name < rhs.name;
	}
};

void printVec(vector<Person>& v){
	for (Person p : v)
		cout << "(" << p.name << "," << p.age << "),";
	cout << endl;
}

class lessThanGivenAge{
	int reference;
public:
	lessThanGivenAge(int newage) :reference(newage){}
	bool operator()(const Person& p){
		return p.age < reference;
	}
};

template<class T,class C>
vector<T> find_if(vector<T>& v, C comparator){
	vector<T> temp;
	for (T item : v)
		if (comparator(item))
			temp.push_back(item);
	return temp;
}
template <class T>
class AutoPtr{
	T* ptr;
public:
	AutoPtr(T* newptr=nullptr) :ptr(newptr){}
	virtual ~AutoPtr(){ if (ptr != nullptr) delete ptr; }
	AutoPtr(AutoPtr& rhs) :ptr(nullptr) { *this = rhs; }
	void operator=(AutoPtr<T>& rhs);
	T& operator*(){ return *ptr; }
	T* get(){ return ptr; }
	void release(){ ptr = nullptr; }
	void reset(T* newptr){ if(ptr!=nullptr) delete ptr; ptr = newptr; }
};
template <class T>
void AutoPtr<T>::operator=(AutoPtr<T>& rhs){
	if (this == &rhs)
		return;
	if (ptr != nullptr)
		delete ptr;
	ptr = rhs.ptr;
	rhs.ptr = nullptr;
}
void func(){
	auto_ptr<int> aptr(new int);
	*aptr = 100;
	cout << *aptr << endl;
	auto_ptr<int> bptr = aptr;
	cout << *aptr << endl;
	aptr.

}

int main(){
	for (int i = 0; i < 100000000; i++)
		func();

	/*vector<Person> v;
	v.push_back(Person("Daniel", 20));
	v.push_back(Person("David", 30));
	v.push_back(Person("Albert", 100));

	lessThanOnName ln;
	cout << "Sorting on Name...";
	insertionSort(v, ln);
	printVec(v);

	cout << "Sorting on Age...";
	insertionSort(v, lessThanOnAge());
	printVec(v);

	cout << "STL Sort on Name...";
	sort(v.begin(), v.end(), lessThanOnName());
	printVec(v);*/
}