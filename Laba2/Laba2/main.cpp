#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data;

    // Вспомогательная функция для освобождения памяти
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

    // Вспомогательная функция для выделения памяти и копирования данных
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
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // Основной конструктор
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        if (r > 0 && c > 0) {
            data = new double* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols](); // Инициализация нулями
            }
        }
    }

    // Конструктор копирования (требование задания)
    Matrix(const Matrix& other) : data(nullptr) {
        copy(other);
    }

    // Деструктор
    ~Matrix() {
        clear();
    }

    // Оператор присваивания
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

    // Перегрузка оператора умножения матриц (& по заданию)
    Matrix operator&(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "Ошибка: Несовместимые размеры матриц для умножения!" << endl;
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

    // Friend-функция для ввода (требование задания)
    friend istream& operator>>(istream& in, Matrix& mat) {
        cout << "Введите матрицу " << mat.rows << "x" << mat.cols << ":" << endl;
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                cout << "Элемент [" << i << "][" << j << "]: ";
                in >> mat.data[i][j];
            }
        }
        return in;
    }

    // Friend-функция для вывода (требование задания)
    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        out << "Матрица " << mat.rows << "x" << mat.cols << ":" << endl;
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                out << setw(6) << mat.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Функция для установки размеров (удобно для переиспользования объекта)
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

    // Геттеры для размеров
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    setlocale(LC_ALL, "rus");

    int r1, c1, r2, c2;

    // Ввод размеров первой матрицы
    cout << "Введите количество строк и столбцов для первой матрицы: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    cin >> A;

    // Ввод размеров второй матрицы
    cout << "Введите количество строк и столбцов для второй матрицы: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    cin >> B;

    // Проверка на возможность умножения и вычисление
    if (A.getCols() == B.getRows()) {
        Matrix C = A & B; // Использование перегруженного оператора &
        cout << "\nРезультат умножения матриц (A & B):" << endl;
        cout << C;
    }
    else {
        cout << "Ошибка: Количество столбцов первой матрицы должно быть равно количеству строк второй!" << endl;
    }

    // Демонстрация работы конструктора копирования
    Matrix CopyOfA = A;
    cout << "\nКопия матрицы A (создана через конструктор копирования):" << endl;
    cout << CopyOfA;

    return 0;
}