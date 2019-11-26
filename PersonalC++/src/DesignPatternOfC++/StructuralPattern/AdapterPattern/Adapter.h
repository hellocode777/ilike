/*
 * Adapter.h
 *
 *  Created on: 2018-11-27
 *      Author: root
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

namespace AdapterPattern_class_ {

class Target
{
public:
	Target();
	virtual ~Target();
	virtual void Request();
protected:
private:
};

class Adaptee
{
public:
	Adaptee();
	~Adaptee();
	void SpecificRequest();
protected:
private:
};

class Adapter:public Target,private Adaptee
{
public:
	Adapter();
	~Adapter();
	void Request();
protected:
private:
};

} /* namespace AdapterPattern */
#endif /* ADAPTER_H_ */
