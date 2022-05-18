#include <stdio.h>
#include <stdlib.h>
struct nodetype {
    int info;
    struct nodetype *father, *left, *right;
};
typedef struct nodetype *NODEPTR;
NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct nodetype));
    return p;
}
NODEPTR maketree(int x){
    NODEPTR p;
    p = getnode();
    p->info = x;
    p->father = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void pretrav(NODEPTR tree);
void intrav(NODEPTR tree);
void posttrav(NODEPTR tree);

int main(){
    NODEPTR p,q,temp;
    NODEPTR p2;
    int number;
    // printf("\nfor first tree\n");
    scanf("%d",&number);
    
    p = maketree(number);
    while(number != -1){
        scanf("%d",&number);
        if(number==-1)
            break;
        temp = p;
        while(temp!=NULL){
            q = temp;
            if(number > temp->info)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if(number > q->info)
            q->right = maketree(number);
        else if(number == q->info)
            printf("duplicate\n");
        else
            q->left = maketree(number);
    }
    
    printf("preorder:");
    pretrav(p);
    printf("\ninorder:");
    intrav(p);
    printf("\npostorder:");
    posttrav(p);
    return 0;
}
void pretrav(NODEPTR tree){//DLR
    if(tree!=NULL){
        printf("%d,",tree->info);
        pretrav(tree->left);
        pretrav(tree->right);
    }
}
void intrav(NODEPTR p){//LDR
    if(p!=NULL){
        intrav(p->left);
        printf("%d,",p->info);
        intrav(p->right);
    }
}
void posttrav(NODEPTR q){
    if(q!=NULL){
        posttrav(q->left);
        posttrav(q->right);
        printf("%d,",q->info);
    }
}
