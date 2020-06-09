#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
    using namespace std;

int a[] ={5,3,4,2,3,8,90,56,83};
vector<int> vec;



void heap(int i){
    int smallest =i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<vec.size() && vec[left]<vec[smallest]){
        smallest=left;
    }
    if(right<vec.size() && vec[right]<vec[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(vec[smallest],vec[i]);
        heap(smallest);
    }

}

void add(int b){
    vec.push_back(b);
    int i=vec.size()-1;

    while(i>=0 && vec[i]<vec[(i-1)/2]){
        swap(vec[i],vec[(i-1)/2]);
        i=(i-1)/2;
        //cout << i << endl;
    }

}


void buildHeap(){
    for(int i=vec.size()/2-1;i>=0;i--){
        heap(i);
    }
}

void pop(){
    int len=vec.size();
    if(len==0){
        return;
    }
    vec[0]=vec[len-1];
    vec.pop_back();
    heap(0);
}

void print(){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
}

int main(){
    for(int i = 0 ; i < 9 ;i++){
        vec.push_back(a[i]);
    }
    buildHeap();
    print();
    cout << endl;

    //add(1);
    pop();
    print();

    return 0;
}


// right most node of left tree
// left most node of right tree
