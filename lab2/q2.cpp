#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    vector <int> v;
    cin>>n;
    for (int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    vector <int> a = {};
    for (int i =0;i<n;i++) a.push_back(0);

    a[n-1] = -1;
    for (int i = n-2;i>=0;i = i-1){
        
        if (v[i]<v[i+1]){
            a[i] = v[i+1];
        }
        else{
            for (int j = i+1;j<n;j++){
                if (a[j]==-1){
                    a[i] = -1;
                    break;
                }
                else{
                    if (a[j]>v[i]){
                        a[i] = a[j];
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}