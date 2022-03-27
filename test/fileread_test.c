#include <ctest.h>
#include <staticlib/fileread.h>
#include <stdlib.h>

CTEST(input_symbol, output_symbol)
{
    int result = StrNumber('1');
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
