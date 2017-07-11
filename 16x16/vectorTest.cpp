#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return;
}

int main(int argc, char const *argv[]) {
	vector<int> v(10);
	for (int i = 0; i < v.size(); i++) {
		v[i] = i;
	}
	show(v);
	return 0;
}
