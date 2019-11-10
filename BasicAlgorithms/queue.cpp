#include "linked_list.cpp"

template<typename T>
class queue {
private:
	linked_list<T> list = linked_list<T>();

public:
	void enqueue(T item) {
		list.add_first(item);
	}

	T dequeue() {
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