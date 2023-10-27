#include <bits/stdc++.h> 
using namespace std;

class minheap{
    public:
        vector <pair<int,int>> H ;
        int size = 0;
        void heapifyup(int i);
        void swap(int i,int p);
        void insert(pair<int,int> v);
        void heapifydown(int i);
        pair<int,int> removetop();
};

void minheap::swap(int i,int p){
    pair<int,int> temp = H[i];
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

void minheap::insert(pair<int,int> v){
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

pair<int,int> minheap::removetop(){
    pair<int,int> a = H[0];
    H[0] = H.back();

    H.pop_back();

    heapifydown(0);
    return a;
}


// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    
//     vector <int> pointers(k,0);
//     minheap* h = new minheap();
//     for (int i=0;i<k;i++){
//         pair<int,int> p = {kArrays[i][0],i};
//         h->insert(p);
//     }
//     vector <int> ans;
//     while(ans.size()!=k){}


// }



 

class Node{

    public:

    int data;

    int i;

    int j;

    Node(int data , int i , int j){

        this->data = data;

        this->i = i;

        this->j = j;

    } 

};

 

class cmp{

    public:

    bool operator()(Node* a , Node* b){

        return a->data > b->data;

    }

};

 

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)

{

    // Write your code here. 

    priority_queue<Node*,vector<Node*> , cmp> minHeap;

    vector<int> ans;

    for(int i = 0 ; i < k ; i++){

        Node* temp = new Node(kArrays[i][0] , i , 0);

        minHeap.push(temp);

    }

    while(!minHeap.empty()){

        auto top = minHeap.top();

        minHeap.pop();

        ans.push_back(top->data);

        int i = top->i;

        int j = top->j;

        if(j+1 < kArrays[i].size()){

            Node* temp = new Node(kArrays[i][j+1] , i , j+1);

            minHeap.push(temp);

        }

    }

    return ans;

}