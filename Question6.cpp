#include<iostream>
using namespace std;
struct node
{
	int data;
	node* LeftNode;
	node* RightNode;

};
class Tree
{
public:
	int c;
	node* root;
	Tree()
	{
		root = NULL;
	}
	void insert_node(int);
	void display(node* r);
	void IsEmpty();
	void ConvertBSTtoMinHeep();
	void preorderDisplay(node* leaf);
	int nodesCount(node* leaf);
	void inorder(node* leaf, int* arr);
	void preorder(node* leaf, int* arr);
	void enqueue(int x, int* arr);


	
};
void Tree::insert_node(int val)
{
	node* new_node = new node;
	new_node->data = val;
	new_node->LeftNode = NULL;
	new_node->RightNode = NULL;
	node* temp = root;
	if (root == NULL)
	{
		root = new_node;
	}
	while (temp != NULL)
	{

		if (root->data == new_node->data)
		{
			break;
		}

		else if (temp->LeftNode == NULL)
		{
			temp->LeftNode = new_node;
			break;
		}

		else if (temp->RightNode == NULL)
		{
			temp->RightNode = new_node;
			break;
		}
		else
		{
			temp = temp->RightNode;
		}

	}

}



void Tree::display(node* r)
{
	if (r == NULL)
	{
		return;
	}
	display(r->LeftNode);
	cout << r->data << "  ";
	display(r->RightNode);
}


void Tree :: preorder(node* leaf, int* arr)
{

	if (leaf != NULL)
	{
		leaf->data = arr[c];
		c++;
		preorder(leaf->LeftNode, arr);
		preorder(leaf->RightNode, arr);

	}
	else return;
}
 
void Tree::IsEmpty()
{
	if (root == NULL)
	{
		cout << "Your Tree is Empty" << endl;
	}
	else
	{
		cout << "Your tree is not Empty" << endl;
	}
}

void Tree :: preorderDisplay(node* leaf)
{
	if (leaf != NULL)
	{
		cout << leaf->data << endl;
		preorderDisplay(leaf->LeftNode);

		preorderDisplay(leaf->RightNode);
	}
	else return;
}

int Tree:: nodesCount(node* leaf)
{
	if (leaf == NULL)
		return 0;
	return nodesCount(leaf->LeftNode) + nodesCount(leaf->RightNode) + 1;
}

void Tree:: enqueue(int x, int* arr)
{
	arr[c] = x;
	c++;
}

void Tree:: inorder(node* leaf, int* arr)
{
	if (leaf != NULL)
	{
		inorder(leaf->LeftNode, arr);
		enqueue(leaf->data, arr);
		inorder(leaf->RightNode, arr);
	}
	else return;
}

void Tree :: ConvertBSTtoMinHeep()
{
	int size = nodesCount(root);
	int* arr = new int[size];
	inorder(root, arr);
	c = 0;
	preorder(root, arr);
	cout << "After Convertion: \n";
	preorderDisplay(root);
}

int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()				---> Press 1" << endl
			<< "IsEmpty()				---> Press 2" << endl
			<< "Display()				---> Press 3" << endl
			<< "ConvertBSTtoMinHeep()			---> Press 4" << endl
			<< "Exit()					---> Press 0" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			while (val != 0000)
			{

				cout << "Enter the Element You want to insert/ Enter 0000 To exit: " << endl;
				cin >> val;
				if (val != 0000)
				{


					obj.insert_node(val);
				}
			}

			break;
		}

		
		case 2:
		{
			obj.IsEmpty();
			break;
		}
		case 3:
		{
			obj.display(obj.root);
			cout << endl;
			break;
		}
		case 4:
		{
			obj.ConvertBSTtoMinHeep();
			break;

		}
		
		default:
		{
			cout << "Select the Correct Option" << endl;
		}


		}
	} while (opt != 0);
}