//http://acm.timus.ru/problem.aspx?num=1306
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
    using namespace std;

vector<double> vec;
int n;

void heapify(int i,int len){
    int largest=i;
    int a=i*2+1;
    if(a<len && vec[a]>vec[largest]){
        largest=a;
    }
    if(a+1<len && vec[a+1]>vec[largest]){
        largest=a+1;
    }
    if(largest!=i){
        swap(vec[largest],vec[i]);
        heapify(largest,len);
    }
}



void heapSort(){
    for(int i=n/2-1;i>=0;i--){
        heapify(i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(vec[i],vec[0]);
        heapify(0,i);
    }
}

int main(){
    freopen("squence_median.txt","r",stdin);
    cin>> n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    heapSort();

    if(n%2 ==1){
        cout << vec[(n+1)/2-1];
    }else{
        cout << round((vec[n/2]+vec[n/2-1])/2*10)/10;
    }
    return 0;
}

/*
//http://acm.timus.ru/problem.aspx?num=1306
#include<iostream>
#include<stdio.h>
#include <vector>

#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int> pq;

int main(){

    //freopen("squence_median.txt","r",stdin);
    cin>> n;
    for(int i=0;i<n;i++){
        int temp;
        cin>> temp;
        pq.push(temp);
    }

    for(int i=0;i<(n/2)-1;i++){
        pq.pop();
    }
    if(n%2 ==1){
        pq.pop();
        cout << fixed << setprecision(1) << (double)pq.top();
    }else{
        double temp, temp1;
        temp=pq.top();
        pq.pop();
        temp1=pq.top();
        cout << fixed << setprecision(1) << (temp+temp1)/2;
    }
    return 0;
}

*/
