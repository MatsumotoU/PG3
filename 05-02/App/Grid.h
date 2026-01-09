#pragma once

class Grid final {
public:
	Grid() = default;
	~Grid() = default;

	void Init(float screenWidth, float screenHeight,float gridSize);
	void Draw();

	const float& GetGridSize() const;

private:
	float width_;
	float height_;
	float size_;

};