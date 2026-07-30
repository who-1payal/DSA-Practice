/*Overlapping Intervals
You are given a 2D array arr[][] which represents a set of intervals, where each element arr[i] = [start, end] defines an interval.
Your task is to determine if any two intervals in the given set overlap.
Note: Two intervals [a, b] and [c, d] overlap if they have at least one common value, i.e., a ≤ d and c ≤ b.

Examples:
Input: n = 4, arr[][] = [[1, 3], [5, 7], [2, 4], [6, 8]]
Output: true
Explanation: The intervals [1, 3] and [2, 4] overlap.

Input: n = 4, arr[][] = [[1, 3], [7, 9], [4, 6], [10, 13]]
Output: false
Explanation: No pair of intervals overlap.

Constraints:
1 ≤ arr[i][0] < arr[i][1] ≤ 105  
2 ≤ arr.size() ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        sort(intervals.begin(),intervals.end());
        int end1 = intervals[0][1];
        
        for(int i = 1; i< intervals.size(); i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            
            if(end1 >= start2){
                return true;
            }
            
            end1 = max(end1,end2);
        }
        return false;
    }
};

int main() {
    vector<vector<int>> intervals;
    int start;
    int end;
    cout<<"Enter intervals:(Press [-1,-1] to stop):";
    while(true){
        cin>>start>>end;
        if(start==-1 && end==-1) break;
        intervals.push_back({start,end});
    }
    Solution s;
    bool result = s.isIntersect(intervals);
    if(result){
        cout<<"Intervals are intersecting.";
    }
    else{
        cout<<"Intervals are not intersecting.";
    }
}