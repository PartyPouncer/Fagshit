#pragma once

<<<<<<< HEAD
class IVPanel
{
public:
	unsigned int GetPanel(int type)
	{
		typedef unsigned int(__thiscall *tGetPanel)(void*, int type);
		return U::GetVFunc< tGetPanel >(this, 1)(this, type);
	}

	const char* GetName(unsigned int vguiPanel)
	{
		typedef const char* (__thiscall* OriginalFn)(PVOID, unsigned int);
		return U::GetVFunc< OriginalFn >(this, 36)(this, vguiPanel);
	}
=======
class IVPanel
{
public:
	unsigned int GetPanel(int type)
	{
		typedef unsigned int(__thiscall *tGetPanel)(void*, int type);
		return U::GetVFunc< tGetPanel >(this, 1)(this, type);
	}

	const char* GetName(unsigned int vguiPanel)
	{
		typedef const char* (__thiscall* OriginalFn)(PVOID, unsigned int);
		return U::GetVFunc< OriginalFn >(this, 36)(this, vguiPanel);
	}
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
};