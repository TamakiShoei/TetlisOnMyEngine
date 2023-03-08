#ifndef	MINO_H
#define MINO_H

#include <vector>
#include <time.h>

class Mino
{
public:
	Mino(std::vector<std::vector<int>> input_data);
	~Mino();

	void Update();
	inline bool GetCanAction() { return canAction; };

private:
	void RotateRight(std::vector<std::vector<int>> &data);
	void RotateLeft(std::vector<std::vector<int>> &data);

private:
	int posX;
	int posY;
	bool canAction;
	clock_t start;
	clock_t end;
	std::vector<std::vector<int>> data;
};

#endif