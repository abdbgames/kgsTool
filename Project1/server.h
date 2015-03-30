#ifndef server_h
#define server_h

#include <map>
#include <string>

// http://www.cplusplus.com/forum/lounge/17684/

class DedicatedServerManager;

class DedicatedServer
{
public:
	DedicatedServer(const char *name, DedicatedServerManager *root);
	~DedicatedServer();

	void start();
	void close();
	void reset();
	void showToggle();
	void update();
	void destroy();
	void forceSerialise();

private:
	std::map<std::string, std::string*> m_data;

	int m_rebootCount, m_maxRebootsUpdate, m_maxRebootsStop;

	DedicatedServerManager *m_root;
};

class DedicatedServerManager
{
public:
	DedicatedServerManager();
	~DedicatedServerManager();

	void startAll();
	void stopAll();
	void resetAll();
	void updateAll();
	void forceSerialiseAll();

	bool forceRemove(const std::string *name);

private:
	std::map<std::string, DedicatedServer*> m_servers;
};

#endif /* server_h */