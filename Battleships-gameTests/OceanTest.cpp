#include "pch.h"
#include "../Battleships-game/Ocean.cpp"
TEST(Ocean_getCell, should_getWaterCell_when_usingGetCell) {
	Ocean ocean;
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::WATER);
}
TEST(Ocean_getCell, should_getWaterCell_when_usingGetingOutOfBounds) {
	Ocean ocean;
	EXPECT_EQ(ocean.getCellAtCoordinates(-1, -1), Cell::WATER);
}
TEST(Ocean_getCell, should_getIntactShipCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::INTACT_SHIP);
}
TEST(Ocean_getCell, should_getMissedShotCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::MISSED_SHOT);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::MISSED_SHOT);
}
TEST(Ocean_getCell, should_getSunkenShipCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::SUNKEN_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::SUNKEN_SHIP);
}

TEST(Ocean_isCellOutOfBounds, should_getFalse_when_usingisCellOutOfBounds_at_x0_y1) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isCellOutOfBounds(0, 1));
}
TEST(Ocean_isCellOutOfBounds, should_getTrue_when_usingisCellOutOfBounds_at_xMinus1_yMinus1) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isCellOutOfBounds(-1, -1));
}
TEST(Ocean_isCellOutOfBounds, should_getTrue_when_usingisCellOutOfBounds_at_x10_y10) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isCellOutOfBounds(10, 10));
}
