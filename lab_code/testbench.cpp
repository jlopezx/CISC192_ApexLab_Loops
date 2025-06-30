//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include "apex_code.h"
#include <fstream>
#include <iostream>

using namespace std;

static int testNum = 0;
static int testsCorrect = 0;

static int funcTestNum = 0;
static int funcTestCorrect = 0;

#define TEST_FUNC_PTR void (*test_func)(stringstream &, stringstream &)
void test(TEST_FUNC_PTR, const string &input, const string &expected) {
  funcTestNum++;
  testNum++;

  stringstream in_stream(input);
  stringstream out_stream;
  test_func(in_stream, out_stream);

  cout << "Test " << testNum << ": ";

  if (expected == out_stream.str()) {
    cout << "PASS" << endl;
    testsCorrect++;
    funcTestCorrect++;
  } else {
    cout << "With input \"" << input << "\" expected output \"" << expected
         << "\", received \"" << out_stream.str() << "\"" << endl;
  }
}

void start_tests(string startFuncName) {
  cout << "----- Start of testing " << startFuncName << " -----" << endl;

  funcTestNum = 0;
  funcTestCorrect = 0;
}

void end_tests(string endFuncName) {
  if (funcTestNum == funcTestCorrect) {
    cout << "----- All tests passed for " << endFuncName << "! -----" << endl;
  } else {
    cout << "----- Some tests failed for " << endFuncName << " :( -----"
         << endl;
  }
  cout << endl;
}

void end_all_tests() {
  if (testsCorrect == testNum) {
    cout << "All tests passed! Let's goooo" << endl;
  } else {
    cout << "Some tests failed. Keep trying!" << endl;
  }
}

int main() {
  // To add a test case, duplicate one of the test lines below
  // modify input with the first string, and the expected output
  // in the second string.
  start_tests("email_concat");
  test(email_concat, "me@hotmail.com donna@yahoo.com mrt43@sbcglobal.net END",
       "me@hotmail.com:donna@yahoo.com:mrt43@sbcglobal.net:");
  test(email_concat, "thor@getoffmyplanet.com END", "thor@getoffmyplanet.com:");
  test(email_concat, "END", "");
  end_tests("email_concat");

  start_tests("donation_total");
  test(donation_total, "10 10 10 -3", "Total donations made $30.00");
  test(donation_total, "20.50 50 125 101.1 80 21 -1",
       "Send a t-shirt\nSend a t-shirt\nTotal donations made $397.60");
  test(donation_total, "-10", "Total donations made $0.00");
  end_tests("donation_total");

  start_tests("average_books_checked_out");
  test(average_books_checked_out, "10 20 10 20 10 20 10 20 10 20 10 20",
       "Average monthly circulation: 15 books\n");
  test(average_books_checked_out,
       "1800 2348 2485 5030 5644 5785 3043 4598 3940 3943 4002 3400",
       "Average monthly circulation: 3834 books\nExtend hours!!");
  test(average_books_checked_out,
   "1269 1270 1271 1272 1273 1274 1275 1276 1277 1278 1279 1",
   "Average monthly circulation: 1167 books\n");
  test(average_books_checked_out,
   "10000 30000 3000 3000 6000 7000 8000 9000 1000 1 2 3",
   "Average monthly circulation: 6417 books\n");
  end_tests("average_books_checked_out");

  start_tests("rectangles");
  test(rectangles, "3 5 X", "X X X \nX X X \nX X X \nX X X \nX X X \n");
  test(rectangles, "1 1 ?", "? \n");
  end_tests("rectangles");

  end_all_tests();
  return 0;
}
