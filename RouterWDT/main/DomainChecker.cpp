// Copyright (c) 2022 Lukin Aleksandr
#include "DomainChecker.h"


DomainChecker::DomainChecker()
	: _IsChecked(false)
{
	_Icmp = make_shared<Icmp>();
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
		//_IsChecked = true;
		//_ErrorCounter->Reset();
		return true;
	}
	else
	{
		_ErrorCounter->Inc();
	}

	return false;
}

bool DomainChecker::IsChecked()
{
	return _IsChecked;
}

void DomainChecker::ResetState()
{
	_IsChecked = false;
}

shared_ptr<Counter<uint8_t>> DomainChecker::GetErrorCounter()
{
	return _ErrorCounter;
}

DomainChecker::~DomainChecker() {
	// TODO Auto-generated destructor stub
}

