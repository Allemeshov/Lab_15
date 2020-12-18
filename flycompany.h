#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "input_helper.h"
#include "passenger.h"

using namespace std;

struct AddingProtocol
{
    bool status;
    string message;
};
class Flycompany
{
private:
    int maxPlaces;
    int passengersNumber;
    int passengersNumberMoreAverage;
    double averageLuggage;
    Passenger *passengers;

    void increasePassengers();
    void decreasePassengers();
    void calcAverageLuggage();
    std::string getFemaleSurname(int id);
    std::string getMaleSurname(int id);
    std::string getRandSurname();

    int findFreePlace();
    bool isFreePlace(int place);

public:
    Flycompany();
    void initSurnames(std::string feSurnames[], std::string maSurnames[]);
    int getPassengersNumber();
    void setPassengersNumber(int number);
    int getPassengersNumberMoreAverage();
    Passenger *getPassengers();
    void outputPassengersMoreAverageConsole();
    void outputPassengersMoreAverageFile(std::string path);
    AddingProtocol addPassengersConsole();
    AddingProtocol addPassengersRandom();
    AddingProtocol addPassengersFromFile(string path);
    void outputAverageLuggage();
};