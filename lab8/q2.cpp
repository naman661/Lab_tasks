#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <pair<int,int>> v;
        for (int i=0;i<score.size();i++){
            pair<int,int> p = {score[i],i};
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector <string> ans(score.size(),"");
        for (int i=0;i<v.size();i++){
            int id = v[i].second;
            if (i==0){
                ans[id] = "Gold Medal";
            }
            else if(i==1){
                ans[id] = "Silver Medal";
            }
            else if (i==2){
                ans[id] = "Bronze Medal";
            }
            else{
                ans[id] = to_string(i+1);
            }
        }
        return ans;
        
    }
};