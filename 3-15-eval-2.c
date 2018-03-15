#include<stdio.h>
#include<stdlib.h>

// Q2. Singly linked list is given, delete nodes whose sum is 0

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

node* getPrevNode(node *n)
{
    if(n == head) {
        return NULL;
    } else {
        node *temp = head;
        while (temp != NULL) {
            if (temp->next == n) {
                return temp;
            }
            temp = temp->next;
        }
        // If node doesn't exist in linked list
        return NULL;
    }
}

void DeleteNode(node *prev)
{
    node *temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

// Delete nodes between start and end including start and end
void DeleteNodes(node *start, node *end)
{
    node *temp = start;
    // Delte nodes between start and end
    while(temp->next != end){
        DeleteNode(temp);
    }
    // end is now after start, delete end
    DeleteNode(start);
    // Now delete start
    temp = getPrevNode(start);
    if(temp == NULL){
        // start is head
        temp = head;
        head = head->next;
        free(temp);
    } else {
        DeleteNode(temp);
    }
    return;
}

void DeleteSum()
{
    node *curr = head;
    while(curr != NULL) {
        int sum = 0;
        for( node *it = curr; it != NULL; it = it->next) {
            sum = sum + it->data;
            if(sum == 0) {
                DeleteNodes(curr, it);
                break;
            }
        }
        curr = curr->next;
    }
}

int main(int argc, char *argv[])
{
    Initialize();
    DeleteSum();
    printf("\nAfter deletion list is:\n");
    PrintList();
    return 0;
}

