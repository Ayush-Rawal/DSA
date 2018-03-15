#include<stdio.h>
#include<stdlib.h>

// Q3. Reverse a singly linked list

typedef struct LinkedList {
	int data;
	struct LinkedList *next;
} node;

node *head = NULL;

node* createNode()
{
	node *temp = (node *)calloc(1,sizeof(node));
	if(temp == NULL){
		printf("\nAllocation failed, exiting.\n");
		exit(1);
	}
	return temp;
}

void BulkInsertNodes(unsigned int n, int data[])
{
	node *prevNode = NULL;
	for(register unsigned int i = 0;i<n;i++){
		node *temp = createNode();
		temp->data = data[i];
		temp->next = NULL;
		if(head == NULL){
			head = temp;
		}
		else {
			prevNode->next = temp;
		}
		prevNode = temp;
	}
}

void Initialize()
{
	if(head != NULL){
		printf("A list already exists\n");
		return;
	}
	unsigned int n;
	printf("\nHow many nodes do you wish to enter?\n");
	scanf("%d",&n);
	int *data = calloc(n,sizeof(int));
	if(data == NULL){
		printf("Allocation failed");
	}
	printf("\nEnter data for these nodes:\n");
	for(register unsigned char i = 0; i < n; i++){
		scanf("%d",&data[i]);
	}
	BulkInsertNodes(n,data);
	printf("\nList initialized succesfully\n");
	return;
}

void PrintList()
{
	if(head == NULL){
		printf("The current list is empty\n");
		return;
	}
	node *temp = head;
	printf("The current list is:\n");
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	return;
}

void ReverseList()
{
    node *prevNode = NULL, *currNode = head, *nextNode = head->next ;
    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

int main(int argc, char *argv[])
{
    Initialize();
    PrintList();
    ReverseList();
	printf("After reversing\n");
    PrintList();
    return 0;
}