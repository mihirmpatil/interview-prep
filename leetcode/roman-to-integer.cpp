/* Read the rules regarding roman numerals here:
 * http://www.roman-numerals.org/add.html
 * http://www.roman-numerals.org/subtract.html (important!)
 * http://www.roman-numerals.org/calculator.html
 * */

class Solution {
	public:
		int romanToInt(string s) {
			unordered_map<char, int> map = {{'I', 1}, {'i', 1},
				{'V', 5}, {'v', 5},
				{'X', 10}, {'x', 10},
				{'L', 50}, {'l', 50},
				{'C', 100}, {'c', 100},
				{'D', 500}, {'d', 500},
				{'M', 1000}, {'m', 1000}};
			vector<int> v(s.length(),1);
			if(s.length()==1)
				return map[s[0]];
			int i, ret=0;
			for (i=0; i<s.length()-1; i++){
				if (map[s[i]] < map[s[i+1]]) {
					ret += (map[s[i+1]] - map[s[i]]);
					v[i]=0;
					v[i+1]=0;
					i++;
				}
			}
			for (i=0; i<s.length(); i++) {
				if(v[i]==0)
					continue;
				ret += map[s[i]];
			}
			return ret;
		}
};
