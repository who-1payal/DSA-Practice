/* Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    vector<int> arr1;
    vector<int> arr2;
    for(int i = 0; i<n ; i++){
        if(arr[i]<0){
            arr1.push_back(arr[i]);
        }
        else{
            arr2.push_back(arr[i]);
        }
    }
    if(arr1.size()==0){
        for(int i = 0; i<arr2.size(); i++){
            arr2[i] = arr2[i]*arr2[i];
            cout<<arr2[i];
        }
    }
    if(arr2.size()==0){
        for(int i = 0; i<arr1.size();i++){
            arr1[i]=arr1[i]*arr1[i];
        }
        reverse(arr1.begin(),arr1.end());
        for(int i = 0; i<arr.size();i++){
            cout<<arr1[i];
        }
    }
    for(int i = 0; i<arr1.size();i++){
        arr1[i] = arr[i]*arr[i];
    }
    reverse(arr1.begin(),arr1.end());

    for(int i = 0; i<arr2.size();i++){
        arr2[i]=arr2[i]*arr2[i];
    }

    int i = 0;
    int j = 0;
    int k = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }
        else{
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<arr1.size()){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<arr2.size()){
        arr[k]=arr2[j];
        k++;
        j++;
    }

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}