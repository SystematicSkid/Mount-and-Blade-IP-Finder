#include "sdk.h"

void Init()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	printf("Server IP Finder by Seb @ Aimjunkies.com\n\tMade with <3\n\t\The IP will be printed once every two minutes\n");

	if (!ints.Init())
	{
		MessageBoxA(NULL, "Interfaces: Failed to init.", NULL, NULL);
		return;
	}

	while (true)
	{
		printf("Server IP: %s\n", ints.multplayer_client->GetIP());
		Sleep(120000);
	}
		
}

DWORD __stdcall DllMain(HMODULE dll, DWORD callreason, void* reserved)
{
	if (callreason == DLL_PROCESS_ATTACH)
	{
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);

		return 1;
	}

	return 0;
}