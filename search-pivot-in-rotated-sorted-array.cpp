#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector<int> v) {
	int low = 0;
	int high = v.size()-1;
	int mid;
	while (low<=high) {
		mid = (low+high)/2;
		cout << low << " " << high << " " << mid << endl;
		if (mid==0)
			return mid;
		if (v[mid] < v[mid-1])
			return mid;
		if (v[mid]<v[high]) {
			high = mid -1;
		}
		else {
			low = mid+1;
		}
	}
	return -1;
}

int main() {
	//int arr[] = { 7,9,11,13,2,3,4,5,6,7};
	//int arr[] = { 7,9,11,13};
	int arr[] = { 7,9,11,13,5};
	vector<int> vec(arr, arr+(sizeof(arr)/sizeof(int)));
	int ret = findPivot(vec);
	cout << ret << endl;
	return 0;
}
