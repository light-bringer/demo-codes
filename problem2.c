/*
convert circular linked list to doubly linked list
*/

#include<stdio.h>
#include <stdlib.h>

struct CircularNode
{
    // circular linked list
    int data;
    struct CircularNode *next;
};

struct CircularNode *addToEmpty(struct CircularNode *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;

    // Creating a CircularNode dynamically.
    struct CircularNode *temp =
           (struct CircularNode*)malloc(sizeof(struct CircularNode));

    // Assigning the data.
    temp -> data = data;
    last = temp;

    // Creating the link.
    last -> next = last;

    return last;
}

struct CircularNode *addBegin(struct CircularNode *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    struct CircularNode *temp =
            (struct CircularNode *)malloc(sizeof(struct CircularNode));

    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;

    return last;
}

struct CircularNode *addEnd(struct CircularNode *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    struct CircularNode *temp =
        (struct CircularNode *)malloc(sizeof(struct CircularNode));

    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;

    return last;
}

struct CircularNode *addAfter(struct CircularNode *last, int data, int item)
{
    if (last == NULL)
        return NULL;

    struct CircularNode *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct CircularNode *)malloc(sizeof(struct CircularNode));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);

    printf("%d not present in the list.\n", item);
    return last;

}

void traverse(struct CircularNode *last)
{
    struct CircularNode *p;

    // If list is empty, return.
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // Pointing to first CircularNode of the list.
    p = last -> next;

    // Traversing the list.
    do
    {
        printf("%d ", p -> data);

        p = p -> next;

    }
    while(p != last->next);

}


// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 3. put in the data  */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}


struct Node *convert(struct CircularNode *last)
{
    struct CircularNode *p;
    struct Node * head = NULL;

    // If list is empty, return.
    if (last == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    // Pointing to first CircularNode of the list.
    p = last -> next;

    // Traversing the list.
    do
    {
        printf("Inserting CLL data to DLL, value : %d \n", p -> data);
        append(&head, p->data);

        p = p -> next;

    }
    while(p != last->next);

    return head;

}


// Driven Program
int main()
{
    struct CircularNode *last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);

    traverse(last);

    struct Node *dll = NULL;
    dll = convert(last);
    printList(dll);

    return 0;
}

