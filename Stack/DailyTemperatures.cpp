/*Daily Temperatures
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
 
Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> temp(temperatures.size());
        vector<int> diff(temperatures.size());
        temp[temperatures.size()-1] = temperatures.size(); 
        st.push({temperatures[temperatures.size()-1],temperatures.size()-1});
        for(int i = temperatures.size()-2; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = temperatures.size();
            }
            else{
                temp[i] = st.top().second;
            }
            st.push({temperatures[i], i});
        }

        for(int i = 0; i < diff.size(); i++){
            if(temp[i] == temperatures.size())
                diff[i] = 0;
            else
                diff[i] = temp[i] - i;
        }
        return diff;
    }
};

int main(){
    vector<int> temperatures;
    int input;
    while(true){
        cin>>input;
        if(input==-1)break;
        temperatures.push_back(input);
    }
    Solution s;
    vector<int> result = s.dailyTemperatures(temperatures);
    for(int i = 0; i<temperatures.size(); i++){
        cout<< result[i]<<" ";
    }
}