#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <mutex>
#include <sstream>

std::mutex mtx;

void compressChunk(const std::string &input, std::ostringstream &output, int start, int end) {
    for (int i = start; i < end; ++i) {
        char current = input[i];
        int count = 1;
        while (i + 1 < end && input[i + 1] == current) {
            ++count;
            ++i;
        }
        std::lock_guard<std::mutex> lock(mtx);
        output << current << count;
    }
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cout << "Input file not found!" << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

    int numThreads = 4;
    int chunkSize = content.size() / numThreads;

    std::vector<std::thread> threads;
    std::ostringstream output;

    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? content.size() : (i + 1) * chunkSize;
        threads.emplace_back(compressChunk, std::ref(content), std::ref(output), start, end);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::ofstream outFile("compressed.txt");
    outFile << output.str();
    outFile.close();

    std::cout << "File compression complete! Check 'compressed.txt'" << std::endl;

    return 0;
}
