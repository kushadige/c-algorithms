#include <stdlib.h>
#include <stdio.h>
struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}
void insafter(NODEPTR p, int x){
    NODEPTR q;
    if(p==NULL){
        printf("void insertion\n");
        exit(1);
    }
    q = getnode();
    q->next = p->next;
    p->next = q;
    q->info = x;
}
void delafter(NODEPTR p){
    NODEPTR q;
    if(p->next==NULL){
        printf("void deletion\n");
        exit(1);
    }
    q = getnode();
    q = p->next;
    p->next = q->next;
    free(q);
}
void yazdir(NODEPTR p){
    NODEPTR q;
    if(p->next==NULL){
        printf("bos liste\n");
        exit(1);
    }
    q = getnode();
    q = p->next;
    while(q!=NULL){
        printf("%d-",q->info);
        q = q->next;
    }
    printf("\n");
    free(q);
}
void reverse(NODEPTR p){
    if(p->next==NULL){
        printf("empty list\n");
        exit(1);
    }
    NODEPTR A=getnode(),B=getnode(),q=getnode(),temp=getnode();
    
    A = B = q = p;
    temp = p->next;
    while(p!=NULL){
        B = p->next;
        p->next = A;
        A = p;
        p = B;
    }
    q->next = A;
    temp->next = NULL;
}
int main(){
    NODEPTR liste;
    liste = getnode();
    liste->next = NULL;
    printf("listeye kac eleman eklemek istersiniz? ");
    int size;
    scanf("%d",&size);
    int temp;
    for(int i=0;i<size;i++){
        printf("%d. eleman: ",i+1);
        scanf("%d",&temp);
        insafter(liste,temp);
    }
    yazdir(liste);
    reverse(liste);
    yazdir(liste);
}