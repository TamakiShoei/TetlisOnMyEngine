#include "FieldManager.h"
#include "CommonDefinition.h"
#include "FileReader/FileReader.h"
#include "../Engine/Engine.h"

FieldManager* FieldManager::instance;

void FieldManager::Initialize()
{
	data = FileReader::Instance()->Read(std::string("Res/Data/Field.csv"));
	handles.push_back(Engine::LoadTexture("Res/Texture/IBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/OBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/SBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/ZBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/JBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/LBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/TBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/StageBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/WallBlock.png"));
	handles.push_back(Engine::LoadTexture("Res/Texture/EmptyBlock.png"));

	isGameOver = false;
}

void FieldManager::Draw()
{
	//フィールドの全ブロックを描画
	int index;
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			Engine::DrawTexture(j * BLOCK_WIDTH, i * BLOCK_HEIGHT, handles.at(data.at(i).at(j)));
		}
	}
}

void FieldManager::EraseBlock(int pos_x, int pos_y, std::vector<std::vector<int>> input_data)
{
	//現在の位置のミノを削除する
	//ミノを移動する際に呼ぶ必要がある
	for (int y = 0; y < MINO_HEIGHT; y++)
	{
		for (int x = 0; x < MINO_WIDTH; x++)
		{
			if (input_data.at(y).at(x) <= (int)BlockType::T)
			{
				data.at(pos_y + y).at(pos_x + x) = (int)BlockType::Stage;
			}
		}
	}
}

void FieldManager::PaintBlock(int pos_x, int pos_y, std::vector<std::vector<int>> input_data)
{
	//フィールド上にミノを塗る
	for (int y = 0; y < MINO_HEIGHT; y++)
	{
		for (int x = 0; x < MINO_WIDTH; x++)
		{
			if (input_data.at(y).at(x) == (int)BlockType::Stage)
			{
				continue;
			}

			data.at(pos_y + y).at(pos_x + x) = input_data.at(y).at(x);
		}
	}

}

bool FieldManager::CanMove(int after_pos_x, int after_pos_y, std::vector<std::vector<int>> input_data)
{
	//動こうとしている位置に動けるかを先にチェックする
	for (int y = 0; y < MINO_HEIGHT; y++)
	{
		for (int x = 0; x < MINO_WIDTH; x++)
		{
			if (data.at(after_pos_y + y).at(after_pos_x + x) != (int)BlockType::Stage &&
				(input_data.at(y).at(x) <= (int)BlockType::T))
			{
				CheckIsGameOver();
				return false;
			}
		}
	}

	return true;
}

void FieldManager::CheckIsGameOver()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (data.at(y).at(x) <= 6)
			{
				isGameOver = true;
				return;
			}
		}
	}
	return;
}

void FieldManager::CheckIsMatch()
{
	//横一列がブロックで埋まっているかをチェックする
	bool isMatch = false;
	int deleteLineNum;
	for (int y = FIELD_HEIGHT - 1; y > 0; y--)
	{
		int counter = 0;
		for (int x = FIELD_WIDTH - 1; x > 0; x--)
		{
			if (data.at(y).at(x) <= (int)BlockType::T)
			{
				counter++;
			}
			if (counter == STAGE_WIDTH)
			{
				deleteLineNum = y;
				isMatch = true;
				break;
			}
		}
	}
	if (isMatch == false)
	{
		return;
	}
	
	//もし埋まっていたら埋まっていたラインのブロックを削除する
	for (int x = 0; x < FIELD_WIDTH; x++)
	{
		if (data.at(deleteLineNum).at(x) <= 6)
		{
			data.at(deleteLineNum).at(x) = 7;
		}
	}

	//削除されたブロックより上のブロックは一つ下の段に下げる
	for (int y = deleteLineNum; y > 0; y--)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			int tmp = data.at(y).at(x);
			if (tmp >= (int)BlockType::Stage)
			{
				continue;
			}
			data.at(y).at(x) = (int)BlockType::Stage;
			data.at(y + 1).at(x) = tmp;
		}
	}
	//再帰的に実行して一気に二列以上消した場合に対応
	return CheckIsMatch();
}