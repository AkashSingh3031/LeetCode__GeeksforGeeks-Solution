// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

Node * reverse(Node * curr)
{
   Node * q=NULL;
   while(curr)
   {
       Node * prev=curr->next;
       curr->next=q;
       q=curr;
       curr=prev;
   }
   return q;
}
class Solution
{
   public:
   Node* reverseBetween(Node* head, int m, int n)
   {
       Node* temp=head;
       Node * start=NULL;
       Node * end=NULL;
       Node *prevstart=NULL;
       Node * nextend=NULL;
      int count=0;
       while(temp)
       {   count++;
           
           if(count==m)
            {  start=temp;
                 
            }
            else if(start==NULL)
            {
                prevstart=temp;
            }
            
             if(count==n)
            {
                end=temp;
                nextend=temp->next;
                end->next=NULL;
            }
            
           temp=temp->next;
       }
       if(prevstart)
            prevstart->next=NULL;
       if(prevstart)
            prevstart->next=reverse(start);
       else
            head=reverse(start);
       
       start->next=nextend;
       return head;
       
       
   }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends