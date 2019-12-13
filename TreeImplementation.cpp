// CREATED BY MEHMET ÞENER - MRX TECHNOLOGY

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* right; // pointer of right child
    Node* left;  // pointer of left child

};

class Tree 
{
public:
    Node* root;
    //Tree();
    bool isEmpty();
    Node* createNode(int);
    void insert(int);
    Node* Delete(Node* r, int data);
    void preorderTraversal(Node*);
    void inorderTraversal(Node*);
    void postorderTraversal(Node*);
    void LevelOrder(Node*);
    int height(Node*);
    void printLevel(Node* root, int level);
    void Search(int element);
    Node* findmax(Node*);
    Node* findmin(Node*);
    Node* parent(int);
 
};


Node* Tree::parent(int element)
{
    Node* temp = root;
    Node* parent = NULL;
    bool found = false;
    while (temp!=NULL)
    {
        if (element==temp->data)
        {
            found = true;
            break;
        }

        else
        {
            parent = temp;
            if (element<temp->data)
            {
                temp = temp->left;
            }

            else
            {
                temp = temp->right;
            }

        }
    }

    if (found)
    {
        parent = NULL;
    }

    return parent;
}


bool Tree::isEmpty()
{
    return root == NULL;
}

Node* Tree::createNode(int element)
{
    Node* temp = new Node;
    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* Tree::findmax(Node* r)
{
    while (r->right!=NULL)
    
        r = r->right;
        
    
    return r;
}

Node* Tree::findmin(Node* r)
{
    while (r->left!=NULL)
    
        r = r->left;
        
    
    return r;
}

void Tree::Search(int element)
{
    Node* temp = root;
    bool found = false;


    while (temp!=NULL)
    {
        if (element==temp->data)
        {
            found = true;
            break;
        }

        else
        {
            if (element<temp->data)
            {
                temp = temp->left;
            }

            else
            {
                temp = temp->right;
            }
        }
    }


    if (found)
    {
        cout << element << "found" << endl;
    }

    else
    {
        cout << element << "Not found" << endl;
    }


}

void Tree::insert(int element)
{
    if (root==NULL)
    {
        root = createNode(element);
    }

    else 
    {
        Node* temp, * parent;
        temp = root;
        parent = NULL;

        while (temp!=NULL)
        {
            parent = temp;

            temp = element < temp->data ? temp->left : temp->right;

        }
        temp = createNode(element);

        if (element<parent->data)
        {
            parent->left = temp;
        }
        else
        {
            parent->right = temp;
        }
    }
}

Node* Tree::Delete(Node* root, int data)
{
    if (root==NULL)
    {
        return root;
    }

    else if (data<root->data)
    {
        root->left = Delete(root->left, data);
    }


    else if (data>root->data)
    {
        root->right = Delete(root->right, data);
    }

    else
    {
        //case 1 : No child    

        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            root = NULL;
        }

        //case 2 : one child
        
        else if (root->left==NULL)
        {
            struct Node* temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right==NULL)
        {
            struct Node* temp = root;
            root = root->left;
            delete temp;
        }

        else
        {
            //case 3 : two children
            Node* temp = findmax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, data);
        }
}
       return root;

}

void Tree::preorderTraversal(Node* temp)
{
    if (temp==NULL)
    {
        return;
    }

    cout << temp->data << "";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);

}

void Tree::inorderTraversal(Node* temp)
{
    if (temp==NULL)
    {
        return;
    }

    inorderTraversal(temp->left);
    cout << temp->data << "";
    inorderTraversal(temp->right);

}

void Tree::postorderTraversal(Node* temp)
{
    if (temp==NULL)
    {
        return;
    }

    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << temp->data << "";
}

int Tree::height(Node* node)
{
    if (node==NULL)
    {
        return 0;
    }

    else
    {
        // compute the height of each subtree

        int lhegiht = height(node->left);
        int rheight = height(node->right);

        //use the large one

        if (lhegiht>rheight)
        {
            return (lhegiht + 1);
        }

        else
        {
            return (rheight + 1);
        }

    }


}


void Tree::LevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for(i = 1;  i<=h; i++)
    {
        printLevel(root, i);
        cout << endl;
    }


}



void Tree::printLevel(Node* root, int Level)
{
    if (root==NULL)
    {
        return;
    }

    if (Level==1)
    {
        cout << root->data << "";
    }

    else if (Level>1)
    {
        printLevel(root->left, Level - 1);
        printLevel(root->right, Level - 1);
    }
}



int main()
{
    class Tree T;
    T.insert(10);
    T.insert(20);
    T.insert(35);
    T.insert(46);
    T.insert(55);
    T.insert(48);
    T.insert(16);
    T.insert(1);
    T.insert(60);
    T.insert(100);
    T.insert(54);
    cout << "Seach 29" << endl;
    T.Search(29);
    cout << "Search 48" << endl;
    T.Search(48);
   
    
}


