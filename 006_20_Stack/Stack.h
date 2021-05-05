#include <stdexcept>

template <class item_type>
class Stack {
	struct node {
		item_type item;
		node* next;
	};
private:
	node* tail;
	int anz_items;
public:
	Stack();
	~Stack();
	void push(const item_type& r);
	item_type pop();
	item_type top();
	int length();
	bool empty();
};

template<class item_type>
Stack<item_type>::Stack() : tail(nullptr), anz_items(0) { }

template<class item_type>
Stack<item_type>::~Stack()
{
	node* current_node = tail;

	while (current_node != nullptr) {
		node* next_node = current_node->next;
		delete current_node;
		current_node = next_node;
	}
}

template<class item_type>
void Stack<item_type>::push(const item_type & r)
{
	tail = new node{ r, tail };
	anz_items++;
}

template<class item_type>
item_type Stack<item_type>::pop()
{
	if (empty())
		throw std::logic_error("no elements left to pop");

	item_type result = tail->item;
	node* old_tail = tail;
	tail = tail->next;
	delete old_tail;
	anz_items--;

	return result;
}

template<class item_type>
inline item_type Stack<item_type>::top()
{
	if (empty())
		throw std::logic_error("stack is empty");

	return tail->item;
}

template<class item_type>
int Stack<item_type>::length()
{
	return anz_items;
}

template<class item_type>
bool Stack<item_type>::empty()
{
	return anz_items == 0;
}
