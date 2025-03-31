#include <iostream>
using namespace std;

class Node {
	string key;
	string meaning;
	Node *left;
	Node *right;
	int height;
public:
	Node() {
		key = "";
		meaning = "";
		left = NULL;
		right = NULL;
		height = 0;
	}

	Node(string key, string meaning) 
	{
		this->key = key;
		this->meaning = meaning;
		left = right = NULL;
		height = 1;
	}

	friend class AVL;
};

class AVL {
	Node *root;
public:
	AVL() {
		root = NULL;
	}

	void insert(string key, string meaning) {
		this->root = insert(root, key, meaning);
	}

	void printInorder() {
		inorder(root);
	}

	void printPreorder() {
		preorder(root);
	}

    int search(string key) {
		int comparisons = 0;
		search(root, key, comparisons);
		return comparisons;
	}
private:
	int height(Node *node) {
		if (node == NULL) {
			return 0;
		}
		return node->height;
	}

	int getBF(Node *node) {
		if (node == NULL) {
			return 0;
		}
		return height(node->left) - height(node->right);
	}

	int max(int a, int b) {
		return (a > b ? a : b);
	}

	Node* rotateRight(Node *p) {
		Node *pl = p->left;
		Node *plrc = pl->right;

		//rotate
		pl->right = p;
		p->left = plrc;

		//update height
		p->height = max(height(p->left), height(p->right));
		pl->height = max(height(pl->left), height(pl->right));

		return pl;
	}

	Node* rotateLeft(Node *p) {
		Node *pr = p->right;
		Node *prlc = pr->left;

		//rotate
		pr->left = p;
		p->right = prlc;

		//update height

		p->height = max(height(p->left), height(p->right));
		pr->height = max(height(pr->left), height(pr->right));

		return pr;
	}


	//Insert a Node
	Node* insert(Node *node, string key, string meaning) {
		Node *new_node = new Node(key, meaning);

		if (node == NULL) {
			return new_node;
		}

		if (key < node->key) {
			node->left = insert(node->left, key, meaning);
		} else if (key > node->key) {
			node->right = insert(node->right, key, meaning);
		} else {
			return node;
		}

		//update height
		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBF(node);

		//LL
		if (balance > 1 && key < node->left->key) {
			cout << "LL" << endl;
			return rotateRight(node);
		}

		if (balance < -1 && key > node->right->key) {
			cout << "RR" << endl;
			return rotateLeft(node);
		}

		//LR
		if (balance > 1 && key > node->left->key) {
			cout << "LR" << endl;
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		//RL
		if (balance < -1 && key < node->right->key) {
			cout << "RL" << endl;
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;

	}

	//Inorder Traversal
	void inorder(Node *node) {

		if (node != NULL) {

			inorder(node->left);
			cout << node->key << " \t "<<node->meaning <<" - "<< getBF(node) <<endl;
			inorder(node->right);

		}
	}

	//Preorder Traversal
	void preorder(Node *node) {

		if (node != NULL) {

			cout << node->key << "" << getBF(node) << " | ";
			preorder(node->left);
			preorder(node->right);

		}
	}

    	//Search for a node
		Node* search(Node *node, string key, int &comparisons)
		{
		comparisons++;
		if (node == NULL || node->key == key) {
			return node;
		}

		if (key < node->key) {
			return search(node->left, key, comparisons);
		}
		return search(node->right, key, comparisons);
	}
};

int main() {

	AVL avl;

	bool flag = true;
	int ch;
	string key, meaning;

	while(flag){
		cout<<"\n======== AVL Dictionary ========="<<endl;
		cout<<"1. Add Words to Dictionary "<<endl;
		cout<<"2. Display Words( Ascending order) "<<endl;
		cout<<"3. Search & Comparsion "<<endl;
		cout<<"4. Exit.."<<endl;
		cout<<"\n Enter Your Choice: ";
		cin>>ch;

		switch(ch){
		case 1:
			cout<<"Enter word: ";
			cin>>key;
			cout<<"Enter Meaning: ";
			cin>>meaning;

			avl.insert(key, meaning);
			break;
		case 2:
			cout<<"Words in Ascending Order: "<<endl;
			cout<<"Word\tMeaning\tBF"<<endl;
			avl.printInorder();
			cout<<endl;
			break;
		case 3:
				cout << "Enter the word to search: ";
			cin >> key;
			{
				int comparisons = avl.search(key);
				if (comparisons != 0)
					cout << "Word found in " << comparisons << " comparisons." << endl;
				else
					cout << "Word not found." << endl;
			}
			break;
		case 4:
			cout<<"ThankYou:)"<<endl;
			flag =false;
			break;
		default:
			cout<<"Invalid Input!!"<<endl;
			break;
		}


	}
	return 0;
}