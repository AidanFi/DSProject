#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    public:
        Matrix(): data({}) {} //constructor
        
        Matrix(const int &rows, const int &cols) {
            Reset(rows, cols);
        }

        void Reset(const int &rows, const int &cols) {
            if (rows == 0 || cols == 0) 
                data.assign(0, vector<int>(0));
            else 
                data.assign(rows, vector<int>(cols));
        }

        int GetNumRows() const {
            return data.size();
        }

        int GetNumColumns() const {
            if (GetNumRows() > 0) 
                return data[0].size();
            return 0;
        }


        int At(const int &row, const int &col) const {  //returns value at a given place in the matrix
            return data.at(row).at(col);
        }

        int& At(const int &row, const int &col) {   //returns a reference to a given value
            return data.at(row).at(col);
         }
        
        void printMatrix(const int &rows, const int &cols) {
            if (rows == 0 || cols == 0)
                cout << "Matrix is empty" << endl;
            else {

            }

        }

    private:
        vector<vector<int>> data;

};



istream& operator >>(istream& stream, Matrix& matrix) {
    int row = 0, col = 0;

    stream >> row >> col;
    matrix.Reset(row, col);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}
// format to input matrix
    /* 
    2 2
    n n
    n n

    3 4
    n n n n
    n n n n
    n n n n
    */

void MatrixInfo(const Matrix& m) {
    cout << "{ \"rows\": " << m.GetNumRows() << ", \"columns\": " << m.GetNumColumns() << " }" << endl;
}

int main() {
    Matrix first;
    Matrix second (3, 5);

    // MatrixInfo(second);

    // cout << second.At(2, 3);
    // second.At(2, 3) = 8;
    // cout << second.At(2, 3);
    // MatrixInfo(first);
    // cin >> first;
    // MatrixInfo(first);
    
    return 0;
}