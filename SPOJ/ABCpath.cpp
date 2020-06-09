//http://www.spoj.com/problems/ABCPATH/


#include<iostream>
#include<stdio.h>
    using namespace std;
char matrix[55][55];
bool visited[55][55];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={0,1,-1,1,-1,0,1,-1};
int h,w;
char dal[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


int DFS(int x, int y,int index){
    visited[x][y]=1;
    int cnt=0;
    for(int i=0;i<8;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0 && y1>=0 && x1<h && y1<w && visited[x1][y1]==0 && dal[index+1]==matrix[x1][y1]){
            int temp=DFS(x1,y1,index+1);
            if(cnt<temp){
                cnt=temp;
            }



        }


    }
    //visited[x][y]=0;
    return 1+cnt;

}

int main(){
    freopen("ABCpath.txt","r",stdin);
    int test=1;
    while(true){
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
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(matrix[i][j]=='A'){

                    int temp=DFS(i,j,0);
                    if(res<temp){

                        res=temp;
                    }
                }
            }
        }
        cout << "Case " << test<< ": " << res << endl;
        test++;




    }
    return 0;
}

