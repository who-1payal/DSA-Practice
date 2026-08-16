/* First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int firstUniqueCharacter(string s){
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        for(int i = 0; i<s.size(); i++){
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    Solution sol;
    cout<<sol.firstUniqueCharacter(s);
    return 0;
}