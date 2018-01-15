#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int V) :val(V), left(NULL), right(NULL) {}
};
void Insert(TreeNode* &root, int value)
{
	if (root == NULL)
	{
		root = new TreeNode(value);
	}
	else
	{
		if (value > root->val)
		{
			Insert(root->right, value);
		}
		else
		{
			Insert(root->left, value);
		}
	}
}
TreeNode* searchNode(TreeNode* &root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	else {
		if (val == root->val)
		{
			return root;
		}
		else
		{
			if (val > root->val)
			{
				return searchNode(root->right, val);
			}
			else {
				return searchNode(root->left, val);
			}

		}
	}
}
TreeNode* Max(TreeNode* &root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;
	else
	{
		return Max(root->right);
	}
}
TreeNode* Min(TreeNode* &root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	else
	{
		return Max(root->left);
	}
}
void Inorder_traversal(TreeNode* &root, list<int>&node)
{
	if (root->left != NULL)
		Inorder_traversal(root->left, node);
		node.push_back(root->val);
	if (root->right != NULL)
		Inorder_traversal(root->right, node);
	else
		return;
}
void flatten(TreeNode* root) {
	if (root == NULL) { return; }
	if (root->left != NULL)
	{
		flatten(root->left);
		TreeNode* ptr = root->left;
		while (ptr->right != NULL) {
			ptr = ptr->right;
		}
		ptr->right = root;
		root->left = ptr;
	}
	if (root->right != NULL) {
		flatten(root->right);

		TreeNode* ptr2 = root->right;
		while (ptr2->left) {
			ptr2 = ptr2->left;
		}
		ptr2->left = root;
		root->right = ptr2;
	}
}
void flatten2(TreeNode* root) {
	

}

void reverseBinarytree(TreeNode* &root)
{
	if (root == NULL){
		return;
	}
	swap(root->left, root->right);
	reverseBinarytree(root->left);
	reverseBinarytree(root->right);
}
TreeNode* Insert2(TreeNode* &root, int value)
{
	if (root == NULL)
	{
		root = new TreeNode(value);
		return root;
	}
	else
	{
		if (value > root->val)
		{
			return Insert2(root->right, value);
		}
		else
		{
			return Insert2(root->left, value);
		}
	}
}
void DeleteNode(int target, TreeNode* &root)
{
	TreeNode* front = root;
	TreeNode* back = root;
	if (root == NULL) { return; }

	while (front->val != target) {

		if (front->val < target&&front->right != NULL) {
			back = front;

			front = front->right;
		}
		if (front->val > target && front->left != NULL) {
			back = front;
			front = front->left;
		}

		if (front->left == NULL&&front->right == NULL&&front->val != target)
		{
			
			return;
		}
	}
	
	if (back->right == front){
		if (front->left != NULL && front->right != NULL) {
			TreeNode* p = Insert2(front->right, front->left->val);
			p->left = front->left->left;
			p->right = front->left->right;
			back->right = front->right;
			delete front;
			return;
		}
		if (front->left == NULL && front->right != NULL) {
			back->right = front->right;
			delete front;
		}
		if (front->left != NULL && front->right == NULL) {
			back->right = front->left;
			delete front;
			return;
		}
		if (front->left == NULL&&front->right == NULL) {
			back->right = NULL;
			return;
		}
	}
	if (back->left == front) {
		if (front->left != NULL && front->right != NULL) {
			TreeNode* p = Insert2(front->left, front->right->val);
			p->right = front->right->right;
			p->left = front->right->left;
			back->left = front->left;
			delete front;
			return;
		}
		if (front->right == NULL && front->left != NULL) {
			back->left = front->left;
			delete front;
			return;
		}
		if (front->right != NULL && front->left == NULL) {
			back->left = front->right;
			delete front;
			return;
		}
		if (front->left == NULL&&front->right == NULL) {
			back->left = NULL;
			return;
		}
	}
}
TreeNode* deleteNode(TreeNode* root, int key) {

	if (root == NULL) { return NULL; }
	if (root->left == NULL&&root->right == NULL&&key == root->val) {
		return NULL;
	}
	if (root->left == NULL || root->right == NULL) {
		
		if (root->left != NULL&&key == root->val) {
			return root->left;
		}
		if (root->right != NULL&&key == root->val) {
			return root->right;
		}
	}
	else {
		if (key == root->val){
			
			TreeNode* leftroot = Insert2(root->right, root->left->val);
			
		leftroot->left = root->left->left; //copy
		leftroot->right = root->left->right;
		return root->right;
	}
}

DeleteNode(key, root);
return root;
}
void print_tree(TreeNode* &root) {


		if (root->left != NULL)
			print_tree(root->left);
		cout << root->val <<  " ";
		if (root->right != NULL)
			print_tree(root->right);
		else
			return;
}
vector<int> myvec;
vector<int> inorderTraversal(TreeNode* root) {
	if (root == NULL) {
		
	}
	if (root->left != 0)
	{
		inorderTraversal(root->left);
	}

	myvec.push_back(root->val);
	if (root->right != 0)
		inorderTraversal(root->right);
	return myvec;
}


