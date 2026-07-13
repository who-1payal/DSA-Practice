/*Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    unordered_map<char,int> f;
    int low = 0;
    int high = 0;
    int res = 0;
    while(high<s.size()){
        f[s[high]]++;
        int k = high-low + 1;
        while(f.size()<k){
            f[s[low]]--;
            if(f[s[low]]==0){
                f.erase(s[low]);
            }
            
            low++;
            k = high-low+1;
        }
        res = max(res,k);
        high++;
    }
    cout<<res;
}