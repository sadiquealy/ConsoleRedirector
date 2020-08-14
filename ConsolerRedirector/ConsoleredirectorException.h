#ifndef CONSOLEREDIRECTOREXCEPTION_H
#define CONSOLEREDIRECTOREXCEPTION_H
#include <string>

using namespace std;
/**
 *   Signals a problem with the execution of a ConsoleRedirector call.
 */

class ConsoleRedirectorException : public std::exception {
public:
    /**
   *   Construct a ConsoleRedirectorException with a explanatory message.
   *   @param message explanatory message
   *   @param bSysMsg true if system message (from strerror(errno))
   *   should be postfixed to the user provided message
   */
    ConsoleRedirectorException(const std::string &message,
                               bool bSysMsg = false) noexcept;

    /** Destructor.
   * Virtual to allow for subclassing.
   */
    virtual ~ConsoleRedirectorException() noexcept;

    /** Returns a pointer to the (constant) error description.
   *  @return A pointer to a \c const \c char*. The underlying memory
   *          is in posession of the \c Exception object. Callers \a must
   *          not attempt to free the memory.
   */
    virtual const char *what() const noexcept {  return m_sMsg.c_str(); }

protected:
    /** Error message.
   */
    std::string m_sMsg;
};
#endif // CONSOLEREDIRECTOREXCEPTION_H
