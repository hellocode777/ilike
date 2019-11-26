/*
 * Director.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_

namespace BuilderPattern {

class Builder;
class Director
{
public:
	Director(Builder* bld);
	~Director();
	void Construct();
protected:
private:
	Builder* _bld;
};

} /* namespace BuilderPattern */
#endif /* DIRECTOR_H_ */
