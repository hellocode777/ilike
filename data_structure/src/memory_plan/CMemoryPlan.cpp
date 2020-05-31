/*
 * CMemoryPlan.cpp
 *
 *  Created on: 2020年5月31日
 *      Author: shuai
 */

#include "CMemoryPlan.h"

void int2str(const int &int_temp, std::string &string_temp)
{
        std::stringstream stream;
        stream<<int_temp;
        string_temp=stream.str();  //
}

void changeMap(std::map<int,std::string> &mymap, int key, std::string value)
{
    mymap[key] = value;
}


CMemoryPlan::CMemoryPlan(int start, int end, int interval) {
	// TODO Auto-generated constructor stub
	int summarize_day = (end - start) / interval;
	all_study_day = end - start + summarize_day + 1;

	all_day = all_study_day + 20;

	inerval_day = interval;

	start_lesson = start;

}

CMemoryPlan::~CMemoryPlan() {
	// TODO Auto-generated destructor stub
}

void CMemoryPlan::MakePlan()
{

	int i;
	int i5 = inerval_day + 1;
	int j = start_lesson;
	std::string m_strStudy;
	std::string m_strReview;
	std::string m_one;

	for (i = 1; i <= all_study_day; i++)
	{

		if (i5 - i == 0)
		{
			g_mapDayStudy.insert(std::pair<int, std::string>(i,"Summarize"));
			i5 = i5 + inerval_day + 1;

		}
		else
		{
			int2str(j, m_one);
			//int2str(++j, m_two);
			m_strStudy = m_one;
			g_mapDayStudy.insert(std::pair<int, std::string>(i,m_strStudy));
			j++;
		}

	}
	for (i = 1; i <= all_day; i++)
	{
		g_mapDayReview.insert(std::pair<int, std::string>(i," "));

	}
	std::map<int, std::string>::iterator iter;
	for(iter = g_mapDayStudy.begin(); iter != g_mapDayStudy.end(); iter++)
	{
		if (iter->second != "Summarize")
		{m_strReview = g_mapDayReview[iter->first + 1 - 1] + iter->second + ",";
		changeMap(g_mapDayReview, iter->first + 1 - 1, m_strReview);}

		if (iter->second != "Summarize")
		{m_strReview = g_mapDayReview[iter->first + 2 - 1] + iter->second + ",";
		changeMap(g_mapDayReview, iter->first + 2 - 1, m_strReview);}

		if (iter->second != "Summarize")
		{m_strReview = g_mapDayReview[iter->first + 4 - 1] + iter->second + ",";
		changeMap(g_mapDayReview, iter->first + 4 - 1, m_strReview);}

		if (iter->second != "Summarize")
		{m_strReview = g_mapDayReview[iter->first + 7 - 1] + iter->second + ",";
		changeMap(g_mapDayReview, iter->first + 7 - 1, m_strReview);}

		if (iter->second != "Summarize")
		{m_strReview = g_mapDayReview[iter->first + 15 - 1] + iter->second + ",";
		changeMap(g_mapDayReview, iter->first + 15 - 1, m_strReview);}
	}
	for(iter = g_mapDayReview.begin(); iter != g_mapDayReview.end(); iter++)
	{
		if (iter->first <= all_study_day)
		{std::cout << iter->first << "      " << g_mapDayStudy[iter->first] << "   ";}
		else
		{std::cout << iter->first << "               ";}
		std::cout << iter->second << std::endl;
	}
	return;
}
