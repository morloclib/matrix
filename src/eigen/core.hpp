#include "Eigen/Dense"

#include <utility>
#include <vector>

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_packMatrix(const std::vector<std::vector<T>>& xss) {
    int rows = xss.size();
    int cols = xss[0].size();

    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mat(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat(i, j) = xss[i][j];
        }
    }

    return mat;
}

template <typename T>
std::vector<std::vector<T>> mlc_unpackMatrix(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    std::vector<std::vector<T>> xss(mat.rows(), std::vector<T>(mat.cols()));

    for (int i = 0; i < mat.rows(); ++i) {
        for (int j = 0; j < mat.cols(); ++j) {
            xss[i][j] = mat(i, j);
        }
    }

    return xss;
}



Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mlc_identity(int n) {
    return Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Identity(n, n);
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_transpose(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.transpose();
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, 1> mlc_col(int index, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.col(index);
}

template <typename T>
Eigen::Matrix<T, 1, Eigen::Dynamic> mlc_row(int index, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.row(index);
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_block(int row, int col, int nrows, int ncols, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.block(row, col, nrows, ncols);
}

template <typename T>
T mlc_cell(int row, int col, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat(row, col);
}

template <typename T>
std::pair<int, int> mlc_shape(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return std::make_tuple(mat.rows(), mat.cols());
}

template <typename T>
int mlc_ncol(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.cols();
}

template <typename T>
int mlc_nrow(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return mat.rows();
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_mmul(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat1, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat2) {
    return mat1 * mat2;
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_madd(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat1, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat2) {
    return mat1 + mat2;
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_smul(T scalar, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    return scalar * mat;
}

template <typename T>
Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mlc_sadd(T scalar, const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& mat) {
    // The array conversion is a zero-cost operation that tells Eigen to treat
    // the input element-wise rather than as a traditional mathematical matrix.
    // Here it allows the scalar value to be added to each element. The Array
    // object is then implicitly converted back to a Matrix.
    return scalar + mat.array();
}

template <typename T>
std::vector<T> mlc_col2list(const Eigen::Matrix<T, Eigen::Dynamic, 1>& col) {
    // col.data() returns a pointer to the first element of the matrix array
    // The constructor uses a range from this first pointer to the array end
    return std::vector<T>(col.data(), col.data() + col.size());
}

template <typename T>
std::vector<T> mlc_row2list(const Eigen::Matrix<T, 1, Eigen::Dynamic>& row) {
    return std::vector<T>(row.data(), row.data() + row.size());
}
