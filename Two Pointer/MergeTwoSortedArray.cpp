/*88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cout<<"Enter size of Array 1: ";
    cin>>a;
    vector<int> arr(a);
    cout<<"Enter elements of Array 1; ";
    for(int i = 0; i<a;i++){
        cin>>arr[i];
    }
    int b;
    cout<<"Enter size of Array 2: ";
    cin>>b;
    vector<int> num(b);
    cout<<"Enter elements of Array 2: ";
    for(int j = 0; j<b; j++){
        cin>>num[j];
    }

    int i = 0;
    int j = 0;
    int k = 0;
    int m = a+b;
    vector<int> res(m);
    while(i<a && j<b){
        if(arr[i]<num[j]){
            res[k] = arr[i];
            i++;
            k++;
        }
        else{
            res[k]=num[j];
            j++;
            k++;
        }
    }
    while(j<b){
        res[k]=num[j];
        j++;
        k++;
    }
    while(i<a){
        res[k]=arr[i];
        i++;
        k++;
    }
    for(int i = 0; i<m ; i++){
        cout<<res[i]<<endl;
    }
}