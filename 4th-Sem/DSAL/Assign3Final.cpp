// Author: Geeksforgeeks code modified

#include <iostream>
using namespace std;

// Class of the Node
class Node {
	int lbit, rbit;
	int value;
	Node *left, *right;

public:
	// Constructor of the
	// Node of the Tree
	Node()
	{
		lbit = rbit = 0;
		value = 0;
		left = right = NULL;
	}
	friend class DTBT;
};

// Class of the Threaded
// Binary search tree
class DTBT {
	Node* root;

public:
	// Constructor of the
	// Threaded of the Binary
	// Search Tree
	DTBT()
	{
		root = new Node();

		// Initialise the dummy node
		// to any random value of
		// your choice.
		root->value = 9999;

		// Considering our whole
		// tree is at left of
		// dummy node
		root->rbit = 1;
		root->lbit = 0;

		// Consider your whole tree
		// lies to the left of
		// this dummy node.
		root->left = root;
		root->right = root;
	}
    Node* getRoot();
	void create();
	void insert(int value);
	void preorder();
	Node* preorderSuccessor(Node*);
	void inorder();
	Node* inorderSuccessor(Node*);
    Node* inorderPredecessor(Node*);
    Node* caseA(Node*, Node*, Node*);
    Node* caseB(Node*, Node*, Node*);
    Node* caseC(Node*, Node*, Node*);
    Node* delThreadedBST(Node*, int);

};

Node* DTBT::getRoot() {
    return root->left;
}

// Function to create the Binary
// search tree
void DTBT::create()
{
	int n, ele;
    cout << "Enter the number of elements you want to insert in the TBST: ";
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cout << "Enter the element: ";
        cin >> ele;
        this->insert(ele); 
    }

	// // Insertion of the nodes
	// this->insert(6);
	// this->insert(3);
	// this->insert(1);
	// this->insert(5);
	// this->insert(8);
	// this->insert(7);
	// this->insert(11);
	// this->insert(9);
	// this->insert(13);
}

// Function to insert the nodes
// into the threaded binary
// search tree
void DTBT::insert(int data)
{
	// Condition to check if there
	// is no node in the binary tree
	if (root->left == root
		&& root->right == root) {

		Node* p = new Node();
		p->value = data;
		p->left = root->left;
		p->lbit = root->lbit;
		p->rbit = 0;
		p->right = root->right;

		// Inserting the node in the
		// left of the dummy node
		root->left = p;
		root->lbit = 1;
		return;
	}

	// New node
	Node* cur = new Node;
	cur = root->left;
	while (1) {
		// Condition to check if the
		// data to be inserted is
		// less than the current node
		if (cur->value < data) {
			Node* p = new Node();
			p->value = data;
			if (cur->rbit == 0) {
				p->right = cur->right;
				p->rbit = cur->rbit;
				p->lbit = 0;
				p->left = cur;

				// Inserting the node
				// in the right
				cur->rbit = 1;
				cur->right = p;
				return;
			}
			else
				cur = cur->right;
		}

		// Otherwise insert the node
		// in the left of current node
		if (cur->value > data) {
			Node* p = new Node();
			p->value = data;
			if (cur->lbit == 0) {
				p->left = cur->left;
				p->lbit = cur->lbit;
				p->rbit = 0;

				// Pointing the right child
				// to its inorder Successor
				p->right = cur;
				cur->lbit = 1;
				cur->left = p;
				return;
			}
			else
				cur = cur->left;
		}
	}
}

// In Threaded binary search tree
// the left pointer of every node
// points to its Inorder predecessor,
// whereas its right pointer points
// to the Inorder Successor
void DTBT::preorder()
{
	Node* c = root->left;

	// Loop to traverse the tree in
	// the preorder fashion
	while (c != root) {
		cout << " " << c->value;
		c = preorderSuccessor(c);
	}
}

// Function to find the preorder
// Successor of the node
Node* DTBT::preorderSuccessor(Node* c)
{
	if (c->lbit == 1) {
		return c->left;
	}
	while (c->rbit == 0) {
		c = c->right;
	}
	return c->right;
}

