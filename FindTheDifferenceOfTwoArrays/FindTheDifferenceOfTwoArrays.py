from typing import List

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1, s2 = set(nums1), set(nums2)
        
        return [list(s1 - s2), list(s2 - s1)]

def main():
    sol = Solution()

    # Example 1
    nums1_1 = [1, 2, 3]
    nums2_1 = [2, 4, 6]
    print(f"Example 1: {sol.findDifference(nums1_1, nums2_1)}")  # Expected: [[1, 3], [4, 6]]

    # Example 2
    nums1_2 = [1, 2, 3, 3]
    nums2_2 = [1, 1, 2, 2]
    print(f"Example 2: {sol.findDifference(nums1_2, nums2_2)}")  # Expected: [[3], []]

if __name__ == "__main__":
    main()