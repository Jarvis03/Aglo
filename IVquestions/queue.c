#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node_t;

typedef struct queue {
    struct node *head;
    struct node *tail;
}queue_t;

queue_t * queue_create(void)
{
    struct queue  * p_head = (struct queue  *)malloc(sizeof(struct queue));
    if (p_head == NULL) {
        return -1;
    }
    p_head->head = NULL;
    p_head->tail = NULL;
    return p_head;
}

int queue_add(queue_t *head, int data)
{
    struct node * p_index = (struct node *) malloc(sizeof(struct node));
    // full
    if(p_index == NULL) {
        return -1;
    }
    p_index->data = data;
    p_index->next = NULL;

    if(head->head == NULL) {
        printf("first\n");
        head->head = p_index;
    }
    if (head->tail == NULL) {
        head->tail       = p_index;
    } else {
        head->tail->next = p_index;
        head->tail       = p_index;
    }
}
int is_empty(queue_t *head)
{
    if (head ->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}
int queue_del(queue_t *head)
{
    int data;
    if (is_empty(head)) {

        return 0;
    }
    struct node * tmp = head->head;
    if(head->head == head->tail) {

        head->head = NULL;
        head->tail = NULL;

    } else {
        head->head = tmp->next;
    }
    data = tmp->data;
    free(tmp);
    return data;

}
void print_queue(queue_t *head)
{
    struct node *p_index = head->head;
    while(p_index != NULL){

        printf("%d\n",p_index->data);
        p_index = p_index->next;
    }
}
void test_queue(void)
{
   queue_t * queue = queue_create();
   queue_add(queue,3);
   queue_add(queue,4);
   queue_add(queue,5);
   print_queue(queue);
    printf("delete\n");
   queue_del(queue);
   print_queue(queue);
}
/*********************************************************/
