/*Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int> maximumLeft(height.size());
        maximumLeft[0] = height[0];
        for(int i = 1; i<height.size(); i++){
            maximumLeft[i] = max(maximumLeft[i-1],height[i]);
        }
        vector<int> maximumRight(height.size());
        maximumRight[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i>=0; i--){
            maximumRight[i] = max(maximumRight[i+1],height[i]);
        }
        vector<int> water(height.size());
        for(int i = 0; i<height.size(); i++){
            water[i] = min(maximumLeft[i], maximumRight[i]) - height[i];
        }
        int sum = 0;
        for(int i = 0; i<water.size(); i++){
            sum += water[i];
        }
        return sum;
    }
};

int main(){
    vector<int> height;
    int n;
    while(true){
        cin>>n;
        if(n == -1) break;
        height.push_back(n);
        
    }
    Solution s;
    cout<<s.trap(height)<<endl;
    return 0;
}