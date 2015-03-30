#ifndef setup_h
#define setup_h

#include <map>
#include <string>
#include <mysql.h>

class SetupData
{
public:
	SetupData();
	~SetupData();

	bool takeRemainingInput();

private:
	std::map<std::string, std::string*> m_data;
	
	bool m_hasUser, m_hasPass, m_premium;

	std::string collectData(const char *type);
	std::string collectData(const char *format, const char *type);
	std::string collectData(const char *type, const unsigned int &minLength, const unsigned int &maxLength);
	std::string collectData(const char *format, const char *type, const unsigned int &minLength, const unsigned int &maxLength);
	std::string collectPassword();

	bool verifyData(const std::string &key);
	bool testUser();
	bool testUserVerified();

	void save();

	MYSQL *m_sql;
};

#endif //setup_h