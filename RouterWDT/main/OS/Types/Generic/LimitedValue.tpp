// Copyright (c) 2022 Lukin Aleksandr
#include "LimitedValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
LimitedValue<T>::LimitedValue()
	:  Range<T>(), DigitalValue<T>(), _IsMinLimit(false), _IsMaxLimit(false)
{

}

template <class T>
T LimitedValue<T>::operator++()
{
	if(!Range<T>::IsSetRange())
		DigitalValue<T>::operator ++();
	else
	{
		T value = Value<T>::GetValue();

		if (Range<T>::IsInRange(++value))
			DigitalValue<T>::operator ++();
		else
		{
			_IsMaxLimit = true;
		}
	}
	return DigitalValue<T>::GetValue();
}

template <class T>
T LimitedValue<T>::operator--()
{
	if(!Range<T>::IsSetRange())
		DigitalValue<T>::operator --();
	else
	{
		T value = Value<T>::GetValue();

		if (Range<T>::IsInRange(--value))
			DigitalValue<T>::operator --();
		else
		{
			_IsMinLimit = true;
		}
	}
	return DigitalValue<T>::GetValue();
}

template <class T>
bool LimitedValue<T>::IsMaxLimit()
{
	return _IsMaxLimit;
}

template <class T>
void LimitedValue<T>::Reset()
{
	DigitalValue<T>::Reset();
	_IsMaxLimit = false;
	_IsMinLimit = false;
}

template <class T>
T LimitedValue<T>::SetValue(T value)
{
	if (!this->IsSetRange())
		return Value<T>::SetValue(value);

	if (Range<T>::IsInRange(value))
	{
		DigitalValue<T>::SetValue(value);

		if (_IsMaxLimit && Range<T>::Max()->IsMore(value)) _IsMaxLimit = false;
		if (_IsMinLimit && Range<T>::Min()->IsLess(value)) _IsMinLimit = false;
	}
	else
	{
		if (Range<T>::Max()->IsLessOrEqual(value))
		{
			SetMaxValue();
			_IsMaxLimit = true;
		}

		if (Range<T>::Min()->IsMoreOrEqual(value))
		{
			SetMinValue();
			_IsMinLimit = true;
		}
	}
	return DigitalValue<T>::GetValue();
}

template <class T>
T LimitedValue<T>::SetMaxValue()
{
	DigitalValue<T>::SetValue(Range<T>::Max()->GetValue());
	return DigitalValue<T>::GetValue();
}

template <class T>
T LimitedValue<T>::SetMinValue()
{
	DigitalValue<T>::SetValue(Range<T>::Min()->GetValue());
	return DigitalValue<T>::GetValue();
}

template <class T>
LimitedValue<T>::~LimitedValue()
{

}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
