use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        let s1: HashSet<i32> = nums1.into_iter().collect();
        let s2: HashSet<i32> = nums2.into_iter().collect();

        vec![
            s1.difference(&s2).cloned().collect(),
            s2.difference(&s1).cloned().collect(),
        ]
    }
}

fn main() {
    let n1_1 = vec![1, 2, 3];
    let n1_2 = vec![2, 4, 6];
    println!("{:?}", Solution::find_difference(n1_1, n1_2));

    let n2_1 = vec![1, 2, 3, 3];
    let n2_2 = vec![1, 1, 2, 2];
    println!("{:?}", Solution::find_difference(n2_1, n2_2));
}