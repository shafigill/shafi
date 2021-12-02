#include<iostream>
using namespace std;

class Node
{
	private:
		int data;
		Node* next;
		
	public:
		void setData(int n)
		{
			data = n;
		}
		int getData()
		{
			return data;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		Node* getNext()
		{
			return next;
		}
};

class list
{
	private:
		Node* head;
		Node* current;
		int size;
		
	public:
		list(int d)
		{
			head = new Node;
			current = head;
			head->setData(d);
			head->setNext(NULL);
			size = 1;
		}
		
		void moveCurrentatLAST()
		{
			if(size != 0)
		{
			while(current->getNext() != NULL)
			{
				current = current->getNext();
			}
		}
		}
		
		void AddNodeatEND(int n)
		{
			moveCurrentatLAST();
			Node* temp = new Node;
			temp->setData(n);
				temp->setNext(NULL);
			current->setNext(temp);
			current = temp;
		
			size++;
		}
		
		void AddNodenexttoHEAD(int n)
		{
			Node* temp = new Node;
			temp->setData(n);
			temp->setNext(head->getNext());
			head->setNext(temp);
			current = temp;
			size++;
			
		}
		
		void AddNodeNexttoCURRENT(int n)
		{
			Node* temp = new Node;
			temp->setNext(current->getNext());
			current->setNext(temp);
			current = temp;
			size++;
		}
		
		void PrintCURRENT()
		{
			cout<<"\n\nCURRENT: "<<current->getData()<<endl<<endl;
		}
		
		void AddNodeBeforeHEAD(int n)
		{
			Node* temp = new Node;
			temp->setData(n);
			temp->setNext(head);
			head = temp;
			current = temp;
			size++;
		}
		
		void printSIZE()
		{
			cout<<"\n\nSIZE: "<<size<<endl<<endl;
		}
		
		void sort()
		{
			for(int i=0; i<size; i++)
			{
				Node* pant = head;
				Node* temp = pant->getNext();
				for(int j=0; j<size-i-1; j++)
				{
					if(pant->getData() > temp->getData())
					{
						pant->setData(pant->getData() + temp->getData());
						temp->setData(pant->getData() - temp->getData());
						pant->setData(pant->getData() - temp->getData());
						
					}
					pant = pant->getNext();
					temp = temp->getNext();
				}
			}
		}
		
		void Print()
		{ 
			Node* tmp = head;
			for(int i=0; i<size; i++)
			{
				cout<<tmp->getData()<<"  ";
				tmp = tmp->getNext();
			}
		}
};

int main()
{
	list a(78);
	a.AddNodeatEND(90);
	a.AddNodeatEND(34);
	a.AddNodeatEND(45);
	a.AddNodeatEND(67);
	a.AddNodeatEND(78);
	a.AddNodeatEND(12);
	a.AddNodeatEND(80);
	a.Print();
	a.sort();
	cout<<endl;
	cout<<"After sorting: \n";
	a.Print();
	return 0;
}
