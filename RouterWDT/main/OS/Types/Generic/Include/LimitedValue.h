// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_
#define MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_

#pragma once

#include "Range.h"
#include "PreCompiller.h"



namespace OS {
namespace Types {
namespace Generic {

template <class T>
class LimitedValue :public Range<T>,  public DigitalValue<T>
{
private:
	bool _IsMinLimit;
	bool _IsMaxLimit;

public:
	LimitedValue();
	virtual ~LimitedValue();

	virtual T operator++() override;
	virtual T operator--() override;

	bool IsMaxLimit();

	void Reset() override;

	virtual T SetValue(T value) override;

	virtual T SetMinValue();
	virtual T SetMaxValue();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../LimitedValue.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_LIMITEDVALUE_H_ */
