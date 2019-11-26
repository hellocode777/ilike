/*
 * AbstractionImp.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef ABSTRACTIONIMP_H_
#define ABSTRACTIONIMP_H_

namespace BridgePattern {

class AbstractionImp {
public:
	virtual ~AbstractionImp();
	virtual void Operation() = 0;
protected:
	AbstractionImp();
private:
};

class ConcreteAbstractionImpA:public AbstractionImp {
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();
	virtual void Operation();
protected:
	private:
};

class ConcreteAbstractionImpB:public AbstractionImp {
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();
	virtual void Operation();
protected:
	private:
};

} /* namespace BridgePattern */
#endif /* ABSTRACTIONIMP_H_ */
