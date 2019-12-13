#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class Queue
{
private:
	Node* front;
	Node* rear;
	int count;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}
	bool isEmpty();// check if Queue is empty
	void enqueue(int);// add new element in last position of Queue
	void dequeue();// remove last element
	void peek();// Show last element
	void displayCount(); // show number of elements in Queue
};
bool Queue::isEmpty()
{
	return rear == NULL;
}
void Queue::enqueue(int val)
{
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	if (isEmpty())
	{
		front = rear = newNode;
		count++;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		count++;
	}
}
void Queue::dequeue()
{
	if (front == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		Node* temp = front;
		int data = temp->data;
		// if there is only one element in queue then remove it
		if (front == rear)
		{
			front = rear = NULL;
			delete(temp);
		}
		else
		{
			//if there are more than one elements
			front = front->next;
			delete(temp);
		}
		cout << "\nDeleted :" << data << endl;
		count--;
	}
}
void Queue::displayCount()
{
	cout << "\nElements in Queue: " << count << endl;
}
void Queue::peek()
{
	if (!isEmpty())
	{
		cout << "\nFirst Element :" << front->data << endl;
	}
}
int main()
{
	Queue q;
	q.dequeue();
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.peek();
	q.enqueue(50);
	q.displayCount();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.displayCount();
	getchar();
}
