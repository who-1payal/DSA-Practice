#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cout<<"Enter Number: ";
    cin>>n;
    int i ;
    cout<<"Enter ith bit: ";
    cin>>i;
    int x = 1<<i;
    int res = n&x;
    if(res==0) cout<<"False";
    else cout<<"True";
}
