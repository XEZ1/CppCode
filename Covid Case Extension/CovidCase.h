#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using std::string;
using std::vector;
using std::ostream;


class CovidCase
{
private:
    double latitude;
    double longitude;
    string name;
    int age;
    int timeStamp;

public:
    CovidCase(double latitudeIN, double longitudeIN, const string& nameIN, int ageIN, int timeStampIN)
            : latitude(latitudeIN), longitude(longitudeIN), name(nameIN), age(ageIN), timeStamp(timeStampIN) {
    }
    CovidCase(const string& everything) {
        string newString;
        vector<string> vec;

        for (char character : everything) {
            if (character == ',') {
                vec.push_back(newString);
                newString = "";
            }
            else if (character == '{') {
                //starts
            }
            else if (character == '}') {
                //finishes
            }
            else {
                newString += character;
            }
        }
        vec.push_back(newString);


        for (char character : vec[2]) {
            if (character == '"' || character == '\\' || character == ' ') {
                //skip
            }
            else {
                name += character;
            }
        }

        latitude = stod(vec[0]);
        longitude = stod(vec[1]);
        //name = vec[2];
        age = stoi(vec[3]);
        timeStamp = stoi(vec[4]);
    }

    const double getLatitude() const {
        return latitude;
    }

    const double getLongitude() const {
        return longitude;
    }

    const string& getName() const {
        return name;
    }

    const int getAge() const {
        return age;
    }

    const int & getTime() const {
        return timeStamp;
    }

    double toRadians(const double & degrees) {
        return (degrees * 3.141592653589793) / 180;
    }

    double distanceTo(CovidCase & another) {
        auto lon2 = toRadians(another.getLongitude());
        auto lon1 = toRadians(this->getLongitude());
        auto lat2 = toRadians(another.getLatitude());
        auto lat1 = toRadians(this->getLatitude());

        auto dlon = lon2 - lon1;
        auto dlat = lat2 - lat1;
        auto a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2);
        auto c = 2 * atan2( sqrt(a), sqrt(1-a) );
        auto distance = 6371 * c;

        return distance*0.62137119; //converting km to miles
    }

    bool operator==(const CovidCase& other) {
        return this->getLatitude() == other.getLatitude() &&
               this->getLongitude() == other.getLongitude() &&
               this->getName() == other.getName() &&
               this -> getAge() == other.getAge() &&
               this->getTime() == other.getTime() ;
    }

};


ostream & operator<<(ostream & o, const CovidCase& covidCaseToPrint) {
    o << "{" << covidCaseToPrint.getLatitude() << ", " << covidCaseToPrint.getLongitude()
      << ", \"" << covidCaseToPrint.getName() << "\", " <<  covidCaseToPrint.getAge() << ", "
      << covidCaseToPrint.getTime () << "}";
    return o;
}


#endif



