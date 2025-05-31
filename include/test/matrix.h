#ifndef MATX_TEST_MATRIX_HEADER
#define MATX_TEST_MATRIX_HEADER

TEST_CASE("matrix::at(i, j) 1d array constructor")
{
    // square
    {
        matx::matrix<float, 2, 2> m(std::array<float, 4>({1, 2, 3, 4}));
        CHECK(m.at(0, 0) == 1);
        CHECK(m.at(0, 1) == 2);
        CHECK(m.at(1, 0) == 3);
        CHECK(m.at(1, 1) == 4);

        m.at(0, 0) = 5;
        CHECK(m.at(0, 0) == 5);
    }

    // col vector
    {
        matx::matrix<float, 2, 1> m(std::array<float, 2>({1, 2}));
        CHECK(m.at(0, 0) == 1);
        CHECK(m.at(1, 0) == 2);

        m.at(0, 0) = 5;
        CHECK(m.at(0, 0) == 5);
    }
}

TEST_CASE("matrix::at(i, j) 2d array constructor")
{
    // square
    {
        matx::matrix<float, 2, 2> m(std::array<std::array<float, 2>, 2>({{{1, 2}, {3, 4}}}));
        CHECK(m.at(0, 0) == 1);
        CHECK(m.at(0, 1) == 2);
        CHECK(m.at(1, 0) == 3);
        CHECK(m.at(1, 1) == 4);

        m.at(0, 0) = 5;
        CHECK(m.at(0, 0) == 5);
    }

    // col vector
    {
        matx::matrix<float, 2, 1> m(std::array<std::array<float, 1>, 2>({{{1}, {2}}}));
        CHECK(m.at(0, 0) == 1);
        CHECK(m.at(1, 0) == 2);

        m.at(0, 0) = 5;
        CHECK(m.at(0, 0) == 5);
    }
}

TEST_CASE("identity creator")
{
    auto m = matx::identity<float, 2>();
    CHECK(m.at(0, 0) == 1);
    CHECK(m.at(0, 1) == 0);
    CHECK(m.at(1, 0) == 0);
    CHECK(m.at(1, 1) == 1);
}

TEST_CASE("matrix::operator+")
{
    // square
    {
        matx::matrix<float, 2, 2> lhs(std::array<float, 4>({1, 2, 3, 4}));
        matx::matrix<float, 2, 2> rhs(std::array<float, 4>({1, 2, 3, 4}));

        matx::matrix<float, 2, 2> result = lhs + rhs;
        for (size_t i = 0; i < result.rows(); i++) {
            for (size_t j = 0; j < result.cols(); j++) {
                CHECK(result.at(i, j) == lhs.at(i, j) + rhs.at(i, j));
            }
        }
    }

    // col vector
    {
        matx::matrix<float, 2, 1> lhs(std::array<float, 2>({1, 2}));
        matx::matrix<float, 2, 1> rhs(std::array<float, 2>({1, 2}));

        matx::matrix<float, 2, 1> result = lhs + rhs;
        for (size_t i = 0; i < result.rows(); i++) {
            for (size_t j = 0; j < result.cols(); j++) {
                CHECK(result.at(i, j) == lhs.at(i, j) + rhs.at(i, j));
            }
        }
    }
}

TEST_CASE("matrix::operator-")
{
    // square
    {
        matx::matrix<float, 2, 2> lhs(std::array<float, 4>({1, 2, 3, 4}));
        matx::matrix<float, 2, 2> rhs(std::array<float, 4>({1, 2, 3, 4}));

        matx::matrix<float, 2, 2> result = lhs - rhs;
        for (size_t i = 0; i < result.rows(); i++) {
            for (size_t j = 0; j < result.cols(); j++) {
                CHECK(result.at(i, j) == lhs.at(i, j) - rhs.at(i, j));
            }
        }
    }

    // col vector
    {
        matx::matrix<float, 2, 1> lhs(std::array<float, 2>({1, 2}));
        matx::matrix<float, 2, 1> rhs(std::array<float, 2>({1, 2}));

        matx::matrix<float, 2, 1> result = lhs - rhs;
        for (size_t i = 0; i < result.rows(); i++) {
            for (size_t j = 0; j < result.cols(); j++) {
                CHECK(result.at(i, j) == lhs.at(i, j) - rhs.at(i, j));
            }
        }
    }
}

#endif
