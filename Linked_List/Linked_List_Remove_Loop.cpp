// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
#include <map>

bool detect_cycle(Node* head){

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && slow != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)    return 1;
    }
    return 0;
}

Node *removeLoop(Node *head){

    if(!detect_cycle(head)){
        return head;
    }

    map<Node*, bool> visited;

    Node* p = head;

    while(1){

        if(visited[p->next] == 1){
            p->next = NULL;
            break;
        }

        visited[p] = 1;
        p = p->next;
    }

    return head;
}