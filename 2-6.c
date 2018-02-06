#include<stdio.h>
#include<stdlib.h>

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

void initializeList(unsigned int n, int data[])
{
	node *prevNode = NULL;
	for(register unsigned int i = 0;i<n;i++){
		node *temp = createNode();
		temp->data = data[i];
		temp->next = head;
		if(head == NULL){
			head = temp;
		}
		else {
			prevNode->next = temp;
		}
		prevNode = temp;
	}
}

node* getNodeByPos(int pos)
{
	node *temp = head;
	int i = 0;
	do{
		if(i == pos){
			return temp;
		}
		temp = temp->next;
		i++;
	}while(temp != head);
	return NULL;
}

node* getNodeByData(int data)
{
	node *temp = head;
	do{
		if(temp->data == data){
			return temp;
		}
		temp = temp->next;
	}while(temp != head);
	return NULL;
}

node* getPrevNodeByData(int data)
{
	node *temp = head;
	do{
		if(temp->next->data == data){
			return temp;
		}
		temp = temp->next;
	}while(temp != head);
	return NULL;
}

int getNodePosByData(int data)
{
	node *temp = head;
	int i=0;
	do{
		if(temp->data == data){
			return i;
		}
		temp = temp->next;
		i++;
	}while(temp != head);
	return -1;
}

void printCircList()
{
	if(head == NULL){
		printf("List not initialized yet, initialize list first");
		return;
	}
	node *first = head;
	do{
		printf("%d",first->data);
		first = first->next;
	}while(first != head);
}

void insertNodeAfterNode(int data, node *prev)
{
	node *temp = createNode();
	if(temp == NULL){
		return;
	}
	temp->data = data;
	temp->next = prev->next;
	prev->next = temp;
	printf("Inserted successfully");
}

void insertNodeAtPos(int data, int pos)
{
	if(pos<0){
		printf("\nPosition can't be negative.");
		return;
	}
	node* temp = getNodeByPos(pos);
	if(temp != NULL){
	insertNodeAfterNode(data,temp);
	} else {
		printf("\nInvalid position");
		return;
	}
}

void handleListInitialize(){

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
	for(register unsigned int i = 0; i < n; i++){
		scanf("%d",&data[i]);
	}
	initializeList(n,data);
	printf("\nList initialized succesfully");
	return;
}

void handleListInsert()
{
	if(head == NULL){
		printf("Please initialize the list first");
		return;
	}
	int find, data;
	printf("\nEnter data to be searched and data to be inserted after data has been found\n");
	scanf("%d %d",&find,&data);
	node *foundNode = getNodeByData(find);
	if(foundNode == NULL){
		printf("Data not found\n");
		return;
	}
	insertNodeAfterNode(data, foundNode);
}

void handleDeleteNode()
{
	if(head == NULL){
		printf("List hasn't been initialized yet, please initialize the list first");
		return;
	}
	int data;
	printf("Enter data to be deleted\n");
	scanf("%d",&data);
	node *beforeToBeDeleted = getPrevNodeByData(data);
	if(beforeToBeDeleted == NULL){
		printf("\nData doesn't exist");
		return;
	}
	node *toBeDeleted = beforeToBeDeleted->next;
	beforeToBeDeleted->next = toBeDeleted->next;
	free(toBeDeleted);
	return;
}

void handleSearch()
{
	if(head == NULL){
	printf("\nList not initialized yet, initialize the list first");
	return;
	}
	int data;
	printf("\nEnter data to be searched");
	scanf("%d",&data);
	int pos = getNodePosByData(data);
	if(pos < 0){
		printf("\nNot found");
		return;
	}
	printf("Data found at position: %d",pos);
	
}

int main(int argc, char* argv[])
{
	printf("\nNote: All positions start at 0 and data stored is an integar\n\n");
	char again='y';
	do{
		int choice;
		printf("Select operation:\n1. To initialize Node\n2. To insert a node after node containing given data\n3. To delete the node after node containing given data\n4. To search for data in the list\n5. To display the current list\n6. To exit\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				handleListInitialize();
				break;
	
			case 2:
				handleListInsert();
				break;
	
			case 3:
				handleDeleteNode();
				break;
	
			case 4:
				handleSearch();
				break;
	
			case 5:
				printCircList();
				break;
	
			case 6:
				exit(0);
				break;
			
			default:
				printf("\nInvalid choice.");
		}
		fflush(stdin);
		printf("\n\nFancy another operation?\n");
		scanf("%c",&again);
		fflush(stdin);
	}while(again == 'y' || again == 'Y');

	return 0;
}