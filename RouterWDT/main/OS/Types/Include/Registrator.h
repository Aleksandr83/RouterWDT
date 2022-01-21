// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_TYPES_REGISTRATOR_H_
#define MAIN_OS_TYPES_REGISTRATOR_H_

#pragma once

#include "PreCompiller.h"
#include <map>

namespace OS {
namespace Types {

template <class TKey,class TValue>
class Registrator {
private:
	std::map<TKey,TValue> _Items;

public:
	Registrator();
	virtual ~Registrator();

	void Registration(TKey, TValue);

	TValue operator[](TKey key);
};

} /* namespace Types */
} /* namespace OS */

#include "../Registrator.tpp"

#endif /* MAIN_OS_TYPES_REGISTRATOR_H_ */
