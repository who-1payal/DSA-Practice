/*Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the binary array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of the binary array: ";
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;

    int low = 0;
    int high = 0;
    int res = 0;
    vector<int> f(2,0);
    while(high<n){
        f[arr[high]]++;
        while(f[0]>k){
            f[arr[low]]--;
            low++;
        }
        int len = high-low+1;
        res = max(res,len);
        high++;

    }
    cout<<res;
}