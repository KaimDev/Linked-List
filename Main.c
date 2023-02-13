#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct Node Node;

struct Node
{
    int32_t value;
    Node    *next;
};

void PrintListInReverse(Node *head)
{
    if (head == NULL) return;
    PrintListInReverse(head->next);
    printf("Value: %d\n", head->value);
}

void PrintList(Node *head)
{
    if (head == NULL) return;
    printf("Value: %d\n", head->value);
    PrintList(head->next);
}

void FreeNode(Node **node)
{
    Node *current = *node;

    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    *node = NULL;
}

int32_t main(void)
{
    Node *head = NULL;
    Node **index = &head;
    size_t node;

    puts("How many Node do you want?");
    scanf("%lu", &node);

    for (size_t i = 0 ; i < node ; ++i)
    {
        *index = malloc(sizeof(Node));
        (**index).value = i + 1;
        index = &(**index).next;
    }

    puts("\nList");
    PrintList(head);

    puts("\nList in Reverse");
    PrintListInReverse(head);

    FreeNode(&head);

    return EXIT_SUCCESS;
}