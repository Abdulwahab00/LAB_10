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
	node* root;
	Tree()
	{
		root = NULL;
	}
	void insert_node(int);
	void display(node* r);
	void IsEmpty();
	bool isComplete(node* leaf, int index, int size);
	int nodesCount(node* leaf);
	
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

bool Tree::isComplete(node* leaf, int index, int size)
{
	if (leaf == NULL)
		return 1;
	if (index >= size)
		return 0;
	int l, r;
	l = 2 * index + 1;
	r = 2 * index + 2;
	return isComplete(leaf->LeftNode, l, size) && isComplete(leaf->RightNode, r, size);
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

int Tree :: nodesCount(node* leaf)
{
	if (leaf == NULL)
		return 0;
	return nodesCount(leaf->LeftNode) + nodesCount(leaf->RightNode) + 1;

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

int main()
{
	Tree obj;
	int opt, val = 1;
	do
	{


		cout << "Insert()	---> Press 1" << endl
			<< "IsEmpty()	---> Press 2" << endl
			<< "Display()	---> Press 3" << endl
			<<"Heep Check	--->Press 4"<<endl
			<< "Exit()		---> Press 0" << endl;
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
			int size = obj.nodesCount(obj.root);
			if (obj.isComplete(obj.root, 0, size))
				cout << "yes, It's a binaray max heap"<<endl;
			else cout << "No, It is not a binaray max heap"<<endl;

		}
		
		default:
		{
			cout << "Select the Correct Option" << endl;
		}


		}
	} while (opt != 0);
}