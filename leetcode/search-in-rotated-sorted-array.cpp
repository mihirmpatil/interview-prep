class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int low = 0;
			int high = nums.size()-1;
			int mid;
			while(low<=high) {
				mid = low+((high-low)/2);
				cout << mid << endl;
				if (nums[mid]==target)
					return mid;
				if (nums[mid] < nums[high]) {
					if (nums[mid] < target && target <= nums[high])
						low = mid+1;
					else
						high = mid-1;
				}
				else {
					if (nums[low]<=target && target < nums[mid])
						high = mid-1;
					else
						low = mid+1;
				}
			}
			return -1;
		}
};
