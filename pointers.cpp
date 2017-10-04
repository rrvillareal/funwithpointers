#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Node Declaration
class NodeType {

public:
	NodeType(int = 0); // constructor with default value for
	int info; // data
	NodeType * nextPtr; // pointer to nextPtr node in the list
};

// Constructor
NodeType::NodeType(int data)
{
	info = data;
	nextPtr = 0;
}

//Insert element to beginning
void insert(NodeType **head, int value)
{
	NodeType *currentPtr;
	currentPtr = new(NodeType);
	if (currentPtr == NULL)
	{
		cout << "Memory not allocated " << endl;
		return;
	}
	else
	{
		currentPtr->info = value;
		currentPtr->nextPtr = *head;
		*head = currentPtr;
	}
}

//Delete First
void deleteFirst(NodeType **head)
{
	NodeType *temp = *head;
	*head = temp->nextPtr;
	delete(temp);
	temp = NULL;
}

//Delete List
void deleteList(NodeType **head)
{
	NodeType *temp = *head;
	while (*head) {
		*head = temp->nextPtr;
		delete(temp);
		temp = *head;
	}
}

//Displays Elements of a link list
void print(NodeType *head)
{
	NodeType *temp;
	if (head == NULL) {
		cout << "The List is Empty" << endl;
		return;
	}
	temp = head;
	cout << "Elements of list are: " << endl;
	while (temp != NULL)
	{
		cout << temp->info << "->";
		temp = temp->nextPtr;
	}
	cout << "NULL" << endl;
}

//Find element
bool find(NodeType *head, int value)
{
	bool flag = false;
	if (head == NULL) {
		cout << "List is empty" << endl;
		return flag;
	}
	NodeType *s;
	s = head;
	while (s != NULL)
	{
		if (s->info == value)
		{
			flag = true;
			cout << "Element " << value << " is found" << endl;
			break;
		}
		s = s->nextPtr;
	}
	if (!flag)
		cout << "Element " << value << " not found in the list" << endl;
	return flag;
}

void findAndDelete(NodeType **head, int value)
{
	NodeType *prev = NULL;
	NodeType *curr = *head;
	if (find(*head, value)) {
		while (curr) {
			if ((curr == *head) && (curr->info == value)) {
				*head = curr->nextPtr;
				delete(curr);
				cout << "Element " << value << " deleted from the list" << endl;
				return;
			}
			if (curr->info == value) {
				prev->nextPtr = curr->nextPtr;
				delete(curr);
				cout << "Element " << value << " deleted from the list" << endl;
				return;
			}
			prev = curr;
			curr = curr->nextPtr;
		}
		delete(curr);
		cout << "Element " << value << " deleted from the list" << endl;
		return;
	}
	cout << "value to deleted not found on the list" << endl;
	return;
}

int main()
{
	int choice, value;
	NodeType *head = NULL;
	NodeType *currentPtr;

	while(1) {
		cout << "===============MENU===============" << endl;
		cout << "1.Add" << endl;
		cout << "2.Print" << endl;
		cout << "3.Delete First" << endl;
		cout << "4.Find & delete" << endl;
		cout << "5.Delete List" << endl;
		cout << "6.Quit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to be inserted: ";
			cin >> value;
			insert(&head, value);
			cout << endl;
			break;
		case 2:
			print(head);
			cout << endl;
			break;
		case 3:
			cout << "First node has been deleted." << endl;
			deleteFirst(&head);
			cout << endl;
			break;
		case 4:
			cout << "Enter the node value to deleted: " << endl;
			cin >> value;
			findAndDelete(&head, value);
			break;
		case 5:
			cout << "List has been deleted" << endl;
			deleteList(&head);
			cout << endl;
			break;
		case 6:
			cout << "Quiting..." << endl;
			deleteList(&head);
			exit(1);
			break;
		default:
			cout << "Wrong choice. Try again." << endl;
		}
	} 
}
