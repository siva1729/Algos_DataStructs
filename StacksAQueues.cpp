#include <iostream>
#include <unordered_set>
#include <new>
#include <stack>
#include <array>

using namespace std;


#if 1

class Node {

public:
	int data;
	int length = 0;
    Node* next;

public:
	Node(int d) : data(d), next(NULL) {}

	void Append(int d) {
		//cout << "\nAppend node\n";
		Node* nnode = new Node(d);
		Node* thisNode = this;

		while (thisNode->next != NULL) {
			thisNode = thisNode->next;
		}
 		thisNode->next = nnode;
		++length;
	}

	void Init(int a[], int len) {
		//cout << "\nInit list\n";
		Node* node = this;
		this->data = a[0];
		for (int i = 1; i < len; i++) Append(a[i]);
		//return this;
	}

	Node* GetNode(int k) {
		//cout << "\nGet node\n";
		Node* node = this;
		int len = 0;
		while (node != NULL) {
			++len;
			if (k == len) return node;
			else node = node->next;
		}
		return NULL;
	}


};


//-----------------------------------------------------
// Print LinkedList
// Assign head to node and check if NULL;
// Print the data and pint node->next to node;
//-----------------------------------------------------
void PrintLL(Node* head) {
	int len = 0;
	Node* inode = head;
	
	while (inode != NULL) {
		cout << inode->data << " -> ";
		inode = inode->next;
		++len;
		if (len >= 15) break;
	}
	cout << "NULL" << endl;
}

void PrintRecLL(Node* node) {

	if (node == NULL) return;

	cout << node->data << " ";
	PrintRecLL(node->next);	
}

void PrintRevRecLL(Node* node) {
	if (node == NULL) return;
	PrintRevRecLL(node->next);
	cout << node->data << " ";
}

//-----------------------------------------------------
// InsertBefore a data in LinkedList
// Assign head to node and check if NULL;
// Print the data and pint node->next to node;
//-----------------------------------------------------
Node* InsertBeforeLL(Node* head, int d, int newd) {
	Node* newhead = head;
	Node* inode = head;
	Node* prev = NULL;

	while (inode != NULL) {
		//cout << inode->data << ":-> ";

		if (inode->data == d) {
			Node* nnode = new Node(newd);
			Node* temp = inode;

			// If node is head, adjust new head;
			if (prev == NULL) {
				newhead = nnode;
			}
			else {
				prev->next = nnode;
			}
			nnode->next = inode;

			break;

		}
		else {
			prev = inode;
			inode = inode->next;
		}
	}
	
	return newhead;
}

//-----------------------------------------------------
// InsertAfter a data in LinkedList
//-----------------------------------------------------
Node* InsertAfterLL(Node* head, int d, int newd) {
	Node* newhead = head;
	Node* inode = head;
	//Node* prev = NULL;

	while (inode != NULL) {
		//cout << inode->data << ":-> ";
		if (inode->data == d) {
			Node* nnode = new Node(newd);
			Node* temp = inode->next;
			inode->next = nnode;
			nnode->next = temp;
			break;
		}
		else {
			inode = inode->next;
		}
	}

	return newhead;
}

//-----------------------------------------------------
// Deletea Node in LinkedList
//-----------------------------------------------------
Node* DeleteLL(Node* head, int d) {
	Node* newhead = head;
	class Node* inode = head;
	Node* prev = NULL;

	while (inode != NULL) {
		//cout << inode->data << ":-> ";
		if (inode->data == d) {
			if (prev == NULL) newhead = inode->next;
			else              prev->next = inode->next;
			if (inode) delete (inode);
			break;
		}
		else {
			prev = inode;
			inode = inode->next;
		}
	}
	return newhead;
}

//-----------------------------------------------------
// Remove duplicates LinkedList
//-----------------------------------------------------
void RemoveDuplicatesLL(Node* head) {
	
	Node* node = head;
	Node* prev = NULL;

	unordered_set<int> uset;

	while (node != NULL) {
		if (uset.find(node->data) != uset.end()) {
			prev->next = node->next;
			delete node;
			node = prev->next;
		}
		else {
			uset.insert(node->data);
			prev = node;
			node = node->next;
		}

	}
	
}


//-----------------------------------------------------
// Find Kth to last element in LinkedList
//-----------------------------------------------------
Node* FindKthToLastLL(Node* head, int K) {

	Node* node = head;
	Node* nodeA = head;
	int length = 0;

	// Runner technique to have 2 pointers
	while (nodeA != NULL) {

		if (length > K) {
			node = node->next;
		}

		nodeA = nodeA->next;
	    ++length;		
	}

	if (length > K) return node;
	else return NULL;

// Two-pass, calc length and then move from head -> (length - K).
#if 1
	// Calulate the pth element from Kth location.
	while (node != NULL) {
		node = node->next;
		++length;
	}
	cout << "Length of LL: " << length << endl;

	if (length <= K) {
		return NULL;
	}
	else {
		int p = length - K - 1;
		node = head;
		for (int i = 0; i < p; i++) node = node->next;
		return node;

	}
#endif

}


