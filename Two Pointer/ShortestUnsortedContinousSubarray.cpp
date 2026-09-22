/*Shortest Unsorted Continuous Subarray
Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0
 
Constraints:
1 <= nums.length <= 104
-105 <= nums[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1;
        int right = -1;
        int max_val = nums[0];
        for(int i = 1; i<nums.size();i++){
            if(nums[i]<max_val){
                right = i;
            }
            max_val = max(max_val,nums[i]);
        }
        int min_val = nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]>min_val){
                left = i;
            }
            min_val = min(min_val,nums[i]);
        }
        if(left==-1)return 0;
        return right-left+1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    Solution solution;
    cout<<solution.findUnsortedSubarray(nums);
    return 0;
}