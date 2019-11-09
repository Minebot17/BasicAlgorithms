#include <cstdlib>

template <typename T>
class dynamic_array {

private:
	unsigned char* memory;
	int type_size;
	int elements_count;

public:
	dynamic_array() {
		this->type_size = sizeof(T);
		elements_count = 0;
		memory = (unsigned char*) malloc('\0');
	}

	void add(T object) {
		T o = object;
		unsigned char* objectp = (unsigned char*) &o;
		memory = (unsigned char*) realloc(memory, (elements_count + 1) * type_size + 1);
		if (memory == nullptr)
			throw "Out of memory!";
		
		unsigned char* local_memory = memory;
		local_memory += elements_count * type_size;
		for (int i = 0; i < type_size; i++) {
			*local_memory = *objectp;
			++objectp;
			local_memory++;
		}
		*local_memory = '\0';
		elements_count++;
	}

	void insert(T object, int index) {
		T o = object;
		unsigned char* objectp = (unsigned char*)&o;
		unsigned char* new_memory = (unsigned char*) malloc((elements_count + 1) * type_size + 1);
		if (new_memory == nullptr)
			throw "Out of memory!";
		
		for (int i = 0; i < type_size * index; i++) {
			*new_memory = *memory;
			memory++;
			new_memory++;
		}
		for (int i = 0; i < type_size; i++) {
			*new_memory = *objectp;
			++objectp;
			new_memory++;
		}
		for (int i = type_size * (index + 1); i < (elements_count + 1) * type_size; i++) {
			*new_memory = *memory;
			memory++;
			new_memory++;
		}
		*new_memory = '\0';
		elements_count++;
		new_memory -= elements_count * type_size;
		//free(memory);
		memory = new_memory;
	}

	void remove(int index) {
		unsigned char* new_memory = (unsigned char*) malloc((elements_count - 1) * type_size + 1);
		if (new_memory == nullptr)
			throw "Out of memory!";

		for (int i = 0; i < type_size * index; i++) {
			*new_memory = *memory;
			memory++;
			new_memory++;
		}
		if (index != elements_count - 1) {
			memory += type_size;
			for (int i = type_size * index; i < type_size * (elements_count - 1); i++) {
				*new_memory = *memory;
				memory++;
				new_memory++;
			}
		}
		*new_memory = '\0';
		elements_count--;
		new_memory -= elements_count * type_size;
		//free(memory);
		memory = new_memory;
	}

	T get(int index) {
		unsigned char* result = memory;
		result += index * type_size;
		return *((T*) result);
	}

	int get_size() {
		return elements_count;
	}
};
