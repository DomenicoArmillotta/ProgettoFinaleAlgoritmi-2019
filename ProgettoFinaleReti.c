#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_DATA 48
#define MAX_LIST_DATA 48
#define MAX_GRAP_DATA 48

    typedef struct treeNode {
        char data[MAX_TREE_DATA];
        int numRel;
        struct treeNode *relation_width;
        struct treeNode *leftPtr;
        struct treeNode *rightPtr;
    }TreeNode;

    typedef TreeNode *TreeNodePtr;
        typedef struct listNode{
        char data[MAX_LIST_DATA];
        TreeNodePtr ralazione;
        struct listNode *succ;
        int maxVal;
    }ListNode;

    typedef ListNode *ListNodePtr;

    ListNodePtr insertListNodeInOrderNoDuplicate(ListNodePtr root,char data[]);
    ListNodePtr deleteListNode(ListNodePtr root,char data[]);
    ListNodePtr searchListNode(ListNodePtr root,char data[]);


    int insertTreeNode(TreeNodePtr *root, char data[]);
    TreeNodePtr deleteTree(struct treeNode* node);
    TreeNodePtr searchTreeNode(TreeNodePtr root, char data[]);
    TreeNodePtr deleteTreeNode(TreeNodePtr root, char data[]);
    TreeNodePtr minTreeNode(TreeNodePtr node);


    TreeNodePtr deleteNome(char nome[],TreeNodePtr root);
    void viewTreeInOrder2(TreeNodePtr root,int maxl);
    int cercaMassimoValore(TreeNodePtr root,int MassimoValore,int A,int B);
    int controlloAccount(char nome[],TreeNodePtr root);
    ListNodePtr addRelazione(ListNodePtr listaRelazioni, char relazione[],char master[],char slave[],TreeNodePtr accounts);
void deleteRelazione( char relazioni[],char master[],char slave[],ListNodePtr listaRelazioni,TreeNodePtr accounts);
void deletPers(char nome[],ListNodePtr listaRelazioni,TreeNodePtr accounts);
void report(ListNodePtr listaRelazioni);




int main() {
   TreeNodePtr accounts = NULL;
    ListNodePtr listaRelazioni=NULL;

    char *p,*q,*r;
    char buf[48];
    char param1[48];
    char param2[48];
    char param3[48];

        while(scanf("%s", buf)==1) {
                if(strcmp(buf,"addent")==0){
                    scanf("%s", param1);
                    p=strtok(param1," \" ");
                    insertTreeNode(&accounts, p);

                }else if(strcmp(buf,"delent")==0){
                    scanf("%s", param1);
                    p=strtok(param1," \" ");
                    deletPers(p,listaRelazioni,accounts);
                }else if(strcmp(buf,"addrel")==0){
                    scanf("%s %s %s", param1,param2,param3);
                    p=strtok(param1," \" ");
                    q=strtok(param2," \" ");
                    r=strtok(param3," \" ");
                    listaRelazioni=addRelazione(listaRelazioni,r,p,q,accounts);


                }else if(strcmp(buf,"delrel")==0){
                    scanf("%s %s %s", param1,param2,param3);
                    p=strtok(param1," \" ");
                    q=strtok(param2," \" ");
                    r=strtok(param3," \" ");
                    deleteRelazione(r,p,q,listaRelazioni,accounts);
                }else if(strcmp(buf,"report")==0){
                    report(listaRelazioni);

                }else if(strcmp(buf,"end")==0){
                    return 0;
                }
        }


    return 0;
}

int insertTreeNode(TreeNodePtr *root, char data[]) {
    if (*root == NULL){
        *root = malloc(sizeof(TreeNode));
        if (*root != NULL) {
                strcpy((*root)->data,data);
                (*root)->relation_width=NULL;
                (*root)->numRel=0;
                (*root)->leftPtr = NULL;
                (*root)->rightPtr = NULL;
                return 1;
        }
    }else if (strcmp(data,(*root)->data)<0)
            insertTreeNode(&((*root)->leftPtr),data);
     else if (strcmp(data,(*root)->data)>0)
            insertTreeNode(&((*root)->rightPtr),data);
     else {

        return 0;
     }
}






TreeNodePtr searchTreeNode(TreeNodePtr root, char data[]){
  while (root!=NULL && strcmp(root->data,data)!= 0){
    root = (strcmp(data,root->data)<0) ? root->leftPtr : root->rightPtr;

  }

  return root;
}



