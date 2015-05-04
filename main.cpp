//Name: Jeremy Chan SID: 861169589 date: 4/19/2015
//Lecturer: Jacobs Lab Director: Dingwen

#include "lab04.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[] )
{
    cout << "Pre-order: (K of 9) " << endl;
    preOrder(atoi(argv[1]));
    cout <<endl<< "Post-order: (K of 9) " << endl;
    postOrder(atoi(argv[1]));
    cout <<endl<< "Sorted: (K of 9) " << endl;
    sortedOrder(atoi(argv[1]));
}