/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// 采用冗余节点的做法，程序写的时候比较优雅
class Solution {
public:
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
    
    void helper(Node* root){
        if(root==nullptr)
            return;
        
        Node dummy(-1);
        Node *dummyPtr = &dummy;
        Node *ptr = root;
        
        while(ptr!=nullptr){
            if(ptr->left){
                dummyPtr->next = ptr->left;
                dummyPtr = dummyPtr->next;
            }
            if(ptr->right){
                dummyPtr->next = ptr->right;
                dummyPtr = dummyPtr->next;
            }
            ptr = ptr->next;
        }
        dummyPtr->next = nullptr; 
        
        if(dummy.next)
            helper(dummy.next);
    }
};



// 不采用冗余节点，省一点空间，但是写程序还要分情况讨论
class Solution {
public:
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
    
    void helper(Node* root){
        if(root==nullptr)
            return;
        
        Node *head = nullptr, *curPtr=nullptr;
        Node *ptr = root;
        
        while(ptr!=nullptr){
            if(ptr->left){
                if(head==nullptr){
                    head = ptr->left;
                    curPtr = head;
                }
                else{
                    curPtr->next = ptr->left;
                    curPtr=curPtr->next;
                }
            }
            if(ptr->right){
                if(head==nullptr){
                    head = ptr->right;
                    curPtr = head;
                }
                else{
                    curPtr->next = ptr->right;
                    curPtr=curPtr->next;
                }
            }
            ptr = ptr->next;
        }
        if(curPtr)
            curPtr->next = nullptr; 
        
        if(head)
            helper(head);
    }
    
};