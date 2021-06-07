## 3Sum

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j, i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set mush not contain duplicate triplets.

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

**Example 2:**

```
Input: nums = []
Output: []
```

**Example 3:**

```
Input: nums = [0]
Output: []
```

**Constraints:**

+ `0 <= nums.length <= 3000`
+ `-105 <= nums[i] <= 105`

## 解题思路

题目要求找到输入序列中的`3`个数，且它们的和为`0`。
为了降低复杂度，首先对序列按照从小到大的顺序进行排列，之后将序列分为左右两部分进行遍历查找符合条件的数值。

先固定左侧的数值，再对右侧部分的序列从左右两侧查找两个数值，并判断它们的和是否为`0`。

### 代码

```c++
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
                        
                        // 跳过重复的数值
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
        
        return (ret);
    }
};
```