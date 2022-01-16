// Copyright (c) 2022 Lukin Aleksandr
#include "Range.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
Range<T>::Range()
{
	_Min = make_shared<DigitalValue<T>>();
	_Max = make_shared<DigitalValue<T>>();
}

template <class T>
shared_ptr<DigitalValue<T>> Range<T>::Min()
{
	return _Min;
}

template <class T>
shared_ptr<DigitalValue<T>> Range<T>::Max()
{
	return _Max;
}

template <class T>
bool Range<T>::IsInRange(T value)
{
	return (_Min->GetValue() <= value)&&(_Max->GetValue() >= value);
}

template <class T>
bool Range<T>::IsSetRange()
{
	return (!(_Max->GetValue() == _Min->GetValue()));
}

template <class T>
Range<T>::~Range() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
