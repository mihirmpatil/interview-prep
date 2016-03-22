class NumArray {
	vector<int> v;
	vector<int> sums;
	public:
	NumArray(vector<int> &nums) {
		if (nums.empty())
			return;
		v = sums;
		int i;
		sums.push_back(nums[0]);
		for (i=1; i<nums.size(); i++)
			sums.push_back(sums[i-1] + nums[i]);
	}
	int sumRange(int i, int j) {
		if (i==0)
			return sums[j];
		else 
			return sums[j] - sums[i-1];
	}
};
