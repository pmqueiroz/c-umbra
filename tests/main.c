// fix this include
#include "../vcpkg/packages/greatest_x64-linux/include/greatest.h"

TEST should_be_equal_1(void) {
   ASSERT_EQ(1, 1);
   PASS();
}

SUITE(the_suite) { RUN_TEST(should_be_equal_1); }

GREATEST_MAIN_DEFS();

int main(int argc, char** argv) {
   GREATEST_MAIN_BEGIN();

   RUN_SUITE(the_suite);

   GREATEST_MAIN_END();
}
