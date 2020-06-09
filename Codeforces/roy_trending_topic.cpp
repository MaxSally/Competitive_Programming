//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/description/

#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;


struct topic{
    long long id;
    long z_score;
    long new_z;
    long change_z;

    topic(long long id1, long z_score1, long new_z1, long change_z1){
        this->id=id1;
        this->z_score=z_score1;
        this->new_z=new_z1;
        this->change_z=change_z1;
    }
    /*bool operator== (topic a,topic b){
        if(a.i==b.id){
            return true;
        }else{
            return false;
        }
    }
    bool operator> (topic a, topic b){
        if(a.change_z>b.change_z){
            return true;
        }else if(a.change_z==b.change_z){
            if(a.id>b.id){
                return true;
            }else{
                return false;
            }
        }else {
            return false;
        }
    }
    topic compare3(topic a, topic b, topic c){
        if(a>b && a>c){
            return a;
        }
        if(b>a && b>c){
            return b;
        }
        if(c>b && c>a){
            return c;
        }
    }*/
};

vector<topic> vec;



void heapify(int i,int n){
    int smallest=i;
    int a=2*i+1;
    if(a<n && vec[a].change_z< vec[smallest].change_z){
        smallest=a;
    }else if(a<n && vec[a].change_z == vec[smallest].change_z){
        if(vec[a].id<vec[smallest].id){
            smallest=a;
        }

    }
    if((a+1)<n && vec[a+1].change_z<vec[smallest].change_z){
        smallest=a+1;
    }else if((a+1)<n && vec[a+1].change_z == vec[smallest].change_z){
        if(vec[a+1].id<vec[smallest].id){
            smallest=a+1;
        }

    }
    if(i!=smallest){
        swap(vec[i],vec[smallest]);
        heapify(smallest,n);
    }

}

void buildHeap(){
    for(int i=vec.size()/2-1;i>=0;i--){

        heapify(i,vec.size());
    }
}

void heapSort(){
    buildHeap();
    for(int i=vec.size()-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(0,i);
    }

}

void print(){
    for(int i=0;i<vec.size();i++){
       cout << vec[i].id << " " << vec[i].change_z << endl;
    }
}


int main(){
    freopen("roy_trending topic.txt", "r", stdin);
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        long long a;
        long b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        topic A(a,b,(50*c+5*d+10*e+20*f),(50*c+5*d+10*e+20*f)-b);
        vec.push_back(A);
    }
    heapSort();
    for(int i=0;i<5;i++){
        cout << vec[i].id << " " << vec[i].new_z << endl;
    }

    //print();
    //cout << vec[0].id << " " << vec[0].new_z << endl;


    return 0;
}
