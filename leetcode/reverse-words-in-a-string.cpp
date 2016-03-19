#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &s) {
	cout << s << endl;
	int i=0,j=0;
	
	// Beginning spaces
	while (s[i] == ' ') {
		i++;
	}
	if (i>0)
		s.erase(s.begin(), s.begin()+i);
	std::reverse(s.begin(), s.end());
	
	// Trailing spaces
	i=0;
	while (s[i] == ' ') {
		i++;
	}
	if (i>0)
		s.erase(s.begin(), s.begin()+i);


	i = 0;
	string::iterator it1 = s.begin();
	string::iterator it2 = s.begin();
	while (it2!=s.end()) {
		cout << s << endl;
		while (*it2 != ' ' && it2 != s.end())
			it2++;
		reverse(it1, it2);
		it1 = it2;
		if (it2==s.end())
			return;
		while (*it2 == ' ' && it2 != s.end()){
			it2++;
		}
		if (it2 > it1+1)
			s.erase(it1+1,it2);
		it2 = ++it1;
	}
}


int main() {
	string s("    hello    world    sdf    ");
	reverseWords(s);
	cout << s << endl;
	return 0;
}
