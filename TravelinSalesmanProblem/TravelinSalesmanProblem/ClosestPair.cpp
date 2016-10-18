#include "stdafx.h"
#include "ClosestPair.h"

using namespace std;

/*
ClosestPair(P)
Let n be the number of points in set P.
For i = 1 to n − 1 do
d = ∞
For each pair of endpoints (s, t) from distinct vertex chains
if dist(s, t) ≤ d then sm = s, tm = t, and d = dist(s, t)
Connect (sm, tm) by an edge
Connect the two endpoints by an edge
*/

ClosestPair::ClosestPair()
{
    m_nn = new NearestNeighbor();
    m_dTraveledDistance = 0;
}
LinkedTraveledPoint * ClosestPair::traverse(Coordinate start, vector<Coordinate> v)
{
    //First make a local copy of the coordinates
    vector<Coordinate> coords;
    for (auto i : v)
    {
        coords.push_back(i);
    }
    LinkedTraveledPoint * p1 = nullptr;
    LinkedTraveledPoint * p2 = nullptr;

    p1 = new LinkedTraveledPoint(new TraveledPoint(start, 0), nullptr);
    p2 = p1;

    while (!coords.empty())
    {
        auto result = getClosestPair(p1, p2, coords);
        int index = get<2>(result);
        coords.erase(coords.begin() + index);
        p1 = get<0>(result);
        p2 = get<1>(result);
    }

    return p1;

}

tuple<LinkedTraveledPoint *,LinkedTraveledPoint *, int> ClosestPair::getClosestPair(LinkedTraveledPoint * p1, LinkedTraveledPoint * p2, vector<Coordinate> v)
{
    auto n1 = m_nn->getNearestNeighbor(p1->point->loc, v);
    auto n2 = m_nn->getNearestNeighbor(p2->point->loc, v);

    auto d1 = get<1>(n1);
    auto d2 = get<1>(n2);
    double distance = 0;
    int index = 0;

    if (d1 < d2)
    {
        Coordinate c1 = get<0>(n1);
        auto tp = new LinkedTraveledPoint(new TraveledPoint(c1,d1),p1);
        p1 = tp;
        distance = d1;
        index = get<2>(n1);
    }
    else //ties goes to p2
    {
        Coordinate c2 = get<0>(n2);
        auto tp = new LinkedTraveledPoint(new TraveledPoint(c2, d2), nullptr);
        p2->next = tp;
        p2 = tp;
        distance = d2;
        index = get<2>(n2);
    }

    m_dTraveledDistance += distance;

    return make_tuple(p1, p2, index);

}