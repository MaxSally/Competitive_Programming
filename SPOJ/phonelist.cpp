//https://www.spoj.com/problems/PHONELST/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
    using namespace std;

struct node{
    struct node *child[10];
    int endW;
    int cntW;
};

struct node *newNode(){
    struct node *Node= new struct node;
    Node-> endW=0;
    Node->cntW=0;
    for(int i=0;i<10;i++){
        Node->child[i]=NULL;
    }
    return Node;
};

void addNum(struct node *root, string b){
    struct node *temp=root;
    for(int i=0;i<b.length();i++){
        int k=b[i]-48;
        if(temp->child[k]==NULL){
            temp->child[k]=newNode();
        }
        temp=temp->child[k];
        temp->cntW++;
    }
    temp->endW++;
}

/*bool checkChild(struct node *p){
    for(int i=0;i<10;i++){
        if(p->child[i]!=NULL){
            return false;
        }
    }
    return true;

}*/


bool check(struct node *root, string b){
    struct node*temp=root;
    for(int i=0;i<b.length();i++){
        int k=b[i]-48;
        temp=temp->child[k];
    }
    if(temp->cntW==1){
        return true;
    }
    return false;
}

void deletenode(struct node *temp){
    for(int i=0;i<10;i++){
        if(temp->child[i]){
            deletenode(temp->child[i]);
            delete temp->child[i];
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        struct node *root=newNode();
        vector<string> store;
        for(int j=0;j<n;j++){
            string a;
            cin >> a;
            addNum(root,a);
            store.push_back(a);
        }
        bool flag=true;
        for(int j=0;j<n;j++){
            if(!check(root,store[j])){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        deletenode(root);
    }
    return 0;
}
