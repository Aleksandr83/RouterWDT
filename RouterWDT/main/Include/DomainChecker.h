// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_DOMAINCHECKER_H_
#define MAIN_DOMAINCHECKER_H_

#pragma once

#include "RandomDomainList.h"
#include "Icmp.h"
#include "Counter.h"
#include "Timer.h"

using OS::Net::Icmp;
using OS::Types::Generic::Counter;
using OS::System::Timer;

class DomainChecker {
private:
	bool _IsEnabled;

	shared_ptr<RandomDomainList> _DomainList;
	shared_ptr<Icmp> 			 _Icmp;
	shared_ptr<Counter<uint8_t>> _ErrorCounter;

	shared_ptr<Timer<DomainChecker*>>	_Timer;

public:
	DomainChecker();
	virtual ~DomainChecker();

	void Init();

	void Enable();
	void Disable();

	shared_ptr<Counter<uint8_t>> GetErrorCounter();

private:
	bool Check();
	void ResetState();

	static void OnTimer(Timer<DomainChecker*>* timer,DomainChecker* domainChecker);
};

#endif /* MAIN_DOMAINCHECKER_H_ */
