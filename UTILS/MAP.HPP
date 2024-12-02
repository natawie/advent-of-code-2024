#ifndef MAP_HPP
#define MAP_HPP

#include "..\utils\vector.hpp"

template <class T, class U>
class Map {
private:
	Vector<T> *keys;
	Vector<U> *values;
public:
	Map() {
		keys = new Vector<T>();
		values = new Vector<U>();
	}

	Map(size_t size) {
		this->keys = new Vector<T>(size);
		this->values = new Vector<U>(size);
	}

	~Map() {
		delete keys;
		delete values;
	}

	U* get(T &key) {
		long idx = -1;
		for (size_t i = 0; i < keys->getSize(); ++i) {
			if (keys->get(i) == key) {
				idx = i;
				break;
			}
		}
		if (idx == -1) return NULL;
		return &values->get(i);
	}

	void put(T key, U value) {
		U* potentialValue = this->get(key);
		if (potentialValue != NULL) {
			*potentialValue = value;
			return;
		}
		keys->push(key);
		values->push(value);
	}
}
#endif