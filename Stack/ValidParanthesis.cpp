/*Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s){

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{

                if(st.empty())
                    return false;

                if((ch == ')' && st.top() != '(') ||
                   (ch == '}' && st.top() != '{') ||
                   (ch == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

int main(){
    string s;
    cout<<"Enter Parenthesis String: ";
    cin>>s;
    Solution sol;
    cout<<sol.isValid(s);
}