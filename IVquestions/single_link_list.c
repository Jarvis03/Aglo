#include <stdio.h>
#include <stdlib.h>
typedef struct s_list{
    int data;
    struct s_list *next;
} s_list_t;

s_list_t * list_create(boid)
{
    s_list_t * head;
    head = (s_list_t * )malloc(sizeof(s_list_t));
    if (head == NULL) {
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    printf("\nis  %x|->%x\n",head,head->next);
    return head;
}

int list_add(s_list_t * head,s_list_t *item)
{
    if(NULL == head || NULL == item) {

        return -1;
    }
    s_list_t *p = head;

    while(p->next != NULL){

        p = p->next;
    }

    p->next = item;
    return 0;
}

s_list_t * list_reverse(s_list_t *head)
{
    if(NULL == head) {

        return NULL;
    }
    s_list_t * p_new = NULL;
    s_list_t * p_tmp = NULL;
    s_list_t * p_index = head;
    while(NULL != p_index) {

        p_tmp = p_index->next;
        p_index->next = p_new;
        p_new = p_index;
        p_index = p_tmp;
    }
    return p_new;
}
// 递归实现
s_list_t * list_reverse_r(s_list_t *head)
{
     if(NULL == head || NULL == head->next) {

        return head;
     }
     s_list_t * pnew = list_reverse_r(head->next);
     head->next->next = head;
     head->next       = NULL;
     return pnew ;
}
void print_list(s_list_t *head)
{
    s_list_t *p = head;
    while(p != NULL) {
        printf("%d|\n",p->data);
        p = p->next;
    }
    return;
}
int test_slist(void)
{
    s_list_t* head;
    s_list_t* pnew;
    head = list_create();

    printf("\nis create %x|->%x\n",head,head->next);

    s_list_t data1,data2,data3;
    data1.data = 1;
    data2.data = 2;
    data3.data = 3;
    data1.next = NULL;
    data2.next = NULL;
    data3.next = NULL;
    list_add(head,&data1);

    list_add(head,&data2);
    list_add(head,&data3);

    print_list(head);
    printf("\nis reverse\n");
    pnew = list_reverse_r(head);
    print_list(pnew);
    printf("\nis end\n");


}
