#ifndef CONSOLEREDIRECTOR_H
#define CONSOLEREDIRECTOR_H
#include <string>
using namespace std;
class ConsoleRedirector {
public:
  ConsoleRedirector(const string &outFile, bool autoReset = false);

private:
  const string m_sOutFile;
  bool m_AutoReset;
};

#endif // CONSOLEREDIRECTOR_H
