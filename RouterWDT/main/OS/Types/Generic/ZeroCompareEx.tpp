// Copyright (c) 2022 Lukin Aleksandr
#include "ZeroCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
ZeroCompareEx<T>::ZeroCompareEx() {
	// TODO Auto-generated constructor stub

}

template <class T>
bool ZeroCompareEx<T>::IsNull()
{
	return (GetValue() == 0);
}

template <class T>
bool ZeroCompareEx<T>::IsNotNull()
{
	return (GetValue() != 0);
}

template <class T>
ZeroCompareEx<T>::~ZeroCompareEx() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
