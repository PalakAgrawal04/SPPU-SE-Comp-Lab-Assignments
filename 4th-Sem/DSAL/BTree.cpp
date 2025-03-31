
#include <iostream>

using namespace std;



class treenode

{

	int data;

	treenode *lc,*rc;

public:

	friend class tree;

	friend class stack;

	treenode()

	{

		data=0;

		lc=NULL;

		rc=NULL;

	}

};



class stack

{

	treenode *s[20];

	int top;

public:

	stack()

	{

		top=-1;

	}

	void push(treenode *x)

	{

		s[++top]=x;

	}

	void pop()

	{

		top--;

	}

	treenode *gettop()

	{

		return s[top];

	}

	bool isempty()

	{

		if(top==-1)

			return true;

		else

			return false;

	}

	// friend class treenode;

};



class tree

{



	treenode *root;

	treenode *maketree();

public:

	tree(){

		root=NULL;

	}

	tree operator=(tree t)

	{

		tree temp;

		temp.root = copy(t.root);

		return temp;

	}

	void create()

	{

		root=maketree();

	}

	void inorder(treenode *T)

	{

		if(T==NULL)

			return;

		inorder(T->lc);

		cout<<T->data<<" ";

		inorder(T->rc);

	}

	void nonr_inorder(treenode *T)

	{

		stack s1;

		while(1)

		{

			while(T!=NULL)

			{

				s1.push(T);

				T=T->lc;

			}

			if(s1.isempty())

				return;

			T=s1.gettop();

			s1.pop();

			cout<<T->data<<" ";

			T=T->rc;

		}

	}

	void nonr_preorder(treenode *T)

		{

			stack s1;

			while(1)

			{

				while(T!=NULL)

				{

					s1.push(T);

					cout<<T->data<<" ";

					T=T->lc;

				}

				if(s1.isempty())

					return;

				T=s1.gettop();

				s1.pop();

				T=T->rc;

			}

		}

	void nonr_postorder(treenode *T)

		{

			stack s1;

			treenode *lv = new treenode();

			while(1)

			{

				while(T!=NULL)

				{

					s1.push(T);

					if(T->rc!=NULL)

					{

						s1.push(T->rc);

						s1.push(lv);

					}

					T=T->lc;

				}

				if(s1.isempty())

					return;

				T=s1.gettop();

				s1.pop();

				while(T!=lv && !s1.isempty())

				{

					cout<<T->data<<" ";

					T=s1.gettop();

					s1.pop();

				}

				if(!s1.isempty()){

					T=s1.gettop();

					s1.pop();

				}

			}

		}

	void preorder(treenode *T)

		{

			if(T==NULL)

				return;

			cout<<T->data<<" ";

			preorder(T->lc);

			preorder(T->rc);

		}

	void postorder(treenode *T)

		{

			if(T==NULL)

				return;

			postorder(T->lc);

			postorder(T->rc);

			cout<<T->data<<" ";

		}

	void traversal()

		{

			cout<<"Inorder traversal : "<<endl;

			inorder(root);

			cout<<"\nPreorder traversal : "<<endl;

			preorder(root);

			cout<<"\nPostorder traversal : "<<endl;

			postorder(root);

			cout<<"\nNon Recur Inorder traversal"<<endl;

			nonr_inorder(root);

			cout<<"\nNon Recur Preorder traversal"<<endl;

			nonr_preorder(root);

			cout<<"\nNon Recur Postorder traversal"<<endl;

			postorder(root);

		}

	void inter(treenode *T)

	{

		treenode *temp;

		if(T==NULL)

			return;

		inter(T->lc);

		inter(T->rc);

		temp = T->lc;

		T->lc = T->rc;

		T->rc = temp;

	}

	void swap()

	{

		inter(root);

		inorder(root);

		cout<<endl;

	}



	int h(treenode *T)

	{

		int x=0,y=0;

		if(T==NULL)

			return 0;

		x = h(T->lc);

		y = h(T->rc);

		if(x>y)

			return x+1;

		else

			return y+1;

	}

	void height()

	{

		cout<<"Height is "<<h(root)<<endl;

	}



	 int leaf(treenode *T)
	 {
		    if(T == NULL)
		        return 0;
		    if(T->lc == NULL && T->rc == NULL)
		        return 1;
		    else
		        return leaf(T->lc)+ leaf(T->rc);
	 }

	 int internalnode(treenode *T)

	 {

		 if(T == NULL || T->lc == NULL && T->rc == NULL)

			 return 0;

		 return 1 + internalnode(T->lc)+ internalnode(T->rc);

	 }

	 void number()

	 {

		 cout<<"No of Leaf: "<<leaf(root)<<endl;

		 cout<<"No of internal node "<<internalnode(root)<<endl;

	 }



	 void dt(treenode *T)

	 {

		 if(T==NULL)

			 return;

		 dt(T->lc);

		 dt(T->rc);

		 cout<<"Deleting node : "<<T->data<<endl;

		 delete T;

	 }

	 void deleteTree()

	 {

		 dt(root);

	 }

	 treenode* copy(treenode*T)

	 	{

	 		if(T==NULL)

	 			return T;

	 		treenode *root1 = new treenode();

	 		root1->data = T->data;

	 		root1->lc = copy(T->lc);

	 		root1->rc = copy(T->rc);

	 		return root1;

	 	}

};



treenode *tree::maketree()

{

	treenode *temp;

	char ch;

	temp = new treenode();

	cout<<"Enter data : "<<endl;

	cin>>temp->data;

	cout<<"Enter Right Child?(Y/N): "<<endl;

	cin>>ch;

	if(ch=='Y')

		temp->rc=maketree();

	cout<<"Enter Left Child?(Y/N): "<<endl;


	cin>>ch;

	if(ch=='Y')

		temp->lc=maketree();

	return temp;

}

int main() {

	tree t,t1;

	int ch;

	cout<<"Create the tree :"<<endl;

	t.create();

	do

	{

		cout<<"Menu: \n 1.Traversal \n 2.Swapping \n 3.Find Height \n 4.Copy tree \n 5.Count Leaf nodes and internal nodes \n 6. Erase all \n 7.Exit"<<endl;

		cout<<"Enter choice : "<<endl;

		cin>>ch;

		switch(ch)

		{

		case 1:	t.traversal();

				break;

		case 2: t.swap();

				break;

		case 3: t.height();

				break;

		case 4: t1=t;

				t1.traversal();

				cout<<"Copied Successfully !"<<endl;

				break;

		case 5: t.number();

				break;

		case 6: t.deleteTree();

				break;

		default: break;

		}

	}while(ch!=7);



	return 0;

}