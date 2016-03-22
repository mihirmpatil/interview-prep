class Solution {
	public:
		bool isPalindrome(int x) {
			if (x<0)
				return false;
			long int rev=0;
			int tmp=x;
			while(x) {
				rev = rev*10 + x%10;
				x = x/10;
			}
			if (tmp==rev)
				return true;
			else
				return false;
		}
};
