/*209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    vector<int> arr(n);
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;

    int low = 0;
    int high = 0;
    int res = INT_MAX;
    int sum = 0;
    while(high<n){
        sum += arr[high];
        while(sum>=target){
            int len = high-low+1;
            res = min(res,len);
            sum = sum-arr[low];
            low++;
        }
        high++;
    }
    if(res==INT_MAX)cout<<0;
    else cout<<res;
}