class Solution {
	public:
		string getHint(string secret, string guess) {
			unordered_map<char, int> m;
			vector<bool> check(secret.size(), true);
			int i;
			int bulls=0;
			int cows=0;
			string res;

			for (i=0; i<secret.size();i++) {
				if (secret[i]==guess[i]) {
					bulls++;
					check[i] = false;
				}
				else {
					if(m.count(secret[i])==0)
						m.emplace(secret[i], 1);
					else
						m[secret[i]]++;
				}
			}

			for (i=0; i<guess.size(); i++) {
				if (check[i]==false)
					continue;
				if (m.count(guess[i])>0) {
					cows += 1;
					m[guess[i]]--;
					if (m[guess[i]]==0)
						m.erase(guess[i]);
				}
			}
			res += to_string(bulls);
			res += "A";
			res += to_string(cows);
			res += "B";
			return res;
		}
};
