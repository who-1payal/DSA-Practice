#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    int i;
    cout<<"Enter ith Bit: ";
    cin>>i;
    int x = 1<<i;
    int res = x|n;
    cout<<res<<endl;
}