bool searchNode1(TreeNode* &root, int val)
{
	if (root == NULL)
	{
		return false;
	}
	else {
		if (val == root->val)
		{
			return true;
		}
		else
		{
			if (val > root->val)
			{
				return searchNode1(root->right, val);
			}
			else {
				return searchNode1(root->left, val);
			}

		}
	}
}
bool findTarget(TreeNode* root, int k) {
	int a = 4;
	
	return searchNode1(root, k);
			
		
	
}
void Insertion(TreeNode* &Head, int val) {
	TreeNode* newnode = 0;
	if (Head == 0) {
		newnode = new TreeNode(val);
	}
	else {
		if (val > Head->val) {
			Insert(Head->right, val);
		}
		else { Insert(Head->left, val); }
	}
}
TreeNode* sortedListToBST(ListNode* head) {
	if (head == 0) { return 0; }
	TreeNode* Head = new TreeNode(head->val);
	ListNode* ptr = head->next;
	while (ptr) {
		Insert(Head, ptr->val);
		ptr = ptr->next;
		cout << "count" << endl;
	}
	return Head;
}

int minSteps(int n) {
	int* a = new int[n + 1];
	a[1] = 0;
	a[2] = 2;
	int i = 3;
	vector<int> sum;
	int target;
	while (i <= n) {
		for (unsigned k = 1; k <= i; k++) {
			if (i % k == 0) {
				sum.push_back(i / k);
				target = sum[sum.size() / 2];
			}
		}
		if (target == 1) { a[i] = i; cout << "a[" << i << "] = " << a[i] << " " << "target = " << target <<" "<<i/target<< "   " << a[target] << " " << a[i / target] << endl;
		}
		else { a[i] = a[target] + a[i / target]; 
		cout << "a[" << i << "] = " << a[i] << " " << "target = " << target << " " << i / target << "   " << a[target] << " " << a[i / target] << endl;
		}
		sum.erase(sum.begin(), sum.end());
		i++;
	}
	return a[n];
}
int maxRoot(TreeNode* root) {
	if (!root) return 0;
	if (maxRoot(root->left) >= 0 || maxRoot(root->right) >= 0)
	return max(maxRoot(root->left), maxRoot(root->right)) + root->val;
	else return root->val;
}
int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	if (!root->left && !root->right) return root->val;
	if (!root->left && root->val < 0) return root->val > maxPathSum(root->right) ? root->val : maxPathSum(root->right);
	if (!root->right && root->val < 0) return root->val > maxPathSum(root->left) ? root->val : maxPathSum(root->left); 
	int left = maxRoot(root->left), right = maxRoot(root->right);
	int FromRoot = (left >= 0 ? left : 0 )+ (right >= 0 ? right : 0) + root->val;
	return max(maxPathSum(root->left), maxPathSum(root->right)) > FromRoot ? max(maxPathSum(root->left), maxPathSum(root->right)) : FromRoot;
}
int main()
{
	TreeNode* root = new TreeNode(2);
	Insert(root, -1);
	cout << maxPathSum(root);
	return 0;
}
