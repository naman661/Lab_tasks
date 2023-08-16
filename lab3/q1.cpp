#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
        int size = 0;

    public:
        void enqueue(int a){
            for (int i = 0;i<size;i++){
                int k = s1.top();
                s1.pop();
                s2.push(k);
            }
            s1.push(a);
            for (int i = 0;i<size;i++){
                int k = s2.top();
                s2.pop();
                s1.push(k);
            }
            size++;
        }

        int dequeue(){
            int k = s1.top();
            s1.pop();
            size--;
            return k;
        }

        bool empty(){
            if (size ==0) return true;
            else return false;
        }

        int front(){
            if (size == 0)  return -1;
            else{
                int k = s1.top();
                return k;
            }
        }

};


int main(){
    Queue* q = new Queue();
    q->enqueue(10);
    q->enqueue(20);
    cout<<q->dequeue()<<endl;

}

