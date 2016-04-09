#include <iostream>
using namespace std;


template <class DT>  
class ParentBinaryTree {
	template<class T>
	friend ostream& operator<< (ostream& s, ParentBinaryTree<T>& pbt); //Overloaded ostream operator
protected:   
	DT* ParentArray; //Array indexed by each position with a value of each position's parent
	int* LeftRightArray; //Array indexed by each position with a value of 0 for left nodes and 1 for right nodes
	int numNodes; //Number of nodes in the tree
	bool firstRoot = true; 
public:
	ParentBinaryTree(); //Default constructor
	ParentBinaryTree(int size); //Initializer
	~ParentBinaryTree(); //Destructor
	ParentBinaryTree(ParentBinaryTree& pbt); //Copy constructor
	void operator=(ParentBinaryTree<DT>& pbt); //Overloaded assignment operator
	void insert(const DT & root, const DT & left, const DT & right); //Inserts the values to create the tree
	int getSize(); //Returns the number of nodes in the tree
	int getHeight(); //Returns the height of the tree
	int getLeft(int x); //Returns the left child position of the given position
	int getRight(int x);  //Returns the right child position of the given position
	bool isLeaf(int x);  //Checks if the position given is a leaf node
	void preorderTraversal(); 
	void preorderTraversal(int x);
	void inorderTraversal();
	void inorderTraversal(int x);
	void postorderTraversal();
	void postorderTraversal(int x);
};

///Overloaded ostream operator
template<class T>
ostream& operator<< (ostream& s, ParentBinaryTree<T>& tree) {
	tree.preorderTraversal();
	s << endl;
	return s;
}

