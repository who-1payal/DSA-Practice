#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> nextGreat(vector<int>& nums){
        vector<int> res;
        for(int num: nums){
            res.push_back(num);
        }
        for(int num: nums){
            res.push_back(num);
        }
        int n = nums.size();
        unordered_map<int,int> mp;
        stack<int> st;

        for(int num:res){
            while(!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for(int x:nums){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};