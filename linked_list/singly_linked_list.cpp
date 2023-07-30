#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* next;
};

void push_bac(Node** head,int val){
    Node* node = new Node();
    node->value = val;
    node->next = NULL;
    // insert in empty list
    if(*head==NULL){
        *head = node;
        return;
    }

    Node* last = *head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = node;
    return;
}

void insert_after(Node* prev_node, int val){
    Node* node = new Node();
    node->value = val;
    node->next = prev_node->next;
    prev_node->next = node;
    return;
}

void delete_element(Node** head,int val){
    if(head==NULL) return;

    // store head pointer
    Node* temp = *head;

    if(temp->value==val){
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = new Node();
    while(temp!=NULL and temp->value!=val){
        prev = temp;
        temp = temp->next;
    }


    if(temp==NULL) return; // not found

    prev->next = temp->next;
    free(temp);
}

void print_list(Node *head){
    cout<<"Item in list : ";
    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 4;
    third->next = NULL;
    print_list(head);

    push_bac(&head,5);
    print_list(head);

    insert_after(second,3);
    print_list(head);

    delete_element(&head,4);
    print_list(head);



}
