/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * prototypeScreen.cpp
 *
 */

#include "prototypeScreen.h"

PrototypeScreen::PrototypeScreen()
{
}

PrototypeScreen::~PrototypeScreen()
{
	CleanUp();
}

void
PrototypeScreen::EventHandler(SDL_Event* event)
{
}

void
PrototypeScreen::Update()
{
}

void
PrototypeScreen::Render()
{
	Window::Clear();
	Window::Present();
}

void
PrototypeScreen::CleanUp()
{
}
