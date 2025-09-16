#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

    // ��������������� ������� ��� ������������ ������
    void clear() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
        rows = 0;
        cols = 0;
    }

    // ��������������� ������� ��� ��������� ������ � ����������� ������
    void copy(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new double* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

public:
    // ����������� �� ���������
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // �������� �����������
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        if (r > 0 && c > 0) {
            data = new double* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols](); // ������������� ������
            }
        }
    }

    // ����������� ����������� (���������� �������)
    Matrix(const Matrix& other) : data(nullptr) {
        copy(other);
    }

    // ����������
    ~Matrix() {
        clear();
    }

    // �������� ������������
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

    // ���������� ��������� ��������� ������ (& �� �������)
    Matrix operator&(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "������: ������������� ������� ������ ��� ���������!" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Friend-������� ��� ����� (���������� �������)
    friend istream& operator>>(istream& in, Matrix& mat) {
        cout << "������� ������� " << mat.rows << "x" << mat.cols << ":" << endl;
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                cout << "������� [" << i << "][" << j << "]: ";
                in >> mat.data[i][j];
            }
        }
        return in;
    }

    // Friend-������� ��� ������ (���������� �������)
    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        out << "������� " << mat.rows << "x" << mat.cols << ":" << endl;
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                out << setw(6) << mat.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // ������� ��� ��������� �������� (������ ��� ����������������� �������)
    void setSize(int r, int c) {
        clear();
        rows = r;
        cols = c;
        if (r > 0 && c > 0) {
            data = new double* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols]();
            }
        }
    }

    // ������� ��� ��������
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    setlocale(LC_ALL, "rus");

    int r1, c1, r2, c2;

    // ���� �������� ������ �������
    cout << "������� ���������� ����� � �������� ��� ������ �������: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    cin >> A;

    // ���� �������� ������ �������
    cout << "������� ���������� ����� � �������� ��� ������ �������: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    cin >> B;

    // �������� �� ����������� ��������� � ����������
    if (A.getCols() == B.getRows()) {
        Matrix C = A & B; // ������������� �������������� ��������� &
        cout << "\n��������� ��������� ������ (A & B):" << endl;
        cout << C;
    }
    else {
        cout << "������: ���������� �������� ������ ������� ������ ���� ����� ���������� ����� ������!" << endl;
    }

    // ������������ ������ ������������ �����������
    Matrix CopyOfA = A;
    cout << "\n����� ������� A (������� ����� ����������� �����������):" << endl;
    cout << CopyOfA;

    return 0;
}