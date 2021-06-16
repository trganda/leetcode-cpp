class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure the left part arrays is less than right
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = nums1.size() - 1;
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        while (true) {
            int i = (left + right) >= 0 ? (left+right)/2 : (left+right)/2 - 1;
            int j = half - i - 2;
            
            int nums1Left = i >= 0 ? nums1[i] : INT_MIN;
            int nums1Right = (i + 1) < nums1.size() ? nums1[i+1] : INT_MAX;
            int nums2Left = j >= 0 ? nums2[j] : INT_MIN;
            int nums2Right = (j + 1) < nums2.size() ? nums2[j+1] : INT_MAX;
                       
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (total % 2 == 0) {
                    return ((max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0);
                } else {
                    return (min(nums1Right, nums2Right));
                }
            } else if (nums1Left > nums2Right) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
    }
};  