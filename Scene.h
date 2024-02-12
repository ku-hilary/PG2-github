#pragma once

class Scene {

public:
	bool isStart_;
	bool isEnd_;
	int counter_;

public:

	Scene(bool isStart, bool isEnd);
	~Scene();
	void Update(char* keys);
	void Draw();
};