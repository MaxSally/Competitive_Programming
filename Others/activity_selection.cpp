#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > activity;
int n;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int printMaxActivities(){
    int currentClass = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (activity[i].first >= activity[currentClass].second ){
            cnt++;
            currentClass = i;
        }
    }
    return cnt;
}

int main(){
    freopen("input.txt","r",stdin);
	cin >> n;
	for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        activity.push_back(make_pair(a,b));
	}
	sort(activity.begin(), activity.end(), compare);
	cout << printMaxActivities();
	return 0;
}

