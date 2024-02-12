#pragma once
#include "Transform.h"
#include "Bullet.h"
#include "Scene.h"

class Enemy {

public:

	Transform transform_;
	int x_;
	int y_;
	int r_;
	int speed_;
	bool isHit_;
	int timer_;


public://‚±‚±‚©‚ç
	Enemy(Transform transform, int r, int speed);
	~Enemy();
	void Update(Scene* scene);
	void Damage(Bullet* bullet);
	void Draw();
};
