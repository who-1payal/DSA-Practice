#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int target;
    vector <int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the target value: ";
    cin>>target;
    int i = 0;
    int sum = 0;
    int j = n-1;
    while(i<j){
        sum = arr[i]+arr[j];
        if(sum==target){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            break;

        }
        else if(sum<target){
            i++;
        }
        else if(sum>target){
            j--;
        }
    }
    return 0;   
}
