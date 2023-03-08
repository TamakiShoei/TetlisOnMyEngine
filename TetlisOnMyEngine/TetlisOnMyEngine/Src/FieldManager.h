#ifndef	FIELD_MANAGER_H
#define FIELD_MANAGER_H

#include <vector>
#include <string>

class FieldManager
{
public:
	static void CreateInstance()
	{
		instance = new FieldManager;
	}
	static FieldManager* GetInstance()
	{
		return instance;
	}
	static void DeleteInstance()
	{
		delete(instance);
	}
	
	void Initialize();
	void Draw();
	void EraseBlock(int pos_x, int pox_y, std::vector<std::vector<int>> input_data);
	void PaintBlock(int pos_x, int pos_y, std::vector<std::vector<int>> input_data);
	bool CanMove(int after_pos_x, int after_pos_y, std::vector<std::vector<int>> input_data);
	void CheckIsMatch();
	bool GetIsGameOver() { return isGameOver; }

private:
	void CheckIsGameOver();

private:
	static FieldManager* instance;
	bool isGameOver;
	std::vector<std::vector<int>> data;
	std::vector<int> handles;

private:
	//インスタンス制限
	FieldManager() = default;
	~FieldManager() = default;
	FieldManager(const FieldManager&) = delete;
	FieldManager(FieldManager&&) = delete;
	FieldManager& operator=(const FieldManager&) = delete;
	FieldManager& operator=(const FieldManager&&) = delete;
};

#endif