TreeNodePtr deleteTree(struct treeNode* root)
{
    if (root == NULL) return root;


        root->leftPtr = deleteTree(root->leftPtr);
        root->rightPtr = deleteTree(root->rightPtr);

        if (root->leftPtr == NULL){
            TreeNodePtr temp = root->rightPtr;
            root=NULL;
            free(root);
            return temp;
        }else if (root->rightPtr == NULL){
            TreeNodePtr temp = root->leftPtr;
            root=NULL;
            free(root);
            return temp;
        }


        TreeNodePtr temp = minTreeNode(root->rightPtr);

        root->rightPtr = deleteTree(root->rightPtr);


}




//QUESTO
TreeNodePtr deleteTreeNode(TreeNodePtr root, char data[]){
    if (root == NULL) return root;


    if (strcmp(data,root->data)<0)
        root->leftPtr = deleteTreeNode(root->leftPtr, data);



    else if (strcmp(data,root->data)>0)
        root->rightPtr = deleteTreeNode(root->rightPtr, data);


    else if(strcmp(data,root->data)==0){
        if (root->leftPtr == NULL){
            TreeNodePtr temp = root->rightPtr;
            root=NULL;
            free(root);
            return temp;
        }else if (root->rightPtr == NULL){
            TreeNodePtr temp = root->leftPtr;
            root=NULL;
            free(root);
            return temp;
        }

        TreeNodePtr temp = minTreeNode(root->rightPtr);

        strcpy(root->data,temp->data);
        root->numRel=temp->numRel;
        root->relation_width=temp->relation_width;
        root->rightPtr = deleteTreeNode(root->rightPtr, temp->data);
        return root;

    }
    return root;
}

TreeNodePtr minTreeNode(TreeNodePtr root){
    TreeNodePtr current = root;
    while (current && current->leftPtr != NULL)
        current = current->leftPtr;
    return current;
}







TreeNodePtr deleteNome(char nome[],TreeNodePtr root){
     TreeNodePtr m,k;
    if (root != NULL) {
        deleteNome(nome,root->leftPtr);
        deleteNome(nome,root->rightPtr);
        k=searchTreeNode(root->relation_width,nome);
        if(k->data!=NULL){
        m=deleteTreeNode(root->relation_width,nome);
        root->numRel--;
        root->relation_width=m;


        root->relation_width=m;

        }
    }

    return root;
}


void viewTreeInOrder2(TreeNodePtr root,int maxl){
    if (root != NULL){
        viewTreeInOrder2(root->leftPtr,maxl);
        if(root->numRel==maxl){
            fputs(" \"",stdout);
            fputs(root->data,stdout);
            fputs("\"",stdout);
        }
        viewTreeInOrder2(root->rightPtr,maxl);

    }
}


int cercaMassimoValore(TreeNodePtr root,int MassimoValore,int A,int B){


        if (root != NULL){

         A=cercaMassimoValore(root->leftPtr,MassimoValore,A,B);
         B=cercaMassimoValore(root->rightPtr,MassimoValore,A,B);
        if(  A>root->numRel){
            if(A>B){
                return A;}
            else{
                return B;}
        }
        else if(B>root->numRel){
            if( B>A){
                return B;}
            else{
                return A;}
        }
        return root->numRel;
}
return 0;
}

int controlloAccount(char nome[],TreeNodePtr root){

    if (root == NULL)
        return 0;
    else if (strcmp(root->data,nome)==0){


        return 1;

    }

    if(strcmp(root->data,nome)>0)
        return controlloAccount(nome,root->leftPtr);

    if(strcmp(root->data,nome)<0)
        return controlloAccount(nome,root->rightPtr);


}



ListNodePtr deleteListNode(ListNodePtr root,char data[]){
    int flgTrovato=0;
    ListNodePtr t=NULL;
    ListNodePtr prec=NULL;
    if(root!=NULL){
        t=root;
        if(strcmp(t->data,data)==0){
            root=t->succ;
            free(t);
        }else{
            while(t!=NULL && flgTrovato==0){
                if(strcmp(t->data,data)==0){
                    prec->succ=t->succ;
                    flgTrovato=1;
                    free(t);
                }
                prec=t;
                t=t->succ;
            }

        }
    }
    return root;
}

