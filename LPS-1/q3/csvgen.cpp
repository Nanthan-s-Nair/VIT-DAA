#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    double distanceFrom(const Point&) const;

    int getX() const { return x; }
    int getY() const { return y; }

    friend istream& operator>>(istream&, Point&);
    friend ostream& operator<<(ostream&, const Point&);
};

double Point::distanceFrom(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
}

void processFile(const string& inputFilename, const string& outputFilename, const string& timingFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error opening file " << inputFilename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Error opening file " << outputFilename << endl;
        return;
    }

    vector<Point> elements;
    int n;
    inputFile >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        inputFile >> p;
        elements.push_back(p);
    }
    inputFile.close();

    Point referencePoint = elements[0];
    for (int i = 1; i < n; i++) {
        if (elements[i].getX() < referencePoint.getX() ||
            (elements[i].getX() == referencePoint.getX() && elements[i].getY() < referencePoint.getY())) {
            referencePoint = elements[i];
        }
    }

    clock_t start = clock();

    for (int j = 1; j < n; j++) {
        Point key = elements[j];
        int i = j - 1;
        while (i >= 0 && elements[i].distanceFrom(referencePoint) > key.distanceFrom(referencePoint)) {
            elements[i + 1] = elements[i];
            i = i - 1;
        }
        elements[i + 1] = key;
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < n; i++) {
        outputFile << elements[i] << endl;
    }

    outputFile.close();

    ofstream timingFile(timingFilename, ios::app);
    timingFile << n << "," << elapsed << endl;
    timingFile.close();
}

int main() {
    vector<int> sizes = {100, 500, 1000, 2500, 3000, 4500, 5000, 6500, 7500, 10000};

    for (size_t i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];

        processFile("points_random_" + to_string(size) + ".txt", "sorted_points_random_" + to_string(size) + ".txt", "random_results.csv");
        processFile("points_best_" + to_string(size) + ".txt", "sorted_points_best_" + to_string(size) + ".txt", "best_case_results.csv");
        processFile("points_worst_" + to_string(size) + ".txt", "sorted_points_worst_" + to_string(size) + ".txt", "worst_case_results.csv");
    }

    return 0;
}