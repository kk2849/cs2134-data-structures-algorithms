#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class BigInt{
	unsigned int val;
public:
	BigInt(int newval = 0){ val = newval; }
	BigInt& operator+=(const BigInt& rhs){ val += rhs.val; return *this; }
	BigInt operator++(int);
	BigInt& operator++();
	BigInt operator--(int);
	BigInt& operator--();
	bool operator[](int)const;
};
bool BigInt::operator[](int pos)const{
	bool arr[31];
	for (int i = 0; i < 32; i++)
		arr[i] = false;
	int temp = val;
	int i = 0;
	while (temp != 0){
		if (temp % 2 == 1)
			arr[i] = true;
		temp = temp / 2;
	}
	return arr[pos];
}
BigInt BigInt::operator++(int){
	BigInt temp = *this;
	val++;
	return temp;
}
BigInt& BigInt::operator++(){
	val++;
	return *this;
}
BigInt BigInt::operator--(int){
	BigInt temp = *this;
	val--;
	return temp;
}
BigInt& BigInt::operator--(){
	val--;
	return *this;
}
BigInt operator+(const BigInt& lhs, const BigInt& rhs){
	BigInt temp(lhs);
	temp += rhs;
	return temp;
}

void fillVec(vector<int>& vec, ifstream& inFile){
	/* file:
	1
	2
	3
	4
	*/
	int temp;
	while (inFile >> temp)
		vec.push_back(temp);
}
class School;
class Student{
	int id;
	int* something;
public:
	Student(int newID) :id(newID){ something = new int; }
	Student(const Student& rhs) : id(rhs.id), something(new int){ *this = rhs; }
	Student& operator=(const Student& rhs);
	virtual ~Student(){ delete something; }
	int getID() const{ return id; }
	string name;
	friend class School;
};
Student& Student::operator=(const Student& rhs){
	if (this == &rhs) //not really necessary in this case, but OK
		return *this;
	id = rhs.id;
	*something = *rhs.something;
	return *this;
}
class School{
	vector<Student> students;
public:
	void addStudent(string name);
};
void School::addStudent(string name){
	int nextID=1;
	if (students.size() != 0)
		nextID = students[students.size() - 1].id + 1;
	students.push_back(Student(nextID));
	students[students.size() - 1].name = name;
}
void fillVec(vector<Student>& vec, ifstream& inFile){
	/* file:
	1 Daniel Katz
	2 John F. Jones
	*/
	int tempid;
	char dummy;
	while (inFile >> tempid){
		Student temp(tempid);
		inFile.get(dummy); //the WS character
		/* or:
		#include <iomanip>
		inFile>>noskipws>>dummy>>skipws;
		*/
		getline(inFile, temp.name);
		vec.push_back(temp);
	}
}

void fillVec2(vector<Student>& vec, ifstream& inFile){
	/* file:
	1
	Daniel Katz
	2
	John F. Jones
	*/
	int tempid;
	while (inFile >> tempid){
		Student temp(tempid);

		inFile.ignore(9999, '\n');
		getline(inFile, temp.name);
		vec.push_back(temp);
	}
}


void openInputFile(ifstream& infile){
	string filename;
	cout << "What file to open for input? ";
	cin >> filename;
	infile.open(filename);
	while (!infile){
		cout << "Bad filename" << endl;
		cout << "What file to open for input? ";
		cin >> filename;
		infile.clear();
		infile.open(filename);
	}
}

int main(){
	int * ptr = new int(100);
	cout << ptr << endl;
	delete ptr;
	cout << ptr << endl; //ptr is dangling pointer
	//cout << *ptr << endl;
	ptr = new int;

	int sarr[5];
	int size = 100;
	int* arr = new int[size];
	


	vector<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i * 2);

	for (int i : v) //for(int i=0; i<v.size(); i++)cout<<v[i]<<endl;
		cout << i << endl;
	//for (;;);
	cout << "What C temp? " << endl;
	double c;
	cin >> c;
	double f = (9. / 5) * c + 32;
	cout << "That temperature is " << f << "F" << endl;

	
}
