#include <iostream>
#include <memory>
#include <vector>

class IShape {
public:
	virtual ~IShape() {};
	virtual void Size() = 0;
	virtual void Draw() = 0;
protected:
	float size;
};

class Circle final : public IShape {
public:
	Circle() = delete;
	explicit Circle(float s) {
		size = s;
	}
	void Size() override {
		size = size * size * 3.14f;
	}
	void Draw() override {
		std::cout << "Circle size: " << size << std::endl;
	}
};
class Rectangle final : public IShape {
public:
	Rectangle() = delete;
	explicit Rectangle(float s) {
		size = s;
	}
	void Size() override {
		size = size * size;
	}
	void Draw() override {
		std::cout << "Rectangle size: " << size << std::endl;
	}
};

int main() {
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.resize(2);
	shapes[0] = std::make_unique<Circle>(5.0f);
	shapes[1] = std::make_unique<Rectangle>(4.0f);
	for (const auto& shape : shapes) {
		shape->Size();
		shape->Draw();
	}
	return 0;
}