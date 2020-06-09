#define _CRT_SECURE_NO_WARNINGS
//http://codeforces.com/problemset/problem/490/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

/*void sort1(vector<pair<int,int> > &line,int left, int right){
if(left>right){
return;
}
int left1=left;
int right1=right;
int x=line[(left+right)/2].first;
while(left<=right){
while(line[left].first<x){
left++;
}
while(line[right].first>x){
right--;
}
if(left<=right){
pair<int,int> temp;
temp.first=line[left].first;
temp.second=line[left].second;
line[left].first=line[right].first;
line[left].second=line[right].second;
line[right].first=temp.first;
line[right].second=temp.second;
left++;
right--;
}
}
sort1(line,left1,right);
sort1(line,left,right1);
}


int binaryS(vector<pair<int,int> > line, int x,int left,int right){

if(left<=right){
int mid=(left+right)/2;
if(line[mid].first==x){
return mid;
}else if(line[mid].first<x){
return binaryS(line,x,mid+1,right);
}else {
return binaryS(line,x,left,mid-1);
}
}
return -1;
}*/

bool compare(int a, int b) {
	return a<b;
}

vector<int> parents;
int n;
int cnt = 0;
map<int, int> m1, m2;

int findSet(int u) {
	while (u != parents[u]) {

		u = findSet(parents[u]);
	}
	return u;
}

void unionSet(int a, int b) {
	int a1 = findSet(a);
	int b1 = findSet(b);
	if (a1 != b1) {
		parents[b1] = a1;
	}

}

int convert(int x) {
	if (m1.find(x) != m1.end()) {
		return m1[x];
	}
	m1[x] = cnt;
	m2[cnt] = x;
	cnt++;
	return cnt - 1;
}





int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	vector<int> line;
	line.resize(n + 2, 1e9);
	parents.resize(n + 2);

	for (int i = 0; i <= n+1; i++) {
		parents[i] = i;
	}
	//vector<pair<int,int> >lineI, lineD;
	for (int i = 0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		if (b == 0) {
			b = 1e9;
		}
		//cout << a << " " << b << endl;
		a = convert(a);
		b = convert(b);
		//cout << a << " " << b << endl;
		unionSet(a, b);
		line[a] = b;
	}

	vector<int> boss;
	for (int i = 0; i <= n+1; i++) {
		if (parents[i] == i) {
			boss.push_back(i);
		}
	}

	queue<int> q1, q2;
	int a;
	if (m2[boss[1]] == 0) {
		a = boss[0];
	}
	else {
		a = boss[1];
	}
	while (line[a] != 1e9) {
		if (m2[a] != 1e9 && m2[a] != 0) {
			q1.push(m2[a]);
		}
		a = line[a];
	}
	q1.push(m2[a]);
	if (m2[boss[1]] == 0) {
		a = boss[1];
	}
	else {
		a = boss[0];
	}
	while (line[a] != 1e9) {
		if (m2[a] != 1e9 && m2[a] != 0) {
			q2.push(m2[a]);
		}
		a = line[a];
	}
	q2.push(m2[a]);
	//sort1(lineI,0,n-1);

	//sort1(lineD,0,n-1);
	/*int cnt=1;
	int a=0;
	while(cnt<n){
	int temp=binaryS(lineI,a,0,lineI.size()-1);
	line[cnt]=lineI[temp].second;
	cnt=cnt+2;
	a=lineI[temp].second;

	}
	if((n % 2)==0){
	cnt=n-2;
	a=0;
	while(cnt>=0){

	int temp=binaryS(lineD,a,0,lineD.size()-1);

	line[cnt]=lineD[temp].second;
	cnt=cnt-2;
	a=lineD[temp].second;
	}
	}else{

	}*/

	for (int i = 0; i<n; i++) {
		if (i % 2 == 0) {
			cout << q1.front() << " ";
			q1.pop();
		}
		else {
			cout << q2.front() << " ";
			q2.pop();
		}
	}

	return 0;
}
