//https://www.hackerrank.com/challenges/contacts/problem
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node {
	struct node *child[26];
	int weight;
	int endW;


};

struct node *addNode() {
	struct node *Node = new struct node;
	Node->endW = 0;
	Node->weight = 0;
	for (int i = 0; i<26; i++) {
		Node->child[i] = NULL;
	}
	return Node;

};

void addWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	for (int i = 0; i<s.length(); i++) {
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL) {
			temp->child[ch] = addNode();
		}
		temp = temp->child[ch];
		temp->weight += 1;
	}
	temp->endW = 1;
}

int findWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i<s.length(); i++) {
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL) {
			return 0;
		}
		temp = temp->child[ch];
	}
	return temp->weight;

}

int main() {
	//freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    struct node *root = addNode();
    for (int i = 0; i<n; i++) {
        string s,t;
        cin >> s >> t;
        if(s=="add"){
            addWord(root, t);
        }else{
            cout << findWord(root,t) << endl;
        }

    }
	return 0;
}

