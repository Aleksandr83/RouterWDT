// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_TYPES_GENERIC_RANDOMLIST_H_
#define MAIN_OS_TYPES_GENERIC_RANDOMLIST_H_

#pragma once

#include "PreCompiller.h"

namespace OS {
namespace Types {
namespace Generic {

template <class T>
class RandomList {
private:
	shared_ptr<list<T>> _Items;

public:
	RandomList();
	virtual ~RandomList();

	virtual void Add(T value);

	virtual T GetRandomNext();

protected:
	virtual int GetRandomIndex();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#include "../RandomList.tpp"

#endif /* MAIN_OS_TYPES_GENERIC_RANDOMLIST_H_ */
