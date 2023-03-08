#include <iostream>
#include "MinoGenerator.h"
#include "Mino.h"
#include "FileReader/FileReader.h"

MinoGenerator* MinoGenerator::instance;

void MinoGenerator::Initialize()
{
	data.push_back((FileReader::Instance()->Read("Res/Data/IMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/OMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/SMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/ZMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/JMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/LMino.csv")));
	data.push_back((FileReader::Instance()->Read("Res/Data/TMino.csv")));

	Generate();
}

void MinoGenerator::Update()
{
	currentMino->Update();
	if (currentMino->GetCanAction() == false)
	{
		Generate();
	}
}

void MinoGenerator::Finalize()
{
	for (auto &mino : minos)
	{
		delete(mino);
		mino = nullptr;
	}
	if (currentMino == nullptr)
	{
		return;
	}
}

void MinoGenerator::Generate()
{
	static int counter = 0;
	currentMino = new Mino(data.at(counter));
	minos.push_back(currentMino);
	counter++;
	if (counter >= 7)
	{
		counter = 0;
	}
}