#include <iostream>
#include <string>

using namespace std;

//DECLARING FUNCTION BEFORE MAIN SO WE CAN USE IT IN IT
bool checker(int userInput);
int random(int min, int max);

// DECLARING GLOBAL VARS
int MAX = 100;
int MIN = 0;
int randomNumber = random(MIN, MAX);

int main() {
   string userInput;
   int counter = 0;

   bool result = true;
    // LOOP GAME
    while(result){
        cout << "Enter a number between " << MIN << " and " << MAX << endl;
        getline(cin, userInput);
        result = checker(stoi(userInput));
        counter++;
    }

    cout << "You found it in " << counter << " steps" << endl;
    return 0;
}

bool checker(int userInput){
    if(userInput == randomNumber){
        cout << "Congrats you found the secret number" << endl;
        return false;
    } else if(userInput > randomNumber) {
        MAX = userInput;
    } else if (userInput < randomNumber){
        MIN = userInput;
    } else {
        //some type of error
        cout << "Error" << endl;
    }
    return true;
}


// from : https://stackoverflow.com/a/7560171
int random(int min, int max){ //range : [min, max)
    static bool first = true;
    if (first){
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}