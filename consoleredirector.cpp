#include "consoleredirector.h"

ConsoleRedirector::ConsoleRedirector(const string &outFile, bool autoReset)
    : m_sOutFile(outFile), m_AutoReset(autoReset) {

  FILE *fp = freopen(outFile.c_str(), "w", stdout);
  if (fp) {
  }
}
