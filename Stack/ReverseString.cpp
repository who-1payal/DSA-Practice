/*Reverse a String Using a Stack
Problem Statement: Given a string s, reverse the string using a stack and return the reversed string. You are not allowed to use any built-in string reversal functions such as reverse().

Function Signature: string reverseString(string &s);

Input: A single string s consisting of printable characters.

Output: Return the reversed string.

Example 1
Input: hello
Output: olleh

Example 2
Input: OpenAI
Output: IAnepO

Example 3
Input: abcd
Output: dcba

Constraints
1 ≤ s.length() ≤ 10^5
The string may contain uppercase letters, lowercase letters, digits, and special characters.
Use a stack to solve the problem.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string reverseString(string& s){
        stack<char> st;
        string res;
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
        }
        while(!st.empty()){
            int ch = st.top();
            st.pop();
            res.push_back(ch);
        }
        return res;
    }
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    Solution sol;
    cout<<"Reversed String: "<< sol.reverseString(s);
}