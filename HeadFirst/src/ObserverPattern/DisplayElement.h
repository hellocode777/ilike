/*
 * DisplayElement.h
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#ifndef DISPLAYELEMENT_H_
#define DISPLAYELEMENT_H_

class DisplayElement {
public:
	DisplayElement();
	virtual void display() = 0;
	virtual ~DisplayElement();
};

#endif /* DISPLAYELEMENT_H_ */
