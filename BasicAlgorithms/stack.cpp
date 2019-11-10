#include "linked_list.cpp"

template <typename T>
class stack {
private:
	linked_list<T> list = linked_list<T>();

public:
	void push(T item) {
		list.add_last(item);
	}

	T pop() {
		T result = list.get_last()->value;
		list.remove_last();
		return result;
	}

	T peek() {
		return list.get_last()->value;
	}

	int count() {
		return list.count();
	}
};