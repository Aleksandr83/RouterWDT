// Copyright (c) 2022 Lukin Aleksandr
#include "DigitalValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
DigitalValue<T>::DigitalValue()
	: Value<T>(), ZeroCompareEx<T>(), ValueCompareEx<T>()
{
	Value<T>::SetValue(0);
	Value<T>::SetDefault(0);
}

template <class T>
T DigitalValue<T>::GetValue()
{
	return Value<T>::GetValue();
}

template <class T>
T DigitalValue<T>::operator++()
{
	T value = GetValue();
	return Value<T>::SetValue(++value);
}

template <class T>
T DigitalValue<T>::operator--()
{
	T value = GetValue();
	return Value<T>::SetValue(--value);
}

template <class T>
DigitalValue<T>::~DigitalValue() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
