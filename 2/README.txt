cs112 assignment 1 2023

rudr prasad - s11219309
pranav datt - 

COVID 19 SIMULATION

What is the project about?
It is a covid-19 simulation. 200 x 200 grid with 100 people. 10% of the population is randomly sick. Simualtion is run for n number of days (determined by user). Each day the person can move 1 sqaure in any direction, or stay in the same spot. Movement in each direction has an equal chance of occuring and is complteley random

Language Used
    - c++ written in DevC++. Console app was created using devc++
    - Git and GitHub was used as a collaboration tool between group members. 
    - code is also available on github (https://github.com/rudrprasad05/assignment1-cs112/tree/main/2)

Project Structure
contains 3 files
    - main.cpp: is the driver of the project. Main logic is locatted here. Binds the prject together. 
    - Person.cpp: logic (methods, getters, setters) for the class Person is located here. Some methods include getters and setters for each variable. More discussed later
    - Person.h - contains the class variables and function prototypes and constructors. 

Main.cpp
    - driver of the project
    - asks for input if user wants a console based programme or a simulation. (note: both are consle based but simualtion will show the movemnet of the people on a grid)
    - vector of type Person (declared in header file described below) is created. Vectors were used instead of arrays because vectors have dynamic memory and are easier to work with (i.e have many inbuilt functions). eg - vector.size() will give length of vector hence no need to have an indexed for loop. 
    - Population is initialized. 10% is randmly made sick using the function makeSick() in main.cpp. Random x and y coordinates assigned to each person. added to vector named population using vector.pushback()
    - checks for input (c or s). All input has been validated. 
    - iterates through the vector population. Uses printInfo() method from person class to print the information of object into the screen. 
    - for every person printed into screen, it checks if it is sick. If it is sick then it checks for any other people within its general area (distance of √2 units away). 
    - if person is sick and another person is within range (√2 units) then the person 2 has a 90% chance of contracting the virus. 
    - for the console app, a message is also printed saying: "id:x made id:y sick". This does not occur for grid simualtion.
    - at the end of the day, number of sick people are printed. 
    - in the grid simulation, system(clear) is used to create an animation which shows the movemnet of people on a daily basis. frames per second is 0.5 (1 frame every 2 seconds). 


Person.h & Person.cpp
    - defines the class Person
    - private variables are: x, y, id and isSick. 
        -> int x is the x coordinates
        -> int y is the y coordinates
        -> int id is a unique id based on the index of its position in the vector
        -> bool isSick shows if person is sick or not
    public methods are getter and setters for all variables. This was done for encapsulation purposes. Moreover has methods such as:         
        -> printInfo(): prints x, y  coordinates, id and if its sick or not. 
        -> move(): will move the person in a random direction
        -> canBeSick(): will check distance bewteen person 1 and the rest of the population. If distance is less than or equal to √2 and person 1 is sick, then person 2 will have 90% chance of getting sick. 
        -> constructor: used to initalize the first population
        