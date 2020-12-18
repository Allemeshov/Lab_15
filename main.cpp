#include <iostream>
#include <string>
#include "passenger.h"
#include "input_helper.h"
#include "flycompany.h"

using namespace std;

int main()
{
    /*
        Для решения задачи согласно варианту предоставить пользователю возможность выбора варианта ввода ( с клавиатуры, случайные числа из диапазона от А до В, из файла) и вывода (на экран или в файл) элементов массива.  Предусмотреть работу с пользовательскими функциями. 
    */

    /*
        13.	Даны сведения о К пассажирах авиарейса: фамилия, место в самолете, количество вещей. Вывести на экран тех, кто имеют количество вещей превосходящее среднее число вещей.
   */

    welcome();

    int choice = -1;

    while (choice != 0)
    {
        choice = selectInputType();

        Flycompany *company = new Flycompany();
        AddingProtocol response;

        switch (choice)
        {
        case 1:
        {
            response = company->addPassengersConsole();
            break;
        }
        case 2:
        {
            response = company->addPassengersRandom();
            break;
        }
        case 3:
        {
            string path;
            cout << "\nPlease, input path to file: ";
            cin >> path;
            response = company->addPassengersFromFile(path);
            break;
        }
        default:
        {
            cout << "\nIt's sad to see you going. Anyway, have a nice day!\n";
            break;
        }
        }

        choice = selectOutputType();

        company->outputAverageLuggage();

        switch (choice)
        {
        case 1:
        {

            company->outputPassengersMoreAverageConsole();
            break;
        }
        case 2:
        {
            string path;
            cout << "Please, enter path to output file: ";
            cin >> path;
            company->outputPassengersMoreAverageFile(path);
            break;
        }
        default:
            break;
        }
    }
    system("pause");
    return 1;
}