
// Better solution
int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
		if (i < 2 || n > nums[i-2])
			nums[i++] = n;
	return i;
}


// My accepted solution
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int i=0,j=0;
			int len = nums.size();
			vector<int>::iterator it = nums.begin();
			int count=0;
			while (j<len) {
				j=i;
				while (j < len && nums[j]==nums[i])
					j++;
				if (j-i>2) {
					nums.erase(it+i+2, it+j);
					i += 2;
					count += 2;
					j=i;
				}
				else {
					count += (j-i);
					i=j;
				}
				len = nums.size();
			}
			return count;
		}
};
