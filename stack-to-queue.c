#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 50
#define MAXQUEUE 50
#define TRUE 1
#define FALSE 0

struct stackelement {
    int x;
};
struct stack {
    int top;
    struct stackelement items[STACKSIZE];
};
struct queue {
    int items[MAXQUEUE];
    int front, rear;
};

//fonksiyonlar
void push();
void insert();
int pop();
int popQueue();
int empty();

int main(int argc, char **argv)
{
    struct stack s;
    struct queue q;
    q.front=0;
    q.rear=0;
    s.top = -1;
    int x=5;
    
    //kullanici 0 girene kadar yığıta eleman okuma
    printf("lutfen eklemek istediginiz elemanlari giriniz..\n");
    while(x!=0){
        scanf("%d", &x);
        push(&s,x);
    }
    
    //yığıttaki elemanlarin kuyruğa aktarımı
    while(!empty(&s)){
        int m = pop(&s);
        insert(&q, m);
    }
    
    //kuyrugu ekrana yazdirma
    printf("\n----kuyruk elemanlari----\n");
    int temp = popQueue(&q);
    while(q.front!=q.rear){
        printf("%d\n" , popQueue(&q));
    }
    return 0;
}

//queuefunctions
void insert(struct queue *pq, int x){
    pq->items[(pq->rear)++] = x;
}
int popQueue(struct queue *pq){
    return (pq->items[(pq->front)++]);
}
//stackfunctions
int empty(struct stack *ps){
    if(ps->top==-1)
        return (TRUE);
    else
        return (FALSE);
}
void push(struct stack *ps, int x){
    if(ps->top==STACKSIZE-1){
        printf("stack overflow\n");
    }
    else
        ps->items[++(ps->top)].x = x;
}
int pop(struct stack *ps){
    if(empty(ps)){
        printf("stack underflow\n");
    }
    else
        return (ps->items[(ps->top)--].x);
    return 0;
}