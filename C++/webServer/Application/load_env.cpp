#include <fstream>
#include <string>
#include <cstdlib>

void load_env(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        size_t eq = line.find('=');
        if (eq != std::string::npos) {
            std::string key = line.substr(0, eq);
            std::string val = line.substr(eq + 1);
            setenv(key.c_str(), val.c_str(), 1);  // Add to env
        }
    }
}

