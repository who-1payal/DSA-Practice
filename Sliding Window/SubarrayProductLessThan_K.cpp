/*Subarray Product Less Than K
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
 
Constraints:
1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter target product: ";
    cin>>k;

    if(k<=1) cout<<0;
    int low = 0;
    int high = 0;
    int product = 1;
    int count = 0;
    while(high<n){
        product *= arr[high];
        while(product>=k){
            product /= arr[low];
            low++;
        }
        count = count+(high-low+1);
        high++;
    }
    cout<<count;
}