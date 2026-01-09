#pragma once
class WorldMap2D;
class Selector;

class MapSelectionHandler final {
public:
	MapSelectionHandler() = delete;
	explicit MapSelectionHandler(WorldMap2D& worldMap, Selector& selector);
	~MapSelectionHandler() = default;
	void Update();
private:
	WorldMap2D& worldMap_;
	Selector& selector_;
	int selectedValue_;
};