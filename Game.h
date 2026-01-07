#pragma once
#include "SDL3/SDL.h"

class Game
{
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

private:
    void ProcessInput();
    void UpdateGame(float deltaTime);
    void GenerateOutput();

    SDL_Window* mWindow = nullptr;  // Spelfönster
    SDL_Renderer* mRenderer = nullptr; // Ritlogik
    bool bIsRunning = false;     // Håller koll på om spelet körs

};
