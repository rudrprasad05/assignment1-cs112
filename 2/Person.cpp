#include "Person.h"
#include <iostream>
#include <cmath>

using namespace std;

const double MAX_DISTANCE = sqrt(2);
const int GRID_MIN = -100;
const int GRID_MAX = 100;

// constructor
Person::Person(int x, int y, int id, bool isSick){
    this->x = x;
    this->y = y;
    this->id = id;
    this->isSick = isSick;
}

//setters

// set x coordinates
void Person::setX(int x){
    this->x = x;
}

// set y coordinates
void Person::setY(int y){
    this->y = y;
}

// set sick status
void Person::setIsSick(bool isSick){
    this->isSick = isSick;
}

// set id. (only initialized when object is created)
void Person::setID(int id){
    this->id = id;
}

// getters
int Person::getX(){
    return this->x;
}

int Person::getY(){
    return this->y;
}

bool Person::getIsSick(){
    return this->isSick;
}

int Person::getID(){
    return this->id;
}

// methods

// print information of the person object onto the screen
void Person::printInfo(){
    string sick = (isSick ? "yes" : "no");
    cout << "id: "<< id << " " << "location: {" 
        << x << ", " << y << "} sick: " << sick << endl;

}

// move the person randomly 1 sqaure in any direction along x, y axis, or stay in same location
void Person::move(){

    // give a random value thats either -1, 0, 1. 
    int dx = rand() % 3 - 1; 
    int dy = rand() % 3 - 1; 

    int newX = this->x + dx;
    int newY = this->y + dy;

    // check that person does not move out of allocated grid of -100 to 100
    if((newX >= GRID_MIN && newX <= GRID_MAX) && (newY >= GRID_MIN && newY <= GRID_MAX)){
        this->x = newX;
        this->y = newY;
    }

}

bool Person::canBeMadeSick(int id1, int x1, int y1, bool isSick){
 
    double distance =  sqrt( pow((this->x - x1),2) + pow((this->y - y1), 2) ); 
    int probability = (rand() % (10)); // random number from 0 to 9. useed to determine 90% probabilty for person to get sick
    
    if(!isSick  || distance == 0 || this->getIsSick() || distance > MAX_DISTANCE){
        return false;
    }
    else{

        // 90% probabilty to get sick
        if (probability != 1){
            cout << this->id << " was close to infected person and caught the virus" << endl;
            return true;

        }

        // 10% chance to be ok
        else{
            cout << this->id  << " was close to infected person but didnt catch the virus" << endl;
            return false;
        }
    }
}

