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
        int top();
};

int minheap::top(){
    return H[0];
}

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

class maxheap{
    public:
        vector <int> H ;
        int size = 0;
        void heapifyup(int i);
        void swap(int i,int p);
        void insert(int v);
        void heapifydown(int i);
        int removetop();
        int top();
};

int maxheap::top(){
    return H[0];
}

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








class MedianFinder {
public:
        minheap* min = new minheap();
        maxheap* max = new maxheap();
        int size =0;
        double median;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (size == 0){
            size++;
            median = num;
        }
        else{
            size++;
            if (size%2 == 0){
                if (num>=median){
                    max->insert(median);
                    min->insert(num);
                    median = (min->top()+ median)/2;
                }
                else{
                    min->insert(median);
                    max->insert(num);
                    median = (max->top()+median)/2;
                }
            }
            else{
                if (num>=min->top()){
                    median = min->top();
                    min->removetop();
                    min->insert(num);
                }
                else if (max->top()<=num && num<=min->top()){
                    median = num;
                }
                else{
                    median = max->top();
                    max->removetop();
                    max->insert(num);
                }
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

