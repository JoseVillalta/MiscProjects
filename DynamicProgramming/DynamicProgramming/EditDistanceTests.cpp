#include "stdafx.h"
#include "EditDistanceTest.h"
#include "EditDistance.h"
#include <iostream>

using namespace std;

void RunEditDistanceTests()
{
	cout << " Running Edit Distance Test" << endl;
	//char s[5] = { 'h','e','l','l','o' };
	//char t[4] = { 'h','e','l','o' };

	char s[4] = { ' ','a','b','c' };
	char t[4] = { ' ','a','b','f' };

	int i = 3;
	int j = 3;

	auto editDistance = string_compare_r(s, t, i, j);
	cout << " Edit distance is: " << editDistance << endl;
	


	char s1[15] = { ' ','T','h','o','u',' ', 's','h','a','l','l',' ','n','o','t' };
	char t1[14] = { ' ','y','o','u',' ', 's','h','a','l','l',' ','n','o','t' };

	auto d = string_compare(s,t,4,4);
	cout << " Edit distance s to t is " << d << endl;
	reconstruct_path(s, t, 3, 3);
	cout << endl;
	d = string_compare(t, s, 4, 4);
	cout << " Edit distance t to s should be the same " << d << endl;
	reconstruct_path(t, s, 3, 3);

	auto d1 = string_compare(s1, t1, 15, 14);

	cout << " Edit distance is " << d1 << endl;
	reconstruct_path(s1, t1, 14, 13);

	cout << endl;

	char s2[6] = { ' ','S','T','E','V','E' };
	char t2[6] = { ' ','S','E','T','V','E' };

	auto d2 = string_compare(t2, s2, 5, 5);
	cout << "Edit distance is " << d2 << endl;
	reconstruct_path(s2, t2, 5, 5);
	cout << endl;



}
