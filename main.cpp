#include <bits/stdc++.h>
#define NUMBER 9


template <typename T> class Node {
public:

        Node<T> *parent, *left, *right;
        T data;

        Node() : parent(NULL), left(NULL), right(NULL)
        {
                parent = NULL;
                left = NULL;
                right = NULL;
        }

        Node(T data) : data(data),  parent(NULL), left(NULL), right(NULL) {}

        Node(T data, Node<T> *parent, Node<T> *left, Node<T> *right) :
                data(data), parent(parent), left(left), right(right) {

        }

        static void structure ( Node<T> *root, int level );
        static void walk(const Node<T> *tree);
        static void Inorder(const Node<T> *tree);
        static Node<T> *Right_Rotation(Node<T> *root);
        static Node<T> *Left_Rotation(Node<T> *root);
        static Node<T> *Splay(Node<T> *root,T value);
        static Node<T> *Search(Node<T> *tree, T value);
        static Node<T> *find(Node<T> *tree, T value);
        static Node<T> *minimum(Node<T> *tree);
        static Node<T> *maximum(Node<T> *tree);
        static Node<T> *successor(Node<T> *tree);
        static void prt(Node<T>* n);
        // Always returns the root of the tree, whether it had to be modified
        // or not
        static Node<T> *Insert(Node<T> *tree, Node<T> *node);
        static Node<T> *Delete(Node<T> *tree, Node<T> *node);
        static Node<T> *insertNode(Node<T> *tree, Node<T> *node);
        static Node<T> *deleteNode(Node<T> *tree, Node<T> *node);

private:
        static Node<T> *transplant(Node<T> *tree, Node<T> *u, Node<T> *v);
};

template<typename T> std::ostream &operator<<(std::ostream &output, Node<T> node);


void padding ( char ch, int n )
{
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

template <typename T> void Node<T>:: structure ( Node<T> *root, int level )
{
  int i;
  if ( root == NULL )
    {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {

    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->data );
    structure ( root->left, level + 1 );
  }
}

void input()
{
    Node<int> *root = NULL;
    Node<int> list[100] = {};
    int choice,input;
    int i=0;
    while(1)
    {
        std::cout<<"\nSplay Tree Operations\n";
        std::cout<<"1. Insert "<<"\n";
        std::cout<<"2. Delete"<<"\n";
        std::cout<<"3. Search"<<"\n";
        std::cout<<"4. Splay"<<"\n";
        std::cout<<"5. Print"<<"\n";
        std::cout<<"6. Exit"<<"\n";
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            std::cout<<"Enter value to be inserted: ";
            std::cin>>input;
            list[i++]=input;
            root = Node<int>::Insert(root,list+i-1);
            std::cout<<"\nAfter Insert: "<<input<<"\n";
            Node<int>::Inorder(root);
            break;
        case 2:
            std::cout<<"Enter value to be deleted: ";
            std::cin>>input;
            list[i++]=input;
            root  = Node<int>::Delete(root, list+i-1);
            std::cout<<"\nAfter Delete: "<<input<<"\n";
            Node<int>::Inorder(root);
            break;
        case 3:
            std::cout<<"Enter value to be searched: ";
            std::cin>>input;
            root=Node<int>::Search(root, input);
            //std::cout << *Node<int>::Search(root, input);
            std::cout<<"\nAfter Search "<<input<<"\n";
            Node<int>::Inorder(root);
            break;
        case 4:
            std::cout<<"Enter value to be splayed: ";
            std::cin>>input;
            root=Node<int>::Splay(root, input);
            Node<int>::Inorder(root);
            break;
        case 5:
            Node<int>::structure ( root, 0 );
            break;
        case 6:
            exit(1);
        default:
            std::cout<<"\nInvalid type! \n";
        }
    }
    Node<int>::structure ( root, 0 );
    std::cout<<"\n";
    return;
}


