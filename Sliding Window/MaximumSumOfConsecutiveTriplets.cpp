/* Maximum Sum of Consecutive Triplets
Problem Statement
Given an integer array `arr` of size `N`, find the **maximum sum** among all **contiguous triplets** (subarrays of size 3).
A triplet consists of **three consecutive elements** in the array.
Return the maximum sum obtained from all possible contiguous triplets.

Example 1
Input
arr = [1, 2, 3, 4, 5]
Output
12

Explanation
Possible triplets:
(1, 2, 3) → Sum = 6
(2, 3, 4) → Sum = 9
(3, 4, 5) → Sum = 12
Maximum sum = 12

Example 2
Input
arr = [4, -2, 1, 8, 3]
Output
12

Explanation
Possible triplets:
(4, -2, 1) → 3
(-2, 1, 8) → 7
(1, 8, 3) → 12
Maximum sum = 12

Constraints
3 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements od the array: ";
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    int window_sum = arr[0]+arr[1]+arr[2];
    int max_sum = window_sum;
    for(int i = 3; i< n; i++){
        window_sum = window_sum + arr[i]-arr[i-3];
        max_sum = max(max_sum,window_sum);
    }
    cout<<max_sum;
}
