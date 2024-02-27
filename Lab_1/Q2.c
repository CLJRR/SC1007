#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    ListNode *head;
    int size;
} LinkedList;

int insertNode(LinkedList *ll, int size, int input);
ListNode *findNode(LinkedList ll, int index);
int removeNode(LinkedList *ll, int index);
int printList(LinkedList *ll);

int main(void)
{
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;
    int input;
    printf("Please enter list of numbers, end with char:\n");
    while (scanf("%d", &input))
    {
        if (!insertNode(&ll, ll.size, input))
            break;
    }
    scanf("%*s");
    printList(&ll);
    printf("please input index to remove:\n");
    while (1)
    {
        scanf("%d", input);
        if (!removeNode(&ll, input))
        {
            printf("current list:\n");
            printList(&ll);
            break;
        }
    }
}

int insertNode(LinkedList *ll, int size, int input)
{
    ListNode *temp, *pre;
    // case 1: first eleement
    if (ll->size == 0)
    {
        temp = malloc(sizeof(ListNode));
        temp->item = input;
        temp->next = NULL;
        ll->head = temp;
        ll->size++;
        return 1;
    }
    // case 2: subseq elements
    pre = findNode(*ll, size - 1);
    if (pre != NULL)
    {
        temp = malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->item = input;
        pre->next = temp;
        ll->size++;
        return 1;
    }
    return 0;
}
ListNode *findNode(LinkedList ll, int index)
{
    ListNode *cur = ll.head;
    if (cur == NULL || index > ll.size)
        return NULL;
    while (index > 0)
    {
        cur = cur->next;
        if (cur == NULL)
            return 0;
        index--;
    }
    return cur;
}
int printList(LinkedList *ll)
{
    ListNode *ptr = ll->head;
    printf("current list: ");
    while (ll != NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }
    printf("\n");
    return 1;
}
int removeNode(LinkedList *ll, int index)
{
}