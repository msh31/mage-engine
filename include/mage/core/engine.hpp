#pragma once
#include <raylib.h>
#include <string>

namespace mage {
    class Engine {
        public:
            Engine(int width, int height, const std::string& title);
            ~Engine();

            // prevents copying - i always forgert
            Engine(const Engine&) = delete;
            Engine& operator=(const Engine&) = delete;

            void run();
            void stop() { m_running = false; }

            float getDeltaTime() const { return m_deltaTime; }
            bool isRunning() const { return m_running; }

        private:
            void init();
            void update();
            void render();
            void shutdown();

            int m_width;
            int m_height;
            int m_maxFPS;
            std::string m_title;
            bool m_running;
            float m_deltaTime;
    };
}
