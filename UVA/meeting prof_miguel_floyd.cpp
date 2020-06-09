
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112

#include <set>

#include <algorithm>

#include <iostream>

#include <iterator>

#include <cstring>

#include <cstdio>

#include <vector>

#include <string>

#include <cmath>

#include <queue>

#include <climits>
    using namespace std;
int graphY[30][30],graphM[30][30];

const int inf=INT_MAX/2;
int res=inf;
int n;
char start,stop;
vector<int> vec;

void floyd(){
    for(int k=0;k<30;k++){
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                graphY[i][j]=min(graphY[i][j],graphY[i][k]+graphY[k][j]);
                graphM[i][j]=min(graphM[i][j],graphM[i][k]+graphM[k][j]);
            }
        }
    }
    /*for(int i=0;i<30;i++){
        cout << costSta[i] << " ";
    }
    cout << endl;
    for(int i=0;i<30;i++){
        cout << costSto[i] << " ";
    }
    cout << endl;*/
    res=inf;
    vec.clear();
    for(int i=29;i>=0;i--){

            if(graphY[((int)start)-65][i]+graphM[((int)stop)-65][i]<res){
                vec.clear();
                res=graphY[((int)start)-65][i]+graphM[((int)stop)-65][i];
                vec.push_back(i);
            }else if(graphY[((int)start)-65][i]+graphM[((int)stop)-65][i]==res){
                vec.push_back(i);
            }




    }
    sort(vec.begin(),vec.end());
}


int main(){
    freopen("meeting prof_miguel.txt","r",stdin);
    while(true){

        cin >> n;

        if(n==0){
            break;
        }
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                if(i==j){
                    graphY[i][j]=0;
                    graphM[i][j]=0;
                }else{
                    graphY[i][j]=inf;
                    graphM[i][j]=inf;
                }

            }
        }

        //-65 for index


        for(int i=0;i<n;i++){
            char ageN,direction,x,y;
            int energy;
            cin >> ageN >> direction >> x >> y >> energy;
            //cout << ageN << direction << x << y << energy << endl;
            if(ageN=='Y'){
                graphY[((int)x) -65][((int)y)-65]=min(energy,graphY[((int)x) -65][((int)y)-65]);
                if(direction=='B'){
                    graphY[((int)y) -65][((int)x)-65]=min(energy,graphY[((int)y) -65][((int)x)-65]);
                }
            }else{
                graphM[((int)x) -65][((int)y)-65]=min(energy,graphM[((int)x) -65][((int)y)-65]);
                if(direction=='B'){
                    graphM[((int)y) -65][((int)x)-65]=min(energy,graphM[((int)y) -65][((int)x)-65]);
                }
            }
        }


        cin >> start >> stop;

        floyd();

        if(res==inf){
            cout << "You will never meet." << endl;
        }else{
            cout << res;
            for(int i=0;i<vec.size();i++){
                cout << " " << (char) (vec[i]+65);
            }
            cout << endl;
        }



    }
    return 0;
}
