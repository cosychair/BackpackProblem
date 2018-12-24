#include "Knapsack.h"

void Knapsack::fill(Queue * possibleThings){
	const size_t dim1 = possibleThings->getSize();
	const size_t dim2 = maxWeight;

}

void Knapsack::printContent(){
	cout << "Total weight of filled knapsack is " << weight << "." << endl;
	cout << "Total value of filled knapsack is " << value << "." << endl;
	things->printToConsole();
}
