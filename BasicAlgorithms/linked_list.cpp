
template <typename T>
class list_node {
public:
	list_node* prev = nullptr;
	list_node* next = nullptr;
	T value;
};

template <typename T>
class linked_list {
private:
	list_node<T>* first = nullptr;
	list_node<T>* last = nullptr;
	int elements_count = 0;

public:
	void add_last(T item) {
		list_node<T>* to_add = new list_node<T>();
		to_add->value = item;
		if (last != nullptr) {
			to_add->prev = last;
			last->next = to_add;
		}
		last = to_add;
		if (first == nullptr)
			first = to_add;
		elements_count++;
	}

	void add_first(T item) {
		list_node<T>* to_add = new list_node<T>();
		to_add->value = item;
		if (first != nullptr) {
			to_add->next = first;
			first->prev = to_add;
		}
		first = to_add;
		if (last == nullptr)
			last = to_add;
		elements_count++;
	}

	void remove_first() {
		if (first != nullptr) {
			list_node<T>* next = first->next;
			delete first;
			if (next != nullptr) {
				next->prev = nullptr;
				first = next;
			}
			else
				first = nullptr;
		}
	}

	void remove_last() {
		if (last != nullptr) {
			list_node<T>* prev = last->prev;
			delete last;
			if (prev != nullptr) {
				prev->next = nullptr;
				last = prev;
			}
			else
				last = nullptr;
		}
	}

	void remove(T item) {
		list_node<T>* current = first;
		while (current != nullptr && current->value != item) {
			current = current->next;
		}
		if (current != nullptr) {
			list_node<T>* prev = current->prev;
			list_node<T>* next = current->next;
			if (prev == nullptr)
				remove_first();
			else if (next == nullptr)
				remove_last();
			else {
				delete current;
				prev->next = next;
				next->prev = prev;
			}
		}
	}

	list_node<T>* get_first() {
		return first;
	}

	list_node<T>* get_last() {
		return last;
	}

	int count() {
		return elements_count;
	}
};