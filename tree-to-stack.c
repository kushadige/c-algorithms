#include <stdio.h>
#include <stdlib.h>
struct stack {
    int top;
    int items[100];
};
struct nodetype {
    int info;
    struct nodetype *left,*right,*father;
};
typedef struct nodetype *NODEPTR;
NODEPTR getnode();
NODEPTR maketree();
void pretrav();
void intrav(NODEPTR tree){
    if(tree!=0){
        intrav(tree->left);
        printf("%d-",tree->info);
        intrav(tree->right);
    }
}
void posttrav(NODEPTR tree){
    if(tree!=0){
        posttrav(tree->left);
        posttrav(tree->right);
        printf("%d-",tree->info);
    }
}
int items[100];
void trav(NODEPTR tree, struct stack *ps){
    if(tree!=0){
        ps->items[++(ps->top)] = tree->info;
        trav(tree->left,ps);
        trav(tree->right,ps);
    }
}
void push_stack();
int pop_stack();
int main(){
    //tree
    struct stack s;
    s.top=-1;
    NODEPTR tree;
    tree = maketree(8);
    
    NODEPTR p,q;
    int sayi[5];
    for(int j=0;j<5;j++)
        sayi[j] = rand() % 100 + 1;
    /*for(int j=0;j<5;j++)
        printf("%d\n",sayi[j]);*/
    int i = 0;
    while(i!=5){
        
        q = tree;
        while(q!=NULL){
            p = q;
            if(sayi[i]>q->info)
                q = q->right;
            else
                q = q->left;
        }
        if(sayi[i]>p->info)
            p->right = maketree(sayi[i++]);
        else if(sayi[i]==p->info){
            printf("duplicate\n");
            i++;
        }
        else
            p->left = maketree(sayi[i++]);
    }
    printf("preorder:");
    pretrav(tree);
    printf("\ninorder:");
    intrav(tree);
    printf("\npostorder:");
    posttrav(tree);
    
    trav(tree,&s);
    printf("\n-------------\n");
    while(s.top!=-1){
        printf("%d\n",pop_stack(&s));
        printf("%d\n",pop_stack(&s));
    }
}
NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct nodetype));
    return p;
}
NODEPTR maketree(int x){
    NODEPTR p;
    p = getnode();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    p->father = NULL;
    return p;
}
void pretrav(NODEPTR tree){
    if(tree!=NULL){
        printf("%d-",tree->info);
        pretrav(tree->left);
        pretrav(tree->right);
    }
}
void push_stack(struct stack *ps, int x){
    if(ps->top==99){
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
    return ps->items[ps->top--];
}