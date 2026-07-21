/*Sort a linked list of 0s, 1s and 2s
Problem Statement:
Given the head of a linked list where every node contains either 0, 1, or 2, sort the linked list in non-decreasing order.

Example:

Input:
1 -> 2 -> 0 -> 1 -> 2 -> 0

Output:
0 -> 0 -> 1 -> 1 -> 2 -> 2*/

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* sortLL(Node* head){
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(temp!=NULL){
        if(temp->data == 0)cnt0++;
        else if(temp->data==1)cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    Node* head = convert2LL(arr);
    head = sortLL(head);
    printLL(head);
}