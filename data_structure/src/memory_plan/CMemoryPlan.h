/*
 * CMemoryPlan.h
 *
 *  Created on: 2020年5月31日
 *      Author: shuai
 */

#ifndef DATA_STRUCTURE_SRC_MEMORY_PLAN_CMEMORYPLAN_H_
#define DATA_STRUCTURE_SRC_MEMORY_PLAN_CMEMORYPLAN_H_

#include "../include/public.h"
#include <map>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>

class CMemoryPlan {
public:

	CMemoryPlan(int start, int end, int interval);
	void MakePlan();
	virtual ~CMemoryPlan();


private:

	int all_study_day;
	int all_day;
	int inerval_day;
	int start_lesson;
	std::map<int, std::string> g_mapDayStudy;
	std::map<int, std::string> g_mapDayReview;


};

#endif /* DATA_STRUCTURE_SRC_MEMORY_PLAN_CMEMORYPLAN_H_ */
