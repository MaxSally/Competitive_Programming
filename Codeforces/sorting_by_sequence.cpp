//http://codeforces.com/problemset/problem/843/A

#include<queue>
#include<functional>
#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;

int n,cnt;
vector<int> ini,fin,visited;
queue<int> temp,temp2,res;
const int inf=2e9;


void heapify(int i,int l){
    int a=2*i+1;
    int temp=i;
    if(a<l && fin[a]>fin[temp]){
        temp=a;
    }
    if(a+1<l && fin[a+1]>fin[temp]){
        temp=a+1;
    }
    if(temp!=i){
        swap(fin[temp],fin[i]);
        heapify(temp,l);
    }

}

void heapSort(){
    for(int i=n/2-1;i>=0;i--){
        heapify(i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(fin[0],fin[i]);
        heapify(0,i);
    }
}

int findN(int a){
    for(int i=0;i<n;i++){
        if(ini[i]==a){
            return i;
        }
    }
}

void findLoop(int a,int b){
    while(a!=b){

        int c=findN(a);
        visited[c]=1;
        temp.push(c);
        a=fin[c];
    }

}

void temp2F(){
    if(!temp2.empty()){
        cnt++;
        res.push(temp2.size());
        res.push(-inf);
        while(!temp2.empty()){
            res.push(temp2.front());
            res.push(-inf);
            temp2.pop();
        }
        res.push(inf);
    }
}

int main(){
    freopen("sorting_by_sequence.txt","r",stdin);

    cin >> n;
    ini.resize(n);
    fin.resize(n);
    visited.resize(n,0);
    for(int i=0;i<n;i++){
        cin >> ini[i];
        fin[i]=ini[i];
    }
    heapSort();
    for(int i=0;i<n;i++){
        if(ini[i]!=fin[i] && visited[i]==0){



            temp.push(i);
            visited[i]=1;
            findLoop(fin[i],ini[i]);
            cnt++;
            res.push(temp.size());
            res.push(-inf);
            while(!temp.empty()){
                res.push(temp.front()+1);
                res.push(-inf); //-inf: space inf: endl;
                temp.pop();
            }
            res.push(inf);
            temp2F();



        }else if(ini[i]==fin[i]){
            if(!temp2.empty()){
                cnt++;
                res.push(temp2.size());
                res.push(-inf);
                res.push(temp2.front());
                res.push(inf);
                temp2.pop();
            }
            temp2.push(i+1);
        }
    }
    temp2F();
    cout << cnt << endl;
    while(!res.empty()){
        if(res.front()==inf){
            cout << endl;
        }else if(res.front()==-inf){
            cout << " ";
        }else{
            cout << res.front();
        }
        res.pop();

    }


    return 0;
}
