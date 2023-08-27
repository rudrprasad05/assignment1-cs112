#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using namespace std;

class Person{
    private:
        int x;
        int y;
        int id;
        bool isSick;

    public:
        
        // constructor
        Person(int x, int y, int id, bool isSick);

        // setters
        void setX(int x);
        void setY(int y);
        void setID(int id);
        void setIsSick(bool isSick);
    

        // getters
        int getX();
        int getY();
        int getID();
        bool getIsSick();
        

        // methods
        void printInfo();
        void move();
        bool canBeMadeSick(int id1, int x1, int y1, bool isSick);
        
            

};

#endif
