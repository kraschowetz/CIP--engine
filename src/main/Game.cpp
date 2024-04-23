#include "Game.h"

#include <iostream>

void Game::start()
{
    /*
        VOID START:

        -set running bool to true

        -init SDL & catch errors
        -init window & catch errors

        set openGL attributs

        init renderer & catch errors

        set renderer blend mode to blend

        init root

        run()

    */
    running = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "ERROR! failed to init SDL\n"
                  << "SDL ERROR: "
                  << SDL_GetError();
    }

    window = SDL_CreateWindow(
        "CIPÓ Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        0);
    if (!window)
    {
        std::cout << "ERROR! failed to create window\n"
                  << "SDL ERROR: "
                  << SDL_GetError();
    }

    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MINOR_VERSION, 3);

    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "ERROR! failed to create renderer\n"
                  << "SDL ERROR: "
                  << SDL_GetError();
    }

    SDL_SetRenderDrawBlendMode(
        renderer,
        SDL_BLENDMODE_BLEND);

    root = new Node();

    // dbg//
    Chunk::collisions.push_back(
        new Collider()
    );

    //entity setup
    e = new Node();
    e->setSize(Vector2(32.f, 32.f));
    root->addChild(e);
    e->addChild(new Collider(e));
    e->translate(Vector2(10.f, 10.f));

    //collider setup
    Node* col = new Node();
    col->setSize(Vector2(128.f, 32.f));
    Collider* c = new Collider(col);
    root->addChild(col);
    col->addChild(c);
    col->translate(Vector2(0.f, 400.f));
    ////
    run();
}

void Game::stop()
{
    /*
        VOID STOP:

        -destroy window & renderer
        -set window & renderer to nullptr

        -set running bool to false
    */
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = nullptr;
    renderer = nullptr;

    running = false;
}

void Game::run()
{
    /*
        VOID RUN:

        -create deltaTime timer

        while running:
            poll events()
            update()

            convert timer time from ticks to seconds

            render()

        stop the game after running()
    */
    Timer deltaTimer;
    deltaTimer.start();

    while (running)
    {
        pollEvents();
        update(deltaTime);

        deltaTime = static_cast<float>(
            deltaTimer.getTicks() / 1000.f);
        deltaTimer.start();

        render();
    }

    stop();
}

void Game::pollEvents()
{
    /*
        VOID POLL EVENTS:

        -call InputHandler event polling

        -quit game if quit button is pressed
    */
    SDL_Event e;
    SDL_PollEvent(&e);

    input.pollEvents(e);

    switch (e.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    }
}

void Game::update(float delta)
{
    root->update(delta);

    // dbg//
    Vector2 dir = Vector2();
    if (input.getKeyPressed(SDLK_LEFT))
    {
        dir.x -= 1;
    }
    if (input.getKeyPressed(SDLK_RIGHT))
    {
        dir.x += 1;
    }
    if (input.getKeyPressed(SDLK_DOWN))
    {
        dir.y += 1;
    }
    if (input.getKeyPressed(SDLK_UP))
    {
        dir.y -= 1;
    }
    e->translate(e->getPosition() + dir.normalized() * 128 * delta);
    ////
    input.update();
}

void Game::render()
{
    /*
        VOID RENDER:

        -clear renderer

        -render game ojects

        -set render color to black
        -diplay rendered objects
    */
    SDL_RenderClear(renderer);

    root->render(renderer);

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        255);

    SDL_RenderPresent(renderer);
}
