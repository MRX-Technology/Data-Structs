#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class Stack
{
private:
	Node *top;
	int count;
public:
	Stack()
	{
		top = NULL;
		count = 0;
	}
	bool isEmpty();// check if stack is empty
	void push(int);// add new element in last position of stack
	void pop();// remove last element
	void peek();// Show last element
	void display(); // show all data in stack
	void displayCount(); // show number of elements in stack
};
bool Stack::isEmpty()
{
	return top == NULL;
}
void Stack::push(int val)
{
	if (isEmpty())
	{
		top = new Node;
		top->data = val;
		top->next = NULL;
		count++;
	}
	else
	{
		Node *newNode = new Node;
		newNode->data= val;
		newNode->next= top;
		// copy address of newnode to top
		top = newNode;
		count++;
	}
}
void Stack::pop()
{
	if (top == NULL)
	{
		cout << "\nStack underflow.\n";
	}
	else
	{
		cout << "Element Deleted: " <<top->data<< endl;
		Node* temp = top;
		top = top->next;
		delete(temp);
		count--;
	}
}
void Stack::display()
{
	if (!isEmpty())
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout <<temp->data<< endl;
			temp =temp->next;
		}
	}
	else
	{
		cout << "\nStack is empty\n";
	}
}
void Stack::displayCount()
{
	cout << "\nElements in Stack: " << count << endl;
}
void Stack::peek()
{
	if (!isEmpty())
	{
		cout << "\nFirst Element :" <<top->data<< endl;
	}
}
int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.displayCount();
	s.display();
	s.peek();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	getchar();
}
