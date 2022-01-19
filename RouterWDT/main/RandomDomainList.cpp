// Copyright (c) 2022 Lukin Aleksandr
#include "RandomDomainList.h"


RandomDomainList::RandomDomainList()
	: RandomList<string>()
{
}

void RandomDomainList::Init()
{
	Add("www.google.com");
	Add("www.amazon.com");
	Add("www.youtube.com");
	Add("www.tiktok.com");
	Add("www.yahoo.com");
	Add("www.yandex.ru");
	Add("www.mail.ru");
	Add("www.ebay.com");
	Add("www.mozilla.org");
	Add("www.twitter.com");
	Add("www.reddit.com");
	Add("www.netflix.com");
	Add("www.spotify.com");
	Add("www.baidu.com");
	Add("www.xnxx.com");
	Add("www.vk.com");
	Add("www.live.com");
	Add("www.ok.ru");
	Add("www.google.de");
	Add("www.google.fr");
	Add("www.jd.com");
	Add("www.office.com");
}

RandomDomainList::~RandomDomainList()
{
}

