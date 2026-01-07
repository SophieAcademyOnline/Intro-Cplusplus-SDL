    #include "Game.h"


    const int SCREEN_WIDTH = 768;
    const int SCREEN_HEIGHT = 480;

    Game::Game()
    {

    }

    bool Game::Initialize()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return false;
        }
        mWindow = SDL_CreateWindow(
            "Academy Online C++ Tutorial",
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_RESIZABLE
        );

        if (!mWindow)
        {
            SDL_Log("Unable to create window: %s", SDL_GetError());
            return false;
        }

        mRenderer = SDL_CreateRenderer(mWindow, NULL);
        if (!mRenderer)
        {
            SDL_Log("Unable to create renderer: %s", SDL_GetError());
            return false;
        }
        bIsRunning = true;
        return true;
    }

    void Game::RunLoop()
    {
        Uint64 prevTicks = SDL_GetTicks();
        while (bIsRunning)
        {
            Uint64 currentTicks = SDL_GetTicks();
            float deltaTime = (currentTicks - prevTicks) / 1000.0f;
            prevTicks = currentTicks;

            ProcessInput();
            UpdateGame(deltaTime);
            GenerateOutput();
        }
    }

    void Game::ProcessInput()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                bIsRunning = false;
        }

        const bool* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_ESCAPE])
            bIsRunning = false;
    }
    void Game::Shutdown()
    {
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }


    void Game::UpdateGame(float deltaTime)
    {
    }


    void Game::GenerateOutput()
    {
 
    }   