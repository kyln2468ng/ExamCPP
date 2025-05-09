#pragma once


namespace Input {
	//キーボード取得関連
	void KeyStateUpdate(); // キーの状態を更新
	bool IsKeyUp(int keyCode); // キーが離された瞬間
	bool IsKeyDown(int keyCode); // キーが押された瞬間
	int IsKeepKeyDown(int keyCode); // キーが押されている間
}