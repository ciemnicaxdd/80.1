#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

class file {
    ifstream in;
    ofstream out;

    public: 

        vector <int> numbers;
        file();
        ~file();

        void rectangular();
        void perimeter();
        void ee();

};

file::file() {
    in.open("C:\\dane_trojkaty.txt");
    out.open("wynik.txt");

    int temp;
    while (!in.eof()) {
        in >> temp;
        numbers.push_back(temp);

    }

}

file::~file() {
    in.close();
    out.close();
}

void file::rectangular() {
    for (int i = 0; i < numbers.size()-3; i++) {
        if ((pow(numbers[i], 2) + pow(numbers[i+1], 2)) == pow(numbers[i+2], 2)) {
            cout << numbers[i] << " " << numbers[i + 1] << " " << numbers[i + 2] << endl;
        }
        else if ((pow(numbers[i], 2) + pow(numbers[i + 2], 2)) == pow(numbers[i + 1], 2)) {
            cout << numbers[i] << " " << numbers[i + 2] << " " << numbers[i + 1] << endl;
        }
        else if ((pow(numbers[i + 1], 2) + pow(numbers[i + 2], 2)) == pow(numbers[i], 2)) {
            cout << numbers[i+1] << " " << numbers[i + 2] << " " << numbers[i] << endl;
        }
    }
}

void file::perimeter() {
    sort(numbers.begin(), numbers.end());
    for (int i = numbers.size() - 1; i > 0; i--) {
        if (numbers[i] < (numbers[i - 1] + numbers[i - 2])) {
            cout << numbers[i] + numbers[i - 1] + numbers[i - 2] << endl;
            break;
        }
    }
}

void file::ee() {
    int counter = 0;
    for (int i = 0; i < numbers.size() - 2; i++) {
        for (int j = i+1; j < numbers.size() - 1; j++) {
            for (int x = j+1; x < numbers.size(); x++) {
                if ((numbers[i] + numbers[j]) > numbers[x]) {
                    counter++;
                }
            }
        }
    }
    cout << counter;
}

int main()
{
    file f;
    f.rectangular();
    f.perimeter();
    f.ee();
}
