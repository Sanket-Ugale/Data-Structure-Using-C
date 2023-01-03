#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create(){
    int data;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data (press -1 for no NODE): ");
    scanf("%d",&data);
    if (data==-1)
    {
        return 0;
    }
    newnode->data=data;
    printf("\nEnter left child of %d: ",data);
    newnode->left=create();    
    printf("\nEnter right child of %d: ",data);
    newnode->right=create();    
    return newnode;
}

void preorder(struct node *root){
    if (root==0)
    {
        return;
    }
    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if (root==0)
    {
        return;
    }
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if (root==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
}

int main(){
    struct node *root;
    printf("\n\nCREATE TREE: \n");
    root=create();
    printf("\n\nPREORDER of TREE: \n");
    preorder(root);
    printf("\n\nINORDER of TREE: \n");
    inorder(root);
    printf("\n\nPOSTORDER of TREE: \n");
    postorder(root);
}
