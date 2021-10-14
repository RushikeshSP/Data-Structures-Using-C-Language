/*

Que : Write a C program for Creation of BST and it's various operations.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.
#include<stdlib.h>


struct node
{
	struct node* left;
	int data;
	struct node* right;
};

struct node* createNode()
{
	struct node* newnode = NULL;

	newnode = (struct node*)malloc(sizeof(struct node));

	if (!(newnode == NULL))
	{
		int data;
		printf("Enter a data: ");
		scanf_s("%d", &data);

		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	else
	{
		printf("Node not created.\n");
	}
	return newnode;
}

void createBST(struct node** root)
{
	struct node* newnode = NULL;
	struct node* tempnode = *root;
	newnode = createNode();

	if (*root == NULL)
	{
		*root = newnode;
	}
	else
	{
		while(tempnode != NULL)
		{
			if (newnode->data < tempnode->data)
			{
				 if(tempnode->left == NULL)
				 {
					 tempnode->left = newnode;
					 break;
				 }
				 else
				 {
					 tempnode = tempnode->left;
				 }
			}
			else
			{
				if (tempnode->right == NULL)
				{
					tempnode->right = newnode;
					break;
				}
				else
				{
					tempnode = tempnode->right;
				}
			}
		}
	}
}

void preorder(struct node* root)
{
	if (root != NULL)
	{
		printf("%d =>", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d =>", root->data);
		inorder(root->right);
	}
}


void postorder(struct node* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d =>", root->data);
	}
}

void main()
{
	struct node* root = NULL;
	int choice;

	do
	{
		printf("********************************************\n");
		printf("Please Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create BST.\n");
		printf("2. Preorder Traversal.\n");
		printf("3. Inorder Traversal.\n");
		printf("4. Postorder Traversal.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("********************************************\n");

		switch (choice)
		{
		case 0:
			printf("Thank you!!!\n");
			break;
		case 1:
			createBST(&root);
			break;
		case 2:
			printf("Preorder Traversal: ");
			preorder(root);
			printf("\n");
			break;
		case 3:
			printf("Inorder Traversal: ");
			inorder(root);
			printf("\n");
			break;
		case 4:
			printf("Postorder Traversal: ");
			postorder(root);
			printf("\n");
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
			break;
		}
	} while (choice != 0);
}