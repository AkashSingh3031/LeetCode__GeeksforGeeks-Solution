// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct result{
        int maxi; //max element in BST
        int mini; //min element of specific BST
        bool isBST; // tree with certain node is BST
        int size; //size if the BST
    };
    struct result findlargestBST(Node* root,int &ans){
        if(root==NULL){
            return {INT_MIN,INT_MAX,true,0};
        }
        
        //go for left and rught subtree and get their data with that we do functions on root node
        struct result left=findlargestBST(root->left,ans);
        struct result right=findlargestBST(root->right,ans);
        
        //create a certain node data
        struct result curr;

        //find the max with help of child subtree ,max will be from right.maxi
        curr.maxi=max(root->data,right.maxi);

        //find the min with the help of child subtree ,min will be from left.mini
        curr.mini=min(root->data,left.mini);

        //total size is size of left+size of ruigt part +root
        curr.size=left.size+right.size+1;
        
        //check whether left is BST ,right is BST ,root commes in range of left and right
        if(left.isBST && right.isBST && (left.maxi <root->data && right.mini >root->data) ){
            curr.isBST=true;
        }
        else{
            curr.isBST=false;
        }
        
        //when the current is BST then we update the ans with max size of BST.
        if(curr.isBST){
            ans=max(ans,curr.size);
        }
        
        return curr;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans=INT_MIN;
    	findlargestBST(root,ans);
    	return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends