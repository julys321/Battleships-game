#include "pch.h"
#include "Dependencies.h"
TEST(Ocean, should_getWaterCell_when_usingGetCell) {
	Ocean ocean;
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 1), Cell::WATER);
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
TEST(Ocean, should_deployOneLongShip_when_usingdeployShip) {
	Ocean ocean;
	ocean.deployShip(0, 0);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployTwoLongShipFacingEast_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 0, 0, Direction::EAST);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 0), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployTwoLongShipFacingSouth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 0, 0, Direction::SOUTH);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 1), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployTwoLongShipFacingNorth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 9, 9, Direction::NORTH);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 9), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 8), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployTwoLongShipFacingWest_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 9, 9, Direction::WEST);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 9), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(8, 9), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployThreeLongShipFacingEast_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(1, 0), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(2, 0), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployThreeLongShipFacingSouth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::SOUTH);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 1), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 2), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployThreeLongShipFacingNorth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 9, 9, Direction::NORTH);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 9), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 8), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 7), Cell::INTACT_SHIP);
}
TEST(Ocean, should_deployThreeLongShipFacingWest_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 9, 9, Direction::WEST);
	EXPECT_EQ(ocean.getCellAtCoordinates(9, 9), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(8, 9), Cell::INTACT_SHIP);
	EXPECT_EQ(ocean.getCellAtCoordinates(7, 9), Cell::INTACT_SHIP);
}
TEST(Ocean, should_beEqual_when_usingEquals) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);

	Ocean oceanMock;
	oceanMock.deployShip(3, 0, 0, Direction::EAST);

	EXPECT_TRUE(ocean.equals(oceanMock));
}
TEST(Ocean, shouldnt_beEqual_when_usingEquals) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);

	Ocean oceanMock;
	oceanMock.deployShip(4, 0, 0, Direction::SOUTH);

	EXPECT_FALSE(ocean.equals(oceanMock));
}
TEST(Ocean, should_getExeption_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);
	EXPECT_ANY_THROW(ocean.deployShip(3, 0, 1, Direction::EAST));
}