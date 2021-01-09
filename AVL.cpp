#include<bits/stdc++.h> 
#include<string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
using namespace std;

string* emails = NULL;
// An AVL tree node
class Node
{
	public:
	string key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get the
// height of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
string max(string a, string b)
{
	return (a.compare(b)>0)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node* newNode(string key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node,string key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if ((node->key).compare(key)>0)
		node->left = insert(node->left, key);
	else if (key.compare(node->key)>0)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && (node->left->key).compare(key)>0)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key.compare(node->right->key)>0)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key.compare(node->left->key)>0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && (node->right->key).compare(key)>0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}


// A utility function to print preorder
// traversal of the tree.
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

// A Search function to find if the emails
// are in the tree or not .
void Search(Node *N, string& email,bool& found)
{
	if(N == NULL)
	    found = false;
	else if((N->key).compare(email)>0)
        Search(N->left,email,found);
	else if((email).compare(N->key)>0)
        Search(N->right,email,found);
    else{
        email = N->key;
        found = true;
    }
}

//to print inOrder traversal of the AVL tree
void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);

    }
}

int main()
{
	Node *root = NULL;


    //to get the emails from the file
	emails = new string [500000];
	int size = 500000;
	ifstream file("emailsSetC.txt");
    if(!file.is_open()){
        cout << "File not found.";
    }
    int i = 0;
    string email;
    while(getline(file,email)){
        emails[i] = email;
        i++;
    }
    file.close();

	// the insert + duration
    auto start = chrono::system_clock::now();
        for(int i =0 ; i < size ; i++ )
        {
        root = insert(root,emails[i]);
        }

    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time to insert: " << duration.count() << "s\n";

	/*
	// to print the tree as InOrder
	cout << "InOrder traversal of the "
                "constructed AVL tree is \n";
        inOrder(root);
        cout << endl<<endl;
	*/
	

	/*
	// to print the tree as preOrder
	 cout << "preOrder traversal of the "
                "constructed AVL tree is \n";
        preOrder(root);
        cout << endl<<endl;
    */

    // emails for search
    string* emailsToSearch= new string[10];
    bool found = false;
    int size2 = 10;

    // to get the targeted emails from the file (found)
	//ifstream file2("SetACanFound.txt"); // for set A
	//ifstream file2("SetBCanFound.txt"); // for set B
	ifstream file2("SetCCanFound.txt");  // for set C

    if(!file2.is_open()){
        cout << "File not found.";
    }
     int j = 0;
    string email2;
    while(getline(file2,email2)){
        emailsToSearch[j] = email2;
        j++;
    }
    file2.close();
   
    auto start2 = chrono::system_clock::now();
        for(int i =0 ; i < size2 ; i++ )
        {
        Search(root, emailsToSearch[i],found);
			
            if (found)
            {
                cout << "found. " ;
            }
            else{
                cout << " not_found." ;
                } 
        }
		cout << endl;
    auto end2 = chrono::system_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    cout << "Time for the search is (Found): " << duration2.count() << "s\n";

    // to search emails from the file (not found)
	ifstream file3("emailNotFound.txt");
	    if(!file3.is_open()){
        cout << "File not found.";
    }

    int k = 0;
    string email3;
    while(getline(file3,email3)){
        emailsToSearch[k] = email3;
        k++;
    }
    file2.close();

    auto start3 = chrono::system_clock::now();
        for(int i =0 ; i < size2 ; i++ )
        {
        Search(root, emailsToSearch[i],found);
			
            if (found)
            {
                cout << " found ";
            }
            else{
                cout << " not_found " ;
                } 
        }
		cout << endl;
    auto end3 = chrono::system_clock::now();
    chrono::duration<double> duration3 = end3 - start3;
    cout << "Time for the search is(not found): " << duration3.count() << "s\n";
	cout << endl;

	system("PAUSE");
	delete[] emails;
    delete[] emailsToSearch;
	return EXIT_SUCCESS;

}
