#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

template <class T>
class Queue{
	T* data;
	int capacity;
	int start;
	int end;
	void resize(int newsize);
public:
	Queue() :capacity(5), data(new T[5]), start(0), end(0){}
	virtual ~Queue(){ delete[] data; }
	Queue(const Queue& rhs) :data(nullptr){ *this = rhs; }
	T top()const { return data[start]; }
	bool isEmpty() const{ return start == end; }
	T pop();
	int size() const;
	void clear();
	void push(const T& item);
	Queue<T>& operator=(const Queue<T>& rhs);
	
};
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs){
	if (this == &rhs)
		return *this;
	int otherpos = rhs.start;
	delete[] data;
	data = new T[rhs.size() + 1];
	capacity = rhs.size() + 1;
	start = end = 0;
	do{
		push(rhs.data[otherpos++]);
		if (otherpos > rhs.capacity)
			otherpos = 0;
	} while (otherpos != rhs.end);
	return *this;
}
template <class T>
void Queue<T>::push(const T& item){
	data[end++]=item;
	if (end == capacity)
		end = 0;
	if (start == end)
		resize(capacity * 2);
}
template <class T>
void Queue<T>::clear(){
	delete[] data;
	capacity = 5;
	data = new T[capacity];
	start = end = 0;
}
template <class T>
void Queue<T>::resize(int newsize){
	T* temp = new T[newsize];
	int datapos = start;
	int temppos = 0;
	do{
		temp[temppos++] = data[datapos++];
		if (datapos == capacity)
			datapos = 0;
	} while (datapos != end);
	start = 0;
	end = temppos;
	capacity = newsize;
	delete [] data;
	data = temp;
}
template <class T>
int Queue<T>::size() const{
	if (start <= end)
		return end - start;
	return (capacity - start) + end;
}
template <class T>
T Queue<T>::pop(){
	T retval = top();
	if (isEmpty())
		return top();
	start++;
	if (start == capacity)
		start = 0;
	return retval;
}

/*template<class T>
class Queue{
	list<T> data;
public:
	void push(const T& item){ data.push_back(item); }
	T pop();
	T top() const{ return *data.begin(); }
	bool isEmpty() const{ return data.size() == 0; }
	void clear() { data.clear(); }
	int size() const { return data.size(); }
};
template <class T>
T Queue<T>::pop(){
	T temp = top();
	data.pop_front();
	return temp;
}*/

template <class T>
class Stack{
	list<T> data;
public:
	void push(const T& item){ data.push_front(item); }
	T pop();
	T top() const{ return *data.begin();}
	bool isEmpty() const{ return data.size() == 0; }
	void clear() { data.clear(); }
	int size() const { return data.size(); }
};

template <class T>
T Stack<T>::pop(){
	T retval = top();
	data.pop_front();
	return retval;
}

int main(){
	Queue<char> q;
	for (int i = 0; i < 26; i++)
		q.push('A' + i);

	for (int i = 0; i < 26 / 2; i++)
		q.pop();
	Queue<char> q2 = q;
	for (int i = 0; i < 26; i++)
		q.push('A' + i);
	while (!q.isEmpty())
		cout << q.pop() << endl;

	/*
	ifstream inFile("StackAndQueue.cpp");
	Stack<char> items;
	char temp;
	while (inFile >> temp){
		if (temp == '{' || temp == '(' || temp == '[')
			items.push(temp);
		else if (temp == '\\'){
			inFile >> temp;
		}
		else if (temp == '\''){
			inFile >> temp;
			if (temp == '\\')
				inFile >> temp;
			inFile >> temp;
		}
		else if (temp == '\"'){
			do {
				inFile >> temp;
				if (temp == '\\')
					inFile >> temp >> temp;
			} while (temp != '\"');
		}
		else if (temp == '}'){
			if (items.top() == '{'){
				cout << "Matched {}" << endl;
				items.pop();
			}
			else{
				cout << "MISMATCH } with " << items.top() << endl;
				return 0;
			}
		}
		else if (temp == ')'){
			if (items.top() == '('){
				cout << "Matched ()" << endl;
				items.pop();
			}
			else{
				cout << "MISMATCH ) with " << items.top() << endl;
				return 0;
			}
		}
		else if (temp == ']'){
			if (items.top() == '['){
				cout << "Matched []" << endl;
				items.pop();
			}
			else{
				cout << "MISMATCH ] with " << items.top() << endl;
				return 0;
			}
		}
	}
	if (items.isEmpty()){
		cout << "Done, success!" << endl;
	}
	else
		cout << "Failed, stack not empty at end." << endl;
		*/
	/*Stack<char> s;
	for (int i = 0; i < 10; i++)
	s.push('A' + i);

	while (!s.isEmpty())
	cout << s.pop() << endl;*/
}