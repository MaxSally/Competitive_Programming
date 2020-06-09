#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct point
{
	int x,y;
	bool operator< (point a)
	{
		return (this->x + this->y)<(a.x + a.y);
	}
	point operator+ (point a)
	{
		point temp;
		temp.x = this->x + a.x;
		temp.y = this->y + a.y;
		return temp;
	}
	point()
	{
		this->x = 0;
		this->y = 0;
	}
	point(int xx, int yy)
	{
		this->x = xx;
		this->y = yy;
	}
};
 
int test,m,n;
vector< vector <char> > matrix(22,vector<char>(22));
vector< vector <bool> > visited(22,vector<bool>(22));
vector< pair<int,int> > index;
 
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
 
bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}
 
bool BFS()
{
	// node temp;
	// node temp2;
	// temp < temp2
	// temp.x = j;
	//temp.y = k;
	// index.push_back(temp);
	// index.push_back((node){j,k});
	queue<pair<int,int> >q;
	q.push(index[0]);
	visited[index[0].first][index[0].second] = 1;
	while(q.size())
	{
		int x,y;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int j = 0 ; j < 4 ; j++ )
		{
			int xx,yy;
			xx = dx[j]+x;
			yy = dy[j]+y;
			if(xx>=0 && xx < m && yy >=0 && yy < n)
			{
				if(matrix[xx][yy] == '.' && !visited[xx][yy])
				{
					visited[xx][yy] = 1;
					if(xx==index[1].first && yy==index[1].second)
					{
						return true;
					}
					q.push(make_pair(xx,yy));
					// pair<int,int> (j,k);
				}
			}
		}
	}
	return false;
}
 
int main()
{
	point A(0,2);
	point B(3,4);
	point C;
	C = A+B;
	cout << C.x << " "<< C.y<<endl;
 
	cin >> test;
	for(int i = 0 ; i < test ; i++)
	{
		cin >> m >> n;
		index.clear();
		for(int j = 0 ; j < m ; j++)
		{
			for(int k = 0 ; k < n ; k++)
			{
				visited[j][k] = 0;
				cin >> matrix[j][k];
				if(matrix[j][k]=='.')
				{
					if(j == 0 || j == m - 1 || k == 0 || k == n-1)
					{
						index.push_back(make_pair(j,k));
					}
				}
			}
		}
 
		if(index.size()!=2)
		{
			cout<<"invalid\n";
		}
		else
		{
			if(BFS()==true)
			{
				cout<<"valid\n";
			}
			else
			{
				cout<<"invalid\n";
			}
		}
	}
 
	return 0;
}
