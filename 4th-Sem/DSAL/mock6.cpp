#include <iostream>
#include <string>
#include <map>
using namespace std;

class Node {
    string data;
    Node *next;

public:
    Node() {
        data = "";               
        next = NULL;
    }
    Node(string val) {
        data = val;
        next = NULL;
    }
    friend class Graph;
    friend class Stack;
    friend class Queue;
};

class Stack
{
    Node *data[20];
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
    void push(Node* ele)
    {
        data[++top]=ele;
    }
    void pop()
    {
        top--;
    }
    Node* Top()
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
    void push(Node* n)
    {
        if(f == NULL && r == NULL)
        {
            f = n;
            r = n;
        }
        else
        {
            r->next = n;
            r = n;
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
    Node* getFront()
    {
        return f;
    }
};

class Graph
{
    int s;
    map<string, Node*> arr;
public:
    Graph()
    {
        s = 0;
    }
    Graph(int ms)
    {
        s = ms;
    }
    void addedge(string src, string dest)
    {
        Node *temp1 = new Node(src);
        Node *temp2 = new Node(dest);
        Node *ptr;
        if(arr.find(src) == arr.end())
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
        if(arr.find(dest) == arr.end())
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
        for(auto it = arr.begin(); it != arr.end(); it++)
        {
            cout<<"Vertex "<<it->first<<" -> ";
            Node *temp = it->second->next;
            while(temp)
            {
                cout<<temp->data<<" -> ";
                temp= temp->next;
            }
            cout<<endl;
        }
    }
    void DFSwithR(string src) {
        bool *visit = new bool[s];
        for(int i = 0; i < s; i++) {
            visit[i] = false;
        }
        recursiveDFS(src, visit);
        cout << endl;
    }

    void recursiveDFS(string src, bool visit[]) {
        visit[stoi(src)] = true;
        cout << src << " ";
        Node *temp = arr[src]->next;
        while (temp != NULL) {
            if (!visit[stoi(temp->data)])
                recursiveDFS(temp->data, visit);
            temp = temp->next;
        }
    }
    void DFSwithoutR(string src)
    {
        Stack st;
        bool *visit = new bool[s];
        for(int i = 0; i < s; i++) {
            visit[i] = false;
        }
        st.push(arr[src]);
        visit[stoi(src)]=true;
        while(!st.isEmpty())
        {
            src = st.Top()->data;
            st.pop();
            cout<<src<<" ";
            Node *temp = arr[src]->next;
            while(temp!=NULL)
            {
                if(!visit[stoi(temp->data)])
                {
                    visit[stoi(temp->data)] = true;
                    st.push(arr[temp->data]);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }

    void BFS(string src)
    {
        Queue q;
        bool *visit = new bool[s];
        for(int i = 0; i < s; i++) {
            visit[i] = false;
        }
        q.push(arr[src]);
        visit[stoi(src)] = true;
        while(!q.empty())
        {
            src = q.getFront()->data;
            q.pop();
            cout<<src<<" ";
            Node *temp = arr[src]->next;
            while(temp!=NULL)
            {
                if(!visit[stoi(temp->data)])
                {
                    visit[stoi(temp->data)] = true;
                    q.push(arr[temp->data]);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }
    void calculateDegree()
    {
        for(auto it = arr.begin(); it != arr.end(); it++)
        {
            int degree = 0;
            Node *temp = it->second->next;
            while(temp)
            {
                degree++;
                temp = temp->next;
            }
            cout << "Vertex " << it->first << " has degree: " << degree << endl;
        }
    }
};

int main() {
    int v ,ch;
    string v1,v2,vstart;
    cout<<"Enter Number  of vertices "<<endl;
    cin>>v;
    Graph g(v);
    do
    {
        cout<<"Enter Choice \n 1.To add edge \n 2.Display \n 3.DFS \n 4.BFS \n 5.Degree \n 6.Exit "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter source vertex "<<endl;
                    cin>>v1;
                    cout<<"Enter destination vertex "<<endl;
                    cin>>v2;
                    g.addedge(v1,v2);
                    break;
            case 2: g.display();
                    break;
            case 3: cout<<"Enter the start vertex "<<endl;
                    cin>>vstart;
                    g.DFSwithoutR(vstart);
                    g.DFSwithR(vstart);
                    break;
            case 4: cout<<"Enter the start vertex "<<endl;
                    cin>>vstart;
                    g.BFS(vstart);
                    break;
            case 5: g.calculateDegree();
                    break;
            case 6: break;
        }
    }while(ch!=6);
    return 0;
}
