#include "FileReader.h"
#include <fstream>
#include <iostream>

std::vector<std::vector<int>>
FileReader::Read(std::string file_path)
{
    //csvƒtƒ@ƒCƒ‹‚Ì“Ç‚İ‚İ
    std::ifstream readingFile;
    readingFile.open(file_path, std::ios::in);
    if (!readingFile) {
        std::vector<std::vector<int> > data;
        return data;
    }
    std::string readingLineBuffer;

    //“ñŸŒ³‚Ìvector‚ğì¬
    std::vector<std::vector<std::string> > data;
    while (std::getline(readingFile, readingLineBuffer)) {
        if (readingLineBuffer.size() == 0) break;
        std::vector<std::string> temp_data;
        temp_data = Split(readingLineBuffer, ',');
        data.push_back(temp_data);
    }

    return StringToInt(data);
}

std::vector<std::string> FileReader::Split(std::string str, char del)
{
    int first = 0;
    int last = str.find_first_of(del);
    std::vector<std::string> result;
    while (first < str.size()) {
        std::string subStr(str, first, last - first);
        result.push_back(subStr);
        first = last + 1;
        last = str.find_first_of(del, first);
        if (last == std::string::npos) {
            last = str.size();
        }
    }
    return result;
}

std::vector<std::vector<int>> 
FileReader::StringToInt(std::vector<std::vector<std::string>> input)
{
    std::vector<std::vector<int>> tmp;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input.at(0).size(); j++)
        {
            tmp.emplace_back();
            tmp.at(i).push_back(atoi(input.at(i).at(j).c_str()));
        }
    }
    return tmp;
}