#include "Treenode.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();

  void insert_node(int);
  void print(int = 0);
    /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/

};

// Additional functions
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr,int); //The real lab
  void kill(TreeNodePtr);

void BST::insert_node(int value) {
    TreeNodePtr new_node = new TreeNode(value);

    if (rootPtr == NULL) {   
        rootPtr = new_node;
    } 
    else {
        TreeNodePtr t = rootPtr;

        while (true) {
            if (value < t->get_value()) {
                if (t->move_left() != NULL)
                    t = t->move_left();
                else {
                    t->set_left(new_node);
                    break;
                }
            } 
            else {
                if (t->move_right() != NULL)
                    t = t->move_right();
                else {
                    t->set_right(new_node);
                    break;
                }
            }
        }
        cout << value << "inserted" << endl << endl; 
    }
    size++;
}

void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr,0);
    cout << endl;
    break;
    default:
    printTree(rootPtr,0);
    cout << endl;

  }
}


BST::BST() {
  rootPtr=NULL;
  size=0;
}

BST::~BST() { 
    cout << "Kill BST" << endl; 
    kill(rootPtr);
}

void inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function
  //printTree(rootPtr,0);

void printTree(TreeNodePtr treePtr, int level) {
    if (treePtr == NULL) return;

    printTree(treePtr->move_right(), level + 1);

    for(int i = 0; i < level; i++){
        cout << "   ";
    }

    cout << treePtr->get_value() << endl << endl; // extra spacing
    printTree(treePtr->move_left(), level + 1);
}


void postOrder(TreeNodePtr treePtr) {
    if (treePtr) {
        postOrder(treePtr->move_left());
        postOrder(treePtr->move_right());
        cout << setw(3) << treePtr->get_value();
    }
}

void kill(TreeNodePtr treePtr) {
    if(treePtr){
        kill(treePtr->move_left());
        kill(treePtr->move_right());
        delete treePtr;
    }
}

void preOrder(TreeNodePtr treePtr) {
    if(treePtr){
        cout << setw(3) << treePtr->get_value();
        preOrder(treePtr->move_left());
        preOrder(treePtr->move_right());
    }
}

