#include "Ocean.h"

Cell Ocean::getCellAtCoordinates(int x, int y){
	return cells[x][y];
}

void Ocean::setCellAtCoordinates(int x, int y, Cell cell){
	cells[x][y] = cell;
}

Ocean::Ocean(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->cells[i][j] = Cell::WATER;
		}
	}
}


Ocean::~Ocean(){

}
