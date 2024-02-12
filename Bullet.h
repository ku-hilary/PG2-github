#pragma once
#include "Transform.h"
#include "Player.h"



class Bullet {

public:

	Transform transform_;
	int x_;
	int y_;
	int r_;
	int speed_;
	bool isShoot_;


public://‚±‚±‚©‚ç
	Bullet(Transform transform, int r, int speed);
	~Bullet();
	void ShootBullet(char* keys, Scene* scene);
	void followPlayer(Player& player);
	void Draw();
};
