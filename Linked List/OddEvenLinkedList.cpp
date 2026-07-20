/*Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 
Constraints:
The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
*/

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