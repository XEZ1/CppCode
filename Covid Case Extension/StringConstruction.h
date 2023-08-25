#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


int action(const string& target, size_t& start, int cloneCost, int appendCost, string& tempResult, size_t count)
{
    if (appendCost * count < cloneCost)
    {
        for (size_t i = 0; i < count; ++i)
        {
            tempResult.push_back(target[start + i]);
            //cout << "append: " << tempResult << endl;
        }
        start += count;
        return appendCost * count;
    }
    //else
    tempResult.append(target.substr(start, count));
    start += count;

    //cout << "clone:  " << tempResult << endl;
    return cloneCost;
    //}
}

int stringConstruction(const string& target, int cloneCost, int appendCost)
{
    int cheapestCost = 0;

    string tempResult;

    size_t start = 0;
    const size_t end = target.size();

    while (start != end)
    {
        size_t count = 0;
        while (start + count != end && tempResult.find(target.substr(start, count + 1)) != string::npos)
            count += 1;

        if (count != 0)
        {
            size_t max_count = count;
            size_t max_start = start;

            for (size_t i = 1; i < count && i < 26; ++i) { // 26 - alphabet
                size_t inner_count = 0;

                string sub;
                while (start + i + inner_count != end && tempResult.find(sub = target.substr(start + i, inner_count + 1)) != string::npos)
                    inner_count += 1;

                if (inner_count > max_count)
                {
                    max_count = inner_count;
                    max_start = start + i;
                }
            }

            if (count != max_count) {
                cheapestCost += action(target, start, cloneCost, appendCost, tempResult, max_start - start);
                count = max_count;
            }
        }

        if (count == 0)
        {
            tempResult.push_back(target[start]);
            //cout << "append: " << tempResult << endl;
            cheapestCost += appendCost;
            start += 1;
        }
        else
            cheapestCost += action(target, start, cloneCost, appendCost, tempResult, count);
    }

    return cheapestCost;
}


#endif

