#include <stdio.h>
#include <malloc.h>
#include <assert.h>

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

node *list_emerge(node *head1, node *head2)
{
    assert(head1 != NULL && head2 != NULL);
    node *new = NULL;
    node **head;
    node *tmp = head1;
    while (head1 && head2 && (head = head1->value < head2->value ? &head1 : &head2)) {
        if (new)
            new->next = *head;
        new = *head;
        *head = new->next;
    }
    new->next = head1 ? head1 : head2;
    return tmp;
}

node *list_emerge1(node *head1, node *head2)
{
    if (head1 && !head2) {
        return head1;
    } else if (!head1 && head2) {
        return head2;
    } else if (!head1 && !head2) {
        return NULL;
    } else {
        node *ret, *head = NULL;
        if (head1->value < head2->value) {
            ret = head = head1;
            head1 = head1->next;
        } else {
            ret = head = head2;
            head2 = head2->next;
        }
        while (head1 && head2) {
            if (head1->value < head2->value) {
                head->next = head1;
                head = head1;
                head1 = head1->next;
            } else {
                head->next = head2;
                head = head2;
                head2 = head2->next;
            }
        }
        head->next = head1 ? head1 : head2;
        return ret;
    }
}

node *list_emerge2(node *head1, node *head2)
{
    node **head = NULL;
    node *dummy = (node *)malloc(sizeof(node));
    node *new = dummy;
    while (head1 && head2 && (head = head1->value < head2->value ? &head1 : &head2)) {
        new->next = *head;
        new = *head;
        *head = (*head)->next;
    }
    new->next = head1 ? head1 : head2;
    new = dummy->next;
    free(dummy);
    return new;
}

void list_remove(node **head, int value)
{
    node **curr;
    for(curr = head; *curr;)
    {
        node *entry = *curr;
        if (entry->value == value) {
            *curr = entry->next;
            free(entry);
        } else {
            curr = &entry->next;
        }
        
    }
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

void test_remove()
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
    list_remove(&head, 2);
    print_list(head);
}

void test_emerge()
{
    node *head1 = (node *)malloc(sizeof(node));
    node *tmp;
    node *prev;
    int i;
    head1->next = NULL;
    head1->value = 1;
    prev = head1;
    for(i = 2; i < 5; i++){
        tmp = (node *)malloc(sizeof(node));
        append_list(prev, tmp, i);
        prev = tmp;
    }
    print_list(head1);
    
    node *head2 = (node *)malloc(sizeof(node));
    head2->next = NULL;
    head2->value = 5;
    prev = head2;
    for(i = 6; i < 9; i++){
        tmp = (node *)malloc(sizeof(node));
        append_list(prev, tmp, i);
        prev = tmp;
    }
    print_list(head2);

    print_list(list_emerge2(head1, head2));
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
    test_emerge();
    test_remove();
    return 0;
}

