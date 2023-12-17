#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>

class collectIDProcess2 {
public:
	collectIDProcess2(const std::vector<std::string>& fnames);
	void run();
private:
	void threadWorker(std::string line, int lineNum, int mapCountIdx);

    void saveToThreadMap(const std::string& line, const int& mapCountIdx);
    void mergeToMainMap();
    void mainMapInfo();
	std::vector<std::string> splitStr(const std::string& str, const std::string& pattern);

	const int threadNum_ = 8;
	std::vector<std::string> fnames_;
	std::map<std::string, std::vector<std::string>> mainMap_;
	std::vector<std::map<std::string, std::vector<std::string>>> threadMap_;
	std::mutex mthreadMap_;
};