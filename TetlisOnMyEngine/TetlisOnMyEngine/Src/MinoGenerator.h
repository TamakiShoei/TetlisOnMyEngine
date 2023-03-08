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

	//初期化
	void Initialize();

	//更新
	void Update();

	//削除
	void Finalize();

	//生成
	void Generate();

private:
	static MinoGenerator* instance;
	//タイプごとのミノデータ
	std::vector<std::vector<std::vector<int>>> data;
	//インスタンスされたミノリスト
	std::vector<Mino*> minos;
	//現在動いているミノ
	Mino* currentMino;
private:
	//インスタンス制限
	MinoGenerator() = default;
	~MinoGenerator() = default;
	MinoGenerator(const MinoGenerator&) = delete;
	MinoGenerator(MinoGenerator&&) = delete;
	MinoGenerator& operator=(const MinoGenerator&) = delete;
	MinoGenerator& operator=(const MinoGenerator&&) = delete;

};

#endif