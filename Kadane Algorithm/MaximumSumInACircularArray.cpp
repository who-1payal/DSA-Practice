/* Maximum Sum Circular Subarray
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

Constraints:
n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxSubarraySum(vector<int>& arr){
        int best_ans = arr[0];
        int ans = arr[0];
        for(int i = 1 ; i < arr.size(); i++){
            int c1 = arr[i];
            int c2 = best_ans + arr[i];
            best_ans = max(c1,c2);
            ans = max(ans,best_ans);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int res = INT_MIN;
        int sumOfArray = 0;
        for(int i = 0; i<nums.size();i++){
            sumOfArray += nums[i];
        }
        int maxnormal = maxSubarraySum(nums);
        if(maxnormal<0)return maxnormal;
        int best_ans = nums[0];
        int ans = nums[0];
        for(int i = 1; i<nums.size();i++){
            int c1 = nums[i];
            int c2 = best_ans + nums[i];
            best_ans = min(c1,c2);
            ans = min(best_ans,ans);
        }
        int max_sum = sumOfArray - ans;
        res = max(maxnormal,max_sum);
        return res;
    }
    
};

int main(){
    vector<int> nums;
    int input;
    cout<<"Enter elements of the array(Press any character/symbol to stop): ";
    while(cin>>input){
        nums.push_back(input);
    }
    Solution s;
    cout<<s.maxSubarraySumCircular(nums);
}