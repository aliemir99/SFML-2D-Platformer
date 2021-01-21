#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Bob.h"
#include "Thomas.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"
using namespace sf;

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	//particle system
	ParticleSystem particleSystem;

	//Thomas and his friend, bob
	Thomas m_Thomas;
	Bob m_Bob;

	// A class to manage levels
	LevelManager m_LevelManager;
	
	//create a sound manager
	SoundManager m_SoundManager;
	
	//the Hud
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Declare a shader for the background
	Shader m_RippleShader;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;

	// Start in full screen mode
	bool m_SplitScreen = false;

	// How much time is left in the current level
	float m_TimeRemaining;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	//the vertex array for the level design
	VertexArray m_VALevel;

	//the 2d array with the map for the level
	//A pointer to a pointer
	int** m_ArrayLevel = NULL;

	//Texture for the background and the level tiles
	Texture m_TextureTiles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	//Load a new level
	void loadLevel();

	//detect collision
	bool detectCollisions(PlayableCharacter& character);

	//make a vector of the best paces to emit sound from
	void populateEmitters(vector <Vector2f>& vSoundEmitters, int** arrayLevel);

	//a vector of vector2f for the fire emitter locations
	vector <Vector2f> m_FireEmitters;
public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};
