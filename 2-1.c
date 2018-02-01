#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList {
	int data;
	struct LinkedList *next;
} node;

node *head=NULL;

int getNodePosByData(int content)
{
	node *temp=head;
	for(int i=0 ;temp != NULL; i++){
		if(temp->data == content){
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

node* getNodeByData(int data)
{
	node *temp=head;
	while(temp->next != NULL){
		if(temp->data == data){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

node* getNodeByPos(unsigned int pos)
{
	node *temp=head;
	for(register unsigned int i=0;i<pos;i++){
		temp=temp->next;
	}
	return temp;
}

node* createNode()
{
	node *temp = calloc(1,sizeof(node));
	if(temp == NULL){
		printf("Allocation failed");
	}
	return temp;
}

void insertAtBeginning(int data)
{
	node *temp = createNode();
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

void insertAtEnd(int data)
{
	node *insertedNode = createNode(), *temp = head;
	insertedNode->data = data;
	insertedNode->next = NULL;
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next = insertedNode;
	return;
}

void insertAtPos(int data, unsigned int pos)
{
	node *insertedNode = createNode();
	insertedNode->data = data;
	node *temp = getNodeByPos(pos-1);
	insertedNode->next = temp->next;
	temp->next = insertedNode;
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
void deleteAtBeginning()
{
	node *temp = head;
	head = head->next;
	free(temp);
	return;
}

void deleteAtEnd()
{
	node *temp=head;
	while(temp->next->next != NULL){
		temp=temp->next;		
	}
	free(temp->next);
	temp->next = NULL;
	return;
}

void deleteAtPos(unsigned int pos)
{
	// Get  the node before the node to be deleted
	node *temp = getNodeByPos(pos-1);
	node *deletedNode = temp->next;
	temp->next = temp->next->next;
	free(deletedNode);
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

void op1()
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
	printf("\nList initialized succesfully");
	return;
}

void op2()
{
	char choice;
	int data;
	printf("\nEnter data:\n");
	scanf("%d",&data);
	fflush(stdin);
	printf("\nWhere do you want to insert the node?");
	printf("\na. At beginning\nb. At the end\nc. At an arbitrary position\n");
	fflush(stdin);
	scanf("%c",&choice);
	unsigned int pos;
	switch(choice){
		case 'a':
			insertAtBeginning(data);
			break;
		case 'b':
			insertAtEnd(data);
			break;
		case 'c':
			printf("\nEnter pos\n");
			scanf("%d",&pos);
			insertAtPos(data,pos);
			break;
		default:
			printf("\nInvalid choice entered.");
	}
	return;
}

void op3()
{
	if(head == NULL){
		printf("The list is empty\n");
		return;
	}
	char choice;
	printf("\nWhere is the node you want to delete??");
	printf("\na. At beginning\nb. At the end\nc. At an arbitrary position\n");
	fflush(stdin);
	scanf("%c",&choice);
	fflush(stdin);
	unsigned int pos;
	switch(choice){
		case 'a':
			deleteAtBeginning();
			break;
		case 'b':
			deleteAtEnd();
			break;
		case 'c':
			printf("\nEnter pos\n");
			fflush(stdin);
			scanf("%d",&pos);
			deleteAtPos(pos);
			break;
		default:
			printf("\nInvalid choice entered.");
	}
	return;
}

void op4()
{
	int data;
	printf("Enter node contents\n");
	fflush(stdin);
	scanf("%d",&data);	
	int pos = getNodePosByData(data);
	if(pos == -1){
		printf("Not found(does not exist)");
	}
	else {
		printf("Node found at pos %d",pos);
	}
	
}

int main(int argc, char* argv[])
{
	char again='y';
	do{
		unsigned char choice;
		printf("Select operation:\n1. To initialize Node\n2. To insert a node\n3. To delete a node\n4. To search for data in the list\n5. To display the current list\n6. To exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				op1();
				break;
	
			case 2:
				op2();
				break;
	
			case 3:
				op3();
				break;
	
			case 4:
				op4();
				break;
	
			case 5:
				PrintList();
				break;
	
			case 6:
				exit(0);
				break;
	
			default:
				printf("\nInvalid choice.");
		}
		printf("\n\nFancy another operation?\n");
		fflush(stdin);
		scanf("%c",&again);
	}while(again == 'y' || again == 'Y');

	return 0;
}