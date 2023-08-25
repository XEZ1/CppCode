#ifndef COVIDCASE_H
#define COVIDCASE_H
#include <iostream>
#include <string>
#include <cmath>


using std::string;
using std::ostream;

class CovidCase
{
private:
    double personsLatitude;
    double personsLongitude;
    string name;
    int age;
    int sinceWhenTestedPositive;

public:
    CovidCase(double personsLatitudeIN, double personsLongitudeIN, const string& nameIN, int ageIN, int sinceWhenTestedPositiveIN)
            : personsLatitude(personsLatitudeIN), personsLongitude(personsLongitudeIN), name(nameIN), age(ageIN), sinceWhenTestedPositive(sinceWhenTestedPositiveIN) {
    }

    const double getPersonsLatitude() const {
        return personsLatitude;
    }

    const double getPersonsLongitude() const {
        return personsLongitude;
    }

    const string& getName() const {
        return name;
    }

    const int getAge() const {
        return age;
    }

    const int getSinceWhenTestedPositive() const {
        return sinceWhenTestedPositive;
    }

    double toRadians(const double & degrees) {
        return (degrees * 3.141592653589793) / 180;
    }

    double distanceTo(const CovidCase& another) {
        auto lon2 = toRadians(another.getPersonsLongitude());
        auto lon1 = toRadians(this->getPersonsLongitude());
        auto lat2 = toRadians(another.getPersonsLatitude());
        auto lat1 = toRadians(this->getPersonsLatitude());

        auto dlon = lon2 - lon1;
        auto dlat = lat2 - lat1;
        auto a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2);
        auto c = 2 * atan2( sqrt(a), sqrt(1-a) );
        auto distance = 6371 * c;

        return distance*0.62137119; //converting km to miles
    }

};

ostream & operator<<(ostream & o, const CovidCase& covidCaseToPrint) {
    o << "{" << covidCaseToPrint.getPersonsLatitude() << ", " << covidCaseToPrint.getPersonsLongitude()
    << ", \"" << covidCaseToPrint.getName() << "\", " <<  covidCaseToPrint.getAge() << ", "
    << covidCaseToPrint.getSinceWhenTestedPositive() << "}";
    return o;
}


#endif



