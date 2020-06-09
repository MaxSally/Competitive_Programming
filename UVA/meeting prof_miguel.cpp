//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;


const int inf=1e9;
vector<int> qRes;
int res=inf;
int costSta[30],costSto[30];
int n;

void dijkstra(int start, int stop, char age[30][30], vector<pair<int,int> > graph[30]){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    costSta[start]=0;
    while(!pq.empty()){
        int a=pq.top().first;
        int b=pq.top().second;
        pq.pop();
        for(int i=0;i<graph[b].size();i++){
            if(age[b][graph[b][i].second]=='Y' && a+graph[b][i].first<costSta[graph[b][i].second]){
                costSta[graph[b][i].second]=a+graph[b][i].first;
                pq.push(make_pair(costSta[graph[b][i].second],graph[b][i].second));
            }
        }
    }
    pq.push(make_pair(0,stop));
    costSto[stop]=0;
    while(!pq.empty()){
        int a=pq.top().first;
        int b=pq.top().second;
        pq.pop();
        for(int i=0;i<graph[b].size();i++){
            if(age[b][graph[b][i].second]=='M' && a+graph[b][i].first<costSto[graph[b][i].second]){

                costSto[graph[b][i].second]=a+graph[b][i].first;
                pq.push(make_pair(costSto[graph[b][i].second],graph[b][i].second));
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
    qRes.clear();
    for(int i=0;i<n;i++){

        if(costSta[i]+costSto[i]<res){
            qRes.clear();
            res=costSta[i]+costSto[i];
            qRes.push_back(i);
        }else if(costSta[i]+costSto[i]==res){
            qRes.push_back(i);
        }
        //cout << res << endl;;

    }
}


int main(){
    freopen("meeting prof_miguel.txt","r",stdin);
    while(true){

        cin >> n;

        if(n==0){
            break;
        }
        char age[30][30];
        vector<pair<int,int> > graph[30];
        //-65 for index

        for(int i=0;i<30;i++){
            costSta[i]=inf;
            costSto[i]=inf;
        }
        for(int i=0;i<n;i++){
            char ageN,direction,x,y;
            int energy;
            cin >> ageN >> direction >> x >> y >> energy;
            //cout << ageN << direction << x << y << energy << endl;
            age[(int) x - 65][(int) y - 65]=ageN;
            graph[(int) x - 65].push_back(make_pair(energy,(int) y - 65));
            if(direction=='B'){
                graph[(int) y - 65].push_back(make_pair(energy,(int) x - 65));
                age[(int) y - 65][(int) x - 65]=ageN;
            }
        }

        char start,stop;
        cin >> start >> stop;

        dijkstra((int) start -65,(int) stop -65,age,graph);

        if(res==inf){
            cout << "You will never meet." << endl;
        }else{
            cout << res;
            for(int i=0;i<qRes.size();i++){
                cout << " "<<(char) (qRes.front()+65);

            }
            cout << endl;
        }



    }
    return 0;
}
