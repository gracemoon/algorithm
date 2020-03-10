#ifndef LIST
#define LIST
typedef struct ListNode {
	int value;
	struct ListNode *next;
}ListNode;

void traversalListNode(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->value);
        temp=temp->next;
    }
};

#endif