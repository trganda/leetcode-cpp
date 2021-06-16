## 3Sum

Given an array `nums` of `n` integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

+ `0 <= a, b, c, d < n`
+ `a, b, c`, and `d` are **distinct**.
+ `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

**Example 1:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

**Example 3:**

```
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
```

**Example 4:**

```
Input: nums1 = [], nums2 = [1]
Output: 1.00000
```

**Example 5:**

```
Input: nums1 = [2], nums2 = []
Output: 2.00000
```

**Constraints:**

+ `nums1.length == m`
+ `nums2.length == n`
+ `0 <= m <= 1000`
+ `0 <= n <= 1000`
+ `1 <= m + n <= 2000`
+ `-106 <= nums1[i], nums2[i] <= 106`

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