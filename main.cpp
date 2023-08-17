#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>



using namespace std;


const int POPULATION = 100;

void drawGrid();
double distanceBetweenPoints(double x1, double y1, double x2, double y2);

class Person
{
    public:
        int id;
        int x,y; 
        bool isSick;
        double distance;

        void printDetails();
        void setID(int i);
        void setLocation(int i );
        void makeSick();
        void move(Person *array, int chance);
        void calDistance(Person *array, int locationData[POPULATION][4]);
    
};


int main(){
    ofstream file("filename.txt");
    bool running = true;
    int counter = 0;
    int infected = 0;
    char input;
    int days;
    int locationData[POPULATION][4];

    Person array[POPULATION];

    while(running){
        
        cout << "Do you wish to run sim? [ Y / N ]" << endl;
        cin >> input;
        // cout << "Enter days for sim" << endl;
        // cin >> days;


        if(toupper(input) == 'Y'){

            

            // populate array
            srand(time(0));
            for(int i = 0; i < POPULATION; i++){
                
                array[i].setID(i);
                array[i].setLocation(i);
                array[i].makeSick();
                locationData[i][0] = array[i].x;
                locationData[i][1] = array[i].y;
                locationData[i][2] = array[i].isSick;
                locationData[i][3] = i;

                array[i].printDetails();

                if(array[i].isSick){
                    infected++;
                    array[i].calDistance(&array[i], locationData);
                }
                
                

                // break;
            }
            
            // start sim of 100 days
            
            // for(int i = 0; i < days; i++){
            //     int chance = (rand() % (9)) + 1;
            //     array[0].move(&array[0], chance);
            //     // array[0].printDetails();
          
            //     chance = 0;
                
            // }

            int tempx;
            int tempy;
            bool tempsick;
            int sickCount = 0;

            if(file.good()){

            

            
                for (int i = -100; i <= 100; i++){

                    file << setw(5) << i << " ";
                    
                    for (int j = -100; j <= 100; j++){
                        for(int k = 0; k < POPULATION; k++){
                        
                            if(locationData[k][0] == j && locationData[k][1] == i){
                                tempx = j;
                                tempy = i;
                                if(locationData[k][2]){
                                    tempsick = true;
                                    
                                    break;
                                }
                                else{
                                    tempsick = false;
                                    break;
                                }
                                
                                break;
                            }
                        
                        }
                        if(tempx == j && tempy == i){
                            if(tempsick){
                                file << setw(2)<< '-';
                                sickCount++;
                            }else{
                                file << setw(2)<< 'O';
                            }
                            
                        }else{
                            file << setw(2) << ' ';
                        }
                    
                    }
                    file << endl;
                }
                file << endl;
                file << sickCount;
                
            

            
            }
            else cout << "file not good" << endl;

            file.close();
        }   

      
    }
}

void drawGrid(char drawChar){
    int width = 50; 
    int height = 50;

    char empty = '.';
    char sick = 's';
    char ok = 'o';

    
}

double distanceBetweenPoints(double x1, double y1, double x2, double y2){
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    if(deltaX == 0 && deltaY == 0){
        return 0;
    }
    double final = sqrt(pow(deltaX,2) + pow(deltaY, 2));
  
    return final;
    
}



void Person::calDistance(Person *array, int locationData[POPULATION][4]){


    int x = this->x;
    int y = this->y;
    int id = this->id;
    double distance;

    for (int i = 0; i < POPULATION; i++){
        
        distance = distanceBetweenPoints(x, y, locationData[i][0], locationData[i][1]);
        if(distance <= 1.414){
            cout << id << " is " << distance << " away from " << locationData[i][3] << endl;
            continue;
        }
            
        

    }
}

void Person::printDetails(){
    string sick = this->isSick ? "sick" : "not sick";
    cout << "ID: " << this->id 
        << " | Location: (" << this->x << ", " << this->y <<") "
        << setw(15) << sick <<endl;
    
}


void Person::setLocation(int i){
        
    this->x = (rand() % (100 + 100 + 1)) + -100;
    this->y = (rand() % (100 + 100 + 1)) + -100;

    // this->x = i;
    // this->y = i;
}


void Person::setID(int i){
    this->id = i;
}


void Person::makeSick(){
    int number = (rand() % (10) + 1);
    if (number == 1){
        this->isSick = true;

    }
    else{
        this->isSick = false;
    }
    cout << number ;
}

void Person::move(Person *array, int chance){
    
    switch (chance)
    {
    case 1: // x inc y inc
        array[0].x++;
        array[0].y++;
        break;

    case 2: // x inc y dec
        array[0].x++;
        array[0].y--;
        break;

    case 3: // x inc y same
        array[0].x++;
        break;

    case 4: // x dec y inc
        array[0].x--;
        array[0].y++;
        break;
    
    case 5: // x dec y dec
        array[0].x--;
        array[0].y--;
        break;

    case 6: // x dec y same
        array[0].x--;
        break;
    
    case 7: // x same y inc
        array[0].y++;
        break;

    case 8: // x same y dec
        array[0].y--;
        break;
    
    case 9: // x same y inc
        break;

    default:
        break;
    }
}