//------------------------------------------
// Delete Midddle Node, node that is given
//------------------------------------------
void DeleteMidLL(Node* mid) {

	if (mid == NULL || mid->next == NULL) return;

	mid->data = mid->next->data;
	mid->next = mid->next->next;
	delete mid;
}


//----------------------------------------------
// All nodes less than x to left of given node x
//----------------------------------------------
Node* ArrangeToLeftLL(Node* head, int x) {

	Node* node = head;
	Node* headNew = head;
	Node* stopNode = NULL;
	Node* lastNode = NULL;
	Node* prev = NULL;

	while (node != NULL) {
		lastNode = node;
		node = node->next;
	}
	cout << "lastNode: " << lastNode->data << endl;

	// Reset node to head 
	node = head;
	
	while (node != stopNode) {
		if (node->data >= x) {
			cout << " node->data: " << node->data << endl;
			Node* temp = node;
			// Update current node pointer
			if (prev == NULL)
			{
				headNew = node->next;
			}
			else {
				prev->next = node->next;
			}
			node = node->next;

			// Move current Node to End (LastNode)
			lastNode->next = temp;
			temp->next = NULL;
			lastNode = temp;
			if (stopNode == NULL) stopNode = temp;
			cout << "last Node->data: " << lastNode->data << endl;
		}
		else {
			prev = node;
			node = node->next;
		}
		PrintLL(headNew);
	}

	return headNew;
}


//----------------------------------------------
// All two LL, numbers in reverse order
//----------------------------------------------
Node* AddReverseLL(Node* num1, Node* num2) {

	Node* n1 = num1;
	Node* n2 = num2;
	Node* prev = NULL;
	int d1, d2;
	int carry = 0;

	while (n1 != NULL && n2 != NULL) {
		if (n1 != NULL) {
			d1 = n1->data;
		}
		if (n2 != NULL) {
			d2 = n2->data; n2 = n2->next;
		}

		d1 = d1 + d2 + carry;
		n1->data = (d1) % 10;
		carry = (d1) / 10;

		if (n1 != NULL) {
			prev = n1;  n1 = n1->next;
		}
	}

	prev->next = new Node(carry);

	return num1;
}

//----------------------------------------------
// All two LL, numbers in forward order
//----------------------------------------------
Node* AddForwardLL(Node* num1, Node* num2) {

	Node* n1 = num1;
	Node* n2 = num2;
	
	int d1, d2;
	int carry = 0;
	int multAdd = 0;
    

	while (n1 != NULL && n2 != NULL) {
		if (n1 != NULL) {
			d1 = n1->data;
		}
		if (n2 != NULL) {
			d2 = n2->data; n2 = n2->next;
		}

		if (multAdd == 1) 	multAdd = d1 + d2;
		else multAdd = (multAdd * 10) + d1 + d2;
	
		if (n1 != NULL) {
			 n1 = n1->next;
		}
	}

	cout << "Sum: " << multAdd << endl;

	bool init = true;
	Node* Sum = new Node(0);
	while (multAdd > 0) {
		d1 = multAdd % 10;
		multAdd /= 10;
		if (init) {
			Sum->data = d1;;
			init = false;
		}
		else  Sum->Append(d1);
		
	}

	return Sum;
}

//---------------------------------------------------
// Add Forward two LLs using Recursion Method
//---------------------------------------------------
Node* RecursionAddTwoLLs(Node* num1, Node* num2) {

	static int carry = 0;
	static int len = 0;

	if (num1->next == NULL || num2->next == NULL) {
		int d = num1->data + num2->data + carry;
		carry = d / 10;
		Node* node = new Node(d % 10);
		node->next = NULL;
		return node;
	}
	cout << "Before.." << num1->data << " , " << num2->data << " len: " << ++len << endl;
	Node* head = RecursionAddTwoLLs(num1->next, num2->next);
	cout << "len: " << len-- << "  data: " << num1->data << " , " << num2->data << " + " << carry << endl;

	int d = num1->data + num2->data + carry;
	carry = d / 10;
	Node* node = new Node(d % 10);
	node->next = head;

	// For the last node to add..
	if (len == 0) {
		Node* n1 = new Node(carry);
		n1->next = node;
		return n1;
	}
	return node;
}
//----------------------------------------------
// Reverse a Linked List
//----------------------------------------------
Node* ReverseRecLL(Node* node) {
	Node* head;

	if(node->next == NULL) {
		head = node;
		return head;
	}

	head = ReverseRecLL(node->next);
	Node* q = node->next;
	q->next = node;
	node->next = NULL;

	return head;
}



