#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define WINDOW_TITLE "Boris the Tomato"
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

#include<SDL.h>
#include<SDL_mixer.h>
#include<iostream>
#include <ctime>
#include"Operations.h"
#include "SDL_Window_Manager.h"
#include"BorisGame.h"
#include"TextureManager.h"
#include"Menu.h"
#include"Level.h"
#include"PauseMenu.h"
#include"SoundManager.h"
#include"GameOver.h"
#include"Options.h"
#include"FontManager.h"
#include"Util.h"
#include"Intro.h"
#include"HighScoreScreen.h"

using namespace std;

//A pointer to the only instance of "SDL_Window_Manager". 
static SDL_Window_Manager* windowManager = SDL_Window_Manager::getInstance();

//A pointer to the only instance of "BorisGame".
static BorisGame* game = BorisGame::GetInstance();

//Load all necessary files into memory (fonts, sounds, images etc.)
//"renderer" parameter represents the renderer of the sdl window.
void ResourceSetup(SDL_Renderer* renderer)
{
	//A pointer to the only instance of "FontManager".
	FontManager* fontmanager = FontManager::GetInstance();
	//Pointers to instances of "Font" which represent the fonts "consolas" and "calibri".
	Font* consolas = new Font("Fonts\\consolaz.ttf", 50, renderer);
	Font* calibri = new Font("Fonts\\calibri.ttf", 50, renderer, { 136,0,21,255 }, { 255,255,255,255 });
	//Add the two font pointers to the font manager so they can be referenced for use later.
	fontmanager->AddFont("Consolas", consolas);
	fontmanager->AddFont("Calibri", calibri);

	//A pointer to the only instance of "TextureManager".
	TextureManager* texturemanager = TextureManager::getInstance();
	//Give the renderer pointer to the "texturemanager" so it can be used to create instances of "SDL_Texture".
	texturemanager->SetRenderer(renderer);
	//Load various image files as textures which are stored in the texture manager in order to be referenced later.
	texturemanager->AddTexture("Menu_Background", "Textures\\menuTemp.png");
	texturemanager->AddTexture("play_game", "Textures\\play_game.png");
	texturemanager->AddTexture("Level_Background", "Textures\\levelTemp.png");
	texturemanager->AddTexture("quit", "Textures\\quit.png");
	texturemanager->AddTexture("resume_game", "Textures\\resume_game.png");
	texturemanager->AddTexture("gameover", "Textures\\game_over_screen.png");
	texturemanager->AddTexture("replay", "Textures\\replay.png");
	texturemanager->AddTexture("options", "Textures\\options.png");
	texturemanager->AddTexture("back", "Textures\\back.png");
	texturemanager->AddTexture("scissors", "Textures\\scissors.png");
	texturemanager->AddTexture("sunlight", "Textures\\sunlight.png");
	texturemanager->AddTexture("water", "Textures\\water.png");
	texturemanager->AddTexture("inactive_volumebutton", "Textures\\inactive_volumebutton.png");
	texturemanager->AddTexture("active_volumebutton", "Textures\\active_volumebutton.png");
	texturemanager->AddTexture("protruding_leaf", "Textures\\protruding_leaf.png");
	texturemanager->AddTexture("retracted_leaf", "Textures\\retracted_leaf.png");
	texturemanager->AddTexture("bottom", "Textures\\bottom.png");
	texturemanager->AddTexture("health_0", "Textures\\health_0.png");
	texturemanager->AddTexture("health_50", "Textures\\health_50.png");
	texturemanager->AddTexture("health_100", "Textures\\health_100.png");
	texturemanager->AddTexture("health_150", "Textures\\health_150.png");
	texturemanager->AddTexture("health_200", "Textures\\health_200.png");
	texturemanager->AddTexture("intro", "Textures\\intro.png");
	texturemanager->AddTexture("intro_0", "Textures\\intro_0.png");
	texturemanager->AddTexture("intro_1", "Textures\\intro_1.png");
	texturemanager->AddTexture("intro_2", "Textures\\intro_2.png");
	texturemanager->AddTexture("intro_3", "Textures\\intro_3.png");
	texturemanager->AddTexture("intro_4", "Textures\\intro_4.png");

	texturemanager->AddTexture("intro_button", "Textures\\intro_button.png");
	texturemanager->AddTexture("highscore", "Textures\\highscore.png");
	texturemanager->AddTexture("save_high_score", "Textures\\save_high_score.png");
	texturemanager->AddTexture("arrow", "Textures\\arrow.png");
	texturemanager->AddTexture("down_arrow", "Textures\\down_arrow.png");
	texturemanager->AddTexture("save_button", "Textures\\save_button.png");

	//Create textures for the digits 0-9 and add them to the texture manager.
	for (int i = 0; i < 10; i++)
	{
		//Create an "LPCSTR" representation of the value of "i".
		LPCSTR name = Operations::Int_to_LPCSTR(i);
		//Add a texture to the texturemanager which is created using the "Consolas" font and the value of "name".
		texturemanager->AddTexture(name, fontmanager->GetFont("Consolas")->CreateTextTexture(name, SOLID));
	}

	//A pointer to the only instance of "SoundManager".
	SoundManager* soundmanager = SoundManager::GetInstance();
	//Load various sound files and add them to the sound manager in order to reference them later.
	soundmanager->AddSound("click", "Sounds\\mouse_click.wav", SFX);
	soundmanager->AddSound("levelmusic", "Sounds\\Boris_the_Tomato.wav", MUSIC);
	soundmanager->AddSound("gameover", "Sounds\\Boris_Game_Over.wav",MUSIC);
	soundmanager->AddSound("menu", "Sounds\\Boris_Menu.wav",MUSIC);
	soundmanager->AddSound("damage", "Sounds\\baseDamage.wav",SFX);
	soundmanager->AddSound("intro", "Sounds\\Boris_Intro.wav", MUSIC);
	soundmanager->AddSound("collection", "Sounds\\Collection.wav", SFX);
	soundmanager->AddSound("scissors", "Sounds\\scissors.wav",SFX);
	soundmanager->AddSound("protrude", "Sounds\\Protrude_Leaf.wav", SFX);
	soundmanager->AddSound("retract", "Sounds\\Retract_Leaf.wav", SFX);

	//A pointer to the only instance of "SceneManager".
	SceneManager* scenemanager = SceneManager::GetInstance();
	//Create pointers to instances of all the scenes of the game.
	Menu* menu = new Menu();
	Level* level = new Level();
	PauseMenu* pausemenu = new PauseMenu();
	GameOver* gameover = new GameOver();
	Options* options = new Options();
	Intro* intro = new Intro();
	HighScoreScreen* highscorescreen = new HighScoreScreen();
	
	//Add the scenes to the scene manager in order to reference them later.
	scenemanager->AddScene("menu", menu);
	scenemanager->AddScene("level", level);
	scenemanager->AddScene("PauseMenu", pausemenu);
	scenemanager->AddScene("gameover", gameover);
	scenemanager->AddScene("options", options);
	scenemanager->AddScene("intro", intro);
	scenemanager->AddScene("highscore", highscorescreen);

	//Create a folder called "Scores" (if it doesn't already exist) in order to store the player scores.
	Operations::CreateFolder("Scores");

	//Create an appropriate seed for the random number generator.
	time_t* seed = NULL;
	srand((unsigned int)time(seed));
}
int main(int argc, char *args[])
{
	//Attempt to initialise an SDL window.
	if (!windowManager->initWND(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		//End the program if the window cannot be initialised.
		return -1;
	}
	//A pointer to the sdl renderer from the sdl window.
	SDL_Renderer* renderer = windowManager->getSDLRenderer();
	//Call the "ResourceSetup" method to load all necessary resources into memory.
	ResourceSetup(renderer);
	//Initialise the game with the sdl window and renderer.
	game->Initialise(windowManager->getSDLWindow(), renderer);
	//Run the game.
	game->Run();
	//Dispose of the game,
	game->Dispose();
	//End the program.
	return 0;
}