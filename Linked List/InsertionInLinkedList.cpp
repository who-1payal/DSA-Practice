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
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}
Node* insertTail(Node*head,int val){
    if(head==NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* element = new Node(val);
    temp->next = element;
    return head;
}
Node* insertAtPosition(Node*head,int val,int k){
    if(head==NULL){
        if(k==1){
            Node* newNode = new Node(val);
            return newNode;
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el, int val){
    if(head==NULL)return NULL;
    if(head->data == val){
        return new Node(el,head);
    }
    Node* temp = head;
    bool found = false;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found==false){
        cout<<"The given value does not exist in the Linked List.";
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,7,11};
    Node* head = convert2LL(arr);
    head = insertHead(head,100);
    head = insertTail(head,22);
    head = insertAtPosition(head,34,3);
    head = insertBeforeValue(head,23,7);
    printLL(head);
}
