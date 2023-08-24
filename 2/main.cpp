#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include<unistd.h>  

#include "Person.h"

using namespace std;

const int MAX_POPULATION = 100;
const int PERCENT_SICK = 10;
const int MAX_GRID_LOCATION = 200;
const int SCREEN_REFRESH_RATE = 2;

bool makeSick();
int randomLocationValue();

int main(){
    srand(time(0));

    int sick_counter = 0;
    int total_days = 0;
    int random_x_coordinates = 0;
    int random_y_coordinates = 0;
    int x_coordinates;
    int y_coordinates;
    
    char input;

    bool is_sick = false;
    bool person_is_sick = false;
    bool is_printed = false;
    

    vector<Person> population;
  

    cout << "Console based - [c]" << endl;
    cout << "Simulation - [s]" << endl;
    cin >> input;

    while(toupper(input) != 'S' && toupper(input) != 'C' ){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter option again ['S', 'C']: ";
        cin >> input; 
    }

    // validate the input. Check to see if input is valid interger

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
    
        is_sick = makeSick(); // randomly make 10% sick
        random_x_coordinates = randomLocationValue(); // random x location
        random_y_coordinates = randomLocationValue(); // random y location

        sick_counter = (is_sick ? sick_counter + 1 : sick_counter); // set the sick counter 

        population.push_back(Person(random_x_coordinates, random_y_coordinates, i, is_sick)); // append to the array
        
    }


    if(toupper(input) == 'C'){

        // loop that controls the number of days the simulation will run for 

        for (int i = 1; i <= total_days; i++){

            cout << "Day " << i << endl;

            // loop will print all the objects in vector population
            for (int j = 0; j < MAX_POPULATION; j++) {
                Person person1 = population[j];
                person1.printInfo();

                x_coordinates = population[j].getX();
                y_coordinates = population[j].getY();
                person_is_sick = population[j].getIsSick(); // check to see if they are sick or not

                // loop will go through everyone else in the vector (array) and check their distance and make them sick accordingly. 
                for (int k = 0; k < MAX_POPULATION; k++){
                    Person person2 = population[k];
                   
                    bool is_sickPossible = person2.canBeMadeSick(i, x_coordinates, y_coordinates, person_is_sick); // check the distance between the poeple. Checks if they can be made sick

                    if(is_sickPossible){
                        population[k].setIsSick(true); // make person sick
                        sick_counter++; // increment sick counter
                        cout << person1.getID() << " made " << person2.getID() << " sick" << endl;
                        
                    }
                }
            }

            cout << "day ended with " << sick_counter << " sick people\n" << endl;

            // this loop will move the people in 1 sqaure in any direction. Occur only after day has finished. 
            for (int j = 0; j < MAX_POPULATION; j++) {
                population[j].move();
            }
        }
    }


    else if(toupper(input) == 'S'){
        system("clear");

        int counter = 0;

        for (int day = 1; day <= total_days; day++){

            cout << "Day " << day << endl;
            for(int y_axis = 0; y_axis <= 50; y_axis++){ // y axis

               
                for (int x_axis = 0; x_axis <= 80; x_axis++) { // x axis
                    is_printed = false;

                    for(int i = 0; i < MAX_POPULATION; i++){ // go throught the vector population
                        Person person = population[i];
                        if(person.getX() == x_axis && person.getY() == y_axis){
                            x_coordinates = person.getX();
                            y_coordinates = person.getY();
                            person_is_sick = person.getIsSick();

                            counter++;
                            
                            for (int j = 0; j < MAX_POPULATION; j++){
                                Person person2 = population[j];
                   
                                bool is_sick_possible = person2.canBeMadeSick(i, x_coordinates, y_coordinates, person_is_sick); // check the distance between the poeple. Checks if they can be made sick

                                if(is_sick_possible){
                                    population[j].setIsSick(true); // make person sick
                                    sick_counter++; // increment sick counter
                                    
                                }
                            }
                            
                            // print 'O' if person is OK
                            if(!person.getIsSick()){
                                cout << setw(2) << 'O';
                                is_printed = true;
                                break;
                            }
                            // print 'S' if person is SICK
                            else if(person.getIsSick()){
                                cout << setw(2) << 'S';
                                is_printed = true;
                                break;
                            }
                           
                        }
                        
                    
                    }
                    if(!is_printed){
                        cout << setw(2) << ".";
                    }
                        
                
                }
                cout << endl;
                
            }

            cout << "day " << day << " ended with "  << sick_counter <<" sick people\n" << endl;
             
            sleep(SCREEN_REFRESH_RATE);
            system("clear");

            // move the poeple in random direction. 
            
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