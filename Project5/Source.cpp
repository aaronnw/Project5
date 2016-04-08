#include <iostream>
using namespace std;


template <class DT>  
class ParentBinaryTree {
	template<class T>
	friend ostream& operator<< (ostream& s, ParentBinaryTree<T>& pbt); //Overloaded ostream operator
protected:   
	DT* ParentArray;
	DT* LeftRightArray;
	int numNodes;
	bool firstRoot = true;
public:
	ParentBinaryTree();
	ParentBinaryTree(int size);
	~ParentBinaryTree();
	ParentBinaryTree(const ParentBinaryTree& pbt);
	void operator=(const ParentBinaryTree<DT>& pbt);
	void insert(const DT & root, const DT & left, const DT & right);
	int getSize();
	int getHeight();
	DT& getLeft(const DT& x);
	DT& getRight(const DT& x);
	void preorderTraversal();
	void inorderTraversal();
	void postorderTraversal();
};

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
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree(const ParentBinaryTree & pbt) {
	//TODO
	for (int i = 0; i < pbt.getSize(); i++) {
		ParentArray[i] = pbt.ParentArray[i];
	}
	numNodes = pbt.numNodes;
}
template<class DT>
void ParentBinaryTree<DT>::operator=(const ParentBinaryTree<DT>& pbt) {
	//TODO
}
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
	return maxHeight;
}

template<class DT>
DT & ParentBinaryTree<DT>::getLeft(const DT & x) {
	//Search through parent array for the value x to find it's children
	for (int i = 0; i < numNodes; i++) {
		if (ParentArray[i] == x) {
			if (LeftRightArray[i] == 0) {
				return i;
			}
		}
	}
	int noChild = -1;
	return noChild;
}

template<class DT>
DT & ParentBinaryTree<DT>::getRight(const DT & x) {
	//Search through parent array for the value x to find it's children
	for (int i = 0; i < numNodes; i++) {
		if (ParentArray[i] == x) {
			if (LeftRightArray[i] == 1) {
				return i;
			}
		}
	}
	int noChild = -1;
	return noChild;
}

template<class DT>
void ParentBinaryTree<DT>::preorderTraversal() {
	//TODO
}

template<class DT>
void ParentBinaryTree<DT>::inorderTraversal() {
	//TODO
}

template<class DT>
void ParentBinaryTree<DT>::postorderTraversal() {
	//TODO
}


int main() {
	int numNodes = 0;
	int temp;
	int root;
	int left;
	int right;
	char c;
	//Reads the number of nodes
	cin >> numNodes;
	cout << numNodes << endl;
	ParentBinaryTree<int>* tree = new ParentBinaryTree<int>(numNodes);
	//Reads the rest of the file
	while (!cin.eof()){
		//For each line
		cin >> root;
		cin >> left;
		cin >> right;
		tree->insert(root, left, right);
	}
	cout << tree->getHeight() << endl;
	return 0;
}