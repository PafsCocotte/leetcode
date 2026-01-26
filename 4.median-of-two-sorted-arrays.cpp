/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = nums1.size();
        int totalHalf = (m+n+1)/2;
        while (l < r) {
            int i = l + (r-l)/2;
            int j = totalHalf - i;
            int il = (i==0) ? INT_MIN : nums1[i-1];
            int ir = (i==m) ? INT_MAX : nums1[i];
            int jl = (j==0) ? INT_MIN : nums2[j-1];
            int jr = (j==n) ? INT_MAX : nums2[j];

            if(il <= jr && jl <= ir) {
                if((m+n) % 2 == 1) {
                    return max()
                }
            }
        }
    }
};
// @lc code=end
