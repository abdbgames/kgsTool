#include "server.h"
#include "misc.h"

/*
* ------------------------------------
* MANAGER:
* ----------------------------------*/

DedicatedServerManager::DedicatedServerManager()
{

}

DedicatedServerManager::~DedicatedServerManager()
{

}

void DedicatedServerManager::startAll()
{

}

void DedicatedServerManager::stopAll()
{

}

void DedicatedServerManager::resetAll()
{

}

void DedicatedServerManager::updateAll()
{

}

void DedicatedServerManager::forceSerialiseAll()
{

}

bool DedicatedServerManager::forceRemove(const std::string *name)
{
	return false;
}

/*
 * ------------------------------------
 * NON PLATFORM SPECIFIC:
 * ----------------------------------*/

DedicatedServer::DedicatedServer(const char *name, DedicatedServerManager *root) : m_root(root)
{
	if (m_data.find("name") != m_data.end())
	{
		printf("There is already a server named \"%s\" running.\nPlease give it a new name and try again");
		destroy();
		return;
	}

	m_data["name"] = new std::string(name);
}

DedicatedServer::~DedicatedServer()
{
	forceSerialise();
}

void DedicatedServer::destroy()
{
	if (!m_root->forceRemove(m_data["name"]))
		KGprintError("if (!m_root->forceRemove(m_data[\"name\"]))", "Failed to remove server from list", "The server list may have corrupted or the server was not input to it correctly!",
			"This is an internal error, not generated by the user.", &m_data, this, m_root, "severe");

	delete this;
}

void DedicatedServer::forceSerialise()
{

}

/*
* ------------------------------------
* PLATFORM SPECIFIC:
* ----------------------------------*/


void DedicatedServer::start()
{

}

void DedicatedServer::close()
{

}

void DedicatedServer::reset()
{

}

void DedicatedServer::showToggle()
{

}

void DedicatedServer::update()
{

}