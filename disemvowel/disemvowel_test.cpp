#include <gtest/gtest.h>

#include "disemvowel.h"


TEST(Disemvowel, HandleEmptyString) {
  char* test_output = disemvowel((char*) "");
  ASSERT_STREQ("", test_output);
  free(test_output);
}

TEST(Disemvowel, HandleNoVowels) {
  char* test_output = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", test_output);
  free(test_output);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* test_output= disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", test_output);
  free(test_output);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* test_output= disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",
		     test_output);
  free(test_output);
}

TEST(Disemvowel, HandlePunctuation) {
  char* test_output= disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ( "n (nxplnd) lphnt!", 
		     test_output);
  free(test_output);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char* disemvowel_string = disemvowel(str);

  ASSERT_STREQ("xyz", disemvowel_string);

  free(str);
  free(disemvowel_string);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
