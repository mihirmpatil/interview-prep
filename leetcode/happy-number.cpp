class Solution {
	public:
		bool isHappy(int n) {
			int tmp = n;
			int sum=0;
			int x;
			while (1) {
				while (tmp!=0) {
					x = tmp%10;
					tmp = tmp/10;
					sum += (x*x);
				}
				if (sum/10==0)
					break;
				tmp = sum;
				sum = 0;
			}
			if (sum==1)
				return true;
			else
				return false;
		}
};
