#include "pch.h"
#include "CppFileReferences.h"
TEST(Ocean, should_getWaterCell_when_usingGetCell) {
	Ocean ocean;
  EXPECT_EQ(ocean.getCellAtCoordinates(1,1),Cell::WATER);
}
TEST(Ocean, should_getIntactShipCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::INTACT_SHIP);
}
TEST(Ocean, should_getMissedShotCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::MISSED_SHOT);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::MISSED_SHOT);
}
TEST(Ocean, should_getSunkenShipCell_when_usingGetCell) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 1, Cell::SUNKEN_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::SUNKEN_SHIP);
}