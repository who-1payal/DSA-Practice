#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        for (auto interval: intervals){
            if(interval[0]>newInterval[0]){
                res.push_back(newInterval);
            }
            res.push_back(interval);
        }
        return res;

        int start1 = res[0][0];
        int end1 = res[0][1];
        vector<vector<int>> ans;

        for(int i = 1; i<res.size(); i++){
            int start2 = res[i][0];
            int end2 = res[i][0];

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
    int start;
    int end;
    while(true){
        cin>>start>>end;
        if(start==-1 && end==-1) break;
        a.push_back({start,end});
    }
    Solution s;
    vector<vector<int>> result = s.insert(a);

    for(int i = 0; i<result.size(); i++){
        cout<<"["<<result[i][0]<<","<<result[i][1]<<"]";
    }
    return 0;
}
