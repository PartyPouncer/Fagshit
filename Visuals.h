<<<<<<< HEAD
#pragma once

struct GlowObject_t {
	CBaseEntity*	m_pEntity;					// 0
	Vector			m_vGlowColor;				// 4
	float			m_flGlowAlpha;				// 16
	unsigned char   junk[ 16 ];					// 20
	bool			m_bRenderWhenOccluded;		// 36
	bool			m_bRenderWhenUnoccluded;	// 37
	bool			m_bFullBloomRender;			// 38
	unsigned char   junk2[ 13 ];				// 39
};

class CVisuals
{
public:
	void Run( );
	void Watermark();
	void NightMode();
	void Timestamp();
	void BulletTraceOverlay( CBaseEntity* entity, Color color );
	bool EntityIsInvaild( CBaseEntity* Entity);
	void DrawGlow();
private:
	bool InGame();

	void DrawDLight(CBaseEntity* pEnt, Color	colore);
	void PlayerESP( int index );
	int bomber;
	void WorldESP( int index );
	void DrawWarnings();
	void EspBox(CBaseEntity * pEntityPlayer, Color clr);
	bool GetBox(CBaseEntity * entity, int & x, int & y, int & w, int & h);
	void bombtimer(CBaseEntity * pEntity);
	void DrawEntity(CBaseEntity * entity, const char * string, Color color);
	void DrawEntity2(CBaseEntity * entity, const char * string, Color color);
	void DrawThrowable(CBaseEntity * throwable, ClientClass * client);
	void DrawOnFloor(CBaseEntity * throwable, ClientClass * client);
	void FovCrosshair();
	void BulletTrace( CBaseEntity* entity, Color color );
	void HitBoxDot(CBaseEntity* entity, Color color);
	void PlayerBox( float x, float y, float w, float h, Color clr );
	void CornerBox(float x, float y, float iWidth, float iMiddle, Color colDraw, float scaling);
	void DBox(Vector pos, CBaseEntity * entity, Color clr);
	void HealthBar( Vector bot, Vector top, float health );
	void Skeleton( CBaseEntity *Entity, Color color );
	void DrawWeapon(int topx, int topy, HFont hFont, CBaseEntity * pEnt);
	void DrawHitbox( matrix3x4a_t* matrix, Vector bbmin, Vector bbmax, int bone, Color color );
	void Hitboxes( CBaseEntity *Entity, Color color );
	void pSpecList();
	void DrawFOVCrosshair();
	void Nightmode();
	void DrawCrosshair( Color color );
=======
#pragma once

struct GlowObject_t {
	CBaseEntity*	m_pEntity;					// 0
	Vector			m_vGlowColor;				// 4
	float			m_flGlowAlpha;				// 16
	unsigned char   junk[ 16 ];					// 20
	bool			m_bRenderWhenOccluded;		// 36
	bool			m_bRenderWhenUnoccluded;	// 37
	bool			m_bFullBloomRender;			// 38
	unsigned char   junk2[ 13 ];				// 39
};

class CVisuals
{
public:
	void Run( );
	void Watermark();
	void NightMode();
	void Timestamp();
	void BulletTraceOverlay( CBaseEntity* entity, Color color );
	bool EntityIsInvaild( CBaseEntity* Entity);
	void DrawGlow();
private:
	bool InGame();

	void DrawDLight(CBaseEntity* pEnt, Color	colore);
	void PlayerESP( int index );
	int bomber;
	void WorldESP( int index );
	void DrawWarnings();
	void EspBox(CBaseEntity * pEntityPlayer, Color clr);
	bool GetBox(CBaseEntity * entity, int & x, int & y, int & w, int & h);
	void bombtimer(CBaseEntity * pEntity);
	void DrawEntity(CBaseEntity * entity, const char * string, Color color);
	void DrawEntity2(CBaseEntity * entity, const char * string, Color color);
	void DrawThrowable(CBaseEntity * throwable, ClientClass * client);
	void DrawOnFloor(CBaseEntity * throwable, ClientClass * client);
	void FovCrosshair();
	void BulletTrace( CBaseEntity* entity, Color color );
	void HitBoxDot(CBaseEntity* entity, Color color);
	void PlayerBox( float x, float y, float w, float h, Color clr );
	void CornerBox(float x, float y, float iWidth, float iMiddle, Color colDraw, float scaling);
	void DBox(Vector pos, CBaseEntity * entity, Color clr);
	void HealthBar( Vector bot, Vector top, float health );
	void Skeleton( CBaseEntity *Entity, Color color );
	void DrawWeapon(int topx, int topy, HFont hFont, CBaseEntity * pEnt);
	void DrawHitbox( matrix3x4a_t* matrix, Vector bbmin, Vector bbmax, int bone, Color color );
	void Hitboxes( CBaseEntity *Entity, Color color );
	void pSpecList();
	void DrawFOVCrosshair();
	void Nightmode();
	void DrawCrosshair( Color color );
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f
};