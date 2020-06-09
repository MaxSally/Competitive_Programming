#include <iostream>
using namespace std;

double a[5005];

int main(){
    freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	double res = -1;
	for(int i = 1; i <= n; i++){
		double t = 0;
    	for(int j = i; j <= n; j++){
    		t += a[j];
    		if(j - (i - 1) >= k){
    			res = max(res, t / (1.0 * (j - (i - 1))));
			}
		//	cout << t << " " << j - (i - 1) << endl;
		}
	//	cout << endl;
	}
	printf("%.6lf\n", res);
    return 0;
}
