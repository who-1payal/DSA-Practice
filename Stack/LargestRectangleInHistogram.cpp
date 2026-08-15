/*Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
 
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        vector<int> right(heights.size());
        right[heights.size()-1] = heights.size();
        st.push(heights.size()-1);
        for(int i = heights.size()-2; i>=0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = heights.size();
            }
            else{
                right[i] = st.top();
            }

            st.push(i);
        }

        stack<int> s;
        vector<int> left(heights.size());
        left[0] = -1;
        s.push(0);
        for(int i = 1; i<heights.size() ; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }
            else{
                left[i] = s.top();
            }
            s.push(i);
        }
        vector<int> width(heights.size());
        for(int i = 0; i<width.size(); i++){
            width[i] = right[i]-left[i]-1;
        }
        vector<int> area(heights.size());
        for(int i = 0; i<area.size(); i++){
            area[i] = width[i]*heights[i];
        }
        int max_element = 0;
        for(int i = 0; i<area.size(); i++){
            max_element = max(max_element,area[i]);
        }
        return max_element;
    }
};  

int main(){
    vector<int> heights;
    int input;
    cout<<"Enter heights: "<<endl;
    while(true){
        cin>>input;
        if(input==-1)break;
        heights.push_back(input);
    }
    Solution s;
    cout<<"Largest Rectangle in Histogram is: "<<endl;
    cout << s.largestRectangleArea(heights);
}