/*Minimum Sum Subarray
Given an array arr[], find the sub-array containing at least one number which has the minimum sum and return its sum.

Examples :
Input: arr[] = {3,-4, 2,-3,-1, 7,-5}
Output: -6
Explanation: The subarray is {-4,2,-3,-1} = -6

Input: arr[] = {2, 6, 8, 1, 4}
Output: 1
Explanation: The sub-array is {1} = 1

Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] ≤ 107
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int input;
    cout<<"Enter elements of the array (Press any character / symbol to stop: )";
    while(cin>>input){
        arr.push_back(input);
    }
    int best_ans = arr[0];
    int ans = arr[0];
    for(int i = 1 ; i<arr.size(); i++){
        int c1 = best_ans + arr[i];
        int c2 = arr[i];
        best_ans = min(c1,c2);
        ans = min(ans,best_ans);
    }
    cout<<ans;
}