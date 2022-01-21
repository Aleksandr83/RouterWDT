// Copyright (c) 2022 Lukin Aleksandr
#include "Registrator.h"

namespace OS {
namespace Types {

template <class TKey,class TValue>
Registrator<TKey,TValue>::Registrator() {
	// TODO Auto-generated constructor stub

}

template <class TKey,class TValue>
void Registrator<TKey,TValue>::Registration(TKey key, TValue value)
{
	_Items.insert(std::make_pair(key, value));
}

template <class TKey,class TValue>
TValue Registrator<TKey,TValue>::operator[](TKey key)
{
	return _Items.at(key);
}

template <class TKey,class TValue>
Registrator<TKey,TValue>::~Registrator() {
	// TODO Auto-generated destructor stub
}

} /* namespace Types */
} /* namespace OS */
