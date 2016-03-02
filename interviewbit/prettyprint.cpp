#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > prettyPrint(int A) {

	int low=0;
	int size=2*A-1;
	int high=size-1;
	int i;
	vector< vector<int> > mat(size, vector<int> (size));
	while(low<=high) {
		for (i=low;i<=high;i++) {
			mat.at(low).at(i) = A;
			mat.at(high).at(i) = A;
			mat.at(i).at(low) = A;
			mat.at(i).at(high) = A;
		}
		low++;
		high--;
		A--;
	}
	return mat;
}

int main() {
	prettyPrint(4);
	return 0;
}
