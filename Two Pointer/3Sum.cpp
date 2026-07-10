/*3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 
Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    for(int i = 0; i<n-2;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int left = i+1;
        int right = n-1;
        int sum = -arr[i];
        while(left<right){
            int s = arr[left]+arr[right];
            if(s==sum){
                res.push_back({arr[i],arr[left],arr[right]});
                left++;
                right--;

                while(left<right && arr[left]==arr[left-1])left++;
                while(left<right && arr[right]==arr[right+1])right--;
            }
            else if(s<sum){
                left++;
            }
            else{
                right--;
            }
        }
    }
    for(auto p: res){
        cout<<"("<<p[0]<<","<<p[1]<<","<<p[2]<<")"<<endl;
    }
}