//----------------------------------------------
// Check if LL isPalindrome 
//----------------------------------------------
template <class T>
bool IsPalindromeLL(Node* head) {
	bool isPalindrome = true;

	// Stack method O(n), space O(n)
#if 1
	stack<T> mystack;
	bool isPalindrome = true;

	Node* node = head;

	while (node != NULL) {
		mystack.push(node->data);
		node = node->next;
	}

	node = head;
	while (node != NULL) {
		if (node->data != mystack.top()) {
			isPalindrome = false;
			break;
		}
		mystack.pop();
		node = node->next;
	}
#endif

	return isPalindrome;
}



bool IsPalindromeRecLL(Node** left, Node* right) {

	//cout << "right->data: " << right->data << endl;
	if (right == NULL) {
		cout << "right->next is NULL\n";
		return true;
	}

	bool isp = IsPalindromeRecLL(left, right->next);
	cout << "\nisp: " << isp  << endl;
	//cout << "After recursive call.." << "left,right: " << (*left)->data << ", " << right->data << "\n";
	if (isp == false) return false;
	cout << "After isp\n";

	bool isp1 = ((*left)->data == right->data);
	cout << "\nleft data, right_data: " << (*left)->data << ", " << right->data;
	(*left) = (*left)->next;
	return isp1;
}


//----------------------------------------------
// Check if two LLs intersect and return common node
//----------------------------------------------
Node* IsIntersectLL(Node* node1, Node* node2) {

	Node* cnode;
	static int k = 0;
	cout << k++ << " :IsintersectLL called...\n";

	int len1 = 0, len2 = 0;

	Node* n1 = node1; Node* n2 = node2;
	while (n1 != NULL) {
		n1 = n1->next;
		++len1;
	}

	while (n2 != NULL) { n2 = n2->next; ++len2; }

	int diff = (len1 > len2) ? len1 - len2 : len2 - len1;
	Node* first = (len1 > len2) ? node1 : node2;
	Node* second = (len1 > len2) ? node2 : node1;


	n1 = node1; n2 = node2;

	len1 = 0;
	while (first != NULL) {
		if (len1 >= diff) {
			if (second == first) {
				return first;
			}
			second = second->next;
		}
		first = first->next;
		++len1;
	}

	return NULL;
	
}

//----------------------------------------------
// Check the common node of a Circular LL
//----------------------------------------------
Node* FindCircularLL(Node* head) {

#if 1
	Node* node = head;
	unordered_set<Node*> myset;

	while (node != NULL) {
		if (myset.find(node) != myset.end()) {
			return node;
		}
		else {
			myset.insert(node);
			node = node->next;
		}
	}

	return NULL;
#endif

	Node* slow = head;
	Node* fast = head;

	// Flyod's Cycle finding algo with 2 ptrs, 
	// slow (move by 1) an fast (move by 2) if cycle exist they will meet
	// at a node in the loop (if a loop exists)
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			cout << "Loop detected at: " << slow->data << endl;
			break;
		}		
	}

	// Count number of nodes in the loop
	if (slow == fast) {
		int len = 1;
		fast = slow;
		while (fast->next != slow) {
			fast = fast->next; ++len;
		}
		cout << "Length of the loop: " << len << endl;

		slow = head;
		fast = head;
		for (int i=0; i < len; i++) fast = fast->next;

		Node* prev = NULL;
		while (slow != fast) {
			prev = fast;
			slow = slow->next;
			fast = fast->next;
		}

		prev->next = NULL;
		cout << "Loop starting node: " << slow->data << ", " << prev->data << endl;
		return slow;
	}

	return NULL;
}



//++++++++++++++++++++++++++++++++++++++++
// Main
//++++++++++++++++++++++++++++++++++++++++

