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
	//�t�B�[���h�̑S�u���b�N��`��
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
	//���݂̈ʒu�̃~�m���폜����
	//�~�m���ړ�����ۂɌĂԕK�v������
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
	//�t�B�[���h��Ƀ~�m��h��
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
	//�������Ƃ��Ă���ʒu�ɓ����邩���Ƀ`�F�b�N����
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
	//����񂪃u���b�N�Ŗ��܂��Ă��邩���`�F�b�N����
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
	
	//�������܂��Ă����疄�܂��Ă������C���̃u���b�N���폜����
	for (int x = 0; x < FIELD_WIDTH; x++)
	{
		if (data.at(deleteLineNum).at(x) <= 6)
		{
			data.at(deleteLineNum).at(x) = 7;
		}
	}

	//�폜���ꂽ�u���b�N����̃u���b�N�͈���̒i�ɉ�����
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
	//�ċA�I�Ɏ��s���Ĉ�C�ɓ��ȏ�������ꍇ�ɑΉ�
	return CheckIsMatch();
}