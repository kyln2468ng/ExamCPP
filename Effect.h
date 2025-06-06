#pragma once
#include "GameObject.h"
#include "globals.h"

class Effect :
    public GameObject
{
public:
    Effect();
    ~Effect();
    void Update();
    void Draw();
protected:
private:
    Point pos_;
    int himage_;
    int timer;
};