// In Threaded binary search tree
// the left pointer of every node
// points to its Inorder predecessor
// whereas its right pointer points
// to the Inorder Successor
void DTBT::inorder()
{
	Node* c;
	c = root->left;
	while (c->lbit == 1)
		c = c->left;

	// Loop to traverse the tree
	while (c != root) {
		cout << " " << c->value;
		c = inorderSuccessor(c);
	}
}

// Function to find the inorder
// successor of the node
Node* DTBT::inorderSuccessor(Node* c)
{
	if (c->rbit == 0)
		return c->right;
	else
		c = c->right;
	while (c->lbit == 1) {
		c = c->left;
	}
	return c;
}

Node* DTBT::inorderPredecessor(Node* ptr)
{
    if (ptr->lbit == 0)
        return ptr->left;
 
    ptr = ptr->left;
    while (ptr->rbit == 1)
        ptr = ptr->right;
    return ptr;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
Node* DTBT::caseA(Node* root, Node* par, Node* ptr)
{
	// If Node to be deleted is root
	if (par == NULL)
		root = NULL;

	// If Node to be deleted is left
	// of its parent
	else if (ptr == par->left) {
		par->lbit = 0;
		par->left = ptr->left;
	}
	else {
		par->rbit = 0;
		par->right = ptr->right;
	}

	// Free memory and return new root
	free(ptr);
	return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
Node* DTBT::caseB(Node* root, Node* par, Node* ptr)
{
	Node* child;

	// Initialize child Node to be deleted has
	// left child.
	if (ptr->lbit == 1)
		child = ptr->left;

	// Node to be deleted has right child.
	else
		child = ptr->right;

	// Node to be deleted is root Node.
	if (par == NULL)
		root = child;

	// Node is left child of its parent.
	else if (ptr == par->left)
		par->left = child;
	else
		par->right = child;

	// Find successor and predecessor
	Node* s = inorderSuccessor(ptr);
	Node* p = inorderPredecessor(ptr);

	// If ptr has left subtree.
	if (ptr->lbit == 1)
		p->right = s;

	// If ptr has right subtree.
	else {
		if (ptr->rbit == 1)
			s->left = p;
	}

	free(ptr);
	return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
Node* DTBT::caseC(Node* root, Node* par, Node* ptr)
{
	// Find inorder successor and its parent.
	Node* parsucc = ptr;
	Node* succ = ptr->right;

	// Find leftmost child of successor
	while (succ->lbit == 1) {
		parsucc = succ;
		succ = succ->left;
	}

	ptr->value = succ->value;

	if (succ->lbit == 0 && succ->rbit == 0)
		root = caseA(root, parsucc, succ);
	else
		root = caseB(root, parsucc, succ);

	return root;
}

// Deletes a key from threaded BST with given root and
// returns new root of BST.
Node* DTBT::delThreadedBST(Node* root, int dkey)
{
	// Initialize parent as NULL and ptrent
	// Node as root.
	Node *par = NULL, *ptr = root;

	// Set true if key is found
	int found = 0;

	// Search key in BST : find Node and its
	// parent.
	while (ptr != NULL) {
		if (dkey == ptr->value) {
			found = 1;
			break;
		}
		par = ptr;
		if (dkey < ptr->value) {
			if (ptr->lbit == 1)
				ptr = ptr->left;
			else
				break;
		}
		else {
			if (ptr->rbit == 1)
				ptr = ptr->right;
			else
				break;
		}
	}

	if (found == 0)
		printf("dkey not present in tree\n");

	// Two Children
	else if (ptr->lbit == 1 && ptr->rbit == 1)
		root = caseC(root, par, ptr);

	// Only Left Child
	else if (ptr->lbit == 1)
		root = caseB(root, par, ptr);

	// Only Right Child
	else if (ptr->rbit == 1)
		root = caseB(root, par, ptr);

	// No child
	else
		root = caseA(root, par, ptr);

	return root;
}

int main() {
    DTBT t1;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Display Inorder\n";
        cout << "5. Display Preorder\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t1.create();
                break;
            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> value;
                t1.insert(value);
                break;
            case 3:
                cout << "Enter the element to be deleted: ";
                cin >> value;
                t1.delThreadedBST(t1.getRoot(), value);
                break;
            case 4:
                cout << "Inorder Traversal of DTBST:\n";
                t1.inorder();
                break;
            case 5:
                cout << "Preorder Traversal of DTBST:\n";
                t1.preorder();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}