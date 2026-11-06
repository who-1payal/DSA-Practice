#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    string res = "";
    while(n!=1){
        res+= to_string(n%2);
        n = n/2;
    }
    res+= "1";
    string reverse = "";
    for(int i=res.length()-1;i>=0;i--){
        reverse+=res[i];
    }
    cout<<"Binary representation: "<< reverse<<endl;
}