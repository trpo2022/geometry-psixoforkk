#include <ctest.h>
#include <staticlib/geometryshapes.h>
#include <stdlib.h>

CTEST(arithmetic_circle_area, simple_area)
{
    double input_array[3] = {3, 4, 5};
    double result = CircleArea(input_array);
    double expected = 78.539750;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(arithmetic_circle_perimeter, simple_perimeter)
{
    double input_array[3] = {3, 4, 5};
    double result = CirclePerimeter(input_array);
    double expected = 31.415900;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(arithmetic_triangle_area, simple_area)
{
    double input_array[6] = {-3, -2, -1, 0.5, -3, 2};
    double result = TriangleArea(input_array);
    double expected = 4;
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(arithmetic_triangle_perimeter, simple_area)
{
    double input_array[6] = {-3, -2, -1, 0.5, -3, 2};
    double result = TrianglePerimeter(input_array);
    double expected = 9.701562;
    ASSERT_DBL_NEAR(expected, result);
}
