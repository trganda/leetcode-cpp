// Link of Problem https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (nums.size() - 2); i++) {
            if ((i > 0 && nums[i] != nums[i-1]) || i == 0) {
                int curSum = -nums[i];

                int left = i+1, right = nums.size() - 1;
                while (left < right) {
                    int tSum = nums[left] + nums[right];
                    if (tSum == curSum) {
                        ret.push_back({nums[i], nums[left], nums[right]});
                        while ((left < right) && (nums[left] == nums[left+1])) {
                            left++;
                        }
                        while ((left < right) && (nums[right] == nums[right-1])) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (tSum < curSum) {
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