///Default Constructor
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree() {
	DT* ParentArray = NULL;
	DT* LeftRightArray = NULL;
	numNodes = 0;
}
///Initializer
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree(int size) {
	ParentArray = new DT[size];
	LeftRightArray = new int[size];
	numNodes = size;
}
///Destructor
template<class DT>
ParentBinaryTree<DT>::~ParentBinaryTree() {

}
///Copy constructor
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree(ParentBinaryTree<DT> & pbt) {
	numNodes = pbt.numNodes;
	ParentArray = new DT[numNodes];
	LeftRightArray = new int[numNodes];
	//Copy the parent array
	for (int i = 0; i < pbt.getSize(); i++) {
		ParentArray[i] = pbt.ParentArray[i];
		LeftRightArray[i] = pbt.LeftRightArray[i];
	}
	
}
///Overloaded assignment operator
template<class DT>
void ParentBinaryTree<DT>::operator=(ParentBinaryTree<DT>& pbt) {
	numNodes = pbt.numNodes;
	ParentArray = new DT[numNodes];
	LeftRightArray = new int[numNodes];
	//Copy the parent array
	for (int i = 0; i < pbt.getSize(); i++) {
		ParentArray[i] = pbt.ParentArray[i];
		LeftRightArray[i] = pbt.LeftRightArray[i];
	}
}
///Inserts values into the tree
template<class DT>
void ParentBinaryTree<DT>::insert(const DT & root, const DT & left, const DT & right) {
	if (firstRoot) {
		ParentArray[root] = -1;
		LeftRightArray[root] = -1;
		firstRoot = false;
	}
	//Check if the data type is already in the array 
	if (left >= 0) {
		ParentArray[left] = root;
		LeftRightArray[left] = 0;
	}
	if (right >= 0) {
		ParentArray[right] = root;
		LeftRightArray[right] = 1;
	}
}
///Returns number of nodes in the tree
template<class DT>
int ParentBinaryTree<DT>::getSize() {
	return numNodes;
}
///Returns the height of the tree
template<class DT>
int ParentBinaryTree<DT>::getHeight() {
	int maxHeight = 0;
	int height = 0;
	for (int i = 0; i < numNodes; i++) {
		if (isLeaf(i)) {
			int k = i;
			while (ParentArray[k] != -1) {
				k = ParentArray[k];
				height++;
			}
			if (height > maxHeight) {
				maxHeight = height;
			}
			height = 0;
		}
	}
	return maxHeight;
}
///Returns the left child of a given position
template<class DT>
int ParentBinaryTree<DT>::getLeft(int x) {
	//Search through parent array for the value x to find it's children
	for (int i = 0; i < numNodes; i++) {
		if (ParentArray[i] == x) {
			if (LeftRightArray[i] == 0) {
				return i;
			}
		}
	}
	return -1;
}
///Returns the right child of a given position
template<class DT>
int ParentBinaryTree<DT>::getRight(int x) {
	//Search through parent array for the value x to find it's children
	for (int i = 0; i < numNodes; i++) {
		if (ParentArray[i] == x) {
			if (LeftRightArray[i] == 1) {
				return i;
			}
		}
	}
	return -1;
}
///Returns a boolean true if the position is a leaf node
template<class DT>
bool ParentBinaryTree<DT>::isLeaf(int x) {
	//Check if the position has children
	if ((getLeft(x) == -1 ) && (getRight(x) == -1)) {
		return true;
	} else {
		return false;
	}
}
///Prints the node values in preorder format
template<class DT>
void ParentBinaryTree<DT>::preorderTraversal(int x) {
	//Root, left, right
	cout << x;
	if (getLeft(x) != -1) {
		preorderTraversal(getLeft(x));
	}
	if (getRight(x) != -1) {
		preorderTraversal(getRight(x));
	}
}
///Finds the root node then prints the node values in preorder format
template<class DT>
void ParentBinaryTree<DT>::preorderTraversal() {
	//Root, left, right
	//Find root node
	int root = 0;
	while (ParentArray[root] != -1 && root < numNodes) {
		root++;
	}
	//Start the traversal at the root node
	preorderTraversal(root);
}
//Prints the node values in inorder format
template<class DT>
void ParentBinaryTree<DT>::inorderTraversal(int x) {
	//Left, root, right
	if (getLeft(x) != -1) {
		inorderTraversal(getLeft(x));
	}
	cout << x;
	if (getRight(x) != -1) {
		inorderTraversal(getRight(x));
	}
}
///Finds the root node then prints the node values in inorder format
template<class DT>
void ParentBinaryTree<DT>::inorderTraversal() {
	//Left, root, right
	//Find root node
	int root = 0;
	while (ParentArray[root] != -1 && root < numNodes) {
		root++;
	}
	//Start the traversal at the root node
	inorderTraversal(root);
}
///Prints the node values in postorder format
template<class DT>
void ParentBinaryTree<DT>::postorderTraversal(int x) {
	//Left, root, right
	if (getLeft(x) != -1) {
		postorderTraversal(getLeft(x));
	}
	if (getRight(x) != -1) {
		postorderTraversal(getRight(x));
	}
	cout << x;
}
///Finds the root node then prints the node values in postorder format
template<class DT>
void ParentBinaryTree<DT>::postorderTraversal() {
	//Left, root, right
	//Find root node
	int root = 0;
	while (ParentArray[root] != -1 && root < numNodes) {
		root++;
	}
	//Start the traversal at the root node
	postorderTraversal(root);
}

int main() {
	int numNodes = 0;
	int root;
	int left;
	int right;
	//Reads the number of nodes
	cin >> numNodes;
	cout << numNodes << endl;
	//Initializer
	ParentBinaryTree<int>* tree = new ParentBinaryTree<int>(numNodes);
	//Reads the rest of the file
	while (!cin.eof()){
		//For each line add the info to the tree
		cin >> root;
		cin >> left;
		cin >> right;
		tree->insert(root, left, right);
	}
	//Show that all the methods work
	//Default constructor
	ParentBinaryTree<int>* emptyTree = new ParentBinaryTree<int>();
	//Copy constructor
	ParentBinaryTree<int>* newTree = new ParentBinaryTree<int>(*tree);
	//Overloaded assignment operator
	ParentBinaryTree<int>* tree2 = tree;
	//size method
	cout << tree->getSize() << endl;
	//height method
	cout << tree->getHeight() << endl;
	//Preorder
	tree->preorderTraversal();
	cout << endl;
	//Inorder
	tree->inorderTraversal();
	cout << endl;
	//Postorder
	tree->postorderTraversal();
	cout << endl;
	cout << *tree;
	//getRight and getLeft included in traversals
	return 0;
}