#include <ctest.h>
#include <staticlib/fileread.h>
#include <stdlib.h>

CTEST(arithmetic_circle_area, simple_area)
{
    int result = StrNumber('1');
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
