#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct _ListNode
{
    int number;
    struct _ListNode *next;
} ListNode;

// typedef struct _ll
// {
//     ListNode *head;
//     int size;
// } LinkedList;

void printList(ListNode *cur);
ListNode *findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
int removeNode(ListNode **ptrHead, int index);

int main(void)
{
    int size = 0;
    int index;
    ListNode *head = NULL;
    int input;
    printf("Please enter list of numbers:\n");
    while (scanf("%d", &input))
        if (insertNode(&head, size, input))
            size++;
    scanf("%*s");

    printList(head);
    printf("%d\n", size);
    while (1)
    {
        printf("Enter the index of the node to be removed: ");
        scanf("%d", &index);

        if (removeNode(&head, index))
            size--;
        else
        {
            printf("The node cannot be removed.\n");
            break;
        }

        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}
int insertNode(ListNode **ptrHead, int size, int item)
{
    ListNode *pre, *newNode;
    // if size is 0:
    if (size == 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->number = item;
        newNode->next = NULL;
        *ptrHead = newNode;
        return 1;
    }
    if ((pre = findNode(*ptrHead, size - 1)) != 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->number = item;
        newNode->next = NULL;
        pre->next = newNode;
        return 1;
    }
    return 0;
}
void printList(ListNode *cur)
{
    printf("current list:   ");
    while (cur != NULL)
    {
        printf("%d ", cur->number);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode *cur, int size)
{
    if (cur == NULL || size < 0)
        return NULL;
    while (size > 0)
    {
        cur = cur->next;
        if (cur == NULL)
            return NULL;
        size--;
    }
    return cur;
}

int removeNode(ListNode **ptrHead, int index)
{
    ListNode *pre, *temp;
    if (index == 0)
    {
        if (*ptrHead == NULL)
            return 0;
        temp = *ptrHead;
        *ptrHead = temp->next;
        free(temp);
        return 1;
    }

    pre = findNode(*ptrHead, index - 1);
    if (pre != NULL && pre->next != NULL)
    {
        temp = pre->next;
        pre->next = temp->next;
        free(temp);
        return 1;
    }
    return 0;
}
