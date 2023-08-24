#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

#include "Person.h"

using namespace std;

const int MAX_POPULATION = 100;
const int DAYS = 5;
const int PERCENT_SICK = 10;
const int MAX_GRID_LOCATION = 200;

bool makeSick();
int randomLocationValue();



int main(){
    srand(time(0));

    int sickCounter = 0;
    int total_days = 0;
    int random_x_coordinates = 0;
    int random_y_coordinates = 0;

    int temp_x;
    int temp_y;
    

    char input;

    bool isSick = false;
    bool temp_sick = false;
    

    vector<Person> population;

    vector<int> xCoordinates;
    vector<int> yCoordinates;
    vector<int> id;

  

    cout << "Console based - [c]" << endl;
    cout << "Simulation - [s]" << endl;
    cin >> input;

    cout << "How many days would the simulation be run for: ";
    cin >> total_days;

    // validate the input. Check to see if total_days is valid interger
    while(cin.fail() || total_days <= 0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter days again [positive integer]: ";
        cin >> total_days; 
    }
    

    // initialize the population
    for (int i = 0; i < MAX_POPULATION; i++) {
    
        isSick = makeSick(); // randomly make 10% sick
        random_x_coordinates = randomLocationValue(); // random x location
        random_y_coordinates = randomLocationValue(); // random y location

        sickCounter = (isSick ? sickCounter + 1 : sickCounter); // set the sick counter 

        population.push_back(Person(random_x_coordinates, random_y_coordinates, i, isSick)); // append to the array
        
    }


    if(toupper(input) == 'C'){

        // loop that controls the number of days the simulation will run for 

        for (int i = 1; i <= total_days; i++){

            cout << "Day " << i << endl;

            // loop will print all the objects in vector population
            for (int j = 0; j < MAX_POPULATION; j++) {
                Person person1 = population[j];
                person1.printInfo();

                temp_x = population[j].getX();
                temp_y = population[j].getY();
                temp_sick = population[j].getIsSick(); // check to see if they are sick or not

                // loop will go through everyone else in the vector and check their distance and make them sick accordingly. 
                for (int k = 0; k < MAX_POPULATION; k++){
                    Person person2 = population[k];
                   
                    bool isSickPossible = person2.canBeMadeSick(i, temp_x, temp_y, temp_sick); // check the distance between the poeple. Checks if they can be made sick

                    if(isSickPossible){
                        population[k].setIsSick(true); // make person sick
                        sickCounter++; // increment sick counter
                        
                    }
                }
                
                
            }
            cout << "day ended with " << sickCounter << " sick people\n" << endl;

            // this loop will move the people in 1 sqaure in any direction. Occur only after day has finished. 
            for (int j = 0; j < MAX_POPULATION; j++) {
                population[j].move();
            }
        }
    }


    else if(toupper(input) == 'S'){

        int counter = 0;

        for (int day = 1; day <= total_days; day++){

            cout << "Day " << day << endl;
            for(int y_axis = 0; y_axis <= 50; y_axis++){ // y axis

                cout << y_axis << " | ";

                for (int x_axis = 0; x_axis <= 80; x_axis++) { // x axis

                    for(int i = 0; i < MAX_POPULATION; i++){ // go throught the vector population
                        Person person = population[i];
                        if(person.getX() == x_axis && person.getY() == y_axis){
                            temp_x = person.getX();
                            temp_y = person.getY();
                            temp_sick = person.getIsSick();

                            counter++;
                            
                            for (int j = 0; j < MAX_POPULATION; j++){
                                Person person2 = population[j];
                   
                                bool isSickPossible = person2.canBeMadeSick(i, temp_x, temp_y, temp_sick); // check the distance between the poeple. Checks if they can be made sick

                                if(isSickPossible){
                                    population[j].setIsSick(true); // make person sick
                                    sickCounter++; // increment sick counter
                                    
                                }
                            }
                            

                            if(!person.getIsSick()){
                                cout << setw(2) << 'O' << person.getX() << ", " << person.getY();
                                break;
                            }
                            else if(person.getIsSick()){
                                cout << setw(2) << 'S' << person.getX() << ", " << person.getY();
                                sickCounter++;
                                break;
                            }
                           
                        }
                    
                    }
                        
                    cout << setw(2) << " ";
                
                }
                cout << endl;
                
            }

            cout << "day " << day << " ended with "  << sickCounter <<" sick people\n" << endl;
            
            for (int j = 0; j < MAX_POPULATION; j++) {
                population[j].move();
            }
  
        }
            

    }

    
}

bool makeSick(){
    
    int number = (rand() % (PERCENT_SICK) + 1);
    if (number == 1){
        return true;

    }
    else{
        return false;
    }
}

int randomLocationValue(){
    return ((rand() % (MAX_GRID_LOCATION + 1)) - 100);
}