#if 1
int main() {

	cout << "Hello World\n" << endl;

	int a[7] = { 6, 1, 7, 8, 7, 1, 6};
	Node* num1 = new Node(0);
	num1->Init(a, 7);
	PrintLL(num1); cout << endl;

#if 1
	int aa[6] = { 1, 2, 3, 4, 5, 6 };
	Node* aaInt = new Node(0);
	aaInt->Init(aa, 6);

	Node* l = aaInt->GetNode(6);
	Node* k = aaInt->GetNode(4);
	l->next = k;
	PrintLL(aaInt);

	cout << "Start node circularLL: " << FindCircularLL(aaInt)->data << endl;
	PrintLL(aaInt);

#endif

#if 1

  int aa[6] = { 1, 2, 3, 4, 5, 6};
	int bb[6] = { 80, 40, 88, 99, 55 };

	Node* aaInt = new Node(0);
	Node* bbInt = new Node(0);

	aaInt->Init(aa, 6);
	bbInt->Init(bb, 5);

	Node* b5 = bbInt->GetNode(5);
	Node* a4 = aaInt->GetNode(6);
	b5->next = a4;

	cout << "kth node: " << b5->data << endl;
	PrintLL(bbInt);


	cout << "RecursiveLL...\n";
	Node* cnode = IsIntersectLL(aaInt, bbInt);
	if (cnode == NULL) cout << "No common node\n";
	else cout << "common node: " << cnode->data << endl;

	Node* n1 = new Node(3);
	Node* n2 = new Node(4);
	Node* n3 = new Node(5);
	Node* n4 = new Node(7);

	Node* head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	n2->Append(40);
	n2->Append(5);
	n2->Append(6);
	n2->Append(5);
	n2->Append(2);

	PrintLL(head);

	cout << "InserBeforeLL.." << endl;
	head = InsertBeforeLL(head, 7,6);
	PrintLL(head);
	head = InsertBeforeLL(head, 3, 2);
	PrintLL(head);

	cout << "InserAfterLL.." << endl;
	head = InsertAfterLL(head, 2, 20);
	PrintLL(head);
	head = InsertAfterLL(head, 7, 70);
	PrintLL(head);

	cout << "\nDeleteLL.." << endl;
	head = DeleteLL(head, 2);
	PrintLL(head);
	head = DeleteLL(head, 70);
	PrintLL(head);
	head = DeleteLL(head, 5);
	PrintLL(head);

	cout << "\nRemoveDuplicatesLL.." << endl;
	RemoveDuplicatesLL(head);
	PrintLL(head);

	cout << "\nFindKthLastLL.." << endl;
	Node* head2 = new Node(1);
	cout << "..here1" << endl;
	for (int i=2; i < 9; i++) head2->Append(i);
	cout << "..here2" << endl;
	PrintLL(head2);

	Node* kth = FindKthToLastLL(head2, 2);
	cout << "2nd to last element: " << kth->data << endl;

	cout << "5th to last element: " << FindKthToLastLL(head2, 5)->data << endl;
	cout << "7th to last element: " << FindKthToLastLL(head2, 7)->data << endl;

	cout << "\nDeleteMidLL ..." << endl;
	PrintLL(head2);
	Node* node = head2->GetNode(3);
	cout << node->data << endl;
	//DeleteMidLL(node);
	PrintLL(head2);

	Node* head3 = new Node(3);
	head3->Append(5);
	head3->Append(8);
	head3->Append(5);
	head3->Append(10);
	head3->Append(2);
	head3->Append(1);

	cout << "\nArrangeToLeftLL ..." << endl;
	PrintLL(head3);
	head2 = ArrangeToLeftLL(head3, 5);
	PrintLL(head2);

	cout << "\nArrangeToLeftLL ..." << endl;
	PrintLL(head3);
	head2 = ArrangeToLeftLL(head3, 5);
	PrintLL(head2);

	cout << "\nAddResevereLL ..." << endl;
	int a[3] = { 6, 1, 7 };
	int b[3] = { 9, 8, 6 };
	Node* num1 = new Node(0);
	Node* num2 = new Node(0);
	num1->Init(a, 3);
	num2->Init(b, 3);
    PrintLL(num1);
	PrintLL(num2);
	cout << "\nAddResevereLL ..." << endl;
	Node* sum = AddReverseLL(num1, num2);
	PrintLL(sum);
	cout << "\nAddForwardLL ..." << endl;
	sum = AddForwardLL(num1, num2);
	PrintLL(sum);

	cout << "\nIsPalindromeLL ..." << endl;
	int aa[5] = { 1, 22, 333, 22, 1 };
	int bb[5] = { 1, 22, 333, 21, 1 };
	Node* aaInt = new Node(0);
	Node* bbInt = new Node(0);

	aaInt->Init(aa, 5);
	bbInt->Init(bb, 5);

	PrintLL(aaInt);
	cout << "IsPalindrome: " << IsPalindromeLL<int>(aaInt) << endl;
	PrintLL(bbInt);
	cout << "IsPalindrome: " << IsPalindromeLL<int>(bbInt) << endl;

	int a[3] = { 6, 1, 7 };
	Node* num1 = new Node(0);
	num1->Init(a, 3);
	PrintLL(num1); cout << endl;
	PrintRecLL(num1); cout << endl;
	PrintRevRecLL(num1);

	cout << "ReverseRecLL...\n";
	num1->data = 0;
	num1 = ReverseRecLL(num1);
	PrintLL(num1);
	bool isp =  IsPalindromeRecLL(&num1, num1);
	cout << " IsPalindromeRecLL: " << (isp ? "true" : "false") << endl;

#endif

	
	 
	   	  
}


#endif

#endif
