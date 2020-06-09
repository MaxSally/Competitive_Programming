//http://www.spoj.com/problems/MKJUMPS

#include<vector>
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

bool matrix[10][10];
bool visited[10][10];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,-2,2,-2,2,-1,1};


int DFS(int x,int y){
    int cnt=0;
    visited[x][y]=1;
    for(int i=0;i<8;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0 && y1>=0 && x1<10 && y1<10 && matrix[x1][y1]==1 && visited[x1][y1]==0){

            int temp=DFS(x1,y1);
            if(cnt<temp){
                cnt=temp;
            }

        }
    }
    visited[x][y]=0;
    return cnt+1;
}

/*
psuedo code :

int DFS(int x, int y):
    int cnt = 0;
    visited[x][y] = true;
    for all valid cells [x1,y1]:
        cnt = max(cnt,DFS(x1,y1))
    visited[x][y] = false;
    return cnt+1;
*/


int main(){
    int numberTestCase=0;
    while(true){
        numberTestCase++;
        int n,x,y,totalSquare;
        totalSquare=0;
        cin >> n;
        if(n==0){
            break;
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matrix[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){

            int temp, temp1;
            cin >> temp >> temp1;
            totalSquare+=temp1;
            if(i==0){
                x=0;
                y=temp;
            }

            for(int j=0;j<temp1;j++){
                matrix[i][temp+j]=1;
            }

        }
        int res=totalSquare-DFS(x,y);

        if(res==1){
            cout << "Case "<< numberTestCase << ", " << res << " square can not be reached." << endl;
        }else{
            cout << "Case "<< numberTestCase << ", " << res << " squares can not be reached." << endl;
        }


        /*for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout << x <<" "<< y;*/
    }


    return 0;
}
