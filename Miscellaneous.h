#pragma once

class CMiscellaneous
{
public:
	void Initialize();
	void Run();
	void Think();
	void Bunnyhop();
<<<<<<< HEAD
	void AutoStrafe();
	void RageAutoStrafe(CUserCmd * pCmd);
=======
	void AutoStrafe();
	void RageAutoStrafe(CUserCmd * pCmd);
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
	void CircleStrafer(Vector & angles);
	void ChangeName( const char* name );
	void Chatspam();
	void ReadChatspam( const char* fileName );
<<<<<<< HEAD
	void AirStuck();
	void AutoPistol();
	void moonwalk();
	void NameHide();
	void NameSpammer();
	void NameSpammer2();
	void NameSteal();
	void Teleport();
	void LocationSpam();
	void MTeleport();
	void SwastikaSpam();
	void AutoBlocker(CUserCmd* cmd);
	void SetClanTag(const char * tag, const char * name);
	void Walkbot(CUserCmd * pCmd, CBaseEntity * Local);
	void fakelag();
	void Panic();
	void AutoRevolver();
	void svcheats();
	void ForceThirdPerson();
	void RemoveScope();
	void postprozess();
	void FakeWalk(CUserCmd * pCmd, bool & bSendPacket);
=======
	void AirStuck();
	void AutoPistol();
	void moonwalk();
	void NameHide();
	void NameSpammer();
	void NameSpammer2();
	void NameSteal();
	void Teleport();
	void LocationSpam();
	void MTeleport();
	void SwastikaSpam();
	void AutoBlocker(CUserCmd* cmd);
	void SetClanTag(const char * tag, const char * name);
	void Walkbot(CUserCmd * pCmd, CBaseEntity * Local);
	void fakelag();
	void Panic();
	void AutoRevolver();
	void svcheats();
	void ForceThirdPerson();
	void RemoveScope();
	void postprozess();
	void FakeWalk(CUserCmd * pCmd, bool & bSendPacket);
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
	void aniclantag();
private:
	

private:
	bool m_bInitialized = false;
	std::vector<std::string> m_spamlines;
	std::vector<std::string> m_insults;

};

<<<<<<< HEAD
using SetClanTagFn = void(__fastcall*) (const char *tag, const char *name);
extern SetClanTagFn SetClanTagEx;

static float GetTraceFractionWorldProps(Vector start, Vector end);
=======
using SetClanTagFn = void(__fastcall*) (const char *tag, const char *name);
extern SetClanTagFn SetClanTagEx;

static float GetTraceFractionWorldProps(Vector start, Vector end);
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
