// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_RANDOMDOMAINLIST_H_
#define MAIN_RANDOMDOMAINLIST_H_

#pragma once

#include "PreCompiller.h"
#include "RandomList.h"

using std::string;
using OS::Types::Generic::RandomList;

class RandomDomainList : public RandomList<string>
{
public:
	RandomDomainList();
	virtual ~RandomDomainList();

	void Init();

};

#endif /* MAIN_RANDOMDOMAINLIST_H_ */
