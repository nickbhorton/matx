#ifndef MATX_CORE_GRAPHICS_HEADER
#define MATX_CORE_GRAPHICS_HEADER

#include <cmath>

namespace matx
{
template <typename T> auto rotation2(T theta) -> matx::matrix<T, 2, 2>
{
    return matx::matrix<T, 2, 2>(std::array<T, 4>(
        {static_cast<T>(std::cos(static_cast<double>(theta))),
         -static_cast<T>(std::sin(static_cast<double>(theta))),
         static_cast<T>(std::sin(static_cast<double>(theta))),
         static_cast<T>(std::cos(static_cast<double>(theta)))}
    ));
}
} // namespace matx

#endif
