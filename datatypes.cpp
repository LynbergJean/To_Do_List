#include <iostream>

using namespace std;

int main(){
    cout << "guess the number between one and 10: ";
    /*lets track the logic
        1- we get the number we want the user to guess
        2- the user inputs his guess
        3- while the guess does ot ewual the number we want the loop 
            will keep running
        4- inside the loop if checks for greater or less than and gets another inout from the user
        goes back to the loop to check if its the right number and keeps doing
        this until iut finds the right number and the loop breaks and the last line in the 
        code prints*/
    int guess, actual = 3;
    cin >> guess;

    while(guess != actual){
        if(guess > 10 || guess < 1){
            cout << "Number not in range pls pick between 1 and 10" << endl;
        }else if(guess < actual ){
            cout << "Too Low! Try again: ";
        }else if(guess > actual){
            cout << "too High! Try again: ";
        }
        cin >> guess;

    }

    cout << "congrats " << guess << " is the right number!"<< endl;
    return 0;

            
}