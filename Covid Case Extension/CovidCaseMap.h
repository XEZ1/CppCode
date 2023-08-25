#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"


class TimeAndCaseData {
private:
    int time {0};
    int numberOfCases {0};
    int static staticNumberOfCases;
public:
    TimeAndCaseData(int timeIN)
            : time(timeIN) {
        numberOfCases = staticNumberOfCases;
        ++numberOfCases;
        staticNumberOfCases = numberOfCases;
    }

    int & getTime() {
        return time;
    }

    int & getNumberOfCases() {
        return numberOfCases;
    }

    int & getStaticNumberOfCases() {
        return staticNumberOfCases;
    }
};


class CovidCaseMap {
private:
    vector<CovidCase> vectorOfCovidCases;
    vector<TimeAndCaseData> vectorOfActiveCovidCases;
public:
    void addCase(const CovidCase& covidCase){
        vectorOfCovidCases.push_back(covidCase);
    }

    vector<TimeAndCaseData> & getCasesOverTime(int timeLimit) {
        int i = 0;
        int j = 0;
        int temp;
        TimeAndCaseData data {0};
        --data.getNumberOfCases();
        --data.getStaticNumberOfCases();
        vectorOfActiveCovidCases.push_back(data);
        while (i != vectorOfCovidCases.size() || j != vectorOfCovidCases.size()) {
            if (j != vectorOfCovidCases.size()) {
                temp = vectorOfCovidCases[j].getTime();
                if (temp < vectorOfCovidCases[i].getTime() + timeLimit) {
                    TimeAndCaseData data {temp};
                    vectorOfActiveCovidCases.push_back(data);
                    ++j;
                } else if (temp > vectorOfCovidCases[i].getTime() + timeLimit) {
                    TimeAndCaseData data {vectorOfCovidCases[i].getTime() + timeLimit};
                    data.getNumberOfCases() -= 2;
                    data.getStaticNumberOfCases() -= 2;
                    vectorOfActiveCovidCases.push_back(data);
                    ++i;
                }
            } else {
                TimeAndCaseData data {vectorOfCovidCases[i].getTime() + timeLimit};
                data.getNumberOfCases() -= 2;
                data.getStaticNumberOfCases() -= 2;
                vectorOfActiveCovidCases.push_back(data);
                ++i;
            }
        }
        return vectorOfActiveCovidCases;
    }

    vector<CovidCase> deleteWhatsNotIll(int time, vector<CovidCase>& vectorOfCovidCases) {
        vector<CovidCase> vectorOfCovidCasesNew;
        for (int i = 0; i < vectorOfCovidCases.size(); ++i) {
            if (vectorOfCovidCases[i].getTime() <= time) {
                vectorOfCovidCasesNew.push_back(vectorOfCovidCases[i]);
            }
        }
        return vectorOfCovidCasesNew;
    }

    double supportVisitGreedyTSP(double latitude, double longitude, int time, int length) {
        vector<TimeAndCaseData> active = getCasesOverTime(length - time);

        int j = 0;
        double traveledDistance = 0;
        vector<double> wayBack;

        CovidCase firstElement {latitude, longitude, "start_position", 0, 0};
        vectorOfCovidCases.insert(vectorOfCovidCases.begin(), firstElement);
        vectorOfCovidCases = deleteWhatsNotIll(time, vectorOfCovidCases);

        while (vectorOfCovidCases.size() != 1) {
            vector<double> distance;
            for (int i = 1; i < vectorOfCovidCases.size(); ++i) {
                for (int m = 1; m < active.size(); ++m) {
                    if (active[m].getTime() == vectorOfCovidCases[i].getTime() && vectorOfCovidCases[i].getTime() <= time) {
                        distance.push_back(vectorOfCovidCases[0].distanceTo(vectorOfCovidCases[i]));
                    }
                }
            }
            if (j == 0) {
                wayBack = getThefurthestPatient(distance);
                ++j;
            }
            vector<double> closest = getTheClosestPatient(distance);
            traveledDistance += distance[int(closest[1])];
            vectorOfCovidCases[0] = vectorOfCovidCases[int(closest[1])];
            vectorOfCovidCases.erase(vectorOfCovidCases.begin() + closest[1]);
        }
        CovidCase lastElement = vectorOfCovidCases[0];

        traveledDistance += wayBack[0];  //way to the first point

        return traveledDistance;
    }

    vector<double> getTheClosestPatient(const vector<double>& vec) {
        double minElement = vec[0];
        double idx = 0;
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] < minElement) {
                minElement = vec[i];
                idx = i;
            }
        }
        vector<double> answer {minElement, idx};
        return answer;
    }

    vector<double> getThefurthestPatient(const vector<double>& vec) {
        double maxElement = vec[0];
        double idx = 0;
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] > maxElement) {
                maxElement = vec[i];
                idx = i;
            }
        }
        vector<double> answer {maxElement, idx};
        return answer;
    }

};

int TimeAndCaseData::staticNumberOfCases = 0;


#endif



