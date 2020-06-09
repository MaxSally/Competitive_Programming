#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
    using namespace std;

vector<int> a;

int maxN(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

vector<int> Merge(vector<int> &b, vector<int> &c){
    int i,j;
    i=0;
    j=0;
    /*for(int i=0;i<b.size();i++){
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i=0;i<c.size();i++){
        cout << c[i] << " ";
    }

    cout << endl;*/
    vector<int> ans;
    while(i< b.size() && j< c.size()){
        if(b[i]<c[j]){
            ans.push_back(b[i]);
            i++;
        }else{
            ans.push_back(c[j]);
            j++;
        }
    }
    if(i<b.size()){
        for(i;i<b.size();i++){
            ans.push_back(b[i]);
        }
    }else if(j<c.size()){
        for(j;j<c.size();j++){
            ans.push_back(c[j]);
        }
    }
    return ans;

}


vector<int> MergeSort(int l, int r){
      if (l == r) {
        vector<int> ans;
        ans.push_back(a[l]);
        return ans;
      }
      int mid = (l + r) / 2;
      vector <int> b, c, d;
      b = MergeSort(l, mid);
      c = MergeSort(mid + 1, r);
      d = Merge(b, c);
      return d;
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    /*for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;*/
    vector<int> temp = MergeSort(0,a.size()-1);
    temp[0]=1;
    for(int i=1;i<n;i++){
        if(temp[i]-1>temp[i-1]){
            temp[i]=temp[i-1]+1;
        }

    }
    cout << temp[temp.size()-1]+1;
    return 0;

}
