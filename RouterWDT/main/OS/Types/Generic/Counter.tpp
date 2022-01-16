// Copyright (c) 2022 Lukin Aleksandr
#include "Counter.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Counter<T>::Counter()
	: LimitedValue<T>()
{
}

template <class T>
void Counter<T>::Inc()
{
	Counter<T>::operator ++();
}

template <class T>
T Counter<T>::operator++()
{
	return LimitedValue<T>::operator ++();
}

template <class T>
Counter<T>::~Counter()
{

}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
