#ifndef MATX_CORE_MATRIX_HEADER
#define MATX_CORE_MATRIX_HEADER

#include <array>
#include <cstddef>
#include <initializer_list>

namespace matx
{
template <typename T, std::size_t Rows, std::size_t Cols> class matrix
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = value_type const&;

    using size_type = std::size_t;

    ~matrix() {}
    matrix() : data{Rows * Cols, static_cast<T>(0)} {}
    matrix(std::array<T, Rows * Cols> const& array) : data(array) {}
    matrix(std::array<std::array<T, Cols>, Rows> const& array)
    {
        for (size_type r = 0; r < Rows; r++) {
            for (size_type c = 0; c < Cols; c++) {
                data[r * Cols + c] = array[r][c];
            }
        }
    }
    matrix(matrix const& other) : data(other.data) {}
    matrix(matrix&& other) noexcept : data(std::move(other.data)) {}
    matrix& operator=(matrix const& other) { return *this = matrix(other); }
    matrix& operator=(matrix&& other) noexcept { return *this = matrix(std::move(other)); }

    // get at elements
    reference at(size_type r, size_type c = 0) { return data[r * Cols + c]; }
    const_reference at(size_type r, size_type c = 0) const { return data[r * Cols + c]; }

    // structure
    size_type rows() { return Rows; }
    size_type cols() { return Cols; }

private: // methods
    reference operator[](size_type pos) { return data[pos]; }
    const_reference operator[](size_type pos) const { return data[pos]; }

private: // members
    std::array<T, Rows * Cols> data;
};

// creations
template <typename T, std::size_t Size> auto identity() -> matx::matrix<T, Size, Size>
{
    matx::matrix<T, Size, Size> result{};
    for (typename matx::matrix<T, Size, Size>::size_type i = 0; i < Size; i++) {
        result.at(i, i) = static_cast<T>(1);
    }
    return result;
}

} // namespace matx

// lhs + rhs
template <typename T, std::size_t Rows, std::size_t Cols>
auto operator+(matx::matrix<T, Rows, Cols> const& lhs, matx::matrix<T, Rows, Cols> const& rhs)
    -> matx::matrix<T, Rows, Cols>
{
    matx::matrix<T, Rows, Cols> result{};
    for (typename matx::matrix<T, Rows, Cols>::size_type i = 0; i < Rows; i++) {
        for (typename matx::matrix<T, Rows, Cols>::size_type j = 0; j < Cols; j++) {
            result.at(i, j) = lhs.at(i, j) + rhs.at(i, j);
        }
    };
    return result;
}

// lhs - rhs
template <typename T, std::size_t Rows, std::size_t Cols>
auto operator-(matx::matrix<T, Rows, Cols> const& lhs, matx::matrix<T, Rows, Cols> const& rhs)
    -> matx::matrix<T, Rows, Cols>
{
    matx::matrix<T, Rows, Cols> result{};
    for (typename matx::matrix<T, Rows, Cols>::size_type i = 0; i < Rows; i++) {
        for (typename matx::matrix<T, Rows, Cols>::size_type j = 0; j < Cols; j++) {
            result.at(i, j) = lhs.at(i, j) - rhs.at(i, j);
        }
    };
    return result;
}

// -m
template <typename T, std::size_t Rows, std::size_t Cols>
auto operator-(matx::matrix<T, Rows, Cols> const& m) -> matx::matrix<T, Rows, Cols>
{
    matx::matrix<T, Rows, Cols> result{};
    for (typename matx::matrix<T, Rows, Cols>::size_type i = 0; i < Rows; i++) {
        for (typename matx::matrix<T, Rows, Cols>::size_type j = 0; j < Cols; j++) {
            result.at(i, j) = -m.at(i, j);
        }
    };
    return result;
}

// scalar * m
template <typename T, typename U, std::size_t Rows, std::size_t Cols>
auto operator*(U const& scalar, matx::matrix<T, Rows, Cols> const& m) -> matx::matrix<T, Rows, Cols>
{
    matx::matrix<T, Rows, Cols> result{};
    for (typename matx::matrix<T, Rows, Cols>::size_type i = 0; i < Rows; i++) {
        for (typename matx::matrix<T, Rows, Cols>::size_type j = 0; j < Cols; j++) {
            result.at(i, j) = m.at(i, j) * static_cast<T>(scalar);
        }
    };
    return result;
}
template <typename T, typename U, std::size_t Rows, std::size_t Cols>
auto operator*(matx::matrix<T, Rows, Cols> const& m, U const& scalar) -> matx::matrix<T, Rows, Cols>
{
    matx::matrix<T, Rows, Cols> result{};
    for (typename matx::matrix<T, Rows, Cols>::size_type i = 0; i < Rows; i++) {
        for (typename matx::matrix<T, Rows, Cols>::size_type j = 0; j < Cols; j++) {
            result.at(i, j) = m.at(i, j) * static_cast<T>(scalar);
        }
    };
    return result;
}

// lhs * rhs
template <typename T, std::size_t RowsLhs, std::size_t ColsLhsRowsRhs, std::size_t ColsRhs>
auto operator*(matx::matrix<T, RowsLhs, ColsLhsRowsRhs> const& lhs, matx::matrix<T, ColsLhsRowsRhs, ColsRhs> const& rhs)
    -> matx::matrix<T, RowsLhs, ColsRhs>
{
    matx::matrix<T, RowsLhs, ColsRhs> result{};
    for (typename matx::matrix<T, RowsLhs, ColsRhs>::size_type i = 0; i < RowsLhs; i++) {
        for (typename matx::matrix<T, RowsLhs, ColsRhs>::size_type j = 0; j < ColsRhs; j++) {
            T val{};
            for (typename matx::matrix<T, RowsLhs, ColsRhs>::size_type k = 0; k < ColsLhsRowsRhs; k++) {
                val += lhs.at(i, k) * rhs.at(k, j);
            }
            result.at(i, j) = val;
        }
    };
    return result;
}
#endif
