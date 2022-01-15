// Copyright (c) 2022 Lukin Aleksandr
#ifndef OS_TYPES_GENERIC_SWITCHER_H_
#define OS_TYPES_GENERIC_SWITCHER_H_

namespace OS {
namespace Types {
namespace Generic {

class Switcher {
public:
	Switcher();
	virtual ~Switcher();

	virtual void On()  = 0;
	virtual void Off() = 0;
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#endif /* OS_TYPES_GENERIC_SWITCHER_H_ */
