#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cout<<"Enter Binary Number: ";
    cin>>n;
    int len = n.length();
    int res = 0;
    int p = 0;
    for(int i = len-1; i>=0;i--){
        res+=(n[i]-'0')*(pow(2,p));
        p++;
    }
    cout<<"Decimal Representation:"<<res<<endl;
}