#include <iostream>
#include <string.h>

using namespace std;

const int MAX_COMPUTERS = 50;

class Computer{
    private:
        const int static MAX_NAME_SIZE= 20;

        double price;
        char name[MAX_NAME_SIZE];
        int score;

    public:
        Computer();

        Computer& operator=(const Computer&);   // defines the operator = as a function, ignore that for now if you dont understand it.

        void setPrice(double);
        void setName(char*);
        void setScore(int);
        void printPcInfo();

        void readPcFromStandartInput();
        double getPrice();
        char* getName();
        int getScore();
        double getRating();
};

Computer::Computer(){
    //Default constructor
}

void Computer::setPrice(double newPrice){
    price = newPrice;
}

void Computer::setName(char* newName){
    strcpy(name, newName);
}

void Computer::setScore(int newScore){
    score = newScore;
}

double Computer::getPrice(){
    return price;
}

char* Computer::getName(){
    return name;
}

int Computer::getScore(){
    return score;
}

void Computer::readPcFromStandartInput(){
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter price: " << endl;
    cin >> price;
    cout << "Enter score (1 to 100): " << endl;
    cin >> score;
}

void Computer::printPcInfo(){
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Score: " << score << endl;
}

double Computer::getRating(){
    return price/score;
}

Computer& Computer::operator=(const Computer& second){
    strcpy(name, second.name);
    price = second.price;
    score = second.score;
}

// Insertion Sort
void sortComputers(Computer* computers, int size){
    for(int i = 0; i < size-1; ++i){
        int j = i + 1;
        Computer tempElement = computers[j];            //This is where we use the redefined operator=
        while(j > 0 && tempElement.getRating() < computers[j-1].getRating()){
            computers[j] = computers[j-1];
            j = j-1;
            computers[j] = tempElement;
        }
    }
}

int main(){
    int computersToBeRead;
    cout << "How many computer will you enter: " << endl;
    cin >> computersToBeRead;

    Computer myComputers[MAX_COMPUTERS];

    for(int i = 0; i < computersToBeRead; ++i){
        cout << "Reading information for computer " << i << endl;
        myComputers[i].readPcFromStandartInput();
    }

    cout << "Printing unsorted computers: " << endl;
    for(int i = 0; i < computersToBeRead; ++i){
        cout << "Computer " << i << " :" << endl;
        myComputers[i].printPcInfo();
    }

    sortComputers(myComputers, computersToBeRead);

    cout << "Printing sorted computers: " << endl;
    for(int i = 0; i < computersToBeRead; ++i){
        cout << "Computer " << i << " :" << endl;
        myComputers[i].printPcInfo();
    }
}
