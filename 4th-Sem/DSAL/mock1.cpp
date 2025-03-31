#include <iostream>
using namespace std;
class node{
int data;
node *lc ,*rc;
public:
node(){
    data=0;
    lc=NULL;
    rc=NULL;
}
friend class Stack;
friend class Queue;
friend class BT; 
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
class BT{
    public:
    BT(){
        root = NULL;
    }
    node *create(){
        node *temp = new node();
        char ch;
        cout<<"Enter Data"<<endl;
        cin>>temp->data;
        cout<<"Want to add its right child?(Y/N)"<<endl;
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            temp->rc=create();
        }cout<<"Want to add its left child?(Y/N)"<<endl;
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            temp->lc=create();
        }
        return temp;
    }
    void cR(){
        root = create();
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
			inorderNR(root);
			cout<<"\nNon Recur Preorder traversal"<<endl;
			preorderNR(root);
			cout<<"\nNon Recur Postorder traversal"<<endl;
			postorderNR(root);
            cout<<"\nLevel Order traversal"<<endl;
			levelorder(root);
    }
    void height()
    {
        cout<<"Height"<<h(root);
    }
    void Number()
    {
        cout<<"No. of Leaf Node "<<leaf(root);
        cout<<"No. of internal Node "<<internal(root);
    }
    void mirror()
    {
        cout<<"After swapping "<<endl;
        swap(root);
        inorder(root);
    }
    private:
    node *root;
    void inorder(node *T){
        if(T==NULL) return;
        inorder(T->lc);
        cout<<T->data;
        inorder(T->rc);
    }
    void preorder(node *T){
        if(T==NULL) return;
        cout<<T->data;
        preorder(T->lc);
        preorder(T->rc);
    }
    void postorder(node *T){
        if(T==NULL) return;
        postorder(T->lc);
        postorder(T->rc);
        cout<<T->data;
    }
    void inorderNR(node *T){
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
    void preorderNR(node *T){
        Stack s;
        while(1){
            while(T!=NULL){
                s.push(T);
                cout<<T->data<<" ";
                T=T->lc;
            }
            if(s.isEmpty())
                return;
            T = s.gettop();
            s.pop();
            T=T->rc;
        }
    }
    void postorderNR(node *T){
        Stack s,s1;
        s.push(T);
        while(!s.isEmpty()){
            T = s.gettop();
            s.pop();
            s1.push(T);
            if(T->lc!=NULL)
                s.push(T->lc);
            if(T->rc!=NULL)
                s.push(T->rc);
        }
        while(!s1.isEmpty()){
            T = s1.gettop();
            s1.pop();
            cout<<T->data<<" ";
        }
    }
    void levelorder(node *T)
    {
        Queue q;
        if(T == NULL) return;
        q.push(T);
        while(!q.isEmpty()){
            T = q.getfront();
            q.pop();
            cout<<T->data<<" ";
            if(T->lc!=NULL)
                q.push(T->lc);
            if(T->rc!=NULL)
                q.push(T->rc);
        }
    }
    int h(node *T)
    {
        if(T==NULL) return 0;
        int x = h(T->lc);
        int y = h(T->rc);
        return 1 + max(x,y);
    }
    int leaf(node *T){
        if(T==NULL) 
            return 0;
        if(T->lc==NULL && T->rc==NULL)
            return 1;
        else
            return leaf(T->lc)+leaf(T->rc);
    }
    int internal(node *T){
        if(T==NULL || T->lc == NULL && T->rc == NULL)
            return 0;
        return 1+internal(T->lc)+internal(T->rc);
    }
    void swap(node *T){
        node *temp;
        if(T==NULL)
        return;
        swap(T->lc);
        swap(T->rc);
        temp=T->lc;
        T->lc=T->rc;
        T->rc=temp;
    }
};
int main(){
    BT b;
    b.cR();
    b.traversal();
    b.height();
    b.Number();
    b.mirror();
    return 0;
}