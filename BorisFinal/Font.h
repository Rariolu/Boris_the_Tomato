#ifndef _FONT_H
#define _ FONT_H

#include<SDL_ttf.h>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
#include<iostream>
#include"Texture.h"

//Create an enumeration for the different possible ways of displaying text.
enum TextType { SOLID, BLENDED, SHADED };

using namespace std;

//Create a class representing a specific font.
class Font
{
	public:
		//Constructor, takes file path of font to be loaded, size of the font, and a pointer to the sdl renderer.
		Font(const char* filename,int fontSize,SDL_Renderer* _renderer);
		//Constructor, takes the same parameters as the previous one but also takes sdl colours representing the foreground and background colours.
		Font(const char* filename, int fontSize, SDL_Renderer* _renderer, SDL_Color text_colour, SDL_Color background_colour);
		//Destructor method.
		~Font();
		//Returns a pointer to the "TTF_Font" value which represents the font information in the context of the sdl library.
		TTF_Font* GetFont();
		//A method which creates a texture resembling given text and displays it differently depending on the given "TextType".
		Texture* CreateTextTexture(const char* text, TextType text_type);
	private:
		//A pointer to the "TTF_Font" value which represents the font information in the context of the sdl library.
		TTF_Font* ttfFont = nullptr;
		//A pointer to the sdl renderer used in the current window.
		SDL_Renderer* renderer = nullptr;
		//A value used for the foreground colour of the text.
		SDL_Color textColour = {0, 0, 0, 0};
		//A value used for the background colour of the text.
		SDL_Color backgroundColour = {255, 255, 255, 255};
};

#endif