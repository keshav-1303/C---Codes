// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=1&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan

/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node* uniqueSortedList(Node* head) {

    if(head == NULL)    return head;
    
    Node* prev = head;
    Node* curr = head->next;

    while(curr != NULL){

        if(prev->data == curr->data){
            Node* forward = curr->next;
            prev->next = curr->next;
            curr->next = NULL;
            curr = forward;
        }

        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
