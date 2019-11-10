#include <iostream>
#include "dynamic_array.cpp"
#include "linked_list.cpp"
#include "stack.cpp"
#include "queue.cpp"

int main() {
	{ // Динамический массив. Вывод (100 0 1 2 4)
	
		dynamic_array<int> da = dynamic_array<int>();
		for (int i = 0; i < 5; i++)
			da.add(i);
		da.remove(3);
		da.insert(100, 0);

		for (int i = 0; i < da.count(); i++)
			std::cout << da.get(i) << " ";
		std::cout << "\n";
	}
	{ // Двусвязнный список. Вывод (2 4)

		linked_list<int> ll = linked_list<int>();
		ll.add_first(2);
		ll.add_first(1);
		ll.add_last(3);
		ll.add_last(4);
		ll.add_last(5);
		ll.remove_first();
		ll.remove_last();
		ll.remove(3);
		list_node<int> first = *ll.get_first();
		std::cout << first.value << " ";
		std::cout << first.next->value << "\n";
	}
	{ // Стек. Вывод (2 0)
		stack<int> st = stack<int>();
		for (int i = 0; i < 3; i++)
			st.push(i);
		for (int i = 0; i < 2; i++) {
			if (st.peek() == 1)
				st.pop();
			std::cout << st.pop() << " ";
		}
		std::cout << "\n";
	}
	{ // Очередь. Вывод (0 2)
		queue<int> qu = queue<int>();
		for (int i = 0; i < 3; i++)
			qu.enqueue(i);
		for (int i = 0; i < 2; i++) {
			if (qu.peek() == 1)
				qu.dequeue();
			std::cout << qu.dequeue() << " ";
		}
		std::cout << "\n";
	}
	return 0;
}