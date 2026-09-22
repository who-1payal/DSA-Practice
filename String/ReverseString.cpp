/* Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 
Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    vector<char> s;
    while(true){
        char c;
        cin>>c;
        if(c=='#') break;
        s.push_back(c);
    }
    Solution solution;
    solution.reverseString(s);
    for(auto c:s){
        cout<<c<<" ";
    }
    return 0;
}
