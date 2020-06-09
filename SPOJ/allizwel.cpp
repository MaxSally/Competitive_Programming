//http://www.spoj.com/problems/ALLIZWEL/

#include<iostream>
#include<stdio.h>
    using namespace std;
char matrix[110][110];
bool visited[110][110];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={0,1,-1,1,-1,0,1,-1};
int h,w;
char dal[10]={'A','L','L','I','Z','Z','W','E','L','L'};


bool DFS(int x, int y,int index){
    visited[x][y]=1;
    for(int i=0;i<8;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0 && y1>=0 && x1<h && y1<w && visited[x1][y1]==0 && dal[index+1]==matrix[x1][y1]){
            if(index+1==9){
                return 1;
            }
            if(DFS(x1,y1,index+1)==1){
                return 1;
            }

        }


    }
    visited[x][y]=0;
    return 0;

}

int main(){
    freopen("allizwel.txt","r",stdin);
    int test;
    cin >> test;
    for(int i=0;i<test;i++){

        int res=0;

        cin >> h >>w;
        if(h==0 && w==0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> matrix[i][j];
                visited[i][j]=0;
            }
        }

        bool flag=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(matrix[i][j]=='A'){

                    if(DFS(i,j,0)==1){
                        flag=1;
                        cout << "YES" << endl;
                        break;

                    }

                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==0){
            cout << "NO" << endl;
        }
    }
    return 0;
}

