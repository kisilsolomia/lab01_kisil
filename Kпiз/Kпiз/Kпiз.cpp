#include <iostream>
#include <vector>
#include <algorithm>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    void inputMatrix() {
        std::cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    int countNonZeroColumns() const {
        int count = 0;
        for (int j = 0; j < cols; ++j) {
            bool hasZero = false;
            for (int i = 0; i < rows; ++i) {
                if (data[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (!hasZero) {
                ++count;
            }
        }
        return count;
    }

    int countElementsInRange(int a, int b) const {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < a && data[i][j] > b) {
                    ++count;
                }
            }
        }
        return count;
    }

    void sortRowsByColumnSums() {
        std::vector<int> colSums(cols, 0);
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                colSums[j] += data[i][j];
            }
        }

        std::sort(data.begin(), data.end(), [&](const std::vector<int>& row1, const std::vector<int>& row2) {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < cols; ++j) {
                sum1 += row1[j];
                sum2 += row2[j];
            }
            return sum1 < sum2;
            });
    }

    void printMatrix() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;

    Matrix mat(rows, cols);
    mat.inputMatrix();

    std::cout << "Number of columns without zero elements: " << mat.countNonZeroColumns() << "\n";

    int a, b;
    std::cout << "Enter values for a and b: ";
    std::cin >> a >> b;
    std::cout << "Number of elements less than " << a << " and greater than " << b << ": " << mat.countElementsInRange(a, b) << "\n";

    mat.sortRowsByColumnSums();
    std::cout << "Matrix after sorting rows by column sums:\n";
    mat.printMatrix();

    return 0;
}
