#include "mage/core/engine.hpp"

namespace mage {
    Engine::Engine(int width, int height, const std::string& title)
        : m_width(width)
        , m_height(height)
        , m_title(title)
        , m_running(false)
        , m_deltaTime(0.0f)
        , m_maxFPS(0)
    {
        // initializer list does the work
    }

    Engine::~Engine() {
        shutdown();
    }

    void Engine::init() {
        InitWindow(m_width, m_height, m_title.c_str());
        /*ToggleBorderlessWindowed();*/
        SetTargetFPS(m_maxFPS); 
        m_running = true;
    }

    void Engine::run() {
        init();

        while (isRunning() && !WindowShouldClose()) {
            m_deltaTime = GetFrameTime();
            update();
            render();
        }

        shutdown();
    }

    void Engine::update() {
        // process game logic
    }

    void Engine::render() {
        BeginDrawing();
        //TODO: add to config
        ClearBackground(RAYWHITE);
        DrawText("MAGE ENGINE", 10, 10, 40, BLACK);
        DrawFPS(10, 50);

        std::string text = "Monitor Index: " + std::to_string(GetCurrentMonitor());
        DrawText(text.c_str(), 10, 100, 40, BLACK);

        
        EndDrawing();
    }

    void Engine::shutdown() {
        CloseWindow();
        m_running = false;
    }
}
