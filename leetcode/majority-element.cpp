class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int count = 1;
			int cur = nums[0];
			int max=INT_MIN;
			int res;
			for (int i=0; i<nums.size(); i++) {
				cur = nums[i];
				while (i<nums.size()-1 && nums[i+1]==cur) {
					count++;
					i++;
				}
				if (count > max) {
					max = count;
					res = cur;
					count=1;
					cur=nums[i];
				}
			}
			return res;
		}
};
