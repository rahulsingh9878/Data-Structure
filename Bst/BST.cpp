#include<iostream>
#include<stack>
using namespace std;
class BST
{
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *root;
    node *ptr;
    node *new_node;
    node *track;
    node *save;
public:
    BST()
    {
        root=NULL;
    }
    node* get_root()
    {
        return root;
    }
    void create_BST();
    void search_BST();
    void min_and_max_ele();
    void display(node*,int);
    void inorder_BST();
};
void BST::create_BST()
{
    cout<<"Enter value(-1 to terminate): ";
    int num;
    cin>>num;
    while(num!=-1)
    {
        new_node=new node;
        new_node->data=num;
        new_node->left=NULL;
        new_node->right=NULL;
        if(root==NULL)
            root=new_node;
        else
        {
            track=root;
            while(1)
            {
                if(num>track->data)
                {
                    if(track->right==NULL)
                    {
                        track->right=new_node;
                        cout<<"Parent is "<<track->data<<endl;
                       break;
                    }
                    else
                    {
                        track=track->right;
                    }
                }
                else
                {
                    if(track->left==NULL)
                    {
                        track->left=new_node;
                        cout<<"Parent is "<<track->data<<endl;
                        break;
                    }
                    else
                    {
                        track=track->left;
                    }
                }
            }
        }
        cout<<"Enter value(-1 to terminate): ";
        cin>>num;
    }
}
void BST::search_BST()
{
    cout<<"Enter no to search: ";
    int num;
    cin>>num;
    track=root;
    save=NULL;
    while(1)
    {
        if(num==track->data)
        {
            if(save==NULL)
                cout<<"Parent doesnt exist"<<endl;
            else
                cout<<"Parent is "<<save->data<<endl;
            cout<<"Element found"<<endl;
            break;
        }
        else if(num>track->data&&track->right!=NULL)
        {
            save=track;
            track=track->right;
        }
        else if(num<track->data&&track->left!=NULL)
        {
            save=track;
            track=track->left;
        }
        else
        {
            cout<<"ELement not found"<<endl;
            break;
        }
    }
}
void BST::min_and_max_ele()
{
    track=root;
    while(track->left!=NULL)
    {
        track=track->left;
    }
    cout<<"Min Element is "<<track->data<<endl;
    track=root;
    while(track->right!=NULL)
    {
        track=track->right;
    }
    cout<<"Max Element is "<<track->data<<endl;
}
void BST::display(node *tra,int ch)
{
    switch(ch)
    {
    case 1:
        if(tra==NULL)
        return;
        cout<<tra->data<<" ";
        display(tra->left,ch);
        display(tra->right,ch);
        break;
    case 2:
        if(tra==NULL)
        return;
        display(tra->left,ch);
        cout<<tra->data<<" ";
        display(tra->right,ch);
        break;
    case 3:
        if(tra==NULL)
        return;
        display(tra->left,ch);
        display(tra->right,ch);
        cout<<tra->data<<" ";
        break;
    }
}
void BST::inorder_BST(){
stack <node*>stk;
     ptr=root;
     do
     {
         if(ptr){
            stk.push(ptr);
            ptr=ptr->left;
         }
         else{
            ptr = stk.top();
         stk.pop();
         cout<<ptr->data<<" ";
         ptr=ptr->right;
         }

     }while(!stk.empty()||ptr!=NULL);
     }
int main()
{
    BST obj;
    int ch;
    do
    {
        cout<<"Enter 1 to create BST,2 to search element,3 to find min and max element,4 for inoder ,5 to display,0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.create_BST();
            break;
        case 2:
            obj.search_BST();
            break;
        case 3:
            obj.min_and_max_ele();
            break;
        case 4:
            obj.inorder_BST();
            break;
        case 5:
            cout<<"Enter 1 for pre-order,2 for in-order,3 for post-order: ";
            int ch;
            cin>>ch;
            obj.display(obj.get_root(),ch);
            cout<<endl;
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
