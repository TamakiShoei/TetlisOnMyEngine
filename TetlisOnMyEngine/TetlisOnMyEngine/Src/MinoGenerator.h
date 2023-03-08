#ifndef MINO_GENERATOR
#define	MINO_GENERATOR

#include <vector>
#include "Mino.h"

class MinoGenerator
{
public:
	static void CreateInstance()
	{
		instance = new MinoGenerator;
	}
	static MinoGenerator* GetInstance()
	{
		return instance;
	}
	static void DeleteInstance()
	{
		delete(instance);
	}

	//������
	void Initialize();

	//�X�V
	void Update();

	//�폜
	void Finalize();

	//����
	void Generate();

private:
	static MinoGenerator* instance;
	//�^�C�v���Ƃ̃~�m�f�[�^
	std::vector<std::vector<std::vector<int>>> data;
	//�C���X�^���X���ꂽ�~�m���X�g
	std::vector<Mino*> minos;
	//���ݓ����Ă���~�m
	Mino* currentMino;
private:
	//�C���X�^���X����
	MinoGenerator() = default;
	~MinoGenerator() = default;
	MinoGenerator(const MinoGenerator&) = delete;
	MinoGenerator(MinoGenerator&&) = delete;
	MinoGenerator& operator=(const MinoGenerator&) = delete;
	MinoGenerator& operator=(const MinoGenerator&&) = delete;

};

#endif