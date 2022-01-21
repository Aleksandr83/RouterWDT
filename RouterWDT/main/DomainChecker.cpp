// Copyright (c) 2022 Lukin Aleksandr
#include "DomainChecker.h"
#include "Settings.h"

using OS::System::Timer;

DomainChecker::DomainChecker()
	: _IsEnabled(false)
{
	_Icmp  = make_shared<Icmp>();
	_Timer = make_shared<Timer<DomainChecker*>>
			(DEF_DOMAIN_CHECK_INTERVAL, OnTimer, this);
	_DomainList   = make_shared<RandomDomainList>();
	_ErrorCounter = make_shared<Counter<uint8_t>>();
}

void DomainChecker::Init()
{
	_DomainList->Init();
}

bool DomainChecker::Check()
{
	char* domain = (char*)_DomainList->GetRandomNext().c_str();

	if (_Icmp->Ping(domain, 3))
	{
		_ErrorCounter->Reset();
		return true;
	}
	else
	{
		_ErrorCounter->Inc();
		if (_ErrorCounter->IsMaxLimit())
		{
			Disable();
		}
	}

	return false;
}

void DomainChecker::ResetState()
{
	_ErrorCounter->Reset();
}

void DomainChecker::Enable()
{
	if (_IsEnabled) return;

	ResetState();
	_Timer->Start();
	_IsEnabled = true;
}

void DomainChecker::Disable()
{
	if (!_IsEnabled) return;
	_Timer->Stop();
}

shared_ptr<Counter<uint8_t>> DomainChecker::GetErrorCounter()
{
	return _ErrorCounter;
}

void DomainChecker::OnTimer(Timer<DomainChecker*>* timer,DomainChecker* domainChecker)
{
	bool result;
	do
	{
		result = domainChecker->Check();
	}
	while (!result&&!domainChecker->GetErrorCounter()->IsMaxLimit());
}

DomainChecker::~DomainChecker() {
	// TODO Auto-generated destructor stub
}

