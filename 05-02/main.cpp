#include <Novice.h>

#include "App/WorldMap2D.h"
#include "App/Selector/Selector.h"
#include "App/MapSelectionHandler.h"

const char kWindowTitle[] = "LE2A_14_マツモト_ユウタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	float screenWidth = 1280.0f;
	float screenHeight = 720.0f;
	float gridSize = 40.0f;

	WorldMap2D worldMap2D;
	worldMap2D.Init(static_cast<int>(screenWidth), static_cast<int>(screenHeight), gridSize);

	Selector selector(keys, preKeys);
	selector.Init(static_cast<int>(screenWidth / gridSize), static_cast<int>(screenHeight / gridSize), gridSize);

	MapSelectionHandler mapSelectionHandler(worldMap2D, selector);

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

		selector.Update();
		mapSelectionHandler.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		worldMap2D.Draw();
		selector.Draw();

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
