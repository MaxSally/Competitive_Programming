//https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

 int a[105];

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ii=0;ii<t;ii++){
        int n;
        scanf("%d",&n);

        a[n]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i+=2){
            if(a[i]!=a[i+1]){
                printf("%d \n",a[i]);
                break;
            }
        }
    }
    return 0;
}
