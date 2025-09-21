#include <iostream>

class Node{
	public:
		int data;
		Node *next;
		Node(int val); // create node by constructor
};

Node::Node(int val)
{
	data = val;
	next = nullptr;
}

class LinkList{
	private:
		Node *head;
	public:
		LinkList():head(nullptr){};
		void insetAtBegining(int data);
		void insertAtPos(int data, int pos);
		void pintList();
		void delete_node(int index);
		size_t len_of_list();
};

void LinkList::insetAtBegining(int data)
{
	Node *newNode = new Node(data);
	newNode->next = this->head;
	this->head = newNode;
}

void LinkList::insertAtPos(int data, int pos)
{
	if (pos == 0)
	{
		insetAtBegining(data);
		return ;
	}
	Node *newNode = new Node(data);
	Node *tmp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		if (!tmp) 
		{
            std::cout << "Position out of bounds\n";
            return;
        }
		tmp = tmp->next;
	}
	if (!tmp)  // in case list is shorter than expected
	{
		std::cout << "Position out of bounds\n";
		delete newNode;
		return;
	}

	newNode->next = tmp->next;  // key step!
	tmp->next = newNode;      // insert newNode after tmp

}

size_t LinkList::len_of_list()
{
	Node *temp = this->head;
	int i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void LinkList::pintList()
{
	Node *temp = this->head;
	while (temp)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
	
}

void LinkList::delete_node(int index)
{
	if (!head) return;
	if (index < 0 || index > this->len_of_list())
	{
		std::cout << "out of the bounds" << std::endl;
		return ;
	}
	Node *temp = this->head;
	if (this->len_of_list() == 1 && index == 0)
	{
		delete this->head;
		return ;
	}
	if (index == 0) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

	for (size_t i = 0; i < index - 1; i++) // step until one before, why? because you should not miss the chain
	{
		temp = temp->next;
	}
	if (!temp)
	{
		std::cout << "Out of the bounds" << std::endl;
		return ;
	}
	Node *tmp = temp->next;
	temp->next = temp->next->next;
	delete tmp;
}

int main()
{
	//LinkList *linkList; //without un initialze it points to the garbage memory and casue to segfault
	LinkList linkList;

	linkList.insetAtBegining(4);
	linkList.insetAtBegining(5);
	linkList.insetAtBegining(8);
	linkList.insertAtPos(10, 1);
	linkList.insertAtPos(9, 1);
	linkList.delete_node(0); // it can delete the frist element as well easily
	linkList.pintList();
}