#include <iostream>
using namespace std;

class Node {
	int data;
	Node *next;
public:
	Node() {
		data = 0;               
		next = NULL;
	}
	Node(int val) {
		data = val;
		next = NULL;
	}
	friend class Graph;
	friend class Stack;
	friend class Queue;
};

class Stack
{
	int data[20];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	bool isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	void push(int ele)
	{
		data[++top]=ele;
	}
	void pop()
	{
		top--;
	}
	int Top()
	{
		return data[top];
	}
};

class Queue
{
	Node *f;
	Node *r;
	int size;
public:
	Queue()
	{
		f = NULL;
		r = NULL;
		size = 0;
	}
	void push(int n)
	{
		Node *temp = new Node();
		temp->data=n;
		temp->next=NULL;
		if(f == NULL && r == NULL)
		{
			f = temp;
			r = temp;
		}
		else
		{
			r->next=temp;
			r=temp;
		}
		size++;
	}
	void pop()
	{
		Node *temp = f;
		if(f == NULL && r == NULL)
		{
			cout<<"Queue is empty"<<endl;
		}
		if(f == r)
		{
			delete f;
			f = NULL;
			r = NULL;
		}
		else
		{
			f = f->next;
			delete temp;
		}
		size--;
	}
	bool empty()
	{
		if(size==0)
			return true;
		else
			return false;
	}
	int getFront()
	{
		return f->data;
	}
};

class Graph
{
	int s;
	Node *arr[20];
public:
	Graph()
	{
		s = 0;
	}
	Graph(int ms)
	{
		s = ms;
		for(int i=0;i<s;i++)
			arr[i]=NULL;
	}
	void addedge(int src,int dest)
	{
		Node *temp1 = new Node();
		temp1->data = src;
		Node *temp2 = new Node();
		temp2->data = dest;
		Node *ptr;
		if(arr[src]==NULL)
		{
			arr[src] = temp2;
		}
		else
		{
			ptr = arr[src];
			while(ptr->next)
			{
				ptr = ptr->next;
			}
			ptr->next =temp2;
		}
		if(arr[dest]==NULL)
				{
					arr[dest] = temp1;
				}
				else
				{
					ptr = arr[dest];
					while(ptr->next)
					{
						ptr = ptr->next;
					}
					ptr->next =temp1;
				}
	}
	void display()
	{
		for(int i=0;i<s;i++)
		{
			cout<<"Vertex "<<i<<" -> ";
			Node *temp = arr[i];
			while(temp)
			{
				cout<<temp->data<<" -> ";
				temp= temp->next;
			}
			cout<<endl;
		}
	}
	void DFSwithR(int src) {
        bool visit[s] = {};
        recursiveDFS(src, visit);
        cout << endl;
    }

    void recursiveDFS(int src, bool visit[]) {
        visit[src] = true;
        cout << src << " ";
        Node *temp = arr[src];
        while (temp != NULL) {
            if (!visit[temp->data])
                recursiveDFS(temp->data, visit);
            temp = temp->next;
        }
    }
	void DFSwithoutR(int src)
	{
		Stack st;
		bool visit[s]={};
		st.push(src);
		visit[src]=1;
		while(!st.isEmpty())
		{
			src = st.Top();
			st.pop();
			cout<<src<<" ";
			Node *temp = arr[src];
			while(temp!=NULL)
			{
				if(visit[temp->data] == 0)
				{
					visit[temp->data]=1;
			
					st.push(temp->data);
				}
				temp=temp->next;
			}
		}
		cout<<endl;
	}

	void BFS(int src)
	{
		Queue q;
		bool visit[s]={};
		q.push(src);
		visit[src]=1;
		while(!q.empty())
		{
			src = q.getFront();
			q.pop();
			cout<<src<<" ";
			Node *temp = arr[src];
			while(temp!=NULL)
			{
				if(visit[temp->data]==0)
				{
					visit[temp->data]=1;
					q.push(temp->data);
				}
				temp = temp->next;
			}
		}
		cout<<endl;
	}
	void calculateDegree()
	{
		for(int i = 0; i < s; ++i)
		{
			int degree = 0;
			Node *temp = arr[i];
			while(temp)
			{
				degree++;
				temp = temp->next;
			}
			cout << "Vertex " << i << " has degree: " << degree << endl;
		}
	}
};

int main() {
	int v ,v1,v2,ch,vstart;
	cout<<"Enter Number  of vertices "<<endl;
	cin>>v;
	Graph g(v);
	do
	{
		cout<<"Enter Choice \n 1.To add edge \n 2.Display \n 3.DFS \n 4.BFS \n 5.Degree \n 6.Exit "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"Enter vertex 1"<<endl;
					cin>>v1;
					cout<<"Enter vertex 2"<<endl;
					cin>>v2;
					g.addedge(v1,v2);
					break;
			case 2:	g.display();
					break;
			case 3:	cout<<"Enter the start vertex "<<endl;
					cin>>vstart;
					g.DFSwithoutR(vstart);
					g.DFSwithR(vstart);
					break;
			case 4:	cout<<"Enter the start vertex "<<endl;
					cin>>vstart;
					g.BFS(vstart);
					break;
			case 5: g.calculateDegree();
					break;
			case 6:	break;
		}
	}while(ch!=6);
	return 0;
}