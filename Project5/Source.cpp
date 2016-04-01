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
	DT getLeft(DT x);
	DT getRight(DT x);
	preorderTraversal();
	inorderTraversal();
	postorderTraversal();
};


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

template<class DT>
int ParentBinaryTree<DT>::getSize() {
	return numNodes;
}
