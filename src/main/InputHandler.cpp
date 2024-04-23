#include "InputHandler.h"

void InputHandler::pollEvents(SDL_Event e){
    /*
        VOID POLL EVENTS:
        
        -switch event type
        case key_down:
            if key is not in keyPressed vector?
                insert key into Pressed & justPressed vector
        
        case key_up:
            remove key from pressed vector
            add key to justReleased vector
    */
    switch(e.type){
        case SDL_KEYDOWN:
        {
            bool canInsert = true;

            for(int i : keysPressed){
                if(i == e.key.keysym.sym){
                    canInsert = false;
                }
            }
            if(canInsert){
                keysPressed.push_back(
                    e.key.keysym.sym
                );
                keysJustPressed.push_back(
                    e.key.keysym.sym);
            }
        }
        break;

        case SDL_KEYUP:
            for(int i = 0; i < keysPressed.size(); i++){
                if( keysPressed.at(i) == e.key.keysym.sym){
                    keysJustReleased.push_back(
                        e.key.keysym.sym
                    );
                    keysPressed.erase(
                        keysPressed.begin() + i
                    );
                }
            }
        break; 
    }
}

void InputHandler::update(){
    /*
        VOID UPDATE:
            empty keysJustPressed & keysJustReleased vectors
    */
    if(!keysJustPressed.empty()){
        keysJustPressed.clear();
    }
    if(!keysJustReleased.empty()){
        keysJustReleased.clear();
    }
}

bool InputHandler::getKeyPressed(int k){
    /*
        BOOL GET KEY PRESSED:

        return if key is pressed
    */
    for(int i : keysPressed){
        if(i == k){
            return true;
        }
    }
    return false;
}

bool InputHandler::getKeyJustPressed(int k){
    /*
        BOOL GET KEY JUST PRESSED:

        return if key is just pressed
    */
    for(int i : keysJustPressed){
        if(i == k){
            return true;
        }
    }
    return false;
}

bool InputHandler::getKeyJustReleased(int k){
    /*
        BOOL GET KEY JUST RELEASED:

        return if key is just released
    */
    for(int i : keysJustReleased){
        if(i == k){
            return true;
        }
    }
    return false;
}