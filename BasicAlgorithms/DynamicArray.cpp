#include <cstdlib>

class dynamic_array {

private:
	unsigned char* memory;
	int type_size;
	int elements_count;

public:
	dynamic_array(const int type_size) {
		this->type_size = type_size;
		elements_count = 0;
		memory = (unsigned char*) malloc('\0');
	}

	void add(unsigned char* object) {
		memory = (unsigned char*) realloc(memory, (elements_count + 1) * type_size + 1);
		if (memory == nullptr)
			throw "Out of memory!";
		
		unsigned char* local_memory = memory;
		local_memory += elements_count * type_size;
		for (int i = 0; i < type_size; i++) {
			*local_memory = *object;
			object++;
			local_memory++;
		}
		*local_memory = '\0';
		elements_count++;
	}

	void insert(unsigned char* object, int index) {
		memory = (unsigned char*)realloc(memory, (elements_count + 1) * type_size + 1);
		if (memory == nullptr)
			throw "Out of memory!";

		unsigned char* new_memory = (unsigned char*) malloc((elements_count + 1) * type_size + 1);
		if (new_memory == nullptr)
			throw "Out of memory!";
		
		for (int i = 0; i < type_size * index; i++) {
			*new_memory = *memory;
			memory++;
			new_memory++;
		}
		for (int i = 0; i < type_size; i++) {
			*new_memory = *object;
			object++;
			new_memory++;
		}
		for (int i = type_size * (index + 1); i < (elements_count + 1) * type_size + 1; i++) {
			*new_memory = *memory;
			memory++;
			new_memory++;
		}
		*new_memory = '\0';
		new_memory -= (elements_count + 1) * type_size + 1;
		free(memory);
		memory = new_memory;
		elements_count++;
	}
};
