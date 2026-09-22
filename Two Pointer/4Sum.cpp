/* 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i = 0; i<n-3;i++){
            if (i > 0 && nums[i] == nums[i - 1])continue;
            for(int j = i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int left = j+1;
                int right = n-1;
                while(left<right){
                    long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1])left++;
                        while(left<right && nums[right]==nums[right+1])right--;
                    }
                    else if(target>sum)left++;
                    else right--;

                    
                }
            }
        }
        return result;
    }
};

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums,target);
    for(auto v:result){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}