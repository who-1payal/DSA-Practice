/* Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;
bool correct(vector<int> &have, vector<int> &need){
    for(int i = 0; i<256 ; i++){
        if(have[i]<need[i])return false;
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter string s: ";
    cin>>s;
    string t;
    cout<<"Enter string t: ";
    cin>>t;
    if(s.size()<t.size()) 
    {
        cout<<"";
        return 0;
    }
    vector<int> freq_t(256,0);
    vector<int> freq_s(256,0);
    for(char ch:t){
        freq_t[ch]++;
    }
    int high = 0;
    int low = 0;
    int start = 0;
    int res = INT_MAX;
    while(high<s.size()){
        freq_s[s[high]]++;
        while(correct(freq_s,freq_t)){
            int len = high-low+1;
            if(res>len){
                res = len;
                start = low;
            }
            freq_s[s[low]]--;
            low++;
        }
        high++;
    }
    if(res==INT_MAX) cout<< "";
    else{
        cout<<s.substr(start,res);
    }
}