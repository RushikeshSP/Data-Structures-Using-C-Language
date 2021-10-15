/*

Que : Write a C program for Creation of BST and it's various operations.
Owner: Rushikesh Sanjay Pokharkar
Batch: PPA9

*/

//                                        *********  Solution  *********


#include<stdio.h> //Include Necessary Header Files.
#include<stdlib.h>


struct node // Structure of the BST.
{
	struct node* left;
	int data;
	struct node* right;
};

struct node* createNode() // Function to create node for the BST.
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

void createBST(struct node** root) // Function to create BST.
{
	struct node* newnode = NULL;
	struct node* tempnode = *root;
	newnode = createNode();

	if (*root == NULL) // If given node is the first node in the BST.
	{
		*root = newnode;
	}
	else
	{
		while(tempnode != NULL) // Condition for traversal of BST.
		{
			if (newnode->data < tempnode->data) // If given node data is less then root node's data.
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
			else // Given node data is greater than root node's data.
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

void preorder(struct node* root) // Function for preorder traversal of BST.
{
	if (root != NULL)
	{
		printf("%d => ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node* root) // Function for inorder traversal of BST.
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d => ", root->data);
		inorder(root->right);
	}
}

void postorder(struct node* root) // Function for postorder traversal of the BST.
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d => ", root->data);
	}
}

void insertNode(struct node** root) // Function to insert node in to the BST.
{
	createBST(root);
}

int searchNode(struct node* root, int search) // Function to search node into the BST.
{
	if (root != NULL)
	{
		if (root->data == search) // Data found condition.
		{
			return 1;
		}
		else if (search > root->data)
		{
			searchNode(root->right, search);
		}
		else
		{
			searchNode(root->left, search);
		}
	}
	else
	{
		return 0; // If data not found return 0.
	}
}

void countNode(struct node* root, int* count) // Function to count the total nodes in the BST.
{
	if (root != NULL)
	{
		(*count)++;
		countNode(root->left, count);
		countNode(root->right, count);
	}
}

void countLeafNode(struct node* root, int* count) // Function to count the total leaf nodes in the BST.
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL) // Condition to check leaf node.
		{
			(*count)++;
		}
		countLeafNode(root->left, count);
		countLeafNode(root->right, count);
	}
}

void printLeafNodes(struct node* root) // Function to print the leaf nodes from BST.
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL) // Condition to check leaf node.
		{
			printf("%d => ", root->data);
		}
		printLeafNodes(root->left);
		printLeafNodes(root->right);
	}
}

void heightOfTree(struct node* root) // Function to find the height of the tree
{
	int leftHeight = 0, rightHeight = 0;
	struct node* Root = root;

	while (root != NULL)
	{
		leftHeight++;
		root = root->left;
	}
	while (Root != NULL)
	{
		rightHeight++;
		Root = Root->right;
	}

	if (leftHeight > rightHeight)
	{
		printf("The Height of BST is: %d\n", leftHeight);
	}
	else
	{
		printf("The Height of BST is: %d\n", rightHeight);
	}
}

void deleteNode(struct node** root, int num)
{

}

void main()
{
	struct node* root = NULL;
	int choice, count;

	do
	{
		// Menu for the program.
		printf("********************************************\n");
		printf("Please Enter Your Choice: \n");
		printf("0. Exit.\n");
		printf("1. Create BST.\n");
		printf("2. Preorder Traversal.\n");
		printf("3. Inorder Traversal.\n");
		printf("4. Postorder Traversal.\n");
		printf("5. Insert Node.\n");
		printf("6. Search Node.\n");
		printf("7. Count Nodes.\n");
		printf("8. Count Leaf Nodes.\n");
		printf("9. Print Leaf Nodes.\n");
		printf("10. Print Height of BST.\n");
		printf("11. Delete Node.\n");
		printf("Choice = ");
		scanf_s("%d", &choice);
		printf("********************************************\n");

		switch (choice) // Switch case to execute user input.
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
		case 5:
			insertNode(&root);
			break;
		case 6:
			printf("Enter the search Element: ");
			int search;
			scanf_s("%d", &search);
			if (searchNode(root, search))
			{
				printf("Given element %d is found in BST.\n", search);
			}
			else
			{
				printf("Given element %d is NOT found in BST.\n", search);
			}
			break;
		case 7:
			count = 0;
			countNode(root, &count);
			printf("The Total Number of Nodes in BST are: %d \n", count);
			break;
		case 8:
			count = 0;
			countLeafNode(root, &count);
			printf("The Total Number of Leaf Nodes in BST are: %d \n", count);
			break;
		case 9:
			printf("Leaf Nodes: ");
			printLeafNodes(root);
			printf("\n");
			break;
		case 10:
			heightOfTree(root);
			break;
		case 11:
			printf("Enter Element which you want to delete: ");
			int num;
			scanf_s("%d", &num);
			deleteNode(&root, num);
			break;
		default:
			printf("Please Enter a Valid Choice.\n");
			break;
		}
	} while (choice != 0);
}