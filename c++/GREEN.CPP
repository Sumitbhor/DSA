#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class climate {
public:
    float temperature;
    float humidity;
    float co2_level;
    float light_intensity;
    float soil_moisture;

    climate() {
        temperature = 10;
        humidity = 50;
        co2_level = 400;
        light_intensity = 300;
        soil_moisture = 30;
    }

    void display() {
        cout << "Temperature: " << temperature << endl;
        cout << "Humidity: " << humidity << endl;
        cout << "CO2 Level: " << co2_level << endl;
        cout << "Light Intensity: " << light_intensity << endl;
        cout << "Soil Moisture: " << soil_moisture << endl;
        cout << "\n---------------------------------------------------\n";
    }
};

class plot {
public:
    climate climateData;
    int plot_id;
    string name;

    void display() {
        cout << "Plot ID: " << plot_id << endl;
        cout << "Crop Name: " << name << endl;
        climateData.display();
    }
};

class farm {
public:
    static const int length = 2;
    static const int width = 5;
    plot plotGrid[length][width];

    string plots[10] = {"Tomato", "Potato", "Onion", "Brinjal", "Cabbage", "Carrot", "Spinach", "Lettuce", "Cucumber", "Pepper"};

    void assignplot() {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                int index = i * width + j;
                plotGrid[i][j].plot_id = index + 1;
                plotGrid[i][j].name = plots[index];
                plotGrid[i][j].climateData.temperature = rand() % 45;
                plotGrid[i][j].climateData.humidity = rand() % 101;
                plotGrid[i][j].climateData.co2_level = (rand() % 2000) + 300;
                plotGrid[i][j].climateData.light_intensity = rand() % 10000;
                plotGrid[i][j].climateData.soil_moisture = rand() % 101;
            }
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                plotGrid[i][j].display();
            }
        }
    }
};

int main() {
    srand(time(0)); // Random seed
    farm farm1;
    farm1.assignplot();
    farm1.display();
    return 0;
}
