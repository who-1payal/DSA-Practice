/* Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.
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

    int maximumRectangle(vector<vector<char>>& matrix){
        int rows = matrix.size();
        int col = matrix[0].size();
        vector<int> v(col,0);
        int result = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '0') v[j]=0;
                else{
                    v[j]++;
                }
            }
            result = max(result,largestRectangleArea(v));
        }
        return result;
    } 
};

int main(){
    
    int rows;
    int col;
    cout<<"Enter number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter number of columns: "<<endl;
    cin>>col;
    vector<vector<char>> matrix(rows, vector<char>(col));
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<col; j++){
            cout<<"Enter "<< i << j <<" element "<<endl;
            cin>>matrix[i][j];
        }
    }
    Solution s;
    cout<<"Maximum Rectangle Area: "<< s.maximumRectangle(matrix);
}