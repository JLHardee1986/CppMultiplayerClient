// may need #include "stdafx.h" in visual studio
#include "pch.h"

// used for multi-threading
#include <process.h>

void serverLoop(void*);
void clientLoop(void);

ServerGame* server;
ClientGame* client;

int main()
{

	// initialize the client
	client = new ClientGame();

	// initialize the server
	server = new ServerGame();

	// create thread with arbitrary argument for the run function
	_beginthread(serverLoop, 0, (void*)12);



	clientLoop();
}

void serverLoop(void* arg)
{
	while (true)
	{
		server->update();
	}
}

void clientLoop()
{
	while (true)
	{
		//do game stuff
	   //will later run client->update();
		client->update();
	}
}