int main() {
       /* Node<int> list[NUMBER] = {
                45, 50, 1, 9, 44, 56, 98, 43, 32
        };

        // construct a tree
        Node<int> *root = NULL;

        // We will just use the first tree as the root
        for (int i = 0; i < NUMBER; ++i) {
                root = Node<int>::Insert(root, (list + i));
                //root = Node<int>::insertNode(root, (list + i));
        }

        Node<int>::walk(root);
        root=Node<int>::Search(root, 43);
        std::cout << *Node<int>::Search(root, 43);
        //std::cout << *Node<int>::find(root, 43);
        //std::cout << "Minimum: " << *Node<int>::minimum(root);
        //std::cout << "Maximum: " << *Node<int>::maximum(root);

        //Node<int> *nine = Node<int>::Search(root, 9);
        //Node<int> *nine = Node<int>::find(root, 9);
        //std::cout << "9: " << *nine;
        //std::cout << "Successor: " << *Node<int>::successor(nine);

        //Node<int> *fortyFour = Node<int>::Search(root, 44);
        //Node<int> *fortyFour = Node<int>::find(root, 44);
        //std::cout << "44: " << *fortyFour;
        //std::cout << "Successor: " << *Node<int>::successor(fortyFour);

        //root = Node<int>::Delete(root, list+7);
        //root = Node<int>::deleteNode(root, root);
        Node<int>::walk(root);

        //root = Node<int>::Delete(root, list+0);
        //root = Node<int>::deleteNode(root, root);
        Node<int>::walk(root);*/

        input();
        return 0;
}

template <typename T> void Node<T>::walk(const Node<T> *tree) {
        if (tree == NULL) return;
        if(tree->left==NULL) return;
        std::cout << tree -> left->data << "\n";
        walk(tree -> left);
        std::cout << tree -> data << "\n";
        walk(tree -> right);
}

template <typename T> void Node<T>::Inorder(const Node<T> *tree) {
        if (tree == NULL) return;

        std::cout << tree -> data << "\n";
        Inorder(tree -> left);
        Inorder(tree -> right);
}

template <typename T> Node<T> *Node<T>:: Right_Rotation(Node<T> *root)
{
    Node<T> *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    return newroot;
}

template <typename T> Node<T> *Node<T>:: Left_Rotation(Node<T> *root)
{
    Node<T> *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    return newroot;
}

template <typename T> Node<T> *Node<T>:: Splay(Node<T> *root,T key)
{
    if (root == NULL || root->data == key)
        return root;
    Node<T>  header;
    header.left = header.right = NULL;
    Node<T>*  LeftTreeMax = &header;
    Node<T>*  RightTreeMin = &header;
    while (1)
    {
        if (key < root->data)
        {
            if (!root->left) break;
            if (key < root->left->data)
            {
                root = Right_Rotation(root);
                // only zig-zig mode need to rotate once,
                if (!root->left) break;
            }
            /* Link to R Tree */
            RightTreeMin->left = root;
            RightTreeMin = RightTreeMin->left;
            root = root->left;
            RightTreeMin->left = NULL;
        }
        else if (key > root->data)
        {
            if (!root->right) break;
            if (key > root->right->data)
            {
                root = Left_Rotation(root);
                // only zag-zag mode need to rotate once,
                if (!root->right) break;
            }
            /* Link to L Tree */
            LeftTreeMax->right = root;
            LeftTreeMax = LeftTreeMax->right;
            root = root->right;
            LeftTreeMax->right = NULL;
        }
        else break;
    }
    /* assemble L Tree, Middle Tree and R tree */
    LeftTreeMax->right = root->left;
    RightTreeMin->left = root->right;
    root->left = header.right;
    root->right = header.left;
    return root;
}

template <typename T> Node<T> *Node<T>::Insert(Node<T> *tree, Node<T> *node)
{
    // Simple Case: If tree is empty
    if (tree == NULL)
    {
         tree = node;
         node -> parent = NULL;
    }
//std::cout << node -> data << "\n";
    // Bring the closest leaf node to root
    tree = Splay(tree, node->data);
//std::cout << tree -> data << "\n";
    // If key is already present, then return
    if (tree->data == node->data) return tree;


    Node<T> *newnode=node ;

    // If root's key is greater, make root as right child
    // of newnode and copy the left child of root to newnode
    if (tree->data > node->data)
    {
        newnode->right = tree;
        newnode->left = tree->left;
        tree->left = NULL;
        tree=newnode;
    }

    // If root's key is smaller, make root as left child
    // of newnode and copy the right child of root to newnode
    else
    {
        newnode->left = tree;
        newnode->right = tree->right;
        tree->right = NULL;
        tree=newnode;
    }
    node -> parent = NULL;
//std::cout <<"tree "<< tree -> data << "\n";
    return tree; // newnode becomes new root
}

