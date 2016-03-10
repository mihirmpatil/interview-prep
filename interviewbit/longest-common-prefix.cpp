string Solution::longestCommonPrefix(vector<string> &A) {
	string result;
	vector<string>::iterator it;
	int index = 0;
	int flag = 1;
	int count = 0;
	char a;
	while(flag) {
		it=A.begin();
		if (index >= it->size())
			return result;
		a = it->at(index);
		++it;
		count++;
		for(; it!=A.end();++it) {
			if (index >= it->size())
				return result;
			if (a != it->at(index)) {
				return result;
			}
			else {
				count++;
			}
		}
		if (count = A.size()) {
			index++;
			count = 0;
			result.push_back(a);
		}
	}
	return result;
}

