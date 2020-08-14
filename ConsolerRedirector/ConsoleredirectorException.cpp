#include "consoleredirectorexception.h"
#include <string.h>

ConsoleRedirectorException::ConsoleRedirectorException(const std::string &message,
                                                       bool bSysMsg) noexcept :m_sMsg(message)
{
    if (bSysMsg) {
        m_sMsg.append(": ");
        m_sMsg.append(strerror(errno));
    }
}

ConsoleRedirectorException::~ConsoleRedirectorException() noexcept
{

}
