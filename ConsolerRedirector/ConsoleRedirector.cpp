#include "consoleredirector.h"
#include "consoleredirectorexception.h"
ConsoleRedirector::ConsoleRedirector(const string& outFile, bool autoReset)
	: m_sOutFile(outFile), m_AutoReset(autoReset), m_pFp(nullptr) {

	m_pFp = freopen(outFile.c_str(), "w", stdout);
	if (!m_pFp) {
		Reset();
		throw ConsoleRedirectorException("Exception occured;Unable to redirect console to file", true);
	}
}

void ConsoleRedirector::Reset()
{
	if (!freopen("con", "w", stdout))
	{
		throw ConsoleRedirectorException("Exception occured;Unable to reset ConsoleRedirector", true);
	}

	if (m_pFp != nullptr)
	{
		m_pFp = nullptr;
	}
}

ConsoleRedirector::~ConsoleRedirector()
{
	if (m_AutoReset)
		Reset();
}


void ConsoleRedirector::Flush()
{
	if (m_pFp != nullptr)
	{
		if (fflush(m_pFp))
		{
			throw ConsoleRedirectorException("Unable to flush the file", true);
		}
	}
	else
	{
		throw ConsoleRedirectorException("Flush called with a bad file", false);
	}
}
