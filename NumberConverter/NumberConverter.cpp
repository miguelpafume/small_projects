/*
THIS PROGRAMS IS WAS MADE TO HELP SOLVE A HOMEWORK ASSIGNMENT
THE CONVERSION METHODS USED ARE PROBLABLY INEFICIENT AS IT IS DONE THROUGH THE METHODS ASKED BY MY INSTRUCTOR
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//Translates from binary to oct
int BinaryToOct(const int &x) {
  switch(x) {
    case 0: return 0;
    case 1: return 1;
    case 10: return 2;
    case 11: return 3;
    case 100: return 4;
    case 101: return 5;
    case 110: return 6;
    default: return 7;
  }
}

//Translates from binary to hex
char BinaryToHex(const int &x) {
  switch(x) {
    case 0: return '0';
    case 1: return '1';
    case 10: return '2';
    case 11: return '3';
    case 100: return '4';
    case 101: return '5';
    case 110: return '6';
    case 111: return '7';
    case 1000: return '8';
    case 1001: return '9';
    case 1010: return 'A';
    case 1011: return 'B';
    case 1100: return 'C';
    case 1101: return 'D';
    case 1110: return 'E';
    default: return 'F';
  }
}

//Translates from oct to binary
vector<int> OctTranslate(const int x) {
  switch(x) {
    case 0:   return {0, 0, 0};
    case 1:   return {0, 0, 1};
    case 2:   return {0, 1, 0};
    case 3:   return {0, 1, 1};
    case 4:   return {1, 0, 0};
    case 5:   return {1, 0, 1};
    case 6:   return {1, 1, 0};
    default:  return {1, 1, 1};
  }
}

//Translates from hex to binary
vector<int> HexTranslate(const char x) {
  switch(x) {
    case '0': return {0, 0, 0, 0};
    case '1': return {0, 0, 0, 1};
    case '2': return {0, 0, 1, 0};
    case '3': return {0, 0, 1, 1};
    case '4': return {0, 1, 0, 0};
    case '5': return {0, 1, 0, 1};
    case '6': return {0, 1, 1, 0};
    case '7': return {0, 1, 1, 1};
    case '8': return {1, 0, 0, 0};
    case '9': return {1, 0, 0, 1};
    case 'A': return {1, 0, 1, 0};
    case 'B': return {1, 0, 1, 1};
    case 'C': return {1, 1, 0, 0};
    case 'D': return {1, 1, 0, 1};
    case 'E': return {1, 1, 1, 0};
    default:  return {1, 1, 1, 1};
  }
}

//Returns a vector based on the input integer
vector<int> IntToVector(long long unsigned int x) {
  vector<int> int_vec {};
  while(x > 0) {
    long long unsigned int num {x%10}; // num = last digit
    x /= 10; //Removes the last digit
    int_vec.insert(int_vec.begin(), num);
  }
  return int_vec;
}

//Returns a decimal value (size_t) with based on the binary input
size_t BinaryToDecimal(const vector<int>* const vec) {
  size_t decimal_value {0};
  std::cout << std::endl;
  for(int i {static_cast<int>((*vec).size())-1}; i >= 0; i--) {
    if((*vec).at((*vec).size()-i-1) == 1) {
      decimal_value += pow(2, i);
      std::cout << "1 * 2^" << i << " = " << pow(2, i) << std::endl;
    } else {
      std::cout << "0 * 2^" << i << " = 0" << std::endl;
    }
  }
  return decimal_value;
}

void DecimalToBinary(vector<int>* vec, unsigned int decimal) {
  while(decimal!=0) {
    int temp {0};
    temp = decimal % 2;
    cout << decimal << " / 2 = " << temp << endl;
    (*vec).insert((*vec).begin(), temp);
    decimal /= 2;
  }
}

void OctToBinary(vector<int>* vec, size_t input) {
  vector<int> temp_vec = IntToVector(input);

  for(int i: temp_vec) {
    vector<int> temp = OctTranslate(i);
    for(int i: temp) {(*vec).push_back(i);}
  }
}

void HexToBinary(vector<int> *vec) {
  cout << "\nType your number: ";
  string input {0};
  cin >> input;

  for(char i: input) {
    vector<int> temp = HexTranslate(i);

    for(int i: temp) {(*vec).push_back(i);}
  }
}





int main() {
  vector<int> vec {}; 
  vector<int> *vec_ptr = &vec;

  size_t decimal {0};
  size_t choice {0};

  cout << "1. Decimal\n2. Oct\n3. Binary\n4. Hex\n";
  while (true){
    cout << "\nWhat is your input going to be: ";
    cin >> choice;

    switch(choice) {
      case 1: {
        cout << "\nType you number: ";
        cin >> decimal;
        cout << endl;
        DecimalToBinary(vec_ptr, decimal);
        break;
      }
      case 2: {
        cout << "\nType your number: ";
        int oct_input {0};
        cin >> oct_input;
        OctToBinary(vec_ptr, oct_input);
        decimal = BinaryToDecimal(vec_ptr); 
        break;
        }
      case 3: {
        long long unsigned int x {0};
        cout << "\nType the binary number: ";
        cin >> x;
        vec = IntToVector(x);
        decimal = BinaryToDecimal(vec_ptr); 
        break;
        }
      case 4: {
        HexToBinary(vec_ptr);
        decimal = BinaryToDecimal(vec_ptr); 
        break;
      default:
        continue;
      }
    }
    break;
  }

  cout << "\nDecimal: " << decimal;

  if(vec.at(0) == 0) {
    while(vec.at(0) == 0) {
      vec.erase(vec.begin());
    }
  }

  cout << "\nBinario: ";
  for(int i: vec) {
    cout << i;
  }

  cout << "\n\nBinario (OCT): ";
  while(vec.size()%3!=0) {
    vec.insert(vec.begin(), 0);
  }

  for(int i {0}; i < vec.size(); i++) {
    if(i%3==0) {
      cout << "\t";
    }
    cout << vec.at(i);
  }

  vector<int> vec_octal {};

  for(int i {0}; i < vec.size(); i += 3) {
    int temp {0};
    int mult {100};
    for(int j {i}; j <= i+2; j++) {
      temp += vec.at(j)*mult;
      mult /= 10;
    }
    vec_octal.push_back(BinaryToOct(temp));
  }

  cout << "\nOcta: ";
  for(int i: vec_octal) {
      cout << i;
  }


  cout << "\n\nBinario (HEX): ";
  if(vec.at(0) == 0) {
    while(vec.at(0) == 0) {
      vec.erase(vec.begin());
    }
  }
  while(vec.size()%4!=0) {
    vec.insert(vec.begin(), 0);
  }

  for(int i {0}; i < vec.size(); i++) {
    if(i%4==0) {
      cout << "\t";
    }
    cout << vec.at(i);
  }

  vector<char> vec_hex {};

  for(int i {0}; i < vec.size(); i += 4) {
    int temp {0};
    int mult {1000};
    for(int j {i}; j <= i+3; j++) {
      temp += vec.at(j)*mult;
      mult /= 10;
    }
    vec_hex.push_back(BinaryToHex(temp));
  }

  cout << "\nHex: ";

  for(char i: vec_hex) {
      cout << i;
  }

  return 0;
}