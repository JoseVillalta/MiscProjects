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
}
void ClosestPair::traverse()
{

}

tuple<LinkedTraveledPoint *, int> ClosestPair::getClosestPair(LinkedTraveledPoint * p1, LinkedTraveledPoint * p2, vector<Coordinate> v)
{
    auto n1 = m_nn->getNearestNeighbor(p1->point->loc, v);
    auto n2 = m_nn->getNearestNeighbor(p2->point->loc, v);

    auto d1 = get<1>(n1);
    auto d2 = get<1>(n2);
    double distance = 0;
    int index = 0;
    LinkedTraveledPoint * point = nullptr;

    if (d1 < d2)
    {
        Coordinate c1 = get<0>(n1);
        auto tp = new LinkedTraveledPoint(new TraveledPoint(c1,d1),p1);
        point = tp;
        distance = d1;
        index = get<2>(n1);
    }
    else //ties goes to p2
    {
        Coordinate c2 = get<0>(n2);
        auto tp = new LinkedTraveledPoint(new TraveledPoint(c2, d2), nullptr);
        p2->next = tp;
        point = tp;
        distance = d2;
        index = get<2>(n2);
    }

    return make_tuple(point, index);

}