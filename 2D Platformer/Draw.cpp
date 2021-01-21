
#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	//update the shader prameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());
	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);

		// Draw the background
		//draw the background compete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_MainView
		m_Window.setView(m_MainView);

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw thomas
		m_Window.draw(m_Bob.getSprite());

		//draw the particle system
		if (particleSystem.running()) {
			m_Window.draw(particleSystem);
		}
	}
	else
	{
		// Split-screen view is active

		// First draw Thomas' side of the screen

		// Switch to background view
		m_Window.setView(m_BGLeftView);

		// Draw the background
		//draw the background compete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_LeftView
		m_Window.setView(m_LeftView);

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Bob.getSprite());

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		//draw the particle system
		if (particleSystem.running()) {
			m_Window.draw(particleSystem);
		}
	

		// Now draw Bob's side of the screen

		// Switch to background view
		m_Window.setView(m_BGRightView);

		// Draw the background
		//draw the background compete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_RightView
		m_Window.setView(m_RightView);

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw bob
		m_Window.draw(m_Bob.getSprite());

		//draw the particle system
		if (particleSystem.running()) {
			m_Window.draw(particleSystem);
		}
	
	}

	// Draw the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing) {
		m_Window.draw(m_Hud.getMessage());
	}


	// Show everything we have just drawn
	m_Window.display();
}