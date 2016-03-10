
// Time Limit Exceecded but correct. Worst case O(n)
vector<int> Solution::searchRange(const vector<int> &A, int B) {

	vector<int> result;
	int low = 0;
	int high = A.size()-1;
	int mid = (low+high)/2;
	int found =0;
	while(low<=high) {
		mid = (low+high)/2;
		if(A[mid]==B) {
			found = 1;
			break;
		}

		else if(A[mid]<B)
			low = mid+1;
		else
			high = mid-1;
	}
	if (!found) {
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
	int i = mid;
	while(A[i]==A[mid]) { 
		i--;
		if (i<0)
			break;
	}
	result.push_back(i+1);
	i = mid;
	while(A[i]==A[mid]) {
		i++;
		if (i>=A.size())
			break;
	}
	result.push_back(i-1);
	return result;
}


/*
http://stackoverflow.com/questions/12144802/finding-multiple-entries-with-binary-search
*/
// O(log(n)) solution
vector<int> Solution::searchRange(const vector<int> &A, int B) {

	vector<int> result;
	int low = 0;
	int high = A.size()-1;
	int mid = (low+high)/2;
	int found =0;
	while(low<high) {
		mid = (low+high)/2;
		if(low==high && A[low]==B)
			break;
		if(A[mid]>=B) {
			high = mid;
		}
		else if(A[mid]<B)
			low = mid+1;
	}

	if (A[low]!=B) {
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
	else
		result.push_back(low);

	low = 0;
	high = A.size()-1;
	mid = (low+high)/2 + 1;
	while(low<high) {
		mid = (low+high)/2 + 1;
		if(low==high && A[low]==B)
			break;
		if(A[mid]<=B) {
			low = mid;
		}

		else if(A[mid]>B)
			high = mid-1;
	}
	result.push_back(low);
	return result;
}
