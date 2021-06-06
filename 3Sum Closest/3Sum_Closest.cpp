class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        int threshold = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if ((i > 0 && nums[i] != nums[i-1]) || i == 0) {
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int curSum = nums[left] + nums[right] + nums[i];
                    if (abs(curSum - target) < threshold) {
                        threshold = abs(curSum - target);
                        ret = curSum;
                    }
                    if (curSum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return ret;
    }
};
