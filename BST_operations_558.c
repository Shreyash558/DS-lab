#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL) 
	{
        return createNode(value);
    }

    if (value < root->data) 
	{
        root->left = insert(root->left, value);
    }
	else if (value > root->data) 
	{
        root->right = insert(root->right, value);
    }
    return root;
}
void inorderTraversal(struct Node* root)
{
    if (root != NULL)
	{
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void postorderTraversal(struct Node* root)
{
	if(root != NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}
