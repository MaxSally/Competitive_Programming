//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
    using namespace std;

struct node{
    struct node *child[26];
    int weight;
    int endW;


};

struct node *addNode(int weight){
    struct node *Node= new struct node;
    Node->endW=0;
    Node->weight=weight;
    for(int i=0;i<26;i++){
        Node->child[i]=NULL;
    }
    return Node;

};

void addWord(struct node *root,string s,int weight){
    int ch;
    struct node *temp=root;
    for(int i=0;i<s.length();i++){
        ch=s[i]-'a';
        if(temp->child[ch]==NULL){
            temp->child[ch]=addNode(weight);
        }
        temp=temp->child[ch];
        temp->weight=max(temp->weight,weight);
    }
    temp->endW=1;
    temp->weight=max(temp->weight,weight);

}

int findWord(struct node *root,string s){
    int ch;
    struct node *temp=root;
    for(int i=0;i<s.length();i++){
        ch=s[i]-'a';
        if(temp->child[ch]==NULL){
            return -1;
        }
        temp=temp->child[ch];
    }
    return temp->weight;

}



int main(){
    //freopen("input.txt","r",stdin);
    int n,q;
    cin >> n >> q;
    struct node *root=addNode(0);
    for(int i=0;i<n;i++){
        string s;
        int weight;
        cin >> s >> weight;
        addWord(root,s,weight);
    }
    for(int i=0;i<q;i++){
        string s;
        cin >> s;
        cout << findWord(root,s)<< endl;
    }

    return 0;
}
