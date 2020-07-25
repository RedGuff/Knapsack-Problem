#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
int minMoney = 0;
int maxMoney = 0;
int minVolume = 0;
int maxVolume = 0;
string lgg= "en";

void config() {
    lgg = "en";
minMoney = 5;
maxMoney = 100;
minVolume = 5;
maxVolume = 100;
    }

void title(string lgg = "en") {
    cout << "Knapsack Problem." << endl;
    }


void intro(int moneyMin, int volumeMax, string lgg = "en") {
    cout << "Try to pack at least " << moneyMin << " euros in " << volumeMax << " liters maximum only." << endl;
    cout << "I don't know if it's possible, because I'm stupid!" << endl;
    cout << "Enter 1 positive number at a time, zero (2-2) and negative numbers are ignored to help you, a true letter to close." << endl;
    cout << "Number: \tMoney:\t\tVolume:" << endl;
    }

void generateProblem(vector < vector < int > >& Matrix) {
    for (int object=0;object<Matrix.size();object++)// aMax fois, aMax non utilisé. parfait pour les tableaux.
    {
        Matrix[object][0] = rand() % (maxMoney - minMoney + 1) + minMoney;
        Matrix[object][1] = rand() % (maxVolume - minVolume + 1) + minVolume;

    }
    }

void coutMatrix2D(vector < vector < int > >& Matrix) {
    for(int a = 0; a < Matrix.size(); a++) {
        cout << a << ":\t";
        for(int b = 0; b < Matrix[a].size(); b++) {
            cout << "\t" << Matrix[a][b] << "\t";
            }
        cout << endl;
        }
    }

bool isProposedGood() {
    return false;
    }

void input() {}

int main() {
    srand(time(NULL));       // No need for better init.
config();
    title(lgg);
    int amplObject = 5;
    int minObject = 2;
    int VirtualMissingObjectMoney = 0;
    int VirtualMissingObjectVolume = 0;
    int numberObjects = rand() % amplObject + minObject; // ints tous inclus.
    vector < vector < int > > Matrix(numberObjects, vector< int >(2, 0));
    generateProblem(Matrix);
    int moneyMin = rand() % 1000 + 5;
    int volumeMax = rand() % 1000 + 5;
    intro(moneyMin, volumeMax, lgg);
    coutMatrix2D(Matrix);
    input();
    if(isProposedGood() == true) {
        cout << ":-D" << endl;
        }
    else {
        cout << ":-O" << endl;
        }
    return 0;
    }
