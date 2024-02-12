#include <Novice.h>
#include <Player.h>
#include <Enemy.h>
#include <Bullet.h>
#include <Scene.h>

const char kWindowTitle[] = "GC1A_05_コ_キヨウ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Bullet* bullet = new Bullet({ 1280 / 2, 650 }, 10, 20);

	Player* player = new Player({ 1280 / 2, 650 }, 20, 10);

	Enemy* enemy = new Enemy({ 1280 / 2, 100 }, 20, 5);

	Scene* scene = new Scene(false, false);


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		scene->Update(keys);

		bullet->followPlayer(*player);

		bullet->ShootBullet(keys, scene);

		player->Move(keys, scene);

		enemy->Damage(bullet);
		enemy->Update(scene);



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		bullet->Draw();

		player->Draw();

		enemy->Draw();

		scene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

