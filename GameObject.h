#pragma once
#include <vector>

class GameObject
{
protected:
	bool isAlive_; // ゲームオブジェクトが生きているかどうか
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool IsAlive() { return isAlive_; } // ゲームオブジェクトが生きているかどうかを返す
	void SetAlive(bool alive) { isAlive_ = alive; }
};

extern std::vector<GameObject*> gameObjects; // ゲームオブジェクト
extern std::vector<GameObject*> newObjects;

inline void AddGameObject(GameObject* obj)
{
	newObjects.push_back(obj); // ゲームオブジェクト
}

