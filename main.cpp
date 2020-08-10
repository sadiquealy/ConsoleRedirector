#include <iostream>
// redirecting cout's output thrrough its stream buffer
#include <fstream>  // std::ofstream
#include <iostream> // std::streambuf, std::cout
using namespace std;

/**
 * Redirect console output to a file passed as arg
 *
 * \param[in] file file name to which console  output has to be re directed
 * \return file pointer of the file name passed.
 */
FILE *RedirectConsoleToFile(const char *file) {
  FILE *fp = freopen(file, "r", stdin);
  return fp;
}

/**
 * Resets console output back to stdout if it it is redirected to file
 */
void ResetConsoleOutput(void) { freopen("CON", "r", stdin); }
int main() {

#if 0
  FILE *fp = RedirectConsoleToFile("C:\\BKP\\test.txt");
  int age = 0;
  char name[100];
  cout << "\nEnter your name:!" << endl;
  cin >> name;
  cout << "\nEnter your age:!" << endl;
  cin >> age;
  cout << "name is" << name;
  cout << "age is" << age;
  fclose(fp);
  ResetConsoleOutput();
  std::cout.flush();

  cout << "\nafter Enter your name:!" << endl;
  cin >> name;
  cout << "\nafter Enter your age:!" << endl;
  cin >> age;
  cout << "name is" << name;
  cout << "age is" << age;
#endif

  std::streambuf *psbuf, *backup;
  std::ofstream filestr;
  filestr.open("test.txt");

  backup = std::cout.rdbuf(); // back up cout's streambuf

  psbuf = filestr.rdbuf(); // get file's streambuf
  std::cout.rdbuf(psbuf);  // assign streambuf to cout

  std::cout << "This is written to the file";
  printf("\nhello");
  std::cout.rdbuf(backup); // restore cout's original streambuf

  filestr.close();

  std::cout << "after resetting";
  return 0;
}
