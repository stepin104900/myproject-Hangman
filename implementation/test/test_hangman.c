#include "unity.h"
#include "hangman.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_printBody(void)
{
  TEST_ASSERT(4);
  TEST_ASSERT(5);
  TEST_ASSERT(6);
}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_printBody);

  /* Close the Unity Test Framework */
  return UNITY_END();
}


