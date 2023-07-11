#include <iostream>
#include "Eigen/Dense"
#include <string>

int main() {
    Eigen::Matrix2f mat;
    mat << 1, 2,
           3, 4;
    std::cout << "Here is mat:\n" << mat << std::endl;

    Eigen::Matrix<char, 2, 2> charmat;
    charmat << 'A', 'G',
           'C', 'T';
    std::cout << "Here is charmat:\n" << charmat << std::endl;

    Eigen::Matrix<std::string, 2, 2> strmat;
    strmat << "A", "G",
           "C", "T";
    std::cout << "Here is strmat:\n" << strmat << std::endl;

    Eigen::Vector2f vec;
    vec << 5,
           6;
    std::cout << "Here is vec:\n" << vec << std::endl;

    std::cout << "Multiplication of mat and vec:\n" << mat * vec << std::endl;

    std::cout << "Transpose of mat:\n" << mat.transpose() << std::endl;

    std::cout << "The determinant of mat is " << mat.determinant() << std::endl;

    Eigen::Matrix2f inverse = mat.inverse();
    std::cout << "The inverse of mat is:\n" << inverse << std::endl;

    return 0;
}
