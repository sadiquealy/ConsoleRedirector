#ifndef CONSOLEREDIRECTOR_H
#define CONSOLEREDIRECTOR_H

/** Class for redirecting console to a specified file.
 */

#include <string>

using namespace std;

class ConsoleRedirector {
public:
    /**
     *   Construct a ConsoleRedirector  
     *   @param outFile redirecting file
     *   @param autoReset true if wants to reset console back to stdout when scope ends for the object
     */
    ConsoleRedirector(const string &outFile, bool autoReset = false);
    /**
     *  Resets ConsoleRedirector back to stdout
     */
    void Reset();
    /**
     *  Flushes the contents to redirected file
     */
    void Flush();

    /**
     *   Destructs Console Redirector ; if auto reset is true Reset will be called upon destruction
     *   
     */
    ~ConsoleRedirector();
private:
    const string m_sOutFile;
    bool m_AutoReset;
    FILE *m_pFp ;
};

#endif // CONSOLEREDIRECTOR_H
