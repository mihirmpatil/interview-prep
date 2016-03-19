// https://leetcode.com/discuss/51129/10-lines-76ms-easy-c-solution-updated-function-signature

// Correct but get TLE. O(n^2) solution
class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<int> checked(strs.size(), 0);
			vector<string> strs_copy(strs);
			vector< vector<string> > result;
			vector<string>::iterator it = strs_copy.begin();
			vector<string>::iterator it2;
			while(it!=strs_copy.end()) {
				sort(it->begin(), it->end());
				++it;
			}
			int i,j;
			vector<string> v;
			for (i=0;i<strs_copy.size();i++) {
				if (checked[i]>0)
					continue;
				v.push_back(strs[i]);
				checked[i]++;
				for (j=i+1;j<strs_copy.size();j++){
					if (strs_copy[i].compare(strs_copy[j]) == 0  && checked[j] == 0) {
						v.push_back(strs[j]);
						checked[j]++;
					}
				}
				sort(v.begin(),v.end());
				result.push_back(v);
				v.clear();
			}
			return result;
		}
};
