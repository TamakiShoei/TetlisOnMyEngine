#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>
#include <string>

class FileReader
{
public:
	static FileReader* Instance()
	{
		static FileReader* instance;
		return instance;
	}

	std::vector<std::vector<int>>
		Read(std::string file_path);

private:
	std::vector<std::string> Split(std::string str, char del);
	std::vector<std::vector<int>> StringToInt(std::vector<std::vector<std::string>> input);

private:
	//インスタンス制限
	FileReader() = default;
	~FileReader() = default;
	FileReader(const FileReader&) = delete;
	FileReader(FileReader&&) = delete;
	FileReader& operator=(const FileReader&) = delete;
	FileReader& operator=(const FileReader&&) = delete;
};

#endif
