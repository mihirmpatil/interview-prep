class Solution {
	public:
		bool isAnagram(string s, string t) {
			unordered_map<char, int> m;
			int i;
			if (s.size()!=t.size())
				return false;
			if (s.size()==0)
				return true;
			unordered_map<char, int>::iterator it,c;
			for (i=0; i<s.size(); i++) {
				c = m.find(s[i]);
				if (c==m.end())
					m.emplace(s[i], 1);
				else {
					m[s[i]]++;            
				}
			}
			for (i=0;i <t.size(); i++) {
				c = m.find(t[i]);
				m[t[i]]--;
			}
			for (it=m.begin(); it!=m.end(); it++)
				if (it->second > 0)
					return false;
			return true;
		}
};
