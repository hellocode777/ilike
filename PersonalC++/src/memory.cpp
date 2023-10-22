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

int main()
{
	int i;
    // 只需更改如下三个变量的value
	int i5 = 11; // 第多少天开始Summarize
    int j = 47; // 从哪一课开始
    int end = 96; // 最后是哪一课
	string m_strStudy;
	string m_strReview;
	string m_one;
	//string m_two;
    int all = (end - j + 1) / i5 + 1 + end - j + 1;
    std::cout << "all=" << all << std::endl;
	for (i = 1; i <= all; i++)
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
    int review = all + 15;
	for (i = 1; i <= review; i++)
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
		if (iter->first <= all)
		{cout << iter->first << "      " << g_mapDayStudy[iter->first] << "   ";}
		else
		{cout << iter->first << "               ";}
		cout << iter->second << endl;
	}
	return 0;
}

/*
1       45           45,
2       46           45,46,
3       47           46,47,
4       48           45,47,48,
5       49           46,48,49,
6       50           47,49,50,
7       51           45,48,50,51,
8       52           46,49,51,52,
9       53           47,50,52,53,
10      54           48,51,53,54,
11      Summarize    49,52,54,
12      55           50,53,55,
13      56           51,54,55,56,
14      57           52,56,57,
15      58           45,53,55,57,58,
16      59           46,54,56,58,59,
17      60           47,57,59,60,
18      61           48,55,58,60,61,
19      62           49,56,59,61,62,
20      63           50,57,60,62,63,
21      64           51,58,61,63,64,
22      Summarize    52,59,62,64,
23      65           53,60,63,65,
24      66           54,61,64,65,66,
25      67           62,66,67,
26      68           55,63,65,67,68,
27      69           56,64,66,68,69,
28      70           57,67,69,70,
29      71           58,65,68,70,71,
30      72           59,66,69,71,72,
31      73           60,67,70,72,73,
32      74           61,68,71,73,74,
33      Summarize    62,69,72,74,
34      75           63,70,73,75,
35      76           64,71,74,75,76,
36      77           72,76,77,
37      78           65,73,75,77,78,
38      79           66,74,76,78,79,
39      80           67,77,79,80,
40      81           68,75,78,80,81,
41      82           69,76,79,81,82,
42      83           70,77,80,82,83,
43      84           71,78,81,83,84,
44      Summarize    72,79,82,84,
45      85           73,80,83,85,
46      86           74,81,84,85,86,
47      87           82,86,87,
48      88           75,83,85,87,88,
49      89           76,84,86,88,89,
50      90           77,87,89,90,
51      91           78,85,88,90,91,
52      92           79,86,89,91,92,
53      93           80,87,90,92,93,
54      94           81,88,91,93,94,
55      Summarize    82,89,92,94,
56      95           83,90,93,95,
57      96           84,91,94,95,96,
58                   92,96,
59                   85,93,95,
60                   86,94,96,
61                   87,
62                   88,95,
63                   89,96,
64                   90,
65                   91,
66                   92,
67                   93,
68                   94,
69                   
70                   95,
71                   96,

 */
