// Copyright (c) 2022 Lukin Aleksandr
#ifndef OS_TYPES_GENERIC_COUNTER_H_
#define OS_TYPES_GENERIC_COUNTER_H_

#pragma once

#include "LimitedValue.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class Counter : public LimitedValue<T>
{

public:
	Counter();
	virtual ~Counter();

	virtual void Inc();

	virtual T operator++() override;

};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../Counter.tpp"

#endif /* OS_TYPES_GENERIC_COUNTER_H_ */
