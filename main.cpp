#include <iostream>
#include <string>
#include <queue>

#define STR 2
#define COL 13
#define DCOL (COL + COL)

void printError(std::string msg) { std::cout << "Error: " << msg << std::endl; }

void printMtx(const char mtx[STR][COL], std::string msg = "") {
	std::cout << msg;

	for (size_t i = 0; i < STR; i++) {
		for (size_t j = 0; j < COL; j++)
			std::cout << mtx[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::queue<char>* getFilledQueue(char mtx[STR][COL]) {
	std::queue<char>* qAlpha = new std::queue<char>;

	for (int i = 0; i < COL; i++)
		qAlpha->push(mtx[0][i]);
	for (int i = COL - 1; i >= 0; i--)
		qAlpha->push(mtx[1][i]);
	return qAlpha;
}

void rotateQueue(const int N, std::queue<char>* qAlpha) {
	for (int n = N; n > 0; n--) {
		for (int i = 0; i < DCOL - 1; i++) {
			char ch = qAlpha->front();
			qAlpha->pop();
			qAlpha->emplace(ch);
		}
	}
}

void updateMatrix(char (&mtx)[STR][COL], std::queue<char> *qAlpha) {
	for (size_t i = 0; i < COL; i++) { // заполняю 1ю строку матрицы с начала
		mtx[0][i] = qAlpha->front();
		qAlpha->pop();
	}
	for (size_t i = COL; i != 0; i--) { // 2ю часть уже в обратном порядке
		mtx[1][i - 1] = qAlpha->front();
		qAlpha->pop();
	}
}

void Zadanie_3(int N) {
	char mtxAlpha[STR][COL] = {
		{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
		{'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
	};

	if (N <= 0) return printError("N < 0 or N = 0");

	printMtx(mtxAlpha, "====Initial MTX====\n");

	if (N > DCOL) N %= DCOL;
	if (N == DCOL || N == 0) return printMtx(mtxAlpha, "====Rezult====\n");
	
	std::queue<char> *qAlpha = getFilledQueue(mtxAlpha);

	rotateQueue(N, qAlpha);
	updateMatrix(mtxAlpha, qAlpha);

	delete qAlpha;

	printMtx(mtxAlpha, "====Rezult====\n");
}
 
int main() {
	for (int i = -1; i <= DCOL * 2; i++) {
		std::cout << "========| TEST: N = " << i << " |========\n"; 
		Zadanie_3(i);
		std::cout << std::endl;
	}
		
}