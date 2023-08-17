#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;


const int GRID_SIZE = 200;
const int NUM_PEOPLE = 100;
const int NUM_DAYS = 5;
const double SICK_PERCENTAGE = 0.1;

struct Person {
    int x;
    int y;
    bool isSick;

    Person(int paramX, int paramY, bool paramIsSick) : x(paramX), y(paramY), isSick(paramIsSick) {}
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

bool shouldContractDisease(double x1, double y1, bool isSick1, vector<Person> population, int i) {

    if(!isSick1 || (x1 == population[i].x && y1 == population[i].y)){
        return false;
    }

    return(true);

    // double dist = distance(x1, y1, x2, y2);
    // if (dist <= sqrt(2.0)) {
    //     if (isSick1 || !isSick2) {
    //         int probability = (rand() % 10) + 1 ;
    //         if(probability <= 9){
    //             return true;
    //         };
    //     }
    // }
    // return false;
}

void movePerson(Person& person) {
    int dx = rand() % 3 - 1; // -1, 0, or 1
    int dy = rand() % 3 - 1; // -1, 0, or 1

    int newX = person.x + dx;
    int newY = person.y + dy;

    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
        person.x = newX;
        person.y = newY;
    }
}

bool makeSick(){
    bool isSick;
    int number = (rand() % (10) + 1);
    if (number == 1){
        return isSick = true;

    }
    else{
        return isSick = false;
    }
    
}

int main() {
    srand(time(0));

    vector<int> sick;

    vector<Person> population;

    

    // Initialize people
    // int numSick = (NUM_PEOPLE * SICK_PERCENTAGE);
    for (int i = 0; i < NUM_PEOPLE; ++i) {
        // bool isSick = (i < numSick);
        bool isSick = makeSick();
        population.push_back(Person(rand() % GRID_SIZE, rand() % GRID_SIZE, isSick));
    }

    // Simulate movement for 5 days
    for (int day = 0; day < NUM_DAYS; ++day) {
        int numberOfSick = 0;
     
        // Print current day's information
        cout << "Day " << day + 1 << ":\n";
        for (int i = 0; i < population.size(); ++i) {
            const Person& person = population[i];
            
            cout << "Person at (" << person.x << ", " << person.y << ") - ";
            cout << (person.isSick ? "Sick\n" : "Healthy\n");
            numberOfSick = person.isSick ? (numberOfSick + 1) : numberOfSick;


            for (int j = 0; j < 2; j++){
                const Person& person2 = population[j];
                bool contracted = shouldContractDisease(person.x, person.y, person.isSick, population, j);
                if(contracted){
                    cout << "\nyou made ("<< population[j].x << ", " << population[j].y <<") sick" << endl;
                    population[j].isSick = true;
                    numberOfSick++;
                }
                else{
                    contracted = false;
                }
                
            }

            movePerson(population[i]);
        }

        cout << "At the end of the day, " << numberOfSick << " are sick" << endl;

        cout << "\n";
    }

    return 0;
}
