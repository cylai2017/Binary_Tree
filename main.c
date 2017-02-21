#include<stdio.h>
#include <stdlib.h>

typedef struct nd {
    int data;
    struct node *left;
    struct node *right;
} node;

node* Create_node(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* Insert(node* root, int input_data) {
    if (root == NULL) {
        node* now_node = (node*)malloc(sizeof(node));
        now_node->data = input_data;
        now_node->left = NULL;
        now_node->right = NULL;
        return(now_node);
    }
    else {
        if (input_data <= root->data) root->left = Insert(root->left, input_data);
        else {root->right = Insert(root->right, input_data);}
        return(root);
    } 
}

void PreOrder_Traversal(node *root) {
    if(root != NULL) {
        printf("%d ",root->data);
        PreOrder_Traversal(root->left);
        PreOrder_Traversal(root->right);
    }
}

void InOrder_Traversal(node *root) {
    if(root != NULL) {
        InOrder_Traversal(root->left);
        printf("%d ",root->data);
        InOrder_Traversal(root->right);
    }
}

void PostOrder_Traversal(node *root) {
    if(root != NULL) {
        PostOrder_Traversal(root->left);
        PostOrder_Traversal(root->right);
        printf("%d ", root->data);
    }
}

int main(int argc, const char * argv[]) {
    int binary_tree[10] = {3,1,6,10,4,8,7,2,9,5};
    node *root = NULL;
    
    for(int i=0; i<10; i++){
        root = Insert(root,binary_tree[i] );
    }
    
    printf("Preorder traversal :");
    PreOrder_Traversal(root);
    printf("\ninorder traversal :");
    InOrder_Traversal(root);
    printf("\nPostorder traversal :");
    PostOrder_Traversal(root);
    
    free(root);
    
    printf("\n");
    
    return 0;
}
