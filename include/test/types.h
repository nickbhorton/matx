#ifndef MATX_TEST_TYPES_HEADER
#define MATX_TEST_TYPES_HEADER

#include <limits>

TEST_CASE("computer graphics types useage")
{
    matx::mat2 m(matx::rotation2<double>(M_PI / 2.0));
    matx::vec2 v(std::array<double, 2>({1.0, 0.0}));
    auto v2 = m * v;
    CHECK(abs(v2.at(0) - 0.0) < std::numeric_limits<double>::epsilon());
    CHECK(abs(v2.at(1) - 1.0) < std::numeric_limits<double>::epsilon());
}

#endif
