#include "Scene.h"
#include "Novice.h"

Scene::Scene(bool isStart, bool isEnd)
{
	isStart_ = isStart;
	isEnd_ = isEnd;
	counter_ = 0;
}

Scene::~Scene()
{
}

void Scene::Update(char* keys)
{
	if (keys[DIK_RETURN]) {
		isStart_ = true;
		isEnd_ = false;
	}
	counter_++;

	if (counter_ > 600) {
		isEnd_ = true;
	}
	if (isEnd_ == true) {
		counter_ = 0;
	}

	if (keys[DIK_R] && isEnd_ == true) {
		isEnd_ = false;
		isStart_ = false;
	}
}

void Scene::Draw()
{
	int title = Novice::LoadTexture("./title.png");
	int end = Novice::LoadTexture("./pressR.png");

	if (isStart_ == false) {
		Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);
	}
	if (isEnd_ == true) {
		Novice::DrawSprite(0, 0, end, 1, 1, 0.0f, WHITE);
	}
}
