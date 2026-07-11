/*Triplets with Smaller Sum

Given an array arr[] of distinct integers and a value sum, find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Examples :
Input: sum = 2, arr[] = [-2, 0, 1, 3]
Output:  2
Explanation: Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3). 

Input: sum = 12, arr[] = [5, 1, 3, 4, 7]
Output: 4
Explanation: Triplets with sum less than 12 are (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).

Constraints:
1 ≤ sum ≤ 105
3 ≤ arr.size() ≤ 103
-103 ≤ arr[i] ≤ 103

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements in the array: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    int ans = 0;
    for(int i = 0; i<n-2; i++){
        int left = i+1;
        int right = n-1;
        while(left<right){
            int s = arr[i]+arr[left]+arr[right];

            if(s>=sum){
                right--;
            }
            else{
                ans = ans + (right-left);
                left++;
            }
        }
    }
    cout<<ans;
    
}