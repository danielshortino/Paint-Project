#include "my-sound.h"

void MySound::Play(LPCWSTR filename, HMODULE hmod, DWORD fdwsound)
{
	PlaySound(filename, hmod, fdwsound);
}

