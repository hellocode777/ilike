#include "Public.h"
#include <map>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;
map<int, string> g_mapDayStudy;
map<int, string> g_mapDayReview;


void int2str(const int &int_temp,string &string_temp)
{
        stringstream stream;
        stream<<int_temp;
        string_temp=stream.str();   //
}



void changeMap(map<int,string> &mymap, int key,string value)
{
    mymap[key] = value;
}

int MemoryMain()
{
	int i;
	int i5 = 11;
	int j = 37;
	string m_strStudy;
	string m_strReview;
	string m_one;
	//string m_two;
	for (i = 1; i <= 66; i++)
	{
		
		if (i5 - i == 0)
		{
			g_mapDayStudy.insert(pair<int,string>(i,"Summarize"));
			i5 = i5 + 11;

		}
		else
		{
			int2str(j, m_one);
			//int2str(++j, m_two);
			m_strStudy = m_one;
			g_mapDayStudy.insert(pair<int,string>(i,m_strStudy));
			j++;
		}
		
	}
	for (i = 1; i <= 100; i++)
	{
		g_mapDayReview.insert(pair<int,string>(i," "));

	}
	map<int,string>::iterator iter;
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
		if (iter->first <= 66)
		{cout << iter->first << "      " << g_mapDayStudy[iter->first] << "   ";}
		else
		{cout << iter->first << "               ";}
		cout << iter->second << endl;
	}
	return 0;
}
