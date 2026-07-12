/*Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Examples:
Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.

Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ k ≤ arr.size()
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    cout<<"Enter elements of the array; ";
    vector<int> arr(n);
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the maximum size of the window to be taken for calculating sum:  ";
    cin>>k;

    int low = 0;
    int high = k-1;
    int sum = 0;
    int res = sum;
    for(int i = low ; i<=high; i++){
        sum += arr[i];
    }
    while(high<n){
        high++;
        sum = sum - arr[low] + arr[high];
        low++;
        res = max(res,sum);
    }
    cout<<res;
}