ListNodePtr insertListNodeInOrderNoDuplicate(ListNodePtr root,char data[]){
    int flag = 0;

    ListNodePtr q=malloc(sizeof(ListNode));
    strcpy(q->data,data);
    q->succ=NULL;
    q->ralazione=NULL;
    q->maxVal=0;

    ListNodePtr t=NULL;
    ListNodePtr prec=NULL;
    t=root;
    if(root!=NULL){
        while(t!=NULL && flag==0){
            if(strcmp(t->data,data)<=0){
                prec=t;
                t=t->succ;
            }else{
                flag=1;
            }
        }
        if(prec==NULL){
            q->succ=root;
            root=q;

        }else{
            if(strcmp(prec->data,data)<0){
                prec->succ=q;
                q->succ=t;
            }
        }
    }else{
        root=q;
    }


    return root;
}
ListNodePtr searchListNode(ListNodePtr root,char data[]){
    ListNodePtr risultato = NULL;
    ListNodePtr t = NULL;
    t=root;
    if(root!=NULL){
        while(risultato == NULL && t!=NULL){
            if(strcmp(t->data,data)==0){
              risultato=t;
            }
            t=t->succ;
        }
    }
    return risultato;
}


ListNodePtr addRelazione(ListNodePtr listaRelazioni, char relazione[],char master[],char slave[],TreeNodePtr accounts) {

    int A=controlloAccount(master,accounts);
    int B=controlloAccount(slave,accounts);

    if(A==1 && B==1){

    ListNodePtr l;
    int Controllo=0;

    //l=searchListNode(listaRelazioni,relazione);
    //if(l==NULL)
    listaRelazioni=insertListNodeInOrderNoDuplicate(listaRelazioni,relazione);

    TreeNodePtr n;
    l=searchListNode(listaRelazioni,relazione);
    insertTreeNode(&(l->ralazione),slave);
    n= searchTreeNode(l->ralazione,slave);
    Controllo=insertTreeNode(&(n->relation_width),master);

    if(Controllo==1)
        n->numRel++;
    return listaRelazioni;

    }
    return listaRelazioni;


}


void deleteRelazione( char relazioni[],char master[],char slave[],ListNodePtr listaRelazioni,TreeNodePtr accounts){
    int A=controlloAccount(master,accounts);
    int B=controlloAccount(slave,accounts);
    ListNodePtr l;

    l=searchListNode(listaRelazioni,relazioni);
    if(A==1 && B==1 && l!=NULL){

    TreeNodePtr n,m,k;


    //int D=controlloAccount(slave,l->ralazione);
    n=searchTreeNode(l->ralazione,slave);
    if(n!=NULL){



    //int C=controlloAccount(master,n->relation_width);
    k=searchTreeNode(n->relation_width,master);

    if(k!=NULL){



        if(k->data!=NULL){
        m=deleteTreeNode(n->relation_width,master);
        n->numRel--;
        n->relation_width=m;
        }

    }

    }}


}






void deletPers(char nome[],ListNodePtr listaRelazioni,TreeNodePtr accounts){
    if(controlloAccount(nome,accounts)==1){
    deleteTreeNode(accounts,nome);
    ListNodePtr t=NULL;
    t=listaRelazioni;
    TreeNodePtr n,l,p,r;
    while(t!=NULL){
    //int D=controlloAccount(nome,t->ralazione);
    n=searchTreeNode(t->ralazione,nome);
    if(n!=NULL){


        n->numRel=0;
        //r=deleteTree(n->relation_width);

        n->numRel=0;
        n->relation_width=r;

        p=deleteTreeNode(t->ralazione,nome);
        t->ralazione=p;



    }


    l=deleteNome(nome,t->ralazione);
    t->ralazione=l;


    t=t->succ;


    }
    }
}






void report(ListNodePtr listaRelazioni){
    ListNodePtr t=NULL;
    t=listaRelazioni;
    TreeNodePtr root;
    int MassimoValore;

    if(t==NULL){
        fputs("none\n",stdout);
    }

    while(t!=NULL){
        root=t->ralazione;
        if (root != NULL ) {
        MassimoValore=0;
        MassimoValore=cercaMassimoValore(t->ralazione,MassimoValore,0,0);

        if(MassimoValore!=0){
            fputs("\"",stdout);
            fputs(t->data,stdout);
            fputs("\"",stdout);
            viewTreeInOrder2(t->ralazione,MassimoValore);
            //fputs(MassimoValore,stdout);
            printf(" %d; ",MassimoValore);
            if((t->succ)->data==NULL)
                printf("\n");
        }
    }

        t=t->succ;
    }
}
