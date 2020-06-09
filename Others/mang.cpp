#include <iostream>
using namespace std;

int main()
{
    /*int a[10];
    int b=0;
    for (int i =0;i<10;i++){
        cin >> a[i];
    }
    for( int i =0;i<10;i++){
        b=b+a[i];
    }
    cout << b;

    int* a;
    int b=0;
    a= new int [10];
    for (int i =0;i<10;i++){
        cin >> a[i];
    }
    for( int i =0;i<10;i++){
        b=b+a[i];
    }
    cout << b;
    delete[]a;
    return 0;*/

    /*int a[3][3];
    for( int dong=0;dong<3;dong++){
        for(int cot=0;cot<3;cot++){
            cin >> a[dong][cot];
        }
    }
    for( int dong=0;dong<3;dong++){
        for(int cot=0;cot<3;cot++){
            cout << a[dong][cot] << " ";

        }
        cout << endl;
    }
    for( int i=0;i<3;i++){
        delete[]a[i];
    }*/
    int a[5];
    for (int i =0;i<5;i++){
        cin >> a[i];
    }
    for(int i=3;i<5;i++){
        a[i-1]=a[i];
    }
    for (int i =0;i<4;i++){
        cout << a[i];
        cout << " ";
    }
    //a[5]=0;
    //delete[]a;
    return 0;


}

