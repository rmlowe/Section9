// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit
    
    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1], you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/ 
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> numbers = {};
    char choice{};
    
    while (choice != 'Q' && choice != 'q') {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "F - Find the number of occurrences of a number" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        if (choice == 'Q' || choice == 'q') {
            cout << "Goodbye" << endl;
        } else if (choice == 'P' || choice == 'p') {
            if (numbers.empty()) {
                cout << "[] - the list is empty" << endl;
            } else {
                cout << "[ ";
                
                for (auto n : numbers) {
                    cout << n << " ";
                }
                
                cout << "]" << endl;
            }
        } else if (choice == 'A' || choice == 'a') {
            cout << "Enter integer: ";
            
            int number{};
            cin >> number;
            
            bool already_present = false;
            
            for (auto n : numbers) {
                if (n == number) {
                    already_present = true;
                }
            }
            
            if (already_present) {
                cout << number << " is already present" << endl;
            } else {
                numbers.push_back(number);
                
                cout << number << " added" << endl;
            }
        } else if (choice == 'M' || choice == 'm') {
            if (numbers.empty()) {
                cout << "Unable to calculate the mean - no data" << endl;
            } else {
                double sum{};
                
                for (auto n : numbers) {
                    sum += n;
                }
                
                cout << "The mean is " << (sum / numbers.size()) << endl;
            }
        } else if (choice == 'S' || choice == 's') {
            if (numbers.empty()) {
                cout << "Unable to determine the smallest number - list is empty" << endl;
            } else {
                int min = numbers[0];
                
                for (int i = 1; i < numbers.size(); ++i) {
                    if (numbers[i] < min) {
                        min = numbers[i];
                    }
                }
                
                cout << "The smallest number is " << min << endl;
            }
        } else if (choice == 'L' || choice == 'l') {
            if (numbers.empty()) {
                cout << "Unable to determine the largest number - list is empty" << endl;
            } else {
                int max = numbers[0];
                
                for (int i = 1; i < numbers.size(); ++i) {
                    if (numbers[i] > max) {
                        max = numbers[i];
                    }
                }
                
                cout << "The largest number is " << max << endl;
            }
        } else if (choice == 'F' || choice == 'f') {
            cout << "Enter integer: ";
            
            int number{};
            cin >> number;
            
            int count{};
            
            for (auto n : numbers) {
                if (n == number) {
                    ++count;
                }
            }
            
            cout << number << " occurs " << count << " time(s)" << endl;
        } else if (choice == 'C' || choice == 'c') {
            numbers.clear();
            
            cout << "List cleared" << endl;
        } else {
            cout << "Unknown selection, please try again" << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}
