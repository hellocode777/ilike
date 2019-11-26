/*
 * Subject.h
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Observer.h"
#include "/home/shuai/workspace/C-Knowledge/HeadFirst/include/Public.h"

class Subject {
public:
	Subject();
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObserver() = 0;
	virtual ~Subject();
};

#endif /* SUBJECT_H_ */
