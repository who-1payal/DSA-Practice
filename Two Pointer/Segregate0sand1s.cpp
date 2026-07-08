#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter elements of the array: ";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int i = 0;
    int j = n-1;
    while(i<j){
        while(i<j && arr[i]==0){
            i++;
        }
        while(i<j && arr[j]==1){
            j--;
        }
        if(arr[i]==1 && arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}