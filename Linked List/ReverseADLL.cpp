
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
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
void printDLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node* reverseDLL1(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    Node* point = head;
    while(point!=NULL){
        point->data = st.top();
        st.pop();
        point = point->next;
    }
    return head;
}
Node* reverseDLL2(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* last = nullptr;
    Node* current = head;
    while(current!=NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last->prev;
}

int main(){
    vector<int> arr = {2,5,7,8};
    Node* head = convert2DLL(arr);
    //head = reverseDLL1(head);
    head = reverseDLL2(head);
    printDLL(head);
}