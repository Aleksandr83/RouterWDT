// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_DOMAINCHECKER_H_
#define MAIN_DOMAINCHECKER_H_

#pragma once

#include "RandomDomainList.h"
#include "Icmp.h"
#include "Counter.h"

using OS::Net::Icmp;
using OS::Types::Generic::Counter;

class DomainChecker {
private:
	bool _IsChecked;
	shared_ptr<RandomDomainList> _DomainList;
	shared_ptr<Icmp> 			 _Icmp;
	shared_ptr<Counter<uint8_t>> _ErrorCounter;


public:
	DomainChecker();
	virtual ~DomainChecker();

	void Init();

	bool Check();
	bool IsChecked();

	void ResetState();
	shared_ptr<Counter<uint8_t>> GetErrorCounter();

};

#endif /* MAIN_DOMAINCHECKER_H_ */
