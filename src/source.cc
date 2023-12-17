#include "source.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "boost/asio.hpp"

using boost::asio::thread_pool;
using boost::asio::post;

collectIDProcess2::collectIDProcess2(const std::vector<std::string>& fnames):fnames_(fnames)
{
}

void collectIDProcess2::run()
{
	for (const std::string& fin : fnames_) {

		std::ifstream f(fin);
		if (!f.is_open()) {
			std::cout << "File Read Error." << std::endl;
		}
		else {
			threadMap_.resize(threadNum_);
			thread_pool threadPool(threadNum_);

			std::string line;
			int lineNum = 0;
			while (std::getline(f, line)) {
                int mapCountIdx = lineNum%threadNum_;
				post(threadPool, std::bind(&collectIDProcess2::threadWorker, this, line, lineNum, mapCountIdx));
				lineNum++;
			}
			threadPool.join();

		}
	}
    mergeToMainMap();
    mainMapInfo();
}

void collectIDProcess2::threadWorker(std::string line, int lineNum, int mapCountIdx)
{
	std::lock_guard<std::mutex> lock(mthreadMap_);
	auto id = std::this_thread::get_id();

	std::cout << "Process line Number: " << lineNum << ", Save to threadMap: " << mapCountIdx << std::endl;
	saveToThreadMap(line, mapCountIdx);
}

void collectIDProcess2::saveToThreadMap(const std::string& line, const int& mapCountIdx) {
    auto list_ = splitStr(line, " ");
    for (int i = 1; i < list_.size(); ++i) {
		threadMap_[mapCountIdx][list_[0]].push_back(list_[i]);
	}
}

void collectIDProcess2::mergeToMainMap() {
    for (auto &m:threadMap_) {
        mainMap_.insert(m.begin(), m.end());
    }
}

void collectIDProcess2::mainMapInfo() {
    for (auto &m:mainMap_) {
        std::cout<<"user: "<<m.first<<", data size: "<<m.second.size()<<std::endl;
    }
}

std::vector<std::string> collectIDProcess2::splitStr(const std::string& str, const std::string& pattern)
{
	std::vector<std::string> res;
	size_t start = 0;
	size_t end = str.find(pattern);

	while (end != std::string::npos) {
		res.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(pattern, start);
	}

	// Handle the last substring
	res.push_back(str.substr(start));

	return res;
}