#include "flycompany.h"

using namespace std;

Flycompany::Flycompany()
{
    this->maxPlaces = 20;
    this->passengersNumber = 0;
    this->passengersNumberMoreAverage = 0;
    this->averageLuggage = 0;
    this->passengers = new Passenger[20];
}

void Flycompany::initSurnames(string feSurnames[], string maSurnames[])
{
    feSurnames[0] = "Petrova";
    feSurnames[1] = "Ivanova";
    feSurnames[2] = "Robinovich";
    feSurnames[3] = "Putina";
    feSurnames[4] = "Tereshkova";
    feSurnames[5] = "Onegina";
    feSurnames[6] = "Ilushina";
    feSurnames[7] = "Golomazdina";
    maSurnames[0] = "Petrov";
    maSurnames[1] = "Ivanov";
    maSurnames[2] = "Robinovich";
    maSurnames[3] = "Putin";
    maSurnames[4] = "Trump";
    maSurnames[5] = "Obama";
    maSurnames[6] = "Lemeshov";
    maSurnames[7] = "Sidorov";
}

void Flycompany::increasePassengers()
{
    this->passengersNumber++;
}

void Flycompany::decreasePassengers()
{
    this->passengersNumber--;
}

int Flycompany::getPassengersNumber()
{
    return this->passengersNumber;
}

int Flycompany::getPassengersNumberMoreAverage()
{
    return this->passengersNumberMoreAverage;
}

void Flycompany::setPassengersNumber(int number)
{
    this->passengersNumber = number;
}

Passenger *Flycompany::getPassengers()
{
    return this->passengers;
}

void Flycompany::outputPassengersMoreAverageConsole()
{
    cout << "Passengers who have more than average luggage:\n";

    for (int i = 0; i < this->passengersNumber; i++)
    {

        if (this->passengers[i].luggage > this->averageLuggage)
        {
            cout << this->passengers[i].surname << "     "
                 << this->passengers[i].place << "     "
                 << this->passengers[i].luggage << endl;
        }
    }
}
void Flycompany::outputPassengersMoreAverageFile(string path)
{
    ofstream file;
    file.open(path);
    if (file.good())
    {
        for (int i = 0; i < this->passengersNumber; i++)
        {
            if (this->passengers[i].luggage > this->averageLuggage)
            {
                file << passengers[i].surname
                     << passengers[i].place
                     << passengers[i].luggage << endl;
            }
        }
    }
    else
        cout << "\nCannot read file!\n";
}

int Flycompany::findFreePlace()
{
    bool placesStatus[100] = {0};
    for (int i = 0; i < this->passengersNumber; i++)
    {
        placesStatus[this->passengers[i].place - 1] = false;
    }

    int freePlace;
    for (int i = 0; i < 100; i++)
    {
        if (placesStatus[i])
            freePlace = i + 1;
    }
    return freePlace;
}

void Flycompany::calcAverageLuggage()
{
    double sum = 0;

    for (int i = 0; i < this->passengersNumber; i++)
    {
        sum += this->passengers[i].luggage;
    }
    this->averageLuggage = sum / (this->passengersNumber + 0.0);
}

void Flycompany::outputAverageLuggage()
{
    this->calcAverageLuggage();

    cout << "\nYour average luggage is: " << this->averageLuggage << endl;
}

string Flycompany::getFemaleSurname(int id)
{
    switch (id)
    {
    case 0:
        return "Petrova";
    case 1:
        return "Ivanova";
    case 2:
        return "Lemeshova";
    case 3:
        return "Putina";
    case 4:
        return "Tereshkova";
    case 5:
        return "Onegina";
    case 6:
        return "Ilushina";
    case 7:
        return "Golomazdina";

    default:
        return "";
    }
}
string Flycompany::getMaleSurname(int id)
{
    switch (id)
    {
    case 0:
        return "Petrov";
    case 1:
        return "Ivanov";
    case 2:
        return "Lemeshov";
    case 3:
        return "Putin";
    case 4:
        return "Robinovich";
    case 5:
        return "Trump";
    case 6:
        return "Obama";
    case 7:
        return "Sidorov";

    default:
        return "";
    }
}

string Flycompany::getRandSurname()
{
    int sex = rand() % 2;
    int id = rand() % 8;

    if (sex)
        return this->getFemaleSurname(id);
    else
        return this->getMaleSurname(id);

    //Результат функции может быть "/100/103/111/ov"
    //ov - это последняя часть фамилии, а первые символы неправильно передаются
}

