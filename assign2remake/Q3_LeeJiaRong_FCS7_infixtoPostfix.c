////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h> // Include limits.h for INT_MIN
#define SIZE 1000	// The limit of expression length

typedef struct _listnode
{
	char item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;

////////////////////////////////// stack    /////////////////////

typedef struct stack
{
	LinkedList ll;
} Stack;

//////////////////////// function prototypes //////////////////////

void infixtoPostfix(char *, char *); // You should not change the prototypes of these functions
int precedence(char);				 // You may use this utility function or you write your own precedence () function.

////////////////////////////////////////////////////////////////////

void push(Stack *s, char item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, char item);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////

int main()
{
	char infix[SIZE];
	char postfix[SIZE];

	printf("Enter an infix expression:\n");
	scanf("%[^\n]%*c", infix);

	infixtoPostfix(infix, postfix);
	printf("The postfix expression is \n");
	printf("%s\n", postfix);
	return 0;
}

void infixtoPostfix(char *infix, char *postfix)
{
	Stack s;
	s.ll.head = NULL;
	s.ll.size = 0;
	while (*infix)
	{
		if (isalnum(*infix))
		{
			*postfix = *infix;
			postfix++;
		}
		else if (*infix == '(')
		{
			push(&s, *infix);
		}
		else if (*infix == ')')
		{
			while (peek(&s) != '(')
			{
				if (isEmptyStack(&s))
					break;
				*postfix = pop(&s);
				postfix++;
			}
			if (!isEmptyStack(&s))
				pop(&s);
		}
		else if (isEmptyStack(&s))
		{
			push(&s, *infix);
		}
		else
		{
			while (precedence(*infix) <= precedence(peek(&s)) && !isEmptyStack(&s) && peek(&s) != '(')
			//
			{
				*postfix = pop(&s);
				postfix++;
			}
			push(&s, *infix);
		}
		infix++;
	}
	while (!isEmptyStack(&s))
	{
		*postfix = pop(&s);
		postfix++;
	}
	*postfix == '\0';
}

int precedence(char op)
{
	if (op == '*' || op == '/')
		return 1;
	else
		return 0;
}

//////////////////////////////////////////////////////////

void push(Stack *s, char item)
{
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s)
{
	char item;
	if (!isEmptyStack(s))
	{
		item = ((s->ll).head)->item;
		removeNode(&(s->ll), 0);
		return item;
	}
	return INT_MIN;
}

int peek(Stack *s)
{
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s)
{
	if ((s->ll).size == 0)
		return 1;
	return 0;
}

//////////////////////////////////////////////////

void printList(LinkedList *ll)
{

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%c ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode *findNode(LinkedList *ll, int index)
{

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0)
	{
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, char value)
{

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0)
	{
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL)
	{
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index)
{

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0)
	{
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL)
	{

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}