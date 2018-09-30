#include "pch.h"
#include "Dependencies.h"
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
TEST(Ocean_deployShip, should_deployOneLongShip_when_usingdeployShip) {
	Ocean ocean;
	ocean.deployShip(0, 0);
	EXPECT_EQ(ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
}
TEST(Ocean_equals, should_beEqual_when_usingEquals) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);

	Ocean oceanMock;
	oceanMock.deployShip(3, 0, 0, Direction::EAST);

	EXPECT_TRUE(ocean.equals(oceanMock));
}
TEST(Ocean_equals, shouldnt_beEqual_when_usingEquals) {
	Ocean ocean;
	ocean.deployShip(3, 0, 0, Direction::EAST);

	Ocean oceanMock;
	oceanMock.deployShip(4, 0, 0, Direction::SOUTH);

	EXPECT_FALSE(ocean.equals(oceanMock));
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
TEST(Ocean_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsNorth) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isShipAllowedToDeploy(3, 0, 1, Direction::NORTH));
}
TEST(Ocean_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingNorth) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isShipAllowedToDeploy(3, 0, 2, Direction::NORTH));
}
TEST(Ocean_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsEast) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isShipAllowedToDeploy(3, 9, 0, Direction::EAST));
}
TEST(Ocean_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingEast) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isShipAllowedToDeploy(3, 7, 0, Direction::EAST));
}
TEST(Ocean_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsSouth) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isShipAllowedToDeploy(3, 9, 9, Direction::SOUTH));
}
TEST(Ocean_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingSouth) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isShipAllowedToDeploy(3, 9, 6, Direction::SOUTH));
}
TEST(Ocean_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsWest) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isShipAllowedToDeploy(3, 0, 9, Direction::WEST));
}
TEST(Ocean_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingWest) {
	Ocean ocean;
	EXPECT_TRUE(ocean.isShipAllowedToDeploy(3, 2, 9, Direction::WEST));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorthWest) {
	Ocean ocean;
	ocean.setCellAtCoordinates(0, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorth) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorthEast) {
	Ocean ocean;
	ocean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseWest) {
	Ocean ocean;
	ocean.setCellAtCoordinates(0, 1, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseEast) {
	Ocean ocean;
	ocean.setCellAtCoordinates(2, 1, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouthWest) {
	Ocean ocean;
	ocean.setCellAtCoordinates(0, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouth) {
	Ocean ocean;
	ocean.setCellAtCoordinates(1, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouthEast) {
	Ocean ocean;
	ocean.setCellAtCoordinates(2, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_isThereAShipAroundCoordinates, should_getFalse_when_noShipsExistAround) {
	Ocean ocean;
	EXPECT_FALSE(ocean.isThereAShipAroundCoordinates(1, 1));
}
TEST(Ocean_deployShip, should_deployTwoLongShipFacingEast_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 1, 0, Direction::EAST);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployTwoLongShipFacingSouth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 1, 0, Direction::SOUTH);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployTwoLongShipFacingNorth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 8, 9, Direction::NORTH);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(8, 8, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployTwoLongShipFacingWest_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(2, 8, 9, Direction::WEST);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(7, 9, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployThreeLongShipFacingEast_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 1, 0, Direction::EAST);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(3, 0, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployThreeLongShipFacingSouth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 1, 0, Direction::SOUTH);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(1, 2, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployThreeLongShipFacingNorth_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 8, 9, Direction::NORTH);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(8, 8, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(8, 7, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}
TEST(Ocean_deployShip, should_deployThreeLongShipFacingWest_when_usingDeployShip) {
	Ocean ocean;
	ocean.deployShip(3, 8, 9, Direction::WEST);

	Ocean expectedOcean;
	expectedOcean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(7, 9, Cell::INTACT_SHIP);
	expectedOcean.setCellAtCoordinates(6, 9, Cell::INTACT_SHIP);

	EXPECT_TRUE(ocean.equals(expectedOcean));
}