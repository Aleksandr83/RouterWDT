// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_
#define MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_

#pragma once

#include "Value.h"
#include "ZeroCompareEx.h"
#include "ValueCompareEx.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class DigitalValue
	: public Value<T>, public ZeroCompareEx<T>, public ValueCompareEx<T>
{
public:
	DigitalValue();
	virtual ~DigitalValue();

	virtual T GetValue() override;

	virtual T operator++();
	virtual T operator--();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../DigitalValue.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_DIGITALVALUE_H_ */
