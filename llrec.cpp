#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    //base case: reach the end of og list
    if(head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* next = head->next;
    head -> next = nullptr;

    llpivot(next, smaller, larger, pivot);

    if (head->val > pivot){
        head->next = larger;
        larger = head;
    }else{
        head->next = smaller;
        smaller = head;
    }

    head = nullptr;

}
