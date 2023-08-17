#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

class Person
{
    public:
        string id;
        int x,y; 
        bool isSick;

        void printDetails();
        void setID(int i);
        void setLocation();
        void makeSick();
        void move(Person *array, int chance);
    
};



const int POPULATION = 100;

   int main(){
       ofstream file("filename.txt");
    bool running = true;
    int counter = 0;
    int infected = 0;
    char input;
    int days;
    int locationData[POPULATION][3];

    Person array[POPULATION];

   
   
        
        }
