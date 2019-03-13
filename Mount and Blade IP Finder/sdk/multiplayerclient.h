#pragma once

class MultiplayerClient
{
public:
	const char* GetIP()
	{
		return *(const char**)(this + 0x178);
	}
};