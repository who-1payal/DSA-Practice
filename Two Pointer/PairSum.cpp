/* Pair Sum

Problem Statement: Given an integer array `arr` of size `N` and an integer `target`, find **all unique pairs** of elements whose sum is equal to the given target.
Each pair should contain two distinct elements from the array, and the same pair should not appear more than once in the output.
If no such pair exists, return an empty list.

Example 1
Input
arr = [1, 2, 3, 4, 5, 6, 7]
target = 8
Output
[(1, 7), (2, 6), (3, 5)]

Example 2
Input
arr = [1, 1, 2, 2, 3, 3]
target = 4
Output
[(1, 3), (2, 2)]

Example 3
Input
arr = [2, 4, 6]
target = 15
Output
[]

Constraints
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9
-10^9 ≤ target ≤ 10^9
*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int target;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter elements of the array: ";
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter target value: ";
    cin>>target;
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = n-1;
    int sum = 0;
    vector<pair<int,int>> res;
    while(i<j){
        sum = arr[i]+arr[j];
        if(sum<target){
            i++;
        }
        else if(sum>target){
            j--;
        }
        else{
            res.push_back({arr[i],arr[j]});
            i++;
            j--;
        }
        while(i<j && arr[i]==arr[i-1]){
            i++;
        }
        while(i<j && arr[j]==arr[j+1]){
            j--;
        }
    }
    if(res.empty()){
        cout<<"[ ]";
    }
    else{
        for(auto p : res){
            cout<<"("<<p.first<<","<<p.second<<")"<<endl;
        }
    }
    
}