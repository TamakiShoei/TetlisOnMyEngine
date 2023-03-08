#include "Mino.h"
#include "CommonDefinition.h"
#include "FieldManager.h"
#include "../Engine/Engine.h"

Mino::Mino(std::vector<std::vector<int>> input_data) :
	posX(5), posY(1), canAction(true), data(input_data), 
	start(clock()), end(0)
{

}

Mino::~Mino()
{
	data.clear();
}

void Mino::Update()
{
	if (canAction == false)
	{
		return;
	}

	std::vector<std::vector<int>> tmp = data;
	FieldManager::GetInstance()->EraseBlock(posX, posY, data);

	if (Engine::IsPushedKey(DIK_X))
	{
		RotateRight(tmp);
		if (FieldManager::GetInstance()->CanMove(posX, posY, tmp))
		{
			RotateRight(data);
		}
	}
	else if (Engine::IsPushedKey(DIK_Z))
	{
		RotateLeft(tmp);
		if (FieldManager::GetInstance()->CanMove(posX, posY, tmp))
		{
			RotateLeft(data);
		}
	}
	else if (Engine::IsPushedKey(DIK_RIGHT) && 
		FieldManager::GetInstance()->CanMove(posX + 1, posY, tmp))
	{
		posX++;
	}
	else if (Engine::IsPushedKey(DIK_LEFT) &&
		FieldManager::GetInstance()->CanMove(posX - 1, posY, tmp))
	{
		posX--;
	}
	else if (Engine::IsPushedKey(DIK_SPACE))
	{
		while (FieldManager::GetInstance()->CanMove(posX, posY + 1, data))
		{
			posY++;
		}
	}

	end = clock();
	if ((double)(end - start) / CLOCKS_PER_SEC >= 0.3)
	{
		if (FieldManager::GetInstance()->CanMove(posX, posY + 1, data))
		{
			start = end;
			end = 0;
			posY++;
		}
		else
		{
			canAction = false;
		}
	}
	FieldManager::GetInstance()->PaintBlock(posX, posY, data);
	if (canAction == false)
	{
		FieldManager::GetInstance()->CheckIsMatch();
	}
}

void Mino::RotateRight(std::vector<std::vector<int>>& data)
{
	std::vector<std::vector<int>> tmp(4, std::vector<int>(4));
	//‰ñ“]ˆ—
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			tmp.at(j).at(4 - i - 1) = data[i][j];
		}
	}

	//tmp‚©‚ç‘ã“ü
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			data[i][j] = tmp[i][j];
		}
	}
}

void Mino::RotateLeft(std::vector<std::vector<int>>& data)
{
	std::vector<std::vector<int>> tmp(4, std::vector<int>(4));
	//‰ñ“]ˆ—
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			tmp.at(4 - j - 1).at(i) = data[i][j];
		}
	}

	//tmp‚©‚ç‘ã“ü
	for (int i = 0; i < MINO_HEIGHT; i++)
	{
		for (int j = 0; j < MINO_WIDTH; j++)
		{
			data[i][j] = tmp[i][j];
		}
	}
}