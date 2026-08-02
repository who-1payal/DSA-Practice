/*Previous Smaller Element
You are given an integer array arr[ ].  The task is to find Previous Smaller Element (PSE) for every element in the array. The Previous Smaller Element (PSE) of an element x is the first element that appears to the left of x in the array and is strictly smaller than x.
Note: If no such element exists, assign -1 as the PSE for that position.

Examples:
Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
Explanation:
For 1, there is no element on the left, so answer is -1.
For 6, previous smaller element is 1.
For 2, previous smaller element is 1.

Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
Explanation:
For 1, no element on the left, so answer is -1.
For 5, previous smaller element is 1.
For 0, no element on the left smaller than 0, so answer is -1.
For 3, previous smaller element is 0.
For 4, previous smaller element is 3.
For 5, previous smaller element is 4.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105*/

#include <bits/stdc++.h>
using namespace std;    
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        vector<int> res(arr.size());
        stack<int> st;
        res[0] = -1;
        st.push(arr[0]);
        for(int i = 1; i<arr.size(); i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};

int main(){
    vector<int> arr;
    int input;
    while(cin>>input){
        if(input==-1)break;
        arr.push_back(input);
        
    }
    Solution s;
    vector<int> res = s.prevSmaller(arr);
    for(int x: res){
        cout<< x <<endl;
    }
}