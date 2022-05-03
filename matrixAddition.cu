/*
Programmer: Aidan Fields
Program: matrix addition (3X3)
Date: 4/27/2022
*/

#include <iostream>
#include <chrono>

using namespace std;

class Timer {
    private:
	    using clock_type = chrono::steady_clock;
	    using second_type = chrono::duration<double, ratio<1> >;

	    chrono::time_point<clock_type> m_beg { clock_type::now() };

    public:
	    void reset() {
		    m_beg = clock_type::now();
	    }

	double elapsed() const {
		return chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};

int main() {
    Timer t;
    int i, j;
    int mat1[3][3], mat2[3][3], matSum[3][3];

    cout << "Enter the values for matrix1 (3X3): " << endl;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            cin >> mat1[i][j];
            //mat1[i][j] = 10;
    }

    cout << "Enter the values for matrix2 (3X3): " << endl;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            cin >> mat2[i][j];
            //mat2[i][j] = 10;
    }

    //add matrix1 and matrix2
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            matSum[i][j] = mat1[i][j] + mat2[i][j];
    }

    //start timer here
    t.reset();

    //print matrix1
    cout << endl << "Matrix1: " << endl;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            cout << mat1[i][j] << " ";
        cout << endl;
    }

    //print matrix2
    cout << endl << "Matrix2: " << endl;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            cout << mat2[i][j] << " ";
        cout << endl;
    }

    //print matrixSum
    cout << endl << "Matrix1 + Matrix2: " << endl;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            cout << matSum[i][j] << " ";
        cout << endl;
    }

    //print time taken to run program
    cout << endl << "Time elapsed: " << t.elapsed() << endl;

    return 0;
}