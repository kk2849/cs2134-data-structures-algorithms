#include <iostream>
#include <vector>
#include <set>
#include <ctime>

using namespace std;

template <class T>
void selectionSort(vector<T>& v){
	for (int i = 0; i < v.size(); i++){
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[min])
				min = j;
		T temp = v[min];
		v[min] = v[i];
		v[i] = temp;
	}
}

template <class T>
void insertionSort(vector<T>& v){
	for (int i = 1; i < v.size(); i++){
		T temp = v[i];
		int j = i;
		for (; j > 0 && temp < v[j - 1]; j--){
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}
}

template <class T>
void shellSort(vector<T>& v){
	for (int gap = v.size() / 2; gap > 0; gap /= 2){
		for (int i = gap; i < v.size(); i++){
			T temp = v[i];
			int j = i;
			for (; j >= gap&& temp < v[j - gap]; j -= gap)
				v[j] = v[j - gap];
			v[j] = temp;
		}
	}
}

template <class T>
void setSort(vector<T>& v){ //O(N log N)
	multiset<T> s;
	for (T i : v)
		s.insert(i); //O(log N)
	v.clear();
	while (!s.empty())
		v.push_back(s.pop());
}

class Timer{
	double start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed()const { return (clock() - start) / CLOCKS_PER_SEC; }
};

int main(){
	srand(time(NULL));
	vector<int> v;
	double elapsed;
	Timer t;
	for (int i = 0; i < 10; i++){
		v.clear();
		for (int j = 0; j < (i+1)*10000; j++)
			v.push_back(rand());
		t.reset();
		insertionSort(v);
		elapsed = t.elapsed();
		cout << "V.size=" << v.size() << " sorting took " << elapsed << "seconds" << endl;

	}
}