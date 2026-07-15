#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2LL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* deletehead(Node* head){
    if(head==NULL)return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
} 
void printLL(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
Node* deletetail(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deleteKthElement(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* deleteElement(Node* head,int val){
    if(head==NULL) return head;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,5,7,11};
    Node* head = convert2LL(arr);
    //head = deletehead(head);
    //head = deletetail(head);
    //head = deleteKthElement(head,3); 
    head = deleteElement(head,5);
    printLL(head);
}