template <typename T> Node<T> *Node<T>::insertNode(Node<T> *tree, Node<T> *node) {
        if (!tree) {
                tree = node;
                node -> parent = NULL;
        } else {
                Node<T> *parent, *search = tree;
                bool left = false;
                while (search != NULL) {
                        parent = search;
                        if (node -> data <= search -> data) {
                                search = search -> left;
                                left = true;
                        } else {
                                search = search -> right;
                                left = false;
                        }
                }
                node -> parent = parent;
                if (left) parent -> left = node;
                else parent -> right = node;
        }

        return tree;
}

template <typename T> Node<T> *Node<T>::Search(Node<T> *tree, T value)
{
    return Splay(tree, value);
}

template <typename T> Node<T> *Node<T>::find(Node<T> *tree, T value) {
        if (!tree || tree -> data == value) return tree;
        if (value < tree -> data) return find(tree -> left, value);
        else return find(tree -> right, value);
}

template <typename T> Node<T> *Node<T>::minimum(Node<T> *tree) {
        if (!tree) return NULL;

        while (tree -> left) {
                tree = tree -> left;
        }

        return tree;
}

template <typename T> Node<T> *Node<T>::maximum(Node<T> *tree) {
        if (!tree) return NULL;

        while (tree -> right) {
                tree = tree -> right;
        }

        return tree;
}

template <typename T> Node<T> *Node<T>::successor(Node<T> *node) {
        if (!node) return NULL;

        if (node -> right) {
                return minimum(node -> right);
        } else {
                // We need to traverse upwards in the tree to find a node where
                // the node is the left child of a parent
                // parent is the successor

                Node<T> *parent = node -> parent;
                while(parent && node != parent -> left) {
                        node = parent;
                        parent = node -> parent;
                }

                return parent;
        }

}

// make node U's paarent have node v has its child
template <typename T> Node<T> *Node<T>::transplant(Node<T> *tree, Node<T> *u, Node<T> *v) {
        if (!u -> parent) tree = v;
        else if (u -> parent -> left == u) {
                u -> left = v;
        } else if (u -> parent -> right == u) {
                u -> right = v;
        }
        if (v) v -> parent = u -> parent;
        return tree;
}

template <typename T> Node<T> *Node<T>::Delete(Node<T> *tree, Node<T> *node)
{
    if (tree == NULL) return tree; // empty tree

    // Bring the node to root
    tree = Splay(tree, node->data);

    if (node->data == tree->data)
    {
        if (tree->left == NULL) tree = tree->right;
        else
        {
            Node<T> *x = tree->right;
            tree = tree->left;
            Splay(tree, node->data);
            tree->right = x;
        }
    }
    return tree;
}


template <typename T> Node<T> *Node<T>::deleteNode(Node<T> *tree, Node<T> *node) {
        if (!node -> left) {
                tree = transplant(tree, node, node -> right);
        } else if (!node -> right) {
                tree = transplant(tree, node, node -> left);
        } else {
                // Has two children -- successor must be on the right
                Node <int> *successor = minimum(node -> right);
                assert(successor -> left == NULL);
                if (successor != node -> right) {
                        tree = transplant(tree, successor, successor -> right);
                        successor -> right = node -> right;
                        successor -> right -> parent = successor;
                }

                tree = transplant(tree, node, successor);
                successor -> left = node -> left;
                successor -> left -> parent = successor;
        }
        return tree;
}

template<typename T> std::ostream &operator<<(std::ostream &output, Node<T> node) {
        output << "Value: " << node.data;
        if (node.parent) output << " Parent: " << node.parent -> data;
        if (node.left) output << " Left: " << node.left -> data;
        if (node.right) output << " Right: " << node.right -> data;
        output << "\n";
        return output;
}

