//https://www.urionlinejudge.com.br/judge/en/problems/view/1610

#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;
int m,n;
vector<int> matrix[10010];
// vector<vector<int>> matrix(10010);
int inPath[10001];
bool  visited[10001];

bool DFS(int start){
    visited[start]=1;
    inPath[start]=1;
    int len = matrix[start].size();
    //cout<<len<<endl;
    for(int i=0;i<len;i++){
        if(visited[matrix[start][i]]==0){
            if(DFS(matrix[start][i])==1){
                return 1;
            }
        }else {
            if(inPath[matrix[start][i]]==1){
                return 1;
            }
        }
    }
    inPath[start]=0;
    return 0;

}
int main(){
    //freopen("dudu_service_maker.txt","r",stdin);
    int t;
    cin >>t;
    for(int ii=0;ii<t;ii++){
        cin >>n >>m;
        for(int i=1;i<=n;i++){
            visited[i]=0;
            inPath[i]=0;
            matrix[i].clear();
        }

        for(int i=0;i<m;i++){
            int temp,temp1;
            cin >> temp >> temp1;
            matrix[temp].push_back(temp1);
        }
       bool flag=0;
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                //in();
                //cout<<i<<" in DFS"<<endl;
                if(DFS(i)==1){
                    //cout<< i << " ";
                    cout << "SIM" << endl;
                    flag=1;
                    break;
                }

            }
        }
        if(flag==0){
            cout << "NAO" << endl;
        }


    }
    return 0;
}


//http://www.cplusplus.com/reference/list/list/size/
