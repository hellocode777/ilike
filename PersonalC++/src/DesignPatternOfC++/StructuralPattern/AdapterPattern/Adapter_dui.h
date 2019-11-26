/*
 * Adapter_dui.h
 *
 *  Created on: 2018-11-27
 *      Author: root
 */

#ifndef ADAPTER_DUI_H_
#define ADAPTER_DUI_H_

namespace AdapterPattern_dui_ {

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

class Adapter:public Target
{
public:
	Adapter(Adaptee* ade);
	~Adapter();
	void Request();
protected:
private:
	Adaptee* _ade;
};

} /* namespace AdapterPattern_dui_ */
#endif /* ADAPTER_DUI_H_ */
