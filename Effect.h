#pragma once
#include "GameObject.h"
#include "globals.h"
#include "vector"

class Effect :
    public GameObject
{
public:
    Effect(Point _pos);
    ~Effect();
    void Update() override;
    void Draw() override;
protected:
private:
    std::vector<int> hImage_;
    Point pos_;
    float animeTimer_;
    int frame_;
    float frameTimer_;
};

//“G‚Æ’e‚ª‚Ô‚Â‚©‚Á‚½êŠ‚É”­¶‚µ‚Ä3•b‚ÅÁ‚¦‚é
//