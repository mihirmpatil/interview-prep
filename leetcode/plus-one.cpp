class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			vector<int> result;
			int carry = 0;
			int tmp = digits[digits.size()-1] + 1;
			result.push_back(tmp%10);
			if (tmp>9)
				carry = 1;
			for (int i = digits.size()-2; i>=0 ;i--) {
				tmp = carry+digits[i];
				result.push_back(tmp%10);
				carry = tmp/10;
			}
			if (carry)
				result.push_back(carry);
			reverse(result.begin(), result.end());
			return result;
		}
};
