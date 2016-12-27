// AustralianVoting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <limits>

using namespace std;

void printInput(vector<string> candidates, vector<vector<int>> ballots)
{
    for (string candidate : candidates)
    {
        cout << candidate << endl;
    }

    for (vector<int> vote : ballots)
    {
        for (int v : vote)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}


tuple<int,string> FirstCount(vector<string> candidates, vector<vector<int>> ballot)
{
    vector<int> count(candidates.size()+1, 0);
    int numCandidates = candidates.size();

    for (auto b : ballot)
    {
        count.at(b.at(0))++;
    }

    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i<count.size(); i++)
    {
        if (count.at(i) > max)
        {
            max = count.at(i);
            maxIndex = i;
        }
    }

    int numVotes = ballot.size();
    if (max > numVotes / 2)
    {
        return make_tuple(1, candidates.at(maxIndex-1));
    }
    else
    {
        return make_tuple(0, "None");
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    //Get Number of Test Cases
    int cases;
    cin >> cases;

    
    while (cases > 0)
    {
        //Get Number of Candidates
        int numCandidates;
        cin >> numCandidates;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<string> candidates;
        int counter = numCandidates;

        while (counter > 0)
        {
            string candidate;
            getline(cin, candidate);
            candidates.push_back(candidate);
            counter--;
        }


        //Get All the Votes
        int numVotes = 0;
        string singleVote;
        vector<vector<int>> ballot;

        bool done = false;
        while (!done)
        {
            getline(cin, singleVote);
            if (singleVote == "")
            {
                done = true;
                break;
            }

            stringstream stream(singleVote);
            vector<int> vote;
            int n;
            while (stream >> n )
            {
                vote.push_back(n);
            }
            ballot.push_back(vote);
            numVotes++;
        }

        auto result = FirstCount(candidates, ballot);
        string winner = get<1>(result);
        cout << "The winner is " << winner << endl;

        cases--;

    }
    
    

    return 0;
}

