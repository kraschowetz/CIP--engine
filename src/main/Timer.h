#pragma once

class Timer{
    //members
    private:
        int startTime;
        int pausedTime;
        bool started;
        bool paused;
    //methods
    public:
        Timer()
            : startTime(0), pausedTime(0),
            started(false), paused(false) {}
        void start();
        void stop();
        void pause();
        void resume();
        int getTicks();

        inline bool isStarted() const {
            return started;
        }
        inline bool isPaused() const {
            return paused;
        }
};