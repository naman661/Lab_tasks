#include <bits/stdc++.h> 
using namespace std;

class minheap{
    public:
        vector <int> H ;
        int size = 0;
        void heapifyup(int i);
        void swap(int i,int p);
        void insert(int v);
        void heapifydown(int i);
        int removetop();
};

void minheap::swap(int i,int p){
    int temp = H[i];
    H[i] = H[p];
    H[p] = temp;

}
void minheap::heapifyup(int i){
    if (i==0) return;
    else{
        int p = (i-1)/2;
        if (H[p]>H[i]){
            swap(i,p);
            heapifyup(p);
        }
    }
}

void minheap::insert(int v){
    H.push_back(v);
    size++;
    heapifyup(H.size()-1);
    heapifydown(0);
}

void minheap::heapifydown(int i){
    if (H.size() == 0) return;


    int a = 2*i+1;
    int b = 2*i + 2;
    if (a>=H.size()) return;
    int minindex = i;
    if (H[i]>H[a]){
        minindex = a;
    }
    if (b<H.size() && H[b] < H[minindex]){
        minindex = b;
    }
    if (minindex != i){
        swap(minindex,i);
        heapifydown(minindex);
    }
}

int minheap::removetop(){
    int a = H[0];
    H[0] = H.back();

    H.pop_back();

    heapifydown(0);
    return a;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector <int> ans;
    minheap* h = new minheap;
    for (vector <int> v:q){
        if (v.size() == 2){
            h->insert(v[1]);
        }
        else{
            ans.push_back(h->removetop());
        }
    }
    return ans;
}


