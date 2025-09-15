#include "TwoDArray.h"
#include <algorithm>
#include <iterator>

std::vector<int> TwoDArray::getIntersection(const TwoDArray& arr1, const TwoDArray& arr2) {
    std::set<int> set1 = arr1.getUniqueElements();
    std::set<int> set2 = arr2.getUniqueElements();
    std::vector<int> intersection;

    std::set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::back_inserter(intersection));

    return intersection;
}