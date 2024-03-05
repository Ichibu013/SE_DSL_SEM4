#include <iostream>
#include<math.h>
using namespace std;

struct node
{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
} ;

class tree
{
public:
    node *root;
    tree(){root = NULL;}
    node *newnode(int in_data)
    {
        node *ptr = new node();
        ptr->data = in_data;
        ptr->left= NULL;
        ptr->right= NULL;
        return ptr;
    }
    node *insert(node *temp,int in_data){
        if(temp == NULL){temp = newnode(in_data);}
        else if (temp->data>in_data)
        {
            temp->left= insert(temp->left,in_data);
        }
        else
        {
            temp->right= insert(temp->right,in_data);
        }
        return temp;
    }
    void input()
    {
        int n,x;
        cout<<"Enter no. of element:";
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cout<<i+1<<": Number : ";
            cin>>x;
            root=insert(root,x);
        }
        
    }
    void inorder(node *temp)
    {
        if (temp!=NULL)
        {
            inorder(temp->left);
            cout<<temp->data<<" " ;
            inorder(temp->right);
        }
        
    }
    void postorder(node *temp)
    {
        if (temp!=NULL)
        {
        postorder(temp->left);
        postorder(temp->right); 
        cout << temp->data << " ";
        }
    }
    void preorder(node* temp)
    {
        if (temp != NULL)
        {
            cout<<temp->data<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
    } 
    void minmax(node *temp)
    {
        while (temp->left!=NULL)
        {
            temp=temp->left;
        }
        cout<<"\nMin Value = "<<temp->data<<endl;
        
    }
    void display(node *temp)
    {
        if (temp!=NULL)
        {
            cout<<temp->data<<" ";
            display(temp->left);
            display(temp->right);
        }
        
    }
    void search(int x, node *temp)
    {
        if (temp!=NULL)
        {
            
        }
        
    }
    void mirror(node *temp)
    {
        if (temp==NULL)
        {
            return ;
        }
        else
        {
            node *ptr;
            mirror(temp->left);
            mirror(temp->right);
            ptr=temp->left;
            temp->left=temp->right;
            temp->right=ptr;
        }
        
    }
};
int main()
{
    tree t;
    t.input();
    t.display(t.root);
    cout<<"\nIn-Order Traversal:\t";
    t.inorder(t.root);
    cout<<"\nPost-Order Traversal:\t";
    t.postorder(t.root);
    cout<<"\nPre-Order Traversal:\t";
    t.preorder(t.root);
    t.minmax(t.root);
    //t.mirror(t.root);
    int w;
    cin>>w;
}
