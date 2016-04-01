#include <iostream>
using namespace std;


template <class DT>  
class ParentBinaryTree {
	template<class T>
	friend ostream& operator<< (ostream& s, ParentBinaryTree<T>& pbt); //Overloaded ostream operator
protected:   
	DT* ParentArray;
	int numNodes;
public:
	ParentBinaryTree();
	ParentBinaryTree(int size);
	~ParentBinaryTree();
	ParentBinaryTree(const ParentBinaryTree& pbt);
	void operator=(const ParentBinaryTree<DT>& pbt);
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
	numNodes = 0;
}
///Initializer
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree(int size) {
	DT* ParentArray = new ParentArray<DT>[size];
	numNodes = size;
}
///Destructor
template<class DT>
ParentBinaryTree<DT>::~ParentBinaryTree() {

}
template<class DT>
ParentBinaryTree<DT>::ParentBinaryTree(const ParentBinaryTree & pbt) {
	for (int i = 0; i < pbt.getSize(); i++) {
		ParentArray[i] = pbt.ParentArray[i];
	}
	numNodes = pbt.numNodes;
}
///Returns number of nodes in the tree
template<class DT>
int ParentBinaryTree<DT>::getSize() {
	return numNodes;
}

template<class DT>
int ParentBinaryTree<DT>::getHeight() {
	return 0;
}

template<class DT>
DT & ParentBinaryTree<DT>::getLeft(const DT & x) {
	// TODO: insert return statement here
	return 0;
}

template<class DT>
DT & ParentBinaryTree<DT>::getRight(const DT & x) {
	// TODO: insert return statement here
	return 0;
}

template<class DT>
void ParentBinaryTree<DT>::preorderTraversal() {
}

template<class DT>
void ParentBinaryTree<DT>::inorderTraversal() {
}

template<class DT>
void ParentBinaryTree<DT>::postorderTraversal() {
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

	//Reads the rest of the file
	while (!cin.eof()){
		//For each line
		cin >> root;
		cin >> left;
		cin >> right;
		cout << root << " " << left << " " << right << endl;
		
	}
	return 0;
}