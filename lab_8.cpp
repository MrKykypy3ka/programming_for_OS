#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

struct Record {
    std::string phone_number;
    std::string full_name;
    std::string address;

    Record(std::string pn, std::string fn, std::string ad)
        : phone_number(pn), full_name(fn), address(ad) {}
};

bool compareRecords(const Record& r1, const Record& r2) {
    return r1.phone_number < r2.phone_number;
}

int main() {
    std::string filename = "records.txt";

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Ошибка: не удаётся открыть файл '" << filename << "' для чтения\n";
        return 1;
    }

    std::vector<Record> records;
    std::string line;
    while (std::getline(infile, line)) {
        std::string pn, fn, ad;
        std::istringstream iss(line);
        if (iss >> pn >> fn >> ad) {
            records.emplace_back(pn, fn, ad);
        }
    }

    std::sort(records.begin(), records.end(), compareRecords);

    std::ofstream outfile("sorted_records.txt");
    if (!outfile) {
        std::cerr << "Ошибка: не удаётся открыть файл 'sorted_records.txt' для записи\n";
        return 1;
    }

    for (const auto& record : records) {
        outfile << record.phone_number << " " << record.full_name << " " << record.address << "\n";
    }

    std::cout << "Записи в файле '" << filename << "' были отсортированы и записаны в файл 'sorted_records.txt'\n";

    return 0;
}