//http://lightoj.com/volume_showproblem.php?problem=1129

#include<vector>
#include<stdio.h>
#include<iostream>
#include<string>
    using namespace std;

vector<string> list_number;
int ans=0;


struct node{
    struct node *child[10];
    int countLeaf;
};

struct node *newNode(){
    struct node *Node = new struct node;
    Node->countLeaf=0;
    for(int i=0;i<10;i++){
        Node->child[i]=NULL;
    }
    return Node;
}

void addNum(struct node *root,string b){
    struct node *temp=root;
    for(int i=0;i<b.length();i++){
        int k=b[i]-48;
        if(temp->child[k]==NULL){
            temp->child[k]=newNode();
        }
        temp=temp->child[k];

    }
    temp->countLeaf++;
}

bool checkChild(struct node *p){
    for(int i=0;i<10;i++){
        if(p->child[i]!=NULL){
            return false;
        }
    }
    return true;

}


bool check(struct node *root,string b){
    struct node *temp=root;
    for(int i=0;i<b.length();i++){
        temp=temp->child[b[i]-48];

    }
    if(checkChild(temp)){
        return false; // ko co dinh con
    }
    return true;

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
    freopen("consistency_checker_trie.txt","r",stdin);
    int t;
    cin >> t;

    for(int ii=0;ii<t;ii++){
        int n;
        cin >> n;
        struct node *root=newNode();
        list_number.clear();
        for(int i=0;i<n;i++){
            string a;
            cin >>a;
            list_number.push_back(a);
            addNum(root,a);
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(check(root,list_number[i])){
                flag=false;
            }
        }
        if(flag){
            cout << "Case " << ii+1 << ": YES"  << endl;
        }else{
            cout << "Case " << ii+1 << ": NO"  << endl;
        }
        deletenode(root);
    }
    return 0;
}


