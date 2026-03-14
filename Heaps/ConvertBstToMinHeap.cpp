#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorder(BinaryTreeNode* root,vector<int>& arr){
	if(root == NULL) return;
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);
}
void buildMinHeap(vector<int> &arr,int &i,BinaryTreeNode* root){
if(root == NULL) return;
root->data = arr[i++];
buildMinHeap(arr,i,root->left);
buildMinHeap(arr,i,root->right);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	BinaryTreeNode* temp = root;
	vector<int> arr;
	int i = 0;
	inorder(temp,arr);// it will convert bst into sorted order;
	buildMinHeap(arr,i,temp);
    return root;
}
