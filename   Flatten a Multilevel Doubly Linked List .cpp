/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include<iostream>
using namespace std;

class Solution {
public:
    Node* travelNode(Node* prev, Node* curr)
    {
        if(!curr)
            return prev;
        prev->next = curr;
        curr->prev = prev;
        
        Node* tmp = curr->next;
        Node* child = travelNode(curr, curr->child);
        curr->child = NULL;
        return travelNode(child, tmp);
        
    }
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* pseudoHead = new Node(0, NULL, head, NULL);
        travelNode(pseudoHead, head);
        pseudoHead->next->prev = NULL;
        return pseudoHead->next;
        
    }
};