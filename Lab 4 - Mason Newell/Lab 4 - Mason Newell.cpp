#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class TemperatureChart {
public:
    void loadTemperaturesFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile) {
            std::cerr << "Error: Unable to open the input file." << std::endl;
            return;
        }

        int temperature;
        while (inputFile >> temperature) {
            if (isValidTemperature(temperature)) {
                temperatures.push_back(temperature);
            }
        }

        inputFile.close();
    }

    void displayChart() {
        if (temperatures.empty()) {
            std::cout << "No valid temperatures to display." << std::endl;
            return;
        }

        std::cout << "Temperature Bar Chart (Range: -30 to 120 degrees)" << std::endl;

        for (int temp = -30; temp <= 120; temp += 3) {
            std::cout << temp << " | ";
            int stars = countStarsInRange(temp, temp + 3);
            printStars(stars);
            std::cout << std::endl;
        }
    }

private:
    std::vector<int> temperatures;

    bool isValidTemperature(int temp) const {
        return temp >= -30 && temp <= 120;
    }

    int countStarsInRange(int min, int max) const {
        int count = 0;
        for (int temp : temperatures) {
            if (temp >= min && temp < max) {
                count++;
            }
        }
        return count;
    }

    void printStars(int count) const {
        for (int i = 0; i < count; i++) {
            std::cout << "*";
        }
    }
};

int main() {
    TemperatureChart chart;

    // Provide the filename containing hourly temperatures
    chart.loadTemperaturesFromFile("temperatures.txt");

    // Display the bar chart
    chart.displayChart();

    return 0;
}
