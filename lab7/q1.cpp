#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector <int> a;
        for (int i=0;i<operations.size();i++){
            if (operations[i]=="C"){
                a.erase(a.begin()+a.size()-1);
            }
            else if (operations[i]=="D"){
                a.push_back(2*a[-1]);
            }

            else if (operations[i]=="+"){
                a.push_back(a[-1]+a[-2]);
            }
            else{
                int val = operations[i][0];
                a.push_back(val);
            }
        }
        long sum = 0;
        for (auto i: a){
            sum+=i;
        }
        return sum;
    }
};

int calPoints(vector<string>& operations) {
        vector <int> a;
        for (int i=0;i<operations.size();i++){
            
            if (operations[i]=="C"){
                a.erase(a.begin()+a.size()-1);
            }
            else if (operations[i]=="D"){
                a.push_back(2*a[a.size()-1]);
            }

            else if (operations[i]=="+"){
            
                a.push_back(a[a.size()-1]+a[a.size()-2]);
            }
            else{
                int val = stoi(operations[i]);
                // cout<<"val "<<val<<endl;
                a.push_back(val);
            }
        }
        int sum = 0;
        for (auto i: a){
            cout<<i<<" ";
            sum+=i;
        }
        cout<<endl;
        return sum;
    }


int main(){
    vector <string> ops;
    ops = {"5","2","C","D","+"};
    cout<<calPoints(ops)<<endl;
}