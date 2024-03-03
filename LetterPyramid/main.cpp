#include <iostream>
#include <string>

using namespace std;

int main() {

    //Declares both the user input and its inverted value.
    string pyramid_letters {};
    string inverted_letters {};

    //Asks for the input
    cout << "Input the string to make the pyramid: ";
    getline(cin, pyramid_letters);

    //Goes backwards through pyramid_letters and saves the results to inverted_letters
    for (size_t r {pyramid_letters.size()}; r != 0; r--) {
        inverted_letters.push_back(pyramid_letters.at(r-1));
    }

    //The ammount of times the program'll iterate is bases on the size of the string + the value used to limit the outputs of the string
    for (int i {0}; i < pyramid_letters.size(); i++) {
        //Outputs the spaces bases on the size of the string
        for (size_t j {0}; j < (pyramid_letters.size()-i); j++) {
            cout << " "; 
        }

        //Outputs the inputed string limited at the iteration number
        for (int j {0}; j <= i; j++) {
            cout << pyramid_letters.at(j);
        }

        //Goes through the inverted list and doesn't break automatically
        for (size_t k {(inverted_letters.size())};; k++) {
            //Breaks out of the loop if the position of k is over the size of the string (skips the first/repeated letter)
            if (k-i >= inverted_letters.size())
            break;
            
            //Outputs the letter on the inverted string based on the max value of the string - the iteration value
            if (inverted_letters.at(k-i) != string::npos)
                cout << inverted_letters.at(k-i);
        }
        cout << endl;
    }
    return 0;
}