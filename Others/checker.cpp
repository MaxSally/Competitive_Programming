#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<fstream>
using namespace std;

// argc: so tham so command line
// argv[]: danh sach tham so
// argv[0]: chinh no (ten file)
// argv[1] ... argv[argc - 1]
/* CMS:
 checker input:
    argv[1]: file arrInput
    argv[2]: file correct output (dap an de bai)
    argv[3]: file contestant output
 checker output:
    standard output: point (0.0 - 1.0)
    standard error: message
*/


// cin: standard input
// cout: standard output
// cerr: standard error

string stdinput, stdoutput, contestant_output;
vector<int> arrInput, arrOutput, arrCorrectOutput;

bool compare(int a,int b){
    return a<b;
}

void printResult(double point, string message) {
    cout << point;
    cerr << message;
    exit(0);
}



void check_triplet(){
    vector<int> output;

    /*int n=stdinput.length();
    for(int i=2;i<n;i++){
        if(stdinput[i]!=' '){
            arrInput.insert(stdinput[i]-'0');
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(stdoutput[i]!=' '){
            arrOutput.push_back(contestant_output[i]-'0');
            sum+=contestant_output[i]-'0';
        }
    }*/
    if (arrCorrectOutput.size() == 1) {
        if (arrOutput.size() != 1 || arrOutput[0] != -1) {
            printResult(0, "Wrong answer");
        }
        printResult(1, "Accepted");
    }


    if (arrOutput.size() != 3) {
        printResult(0, "Wrong answer\nExpected: 3 elements\nFound: " + to_string(arrOutput.size()) + " elements");
    }

    int sum=0;
    for(int i=0;i<3;i++){
        sum+=arrOutput[i];
    }
    sort(arrInput.begin(),arrInput.end(),compare);
    sort(arrOutput.begin(),arrOutput.end(),compare);
    double ans=1.0;
    if(sum!=0){
        printResult(0, "Wrong answer");
    }
    int it=0;
    for(int i=0;i<arrOutput.size();i++){
        while(arrInput[it]<arrOutput[i] && it < arrInput.size()){
            it++;
        }
        if(it>=arrInput.size()){
            printResult(0, "Wrong answer");
        }
        if(arrInput[it]==arrOutput[i]){
            it++;
            continue;
        }else{
            printResult(0, "Wrong answer");
        }
    }
   printResult(1.0, "Accepted");
}

void inputstd(string filename){
    ifstream is;
    is.open(filename);
    int n;
    is >> n;
    for(int i=0; i<n; i++){
        int a;
        is >> a;
        arrInput.push_back(a);
    }
    is.close();
}

void correctOutput(string filename){
    ifstream is;
    is.open(filename);
    int a;
    while (is >> a) {
        arrCorrectOutput.push_back(a);
    }
    is.close();
}

void contestantstdout(string filename){
    ifstream is;
    is.open(filename);
    int a;
    while (is >> a) {
        arrOutput.push_back(a);
    }
    is.close();
}


int main(int argc, char* argv[]){
    //freopen("input.txt","r",stdin);
    inputstd(argv[1]);
    correctOutput(argv[2]);
    contestantstdout(argv[3]);
    check_triplet();

    return 0;
}

