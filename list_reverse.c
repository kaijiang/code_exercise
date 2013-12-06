#include <stdio.h>
#include <malloc.h>

typedef struct _node{
    int value;
    struct _node *next;
} node;
    
node *list_reverse(node *head)
{
    node *prev = NULL, *next = NULL;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void append_list(node *head, node *elem, int value)
{
    head->next = elem;
    elem->value = value;
    elem->next = NULL;
}

void print_list(node *head)
{
    node *p = head;
    while(p){
        printf("%d->", p->value);
        p = p->next;
    }
    printf("NULL\n");
    
}

void test1()
{
    node *head = (node *)malloc(sizeof(node));
    node *tmp;
    node *prev;
    int i;
    head->next = NULL;
    head->value = 0;
    prev = head;
    for(i = 1; i < 4; i++){
        tmp = (node *)malloc(sizeof(node));
        append_list(prev, tmp, i);
        prev = tmp;
    }
    print_list(head);
    print_list(list_reverse(head));
}

void test2()
{
    node *head = (node *)malloc(sizeof(node));
    node *tmp;
    node *prev;
    int i;
    head->next = NULL;
    head->value = 0;
    prev = head;
    for(i = 1; i < 2; i++){
        tmp = (node *)malloc(sizeof(node));
        append_list(prev, tmp, i);
        prev = tmp;
    }
    print_list(head);
    print_list(list_reverse(head));
}

void test3()
{
    node *head = (node *)malloc(sizeof(node));
    node *tmp;
    node *prev;
    int i;
    head->next = NULL;
    head->value = 0;
    prev = head;
    for(i = 1; i < 1; i++){
        tmp = (node *)malloc(sizeof(node));
        append_list(prev, tmp, i);
        prev = tmp;
    }
    print_list(head);
    print_list(list_reverse(head));
}

int main()
{
    test1();
    test2();
    test3();
}

