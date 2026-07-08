/*Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :
Input: arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 0, 0, 1, 1, 1, 1, 1].

Input: arr[] = [1, 1]
Output: [1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1]

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1 */

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Use two pointers.
- Left pointer skips all 0s.
- Right pointer skips all 1s.
- Swap misplaced elements until the pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int main(){
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int i = 0;
    int j = n-1;
    while(i<j){
        while(i<j && arr[i]==0){
            i++;
        }
        while(i<j && arr[j]==1){
            j--;
        }
        if(arr[i]==1 && arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}