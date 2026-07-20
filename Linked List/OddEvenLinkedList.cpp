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

Node* OddEven(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp)arr.push_back(temp->data);

    Node* temp2 = head->next;
    while(temp2!=NULL && temp2->next!=NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next->next;
    }
    if(temp2)arr.push_back(temp2->data);

    Node* temp3 = head;
    while(temp3!=NULL){
        for(int i = 0; i<arr.size();i++){
            temp3->data = arr[i];
            temp3 = temp3->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convert2LL(arr);
    head = OddEven(head);
    printLL(head);
}