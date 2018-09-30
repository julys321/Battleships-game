#include "pch.h"
#include "../Battleships-game/Player.cpp"
TEST(Player_setShipLimit, should_setOneLongShipLimitTo6) {
	Player player;
	player.setShipLimit(1, 6);
	EXPECT_EQ(player.getShipLimit(1), 6);
}
TEST(Player_constructor, should_getDefaultShipLimit_4_when_givenLenght_1) {
	Player player;
	EXPECT_EQ(player.getShipLimit(1), 4);
}
TEST(Player_constructor, should_getDefaultShipLimit_3_when_givenLenght_2) {
	Player player;
	EXPECT_EQ(player.getShipLimit(2), 3);
}
TEST(Player_constructor, should_getDefaultShipLimit_2_when_givenLenght_3) {
	Player player;
	EXPECT_EQ(player.getShipLimit(3), 2);
}
TEST(Player_constructor, should_getDefaultShipLimit_1_when_givenLenght_4) {
	Player player;
	EXPECT_EQ(player.getShipLimit(4), 1);
}
TEST(Player_constructor, should_getDefaultShipLimit_0_when_givenLenght_5) {
	Player player;
	EXPECT_EQ(player.getShipLimit(5), 0);
}
TEST(Player_constructor, should_getDefaultShipLimit_0_when_givenLenght_6) {
	Player player;
	EXPECT_EQ(player.getShipLimit(6), 0);
}
TEST(Player_equals, should_beEqual_when_usingEquals) {
	Player player;
	player.deployShip(3, 0, 0, Direction::EAST);

	Player playerMock;
	playerMock.deployShip(3, 0, 0, Direction::EAST);

	EXPECT_TRUE(player.ocean.equals(playerMock.ocean));
}
TEST(Player_equals, shouldnt_beEqual_when_usingEquals) {
	Player player;
	player.deployShip(3, 0, 0, Direction::EAST);

	Player playerMock;
	playerMock.deployShip(4, 0, 0, Direction::SOUTH);

	EXPECT_FALSE(player.ocean.equals(playerMock.ocean));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsNorth) {
	Player player;
	EXPECT_FALSE(player.isShipAllowedToDeploy(3, 0, 1, Direction::NORTH));
}
TEST(Player_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingNorth) {
	Player player;
	EXPECT_TRUE(player.isShipAllowedToDeploy(3, 0, 2, Direction::NORTH));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsEast) {
	Player player;
	EXPECT_FALSE(player.isShipAllowedToDeploy(3, 9, 0, Direction::EAST));
}
TEST(Player_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingEast) {
	Player player;
	EXPECT_TRUE(player.isShipAllowedToDeploy(3, 7, 0, Direction::EAST));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsSouth) {
	Player player;
	EXPECT_FALSE(player.isShipAllowedToDeploy(3, 9, 9, Direction::SOUTH));
}
TEST(Player_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingSouth) {
	Player player;
	EXPECT_TRUE(player.isShipAllowedToDeploy(3, 9, 6, Direction::SOUTH));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_validatingAShipOutOfBoundsWest) {
	Player player;
	EXPECT_FALSE(player.isShipAllowedToDeploy(3, 0, 9, Direction::WEST));
}
TEST(Player_isShipAllowedToDeploy, should_getTrue_when_validatingAShipFacingWest) {
	Player player;
	EXPECT_TRUE(player.isShipAllowedToDeploy(3, 2, 9, Direction::WEST));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorthWest) {
	Player player;
	player.ocean.setCellAtCoordinates(0, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorth) {
	Player player;
	player.ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseNorthEast) {
	Player player;
	player.ocean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseWest) {
	Player player;
	player.ocean.setCellAtCoordinates(0, 1, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsAtTheCoordinates) {
	Player player;
	player.ocean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseEast) {
	Player player;
	player.ocean.setCellAtCoordinates(2, 1, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouthWest) {
	Player player;
	player.ocean.setCellAtCoordinates(0, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouth) {
	Player player;
	player.ocean.setCellAtCoordinates(1, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getTrue_when_ShipExistsTooCloseSouthEast) {
	Player player;
	player.ocean.setCellAtCoordinates(2, 2, Cell::INTACT_SHIP);
	EXPECT_TRUE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isThereAShipAroundCoordinates, should_getFalse_when_noShipsExistAround) {
	Player player;
	EXPECT_FALSE(player.isThereAShipAtAndAroundCoordinates(1, 1));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_shipExistsToTheEast) {
	Player player;
	player.deployShip(2, 5, 4, Direction::NORTH);

	EXPECT_FALSE(player.isShipAllowedToDeploy(2, 4, 4, Direction::NORTH));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_shipExistsToTheSouth) {
	Player player;
	player.deployShip(2, 4, 5, Direction::EAST);

	EXPECT_FALSE(player.isShipAllowedToDeploy(2, 4, 4, Direction::NORTH));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_shipExistsToTheWest) {
	Player player;
	player.deployShip(2, 3, 4, Direction::SOUTH);

	EXPECT_FALSE(player.isShipAllowedToDeploy(2, 4, 4, Direction::NORTH));
}
TEST(Player_isShipAllowedToDeploy, should_getFalse_when_shipExistsToTheNorth) {
	Player player;
	player.deployShip(2, 4, 3, Direction::WEST);

	EXPECT_FALSE(player.isShipAllowedToDeploy(2, 4, 4, Direction::NORTH));
}
TEST(Player_deployShip, should_deployOneLongShip_when_usingdeployShip) {
	Player player;
	player.deployShip(0, 0);
	EXPECT_EQ(player.ocean.getCellAtCoordinates(0, 0), Cell::INTACT_SHIP);
}
TEST(Player_deployShip, should_deployTwoLongShipFacingEast_when_usingDeployShip) {
	Player player;
	player.deployShip(2, 1, 0, Direction::EAST);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployTwoLongShipFacingSouth_when_usingDeployShip) {
	Player player;
	player.deployShip(2, 1, 0, Direction::SOUTH);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployTwoLongShipFacingNorth_when_usingDeployShip) {
	Player player;
	player.deployShip(2, 8, 9, Direction::NORTH);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(8, 8, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployTwoLongShipFacingWest_when_usingDeployShip) {
	Player player;
	player.deployShip(2, 8, 9, Direction::WEST);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(7, 9, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployThreeLongShipFacingEast_when_usingDeployShip) {
	Player player;
	player.deployShip(3, 1, 0, Direction::EAST);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(2, 0, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(3, 0, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployThreeLongShipFacingSouth_when_usingDeployShip) {
	Player player;
	player.deployShip(3, 1, 0, Direction::SOUTH);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(1, 0, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(1, 1, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(1, 2, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployThreeLongShipFacingNorth_when_usingDeployShip) {
	Player player;
	player.deployShip(3, 8, 9, Direction::NORTH);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(8, 8, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(8, 7, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}
TEST(Player_deployShip, should_deployThreeLongShipFacingWest_when_usingDeployShip) {
	Player player;
	player.deployShip(3, 8, 9, Direction::WEST);

	Player expectedPlayer;
	expectedPlayer.ocean.setCellAtCoordinates(8, 9, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(7, 9, Cell::INTACT_SHIP);
	expectedPlayer.ocean.setCellAtCoordinates(6, 9, Cell::INTACT_SHIP);

	EXPECT_TRUE(player.ocean.equals(expectedPlayer.ocean));
}