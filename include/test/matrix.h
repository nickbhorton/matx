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

TEST_CASE("matrix::operator* with scalar")
{
    // square
    {
        matx::matrix<float, 2, 2> m(std::array<float, 4>({1, 2, 3, 4}));
        auto mr = m * 2;
        auto ml = 2 * m;
        CHECK(mr.at(0, 0) == 2);
        CHECK(mr.at(0, 1) == 4);
        CHECK(mr.at(1, 0) == 6);
        CHECK(mr.at(1, 1) == 8);
        CHECK(ml.at(0, 0) == 2);
        CHECK(ml.at(0, 1) == 4);
        CHECK(ml.at(1, 0) == 6);
        CHECK(ml.at(1, 1) == 8);
    }

    // col vector
    {
        {
            matx::matrix<float, 2, 1> m(std::array<float, 2>({1, 2}));
            auto mr = m * 2;
            auto ml = 2 * m;
            CHECK(mr.at(0, 0) == 2);
            CHECK(mr.at(1, 0) == 4);
            CHECK(ml.at(0, 0) == 2);
            CHECK(ml.at(1, 0) == 4);
        }

        {
            matx::matrix<float, 2, 1> m(std::array<float, 2>({1, 2}));
            auto mr = m * 2.f;
            auto ml = 2.f * m;
            CHECK(mr.at(0, 0) == 2);
            CHECK(mr.at(1, 0) == 4);
            CHECK(ml.at(0, 0) == 2);
            CHECK(ml.at(1, 0) == 4);
        }
    }
}

TEST_CASE("matrix::operator* with scalar")
{
    // sqaure
    {
        matx::matrix<float, 2, 2> lhs(std::array<float, 4>({1, 2, 3, 4}));
        matx::matrix<float, 2, 2> rhs(std::array<float, 4>({5, 6, 7, 8}));

        auto r = lhs * rhs;
        CHECK(r.at(0, 0) == 19);
        CHECK(r.at(0, 1) == 22);
        CHECK(r.at(1, 0) == 43);
        CHECK(r.at(1, 1) == 50);
    }
    // matrix * col
    {
        matx::matrix<float, 2, 2> lhs(std::array<float, 4>({1, 2, 3, 4}));
        matx::matrix<float, 2, 1> rhs(std::array<float, 2>({5, 6}));

        auto r = lhs * rhs;
        CHECK(r.at(0, 0) == 17);
        CHECK(r.at(1, 0) == 39);
    }
}

TEST_CASE("matrix::operator- negation")
{
    // sqaure
    {
        matx::matrix<float, 2, 2> m(std::array<float, 4>({1, 2, 3, 4}));

        auto result = -m;
        for (size_t i = 0; i < result.rows(); i++) {
            for (size_t j = 0; j < result.cols(); j++) {
                CHECK(result.at(i, j) == -m.at(i, j));
            }
        }
    }
}

#endif
