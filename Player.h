#pragma once
#include "Transform.h"
#include "Scene.h"

class Player {

public:

	Transform transform_;
	int x_;
	int y_;
	int r_;
	int speed_;


public://‚±‚±‚©‚ç
	Player(Transform transform, int r, int speed);
	~Player();
	void Move(char* keys, Scene* scene);
	void Draw();
};