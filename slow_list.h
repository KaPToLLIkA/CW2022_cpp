#pragma once
#include <stdint.h>

template<typename T>
struct node {
	T* data;
	node<T>* next;
	node<T>* prev;
};

template<typename T>
class slow_list
{
	node<T>* end;
	node<T>* begin;

	uint32_t count;
public:
	explicit slow_list();

	void add(T* value);
	void remove_by_value(T* value);
	T* get_value_at(uint32_t index);

	uint32_t lenght();

	~slow_list();
};

template<typename T>
inline slow_list<T>::slow_list()
{
	count = 0;
	end = nullptr;
	begin = nullptr;
}

template<typename T>
inline void slow_list<T>::add(T* value)
{
	if (count == 0) {
		auto item = new node<T>();
		item->data = value;
		item->next = item;
		item->prev = item;
		end = item;
		begin = item;
	}
	else {
		auto item = new node<T>();
		item->data = value;
		item->prev = end;
		item->next = begin;
		end->next = item;
		begin->prev = item;
		end = item;
	}
	++count;
}

template<typename T>
inline void slow_list<T>::remove_by_value(T* value)
{
	if (count > 1) {
		auto iterator = begin;
		do {
			if (*(iterator->data) == *value) {
				auto prev = iterator->prev;
				auto next = iterator->next;
				prev->next = next;
				next->prev = prev;
				if (iterator == begin) {
					begin = next;
				}
				if (iterator == end) {
					end = prev;
				}
				delete iterator->data;
				delete iterator;
				--count;
				break;
			}
			iterator = iterator->next;
		} while (iterator != begin);
	}
	else if (count == 1 && *begin->data == *value) {
		delete begin->data;
		delete begin;
		begin = nullptr;
		end = nullptr;
		count = 0;
	}
}

template<typename T>
inline T* slow_list<T>::get_value_at(uint32_t index)
{
	if (count > index) {
		auto iterator = begin;
		for (int i = 0; i < index; ++i) {
			iterator = iterator->next;
		}
		return iterator->data;
	}
	return nullptr;
}

template<typename T>
inline uint32_t slow_list<T>::lenght()
{
	return count;
}

template<typename T>
inline slow_list<T>::~slow_list()
{
	auto iterator = begin;
	for (int i = 0; i < count; ++i) {
		auto next = iterator->next;
		delete iterator->data;
		delete iterator;
		iterator = next;
	}
}
