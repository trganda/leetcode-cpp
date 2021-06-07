// Link of Problem https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (nums.size() - 3); i++) {
            if (((i > 0) && (nums[i] != nums[i-1])) || i == 0) {
                for (int j = i+1; j < (nums.size() - 2); j++) {
                    if (nums[j] != nums[j-1] || j == (i+1)) {
                        int left = j + 1, right = nums.size() - 1;
                        while (left < right) {
                            int tSum = nums[i] + nums[j] + nums[left] + nums[right];
                            if (tSum == target) {
                                ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                                while ((left < right) && (nums[left] == nums[left+1])) {
                                    left++;
                                }
                                while ((left < right) && (nums[right] == nums[right-1])) {
                                    right--;
                                }
                                left++;
                                right--;
                            } else if (tSum < target) {
                                left++;
                            } else {
                                right--;
                            }
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};