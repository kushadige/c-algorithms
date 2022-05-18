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
int treenumbers[100];
int i=0;
void pretrav(NODEPTR tree){
    if(tree!=NULL){
        treenumbers[i++] = tree->info;
        pretrav(tree->left);
        pretrav(tree->right);
    }
}
void prettrav(NODEPTR tree){
    if(tree!=NULL){
        printf("%d-",tree->info);
        prettrav(tree->left);
        prettrav(tree->right);
    }
}
void connect(NODEPTR t1, NODEPTR t2){//DLR
    pretrav(t2);
    while(i != -1){
        int temp = treenumbers[i--];
        NODEPTR helper1,helper2;
        helper1 = t1;
        while(helper1!=NULL){
            helper2 = helper1;
            if(temp>helper1->info)
                helper1 = helper1->right;
            else
                helper1 = helper1->left;
        }
        if(temp>helper2->info)
            helper2->right = maketree(temp);
        else if(temp==helper2->info)
            printf("duplicate\n");
        else
            helper2->left = maketree(temp);
    }
    prettrav(t1);
}
int main(){
    //1.ağaç
    NODEPTR p,q,temp;
    int number;
    scanf("%d",&number);
    
    p = maketree(number);
    while(number != -1){
        scanf("%d",&number);
        if(number==-1){
            printf("birinci agac olusturuldu\n");
            break;
        }
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
    
    //2.ağaç
    scanf("%d",&number);
    NODEPTR p2;
    p2 = maketree(number);
    NODEPTR m1,m2;
    while(number!=-1){
        scanf("%d",&number);
        if(number==-1)
            break;
        m1 = p2;
        while(m1!=NULL){
            m2 = m1;
            if(number > m1->info)
                m1 = m1->right;
            else
                m1 = m1->left;
        }
        if(number>m2->info)
            m2->right = maketree(number);
        else if(number==m2->info)
            printf("duplicate\n");
        else
            m2->left = maketree(number);
    }
    
    //calling connect func
    connect(p,p2);
    
    return 0;
}