bool Flycompany::isFreePlace(int place)
{
    bool result = true;
    for (int i = 0; i < this->passengersNumber; i++)
    {
        if (this->passengers[i].place == place)
        {
            result = false;
            break;
        }
    }
    return result;
}

AddingProtocol Flycompany::addPassengersConsole()
{
    AddingProtocol addP;
    addP.status = true;
    bool success = true;

    this->passengersNumber = inputNumberOfPassengers();

    std::cout << "\nPlease enter passengers:\nEnter [-1] to cancel\n";

    for (int i = 0; i < this->passengersNumber; i++)
    {
        string surname;
        cout << "Enter surname: ";
        cin >> surname;
        if (surname == "-1")
        {
            success = false;
            addP.status = false;
            addP.message = "Users finished inputing";
        }

        int place = 0;
        while ((place < 1 || 100 < place) && success)
        {
            cout << "Enter " << this->passengers[i].surname << "'s place (1 < place < 100): ";
            cin >> place;
            if (place == -1)
            {
                addP.status = false;
                addP.message = "Users finished inputing";

                break;
            }
            if (!(this->isFreePlace(place)))
            {
                cout << "This place is reserved. Please choose another one. For example, place " << this->findFreePlace() << " is free.";
                place = 0;
            }
        }

        int luggage = -1;
        while (luggage < 0 && success)
        {
            cout << "Enter " << this->passengers[i].surname << "'s luggage: ";
            cin >> luggage;
            if (luggage == -1)
            {
                addP.status = false;
                addP.message = "Users finished inputing";
                break;
            }
        }

        if (success)
        {
            this->passengers[i].surname = surname;
            this->passengers[i].surname = place;
            this->passengers[i].surname = luggage;
            cout << "Passenger " << surname
                 << " on place " << place
                 << " with " << luggage
                 << "luggage is successfully added!\n";
        }
        else
            break;
    }

    return addP;
}

AddingProtocol Flycompany::addPassengersRandom()
{
    srand(time(NULL));
    this->setPassengersNumber(rand() % this->maxPlaces);

    for (int i = 0; i < this->passengersNumber; i++)
    {
        this->passengers[i].surname = this->getRandSurname();
        this->passengers[i].place = (rand() % (this->maxPlaces + 2)) + 1;
        this->passengers[i].luggage = rand() % 26;
    }
    AddingProtocol addP;
    addP.status = true;
    addP.message = "Passengers successfully generated";
    return addP;
}

AddingProtocol Flycompany::addPassengersFromFile(string path)
{
    AddingProtocol addP;

    Passenger passengersTemp[100];

    addP.status = true;
    bool success = true;

    ifstream file;
    file.open(path);

    if (file.good())
    {
        int passengersNumber;
        file >> passengersNumber;
        this->setPassengersNumber(passengersNumber);

        for (int i = 0; i < passengersNumber; i++)
        {
            string surname;
            file >> surname;

            int place = 0;
            file >> place;
            if (place < 1 || 100 < place)
            {
                success = false;
                addP.status = false;
                addP.message = "Invalid data in file. Place must be more than 0 and less than 101";
                break;
            }
            if (!(this->isFreePlace(place)))
            {
                success = false;
                addP.status = false;
                addP.message = "Duplicated places.  Place " + to_string(place) + " is already reserved.";
                break;
            }

            int luggage = -1;
            file >> luggage;
            if (luggage < 0)
            {
                success = false;
                addP.status = false;
                addP.message = "Invalid data in file. Luggage cannot have negative value";
                break;
            }

            if (success)
            {
                passengersTemp[i].surname = surname;
                passengersTemp[i].surname = place;
                passengersTemp[i].surname = luggage;
                cout << "Passenger " << surname
                     << " on place " << place
                     << " with " << luggage
                     << "luggage is successfully added!\n";
            }
            else
            {
                addP.status = false;
                addP.message = "Cannot process passenger number" + to_string(i + 1);
                break;
            }
        }

        if (success)
        {
            for (int i = 0; i < passengersNumber; i++)
            {
                this->passengers[i].surname = passengersTemp[i].surname;
                this->passengers[i].place = passengersTemp[i].place;
                this->passengers[i].luggage = passengersTemp[i].luggage;
            }
            addP.status = success;
            addP.message = "Success! All passengers are added.";
        }
    }
    else
    {
        addP.status = false;
        addP.message = "File exception. Cannot open file";
    }

    return addP;
}
