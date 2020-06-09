#include<vector>
#include<queue>
#include<iostream>
//#include<stdio.h>
#include<cstdio>

    using namespace std;

int main(){
    freopen("makeMaze.txt","r",stdin);
    int z1;
    cin >> z1;


    vector<int> x1,y1;
    x1.resize(4);
    y1.resize(4);
    x1[0]=0;
    x1[1]=0;
    y1[0]=1;
    y1[1]=-1;
    x1[2]=1;
    x1[3]=-1;
    y1[2]=0;
    y1[3]=0;
    for(int z=0;z<z1;z++){
        vector< vector<int> > v;
        vector< vector<int> > vs;
        int n,m,cnt,boole;
        cnt=0;
        cin >> m>> n;
        //vector< vector<int> > v;
        vector<int> index;
        index.resize(4);
        queue<int> q;
        v.resize(m);
        vs.resize(m);
        for(int i=0;i<m;i++){
            vs[i].resize(n);
            v[i].resize(n);
            for(int j=0;j<n;j++){
                vs[i][j] = 0;
                char c;
                cin >> c;

                if(c=='#'){
                    v[i][j]=1;
                }else{
                    v[i][j]=0;
                    if(i==0 || i==m-1 || j==0 || j==n-1){
                        cnt++;
                        if(cnt<=2){
                            index[2*cnt-2]=i;
                            index[2*cnt-1]=j;
                        }


                    }

                }
            }
        }

        boole=0;
        if(cnt!=2){
            cout << "invalid"<< endl;
        }else{
            q.push(index[0]*m+index[1]);
            vs[index[0]][index[1]] = 1;

            while(true){
                int x,y;
                x=q.front();
                y = x%m;
                x = (x-y)/m;

                if(x == index[2] && y == index[3])
                {
                    cout<<"valid"<<endl;
                    break;
                }
                q.pop();

                for(int i=0;i<4;i++){
                    int g=x+x1[i];
                    int h=y+y1[i];
                    if(g>=0 && g<m && h>=0 && h<n  && v[g][h]==0 && vs[g][h]==0){
                        vs[g][h] = 1;

                        q.push(g*m+h);

                    }
                }
                if(q.empty()==true){
                    cout << "invalid" << endl;
                    break;
                }
            }

        }



    }
    return 0;
}
