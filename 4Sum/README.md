## 3Sum

Given an array `nums` of `n` integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

+ `0 <= a, b, c, d < n`
+ `a, b, c`, and `d` are **distinct**.
+ `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Example 2:**

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```


**Constraints:**

+ `1 <= nums.length <= 200`
+ `-109 <= nums[i] <= 109`
+ `-109 <= target <= 109`

## 解题思路

和3Sum的思路是一样的。

### 代码

```c++
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
```