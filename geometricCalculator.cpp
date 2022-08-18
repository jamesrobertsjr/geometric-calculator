//
// geometricCalculator.cpp
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

const std::string USER_INPUT_ERROR = "ERROR: Invalid entry. Please try again.";

double areaOfTriangle(double, double);
double areaOfQuadrilateral(double, double);
double areaOfRegularPentagon(double);
int validateSideCount(int);
char validateYesNo(char);

struct shapeValues {
    double length1,
            length2,
            length3,
            length4,
            length5,
            length6,
            length7,
            length8,
            length9,
            length10;
};

int main() {
    shapeValues SVal;
    // std::vector<int> sideLengthVec;
    int sideCount = 0;
    char yesNo = '\0';

    do {
        std::cout << "How many sides does the shape have? Enter an integer from 3-10: ";
        std::cin >> sideCount;
        if (validateSideCount(sideCount)) {
            if (sideCount == 3) {
                std::cout << "Enter base and height of triangle: ";
                std::cin >> SVal.length1 >> SVal.length2;
                std::cout << "Area of Triangle: " << 
                        areaOfTriangle(SVal.length1, SVal.length2) << std::endl;
            } else if (sideCount == 4) {
                std::cout << "Enter base and height of quadrilateral: ";
                std::cin >> SVal.length1 >> SVal.length2;
                std::cout << "Area of Quadrilateral: " << 
                        areaOfQuadrilateral(SVal.length1, SVal.length2) << std::endl;
            } else if (sideCount == 5) {
                std::cout << "Enter a side length of a regular pentagon: ";
                std::cin >> SVal.length1;
                std::cout << "Area of Regular Pentagon: " <<
                        areaOfRegularPentagon(SVal.length1) << std::endl;
            }
        }
        std::cout << "Would you like to perform another calculation? ";
        std::cin >> yesNo;
    } while (validateYesNo(yesNo) == 'Y');
    return 0;
}

double areaOfTriangle(double base, double height) {
    double area = (base * height) / 2;
    return area;
}

double areaOfQuadrilateral(double base, double height) {
    double area = base * height;
    return area;
}

double areaOfRegularPentagon(double sideLength) {
    double area = (1 / 4) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(sideLength, 2);
    return area;
}

int validateSideCount(int sideCount) {
    while (sideCount < 3 && sideCount > 10) {
        std::cout << USER_INPUT_ERROR << std::endl;
        std::cin >> sideCount;
    }
    return sideCount;
}

char validateYesNo(char yesNo) {
    while ((toupper(yesNo) != 'Y') && (toupper(yesNo) != 'N')) {
        std::cout << USER_INPUT_ERROR << std::endl;
        std::cin >> yesNo;
    }
    return toupper(yesNo);
}