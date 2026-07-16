#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
void printDLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node* convert2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;  
    }
    Node* prev = temp->prev;
    prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}
Node* removeKthElement(Node* head,int k){
    if(head==NULL)return NULL;
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        if(count==k)break;
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
            
    if(back==NULL && front == NULL)return NULL;
    else if(back==NULL) return deleteHead(head);
    else if(front==NULL) return deleteTail(head);
    back->next = front;
    front->prev = back;
    temp->prev = nullptr;
    temp->next = nullptr;
        
    delete temp;
    return head;
}
void deleteNode(Node* temp){
    Node* back = temp->prev;
    Node* front = temp->next;
    if(front==NULL){
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;
    temp->next = temp->prev = nullptr;
    delete temp;
}
Node* insertBeforeHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    temp->prev = nullptr;
    head->prev = temp;
    return temp;
}
Node* insertBeforeTail(Node* head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* element = new Node(val,temp,back);
    back->next = element;
    temp->prev = element;
    return head;
}
Node* insertBeforeKthElement(Node* head, int k,int val){
    if(head==NULL)return NULL;
    if(k==1)return insertBeforeHead(head,val);
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k){
            Node* back = temp->prev;
            Node* newNode = new Node(val,temp,back);
            back->next = newNode;
            temp->prev = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node* insertBeforeNode(Node* node, int val){
    Node* back = node->prev;
    Node* newNode = new Node(val,node,back);
    back->next = newNode;
    node->prev = newNode;
}
int main(){
    vector<int> arr = {2,5,7,8};
    Node* head = convert2DLL(arr);
    //head = deleteHead(head);
    //head = deleteTail(head);
    //head = removeKthElement(head,3);
    //deleteNode(head->next);
    //head = insertBeforeHead(head,1);
   // head = insertBeforeTail(head,4);
   // head = insertBeforeKthElement(head,3,9);
    insertBeforeNode(head->next,3);
    printDLL(head);
}