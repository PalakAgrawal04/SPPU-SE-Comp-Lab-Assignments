#include <iostream>
using namespace std;
class node{
int data;
node *lc ,*rc;
public:
node(int x){
    data=x;
    lc=NULL;
    rc=NULL;
}
friend class Stack;
friend class Queue;
friend class BST; 
};
class Stack{
    node *s[20];
    int top;
    public:
    Stack(){
        top =-1;
    }
    void push(node* d)
    {
        s[++top]=d;
    }
    void pop(){
        top--;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    node *gettop(){
        return s[top];
    }
};

class Queue{
    node *q[20];
    int f,r;
    public:
    Queue(){
        f=-1;
        r=-1;
    }
    void push(node *d){
        if(f==-1 && r==-1)
    {
        q[++r]=d;
        f=0;
    }
    else {
            q[++r] = d;
        }
    
    }
    void pop(){
        ++f;
         if (f > r) { // Reset f and r when the queue becomes empty
            f = -1;
            r = -1;
        }
    }
    bool isEmpty(){
        if(f==-1 && r==-1)
            return true;
        else 
            return false;
    }
    node *getfront()
    {
        return q[f];
    }
};

class BST{
    public:
    BST(){
        root = NULL;
    }
    void create(){
        int value;
        cout<<"Enter Data to insert into BST (-1 to stop): ";
        cin>>value;
        while(value!=-1){
            root = insertbst(root, value);
            cout<<"enter data:";
            cin>>value;
        }
    }
    void Insert(int data) {
        root = insertbst(root, data);
    }
    void Delete(int key) {
        root = deletenode(root, key);
    }
    void traversal(){
        cout<<"Ascend"<<endl;
        inorderAscendeing(root);
        cout<<"Descend"<<endl;
        inorderDesecending(root);
    }
    void searchBSt(int key){
        int c = search(root,key);
        cout<<"Number of comp "<<c;
    }
    void longPath(){
        cout<<"Long PAth "<<longestpath(root);
    }
    private:
    node *root;
    node *insertbst(node *T,int d){
        if(T == NULL) 
            T = new node(d);
        else if(T->data<d)
            T->rc = insertbst(T->rc,d);
        else
            T->lc = insertbst(T->lc,d);
        return T;
    }
    node *deletenode(node *T,int key){
        if(T==NULL) return NULL;
        if(key<T->data)
            T->lc = deletenode(T->lc,key);
        else if(key>T->data)
            T->rc = deletenode(T->rc,key);
        else{
            if(T->lc==NULL){
                node *temp = T->rc;
                delete T;
                return temp;
            }
            else if(T->rc == NULL){
                node *temp = T->lc;
                delete T;
                return temp;
            }
            node *temp=Minvalue(T->rc);
            T->data = temp->data;
            T->rc = deletenode(T->rc,temp->data);
        }
        return T;
    }
    node *Minvalue(node* T){
        if(T==NULL) return NULL;
        node *temp = T;
        while(temp->lc !=NULL)
        temp=temp->lc;
        return temp;
    }
    node *Maxvalue(node* T){
        if(T==NULL) return NULL;
        node *temp = T;
        while(temp->rc !=NULL)
        temp=temp->rc;
        return temp;
    }
    void inorderAscendeing(node *T){
        Stack s;
        while(1){
            while(T!=NULL){
                s.push(T);
                T=T->lc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            cout<<T->data<<" ";
            T=T->rc;
        }
    }
    void inorderDesecending(node *T){
        Stack s;
        while(1){
            while(T!=NULL){
                s.push(T);
                T=T->rc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            cout<<T->data<<" ";
            T=T->lc;
        }
    }
    int height(node *T){
        if(T == nullptr) {
            return 0;
        }
        int left = height(T->lc);
        int right = height(T->rc);
        return max(left, right) + 1;    
        }
    int longestpath(node *T){
        if(T == nullptr) {
            return 0;
        }
        int left = height(T->lc);
        int right = height(T->rc);
        int lonngpath =  left + right + 1;
        int left1 = longestpath(T->lc);
        int right1 = longestpath(T->rc);
        return max(lonngpath,max(left1,right1));
    }
    int search(node *T, int key)
    {
        int comparison  = 0;
        node *temp = T;
        while(T != NULL){
            comparison++;
            if(key == T->data){
                return comparison;
            }
            else if(key< T->data){
                T= T->lc;
            }
            else{
                T = T->rc;
            }
            
        }

        return -1;
    }
};
int main(){
    BST b;
    b.create();
    b.traversal();
    b.Delete(2);
    b.traversal();
    b.searchBSt(5);
    b.longPath();
    return 0;
}