// Copyright (c) 2022 Lukin Aleksandr
extern "C"{
#include <esp_system.h>
}

#include "RandomList.h"

namespace OS {
namespace Types {
namespace Generic {

using namespace std;

template <class T>
RandomList<T>::RandomList()
{
	_Items = make_shared<list<T>>();
}

template <class T>
void RandomList<T>::Add(T value)
{
	_Items->push_back(value);
}

template <class T>
T RandomList<T>::GetRandomNext()
{
	T result;
	int i = 0;
	int x = GetRandomIndex();
	for (auto iter = _Items->begin(); iter != _Items->end(); iter++)
	{
		if (i == x)
			return *iter;
	    i++;
	}
	return result;
}

template <class T>
int RandomList<T>::GetRandomIndex()
{
	auto range = this->_Items->size();
	//std::default_random_engine dre{random_device{}()};
	//std::uniform_int_distribution<uint> distribution(0,range-1);
	//result = distribution(dre);
	return (random() % range);
}

template <class T>
RandomList<T>::~RandomList() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
