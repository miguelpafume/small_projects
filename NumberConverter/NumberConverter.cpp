#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int CountDigits(int x) {
  int i = 0;
  while(x > 0) {
    x /= 10;
    i++;
  }
  return i;
}

int BinaryToOct(int x) {
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

char BinaryToHex(int x) {
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

int HexTranslate(char x) {
  switch(x) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 10;
    case '3': return 11;
    case '4': return 100;
    case '5': return 101;
    case '6': return 110;
    case '7': return 111;
    case '8': return 1000;
    case '9': return 1001;
    case 'A': return 1010;
    case 'B': return 1011;
    case 'C': return 1100;
    case 'D': return 1101;
    case 'E': return 1110;
    default: return 1111;
  }
}

void IntToVector(vector<int> *vec, long long unsigned int x) {
  while(x > 0) {
    int num {static_cast<int>((x)%10)};
    x /= 10;
    (*vec).insert((*vec).begin(), num);
  }
}

void DecimalToBinary(vector<int> *vec, unsigned int decimal) {
  cout << endl;

  while(decimal!=0) {
    int temp {0};
    temp = decimal % 2;
    cout << decimal << " / 2 = " << temp << endl;
    (*vec).insert((*vec).begin(), temp);
    decimal /= 2;
  }
}

int OctTranslate(int x) {
  switch(x) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 10;
    case 3: return 11;
    case 4: return 100;
    case 5: return 101;
    case 6: return 110;
    default: return 111;
  }
}

void OctToBinary(vector<int> *vec) {
  cout << "\nType your number: ";
  int input {0};
  cin >> input;

  vector<int> temp_vec {};
  IntToVector(&temp_vec, input);

  for(int i: temp_vec) {
    long long unsigned int temp = static_cast<long long unsigned int>(OctTranslate(i));
    vector<int> temp_vec2 {};  
    IntToVector(&temp_vec2, temp);
    if(temp < 100) {
      if(temp/10 >= 1) {
        temp_vec2.insert(temp_vec2.begin(), 0);
      } else {
        for(int i {0}; i < 2; i++) {temp_vec2.insert(temp_vec2.begin(), 0);}
      }
    }
    for(int i: temp_vec2) {(*vec).push_back(i);}
  }
}

void HexToBinary(vector<int> *vec) {
  cout << "\nType your number: ";
  string input {0};
  cin >> input;

  for(char i: input) {
    long long unsigned int temp = static_cast<long long unsigned int>(HexTranslate(i));
    vector<int> temp_vec {};  
    IntToVector(&temp_vec, temp);
    if(temp < 1000) {
      if(temp/100 >= 1) {
        temp_vec.insert(temp_vec.begin(), 0);
      } else if(temp/10 >= 1) {
        for(int i {0}; i < 2; i++) {temp_vec.insert(temp_vec.begin(), 0);}
      } else {
        for(int i {0}; i < 3; i++) {temp_vec.insert(temp_vec.begin(), 0);}
      }
    }
    for(int i: temp_vec) {(*vec).push_back(i);}
  }
}

unsigned int BinaryToDecimal(vector<int> *vec) {
  unsigned int temp {0};
  for(int i {static_cast<int>((*vec).size())-1}; i >= 0; i--) {
    if((*vec).at((*vec).size()-i-1) == 1) {
      temp += pow(2, i);
    }
  }
  return temp;
}

unsigned int BinaryToDecimal(vector<int> *vec, long long unsigned int x) {
  IntToVector(vec, x);
  unsigned int temp {0};
  for(int i {static_cast<int>((*vec).size())-1}; i >= 0; i--) {
    if((*vec).at((*vec).size()-i-1) == 1) {
      temp += pow(2, i);
    }
  }
  return temp;
}

int main() {
  vector<int> vec {}; 
  vector<int> *vec_ptr = &vec;

  unsigned int choice {0};
  cout << "1. Decimal\n2. Oct\n3. Binary\n4. Hex\n";
  cout << "What is your input going to be: ";
  cin >> choice;

  unsigned int decimal {0};
  
  switch(choice) {
    case 1: {
      cout << "\nType you number: ";
      cin >> decimal;
      DecimalToBinary(vec_ptr, decimal);
      break;
    }
    case 2: {
      OctToBinary(vec_ptr);
      decimal = BinaryToDecimal(vec_ptr); 
      break;
      }
    case 3: {
      long long unsigned int x {0};
      cout << "\nType the binary number: ";
      cin >> x;
      decimal = BinaryToDecimal(vec_ptr, x); 
      break;
      }
    default: {
      HexToBinary(vec_ptr);
      decimal = BinaryToDecimal(vec_ptr); 
    }
  }

  cout << "\nDecimal: " << decimal;

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