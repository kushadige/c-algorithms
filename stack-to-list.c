#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
struct stack {
    int top;
    int items[STACKSIZE];
};
struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
void push_stack(struct stack *ps, int x);
int pop_stack(struct stack *ps);
void insafter(NODEPTR, int x);
int i=1;
void yazdir(NODEPTR p){
    if(p!=NULL){
        printf("%d inci eleman: %d\n",i++,p->info);
        yazdir(p->next);
    }
}
NODEPTR getnode();
int main(){
    struct stack s;
    NODEPTR p;
    p = getnode();
    p->next = NULL;
    s.top = -1;
    for(int i=0;i<10;i++){
        push_stack(&s,i+1);
    }
    //insafter(p,5);
    while(s.top!=-1){
        insafter(p,pop_stack(&s));
    }
    
    yazdir(p->next);
}
void push_stack(struct stack *ps, int x){
    if(ps->top==STACKSIZE-1){
        printf("stack overflow\n");
        exit(1);
    }
    ps->items[++(ps->top)] = x;
}
int pop_stack(struct stack *ps){
    if(ps->top==-1){
        printf("stack underflow\n");
        exit(1);
    }
    return ps->items[(ps->top)--];
}
void insafter(NODEPTR p, int x){
    NODEPTR q;
    if(p==NULL)
        printf("void insertion\n");
    q = getnode();
    q->next = p->next;
    p->next = q;
    q->info = x;
}
NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}