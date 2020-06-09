//http://www.spoj.com/problems/PRO/


#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
    using namespace std;

vector<int> vec;


/*void heapify(int i,int len){
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
    for(int i=vec.size()/2-1;i>=0;i--){
        heapify(i,vec.size());
    }
    for(int i=vec.size()-1;i>=0;i--){
        swap(vec[i],vec[0]);
        heapify(0,i);
    }
}*/



int main(){
    freopen("promotion.txt","r",stdin);
    int day;
    long res=0;
    cin>> day;
    for(int ii=0;ii<day;ii++){
        int n;

        cin >>n;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        int a,b;
        a=vec[0];
        b=vec[vec.size()-1];
        res+=b-a;
        vec.pop_back();
        vec[0]=vec[vec.size()-1];
        vec.pop_back();



    }
    cout << res;

    return 0;
}
