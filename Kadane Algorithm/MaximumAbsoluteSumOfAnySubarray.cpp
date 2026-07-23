/* Maximum Absolute Sum of Any Subarray
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
Return the maximum absolute sum of any (possibly empty) subarray of nums.
Note that abs(x) is defined as follows:
If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 
Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int maxSubarraySum(vector<int>& nums){
        int best_ans = nums[0];
        int ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            int c1 = nums[i];
            int c2 = nums[i] + best_ans;
            best_ans = max(c1,c2);
            ans = max(ans,best_ans);
        }

        return ans;
    }

    int minSubarraySum(vector<int>& nums){
        int best_ans = nums[0];
        int ans = nums[0];
        for(int i = 1; i<nums.size();i++){
            int c1 = nums[i];
            int c2 = nums[i] + best_ans;
            best_ans = min(c1,c2);
            ans = min(ans,best_ans);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int res = max(abs(maxSubarraySum(nums)), abs(minSubarraySum(nums)));
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
    cout<<s.maxAbsoluteSum(nums);
}