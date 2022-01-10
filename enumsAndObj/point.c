#include "point.h"
#include <stdio.h>
#include <math.h>

float calculateDistancePoint(Point ptA,Point ptB)
{
    return sqrt(pow(ptB.x - ptA.x, 2) + pow(ptB.y - ptA.y, 2));
}
