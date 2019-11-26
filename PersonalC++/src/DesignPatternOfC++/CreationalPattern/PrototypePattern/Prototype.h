/*
 * Prototype.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

namespace PrototypePattern {

class Prototype
{
public:
	virtual ~Prototype();
	virtual Prototype* Clone() const = 0;
protected:
	Prototype();
private:
};

class ConcretePrototype:public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const ConcretePrototype& cp);
	~ConcretePrototype();
	Prototype* Clone() const;
protected:
private:
};

} /* namespace PrototypePattern */
#endif /* PROTOTYPE_H_ */
