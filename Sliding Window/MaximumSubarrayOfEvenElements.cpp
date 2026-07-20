/*Longest Even Subarray
Given an integer array nums, return the contiguous subarray of maximum length that contains only even numbers.

Example 1
Input: nums = [2,4,6,1,8,10,12]
Output: [2,4,6]
Explanation:
There are two even-only subarrays:
[2,4,6] (length 3)
[8,10,12] (length 3)
Return the first one.

Example 2
Input: nums = [1,2,4,6,8,3,10]
Output: [2,4,6,8]

Example 3
Input: nums = [1,3,5]
Output: []
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Size of the array: ";
    cin>> n;
    vector<int> arr(n);
    cout<<"Enter eleemnts of the array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int i = 0;
    int j = 0;
    int maxLen = 0;
    int maxLeft = 0;
    while(j<n){
        if(arr[j]%2 != 0){
            i = j+1;
        }
        int len = j-i+1;
        if(len>maxLen){
            maxLen = len;
            maxLeft = i;
        }
        j++;
    }
    vector<int> ans(arr.begin()+maxLeft,arr.begin()+maxLeft+maxLen);
    for(int x:ans){
        cout<<x<<" ";
    }
}