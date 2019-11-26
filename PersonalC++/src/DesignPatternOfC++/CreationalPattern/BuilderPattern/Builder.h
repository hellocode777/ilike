/*
 * Builder.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef BUILDER_H_
#define BUILDER_H_
#include <string>
using namespace std;

namespace BuilderPattern {

class Product;

class Builder
{
public:
	virtual ~Builder();
	virtual void BuildPartA(const string& buildPara) = 0;
	virtual void BuildPartB(const string& buildPara) = 0;
	virtual void BuildPartC(const string& buildPara) = 0;
	virtual Product* GetProduct() = 0;
protected:
	Builder();
private:
};

class ConcreteBuilder:public Builder
{
public:
	ConcreteBuilder();
	~ConcreteBuilder();
	void BuildPartA(const string& buildPara);
	void BuildPartB(const string& buildPara);
	void BuildPartC(const string& buildPara);
	Product* GetProduct();
protected:
private:
};

} /* namespace BuilderPattern */
#endif /* BUILDER_H_ */
