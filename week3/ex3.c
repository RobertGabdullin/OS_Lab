#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node* next;
};

void insert_node(struct node* head, struct node* newnode, struct node* prevnode) {
	while (head != NULL && head != prevnode) head = head->next;
	if (head == NULL) return;
	struct node* Next = head->next;
	head->next = newnode;
	newnode->next = Next;
}

struct node* CreateNode(int val) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

struct node* GetNode(struct node* head, int index) { // from 0
	int pos = 0;
	while (head != NULL && pos != index) {
		head = head->next;
		pos++;
	}

	if (head != NULL && pos == index) return head;
	return NULL;

}

struct node* delete_node(struct node* head, struct node* delnode) {
	if (head == NULL) return NULL;
	if (head == delnode) {
		struct node* Next = head->next;
		free(head);
		return Next;
	}
	struct node* origin = head;
	struct node* old = NULL;
	while (head != NULL && head != delnode) {
		old = head;
		head = head->next;
	}
	if (head == NULL) return;

	struct node* Next = head->next;
	old->next = Next;
	free(head);

	return origin;
}

void print_list(struct node* head) {

	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}

	printf("\n");

}

int main()
{

	struct node* linked_list = CreateNode(3);
	
	insert_node(linked_list, CreateNode(5), GetNode(linked_list, 0));

	print_list(linked_list);

	linked_list = delete_node(linked_list, GetNode(linked_list, 0));

	print_list(linked_list);

	insert_node(linked_list, CreateNode(10), GetNode(linked_list, 0));

	print_list(linked_list);

	linked_list = delete_node(linked_list, GetNode(linked_list, 1));

	print_list(linked_list);

}
