// Copyright (c) 2022 Lukin Aleksandr
#include "ValueCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
ValueCompareEx<T>::ValueCompareEx() {
	// TODO Auto-generated constructor stub

}

template <class T>
bool ValueCompareEx<T>::IsMore(T value)
{
	return (GetValue() > value);
}

template <class T>
bool ValueCompareEx<T>::IsMoreOrEqual(T value)
{
	return (GetValue() >= value);
}

template <class T>
bool ValueCompareEx<T>::IsLess(T value)
{
	return (GetValue() < value);
}

template <class T>
bool ValueCompareEx<T>::IsLessOrEqual(T value)
{
	return (GetValue() <= value);
}

template <class T>
ValueCompareEx<T>::~ValueCompareEx() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
