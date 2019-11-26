/*
 * Singleton.h
 *
 *  Created on: 2018-11-25
 *      Author: root
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
using namespace std;
class Singleton
{
public:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;
};

#endif /* SINGLETON_H_ */
