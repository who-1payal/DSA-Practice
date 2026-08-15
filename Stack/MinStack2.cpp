/*Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    
    stack<int> st;
    int min_el = INT_MAX;
    public:
    void push(int value){
        if(st.empty()|| value >= min_el){
            st.push(value);
        }
        else{
            st.push(2*value - min_el);
        }
        min_el = min(min_el,value);
    }

    void pop(){
        if(st.top() >= min_el){
            st.pop();
        }
        else{
            min_el = 2 * min_el - st.top();
            st.pop();
        }
    }

    int top(){
        if(st.empty()) return -1;
        int top_el = st.top();
        if(st.top() >= min_el){
            return top_el;
        }
        else{
            top_el = 2*min_el - st.top();
        }
        return top_el;
    }

    int getMin(){
        if(st.empty())return -1;

        return min_el;
    }

};

int main(){
    Solution* s = new Solution();
    int input;
    while(true){
        cin>>input;
        if(input==-1)break;
        s->push(input);
    }
    cout<<s->getMin()<<endl;
    return 0;
}