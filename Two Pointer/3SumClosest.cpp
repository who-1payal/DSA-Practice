/* 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int target;
    cout<<"Enter target Variable: ";
    cin>>target;
    int min_diff = INT_MAX;
    int res_sum = 0;
    for(int i = 0; i<n-2; i++){
        if (i > 0 && arr[i] == arr[i - 1])continue;
        int left = i+1;
        int right = n-1;
        
        while(left<right){
            int sum = arr[i]+arr[left]+arr[right];
            int diff = abs(sum - target);
            if(diff<min_diff){
                min_diff = diff;
                res_sum = sum;
            }
            if(sum<target) left++;
            else if(sum>target) right--;
            else{
                cout<<sum;
                return 0;
            }
        }
    }
    cout<<res_sum;
}