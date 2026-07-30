/*Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Two intervals are considered overlapping if they share at least one point.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        bool inserted = false;
        for (auto interval: intervals){
            if(inserted==false &&interval[0]>newInterval[0]){
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(interval);
            
        }
        if(!inserted) res.push_back(newInterval);
        if(res.empty()) return {};

        int start1 = res[0][0];
        int end1 = res[0][1];
        vector<vector<int>> ans;

        for(int i = 1; i<res.size(); i++){
            int start2 = res[i][0];
            int end2 = res[i][1];

            if(start2 <= end1){
                end1 = max(end1,end2);
            }
            else{
                ans.push_back({start1,end1});
                start1 = start2;
                end1 = end2;
            }
        }
        ans.push_back({start1,end1});
        return ans;
    }
   
};

int main(){
    vector<vector<int>> a;
    vector<int> newInterval;
    int start;
    int end;
    cout<<"Enter Interval List:(Press [-1,-1] to stop):";
    while(true){
        cin>>start>>end;
        if(start==-1 && end==-1) break;
        a.push_back({start,end});
    }
    cout<<"Enter new Interval:";
    cin>>start>>end;
    newInterval.push_back(start);
    newInterval.push_back(end);
    Solution s;
    vector<vector<int>> result = s.insert(a, newInterval);

    for(int i = 0; i<result.size(); i++){
        cout<<"["<<result[i][0]<<","<<result[i][1]<<"]";
    }
    return 0;
}
