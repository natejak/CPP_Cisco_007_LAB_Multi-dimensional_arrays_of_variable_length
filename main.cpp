#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

    /*
    C – number of courses taken by the student
    Nx – number of grades received during course number x
    Gab – b-th grade received in course number a
    */

    int C;
    int Nx;
    int G;


    cout << "How many courses did you have?: ";
    cin >> C;

    int **ptrarr = new int*[C]; // A pointer to a pointer to ...
    int *counts = new int[C] ;


    for (int i = 0; i < C; i++){
        cout << "How many Grades did Course #" << i+1 << " recived?: ";
        cin >> Nx;
        ptrarr[i] = new int [Nx];
        counts[i] = Nx;
        for (int j = 0; j < Nx; j++){
            cout << "What is the grade #" << j+1 << " : ";
            cin >> G;
            ptrarr[i][j] = G;
        }
    }

    double overallSum;
    overallSum = 0;
    double overallaverage = 0;
    for (int i = 0; i<C ; i++){
        int sum = 0;
        for (int j = 0; j < counts[i]; j++){
            sum += ptrarr[i][j];
        }
        double average = (double)sum/counts[i];
        overallSum += average;
        cout << "Course " << i+1 << ": final " << fixed <<setprecision(2)  << average << ", grades: ";
        for (int j = 0; j < counts[i]; j++){
            cout << ptrarr[i][j]<< " ";
        }
        cout << endl;
    }
    overallaverage = overallSum / C;
    cout << "Overall final " <<fixed << setprecision(2) << overallaverage << endl;


    // releasing the memory

    for (int i = 0; i < C; i++) {
        delete[] ptrarr[i];
    }

    delete[] ptrarr;
    delete[] counts;


    return 0;
}
