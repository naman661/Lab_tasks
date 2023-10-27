#include <bits/stdc++.h>
using namespace std;

class maxheap{
    public:
        vector <int> H ;
        int size = 0;
        void heapifyup(int i);
        void swap(int i,int p);
        void insert(int v);
        void heapifydown(int i);
        int removetop();
};

void maxheap::swap(int i,int p){
    int temp = H[i];
    H[i] = H[p];
    H[p] = temp;

}
void maxheap::heapifyup(int i){
    if (i==0) return;
    else{
        int p = (i-1)/2;
        if (H[p]<H[i]){
            swap(i,p);
            heapifyup(p);
        }
    }
}

void maxheap::insert(int v){
    H.push_back(v);
    size++;
    heapifyup(H.size()-1);
    heapifydown(0);
}

void maxheap::heapifydown(int i){
    if (H.size() == 0) return;


    int a = 2*i+1;
    int b = 2*i + 2;
    if (a>=H.size()) return;
    int maxindex = i;
    if (H[i]<H[a]){
        maxindex = a;
    }
    if (b<H.size() && H[b] > H[maxindex]){
        maxindex = b;
    }
    if (maxindex != i){
        swap(maxindex,i);
        heapifydown(maxindex);
    }
}

int maxheap::removetop(){
    int a = H[0];
    H[0] = H.back();

    H.pop_back();

    heapifydown(0);
    return a;
}