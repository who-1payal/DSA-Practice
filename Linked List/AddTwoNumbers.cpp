/* Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
}

Node* addTwoLL(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    int carry = 0;
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        Node* newNode = new Node( sum % 10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}


int main(){
    vector<int> arr1 = {2,4,5,6};
    vector<int> arr2 = {3,4,5};
    Node* head1 = convertToLL(arr1);
    Node* head2 = convertToLL(arr2);
    Node* head = addTwoLL(head1,head2);
    printLL(head);

}