#include <bits/stdc++.h>
using namespace std;

int arr[5];

void insert(int data, int &h, int &t){
	if (h-t == 1 || h-t == -4){
		cout<<"Queue Overflow"<<endl;
	}
	
	else if (h==t){
		arr[h] = data;
	}	
	else{
		t++;
		t = t%5;
		arr[t] = data;
	}
	
}


void del(int &h, int &t){
	if (h==t){
		cout<<"Queue Underflow"<<endl;
	}
	
	else{
		h++;
		h = h%5;
	}
}


void display(int h, int t){
	if (h==t){
		cout<<"NULL"<<endl;
	}
	
	else{
		int i = h;
		while (i%5 != t){
			cout<<arr[i]<<" ";
			i++;
			i = i%5;
		}
		cout<<endl;
	}
	
}



int main(){
	int h = 0;
	int t = 0;
	int input;
	while(true){
		cin>>input;
		if (input == 4){
			break;
		}
		else if (input == 1){
			int data;
			cin>>data;
			insert(data,h,t);
		}
		
		else if (input == 2){
			del(h,t);
		}
		
		else {
			display (h,t);
		}
	}

}
