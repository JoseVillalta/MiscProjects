#include "stdafx.h"
#include "AustralianVoting.h"


tuple<int, vector<string>> CountVotes(vector<string> candidates, vector<vector<int>> votes)
{
    vector<string> v;
    v.push_back("John Doe");
    return make_tuple(1, v);
}
