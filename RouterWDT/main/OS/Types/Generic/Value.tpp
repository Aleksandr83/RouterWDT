// Copyright (c) 2022 Lukin Aleksandr
#include "Value.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Value<T>::Value()
{
	// TODO Auto-generated constructor stub
}

template <class T>
T Value<T>::GetValue()
{
	return _Value;
}

template <class T>
T Value<T>::SetValue(T value)
{
	_Value = value;
	return _Value;
}

template <class T>
void Value<T>::Reset()
{
	SetValue(GetDefault());
}

template <class T>
T Value<T>::GetDefault()
{
	return _Default;
}

template <class T>
T Value<T>::SetDefault(T value)
{
	_Default = value;
	return _Default;
}

template <class T>
bool Value<T>::operator==(Value& value)
{
	return (_Value == value.GetValue());
}

template <class T>
Value<T>::~Value() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
