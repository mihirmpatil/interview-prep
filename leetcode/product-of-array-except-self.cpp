

// 3 passes; but without division
class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> left(nums.size(),1);
			vector<int> right(nums.size(),1);
			vector<int> result(nums.size(),1);
			int i, accum=1;
			for (i=1; i<nums.size();i++) {
				left[i] = left[i-1]*nums[i-1];
			}
			for (i=nums.size()-2; i>=0;i--) {
				right[i] = right[i+1]*nums[i+1];
			}
			for (i=0; i<nums.size();i++) {
				result[i] = left[i]*right[i];
			}
			return result;
		}
};
