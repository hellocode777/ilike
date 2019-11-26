/*
 * Abstraction.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef ABSTRACTION_H_
#define ABSTRACTION_H_

namespace BridgePattern {

class AbstractionImp;
class Abstraction
{
public:
	virtual ~Abstraction();
	virtual void Operation() = 0;
protected:
	Abstraction();
private:
};

class RefinedAbstraction:public Abstraction {
public:
	RefinedAbstraction(AbstractionImp* imp);
	~RefinedAbstraction();
	void Operation();
protected:
private:
	AbstractionImp* _imp;
};

} /* namespace BridgePattern */
#endif /* ABSTRACTION_H_ */
