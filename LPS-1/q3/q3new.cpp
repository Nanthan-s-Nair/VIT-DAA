#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class point {
    int x, y;
public:
    point(int x = 0, int y = 0) : x(x), y(y) {}

    double distanceFrom(const point&) const;

    int getX() const { return x; }
    int getY() const { return y; }

    friend istream& operator>>(istream&, point&);
    friend ostream& operator<<(ostream&, const point&);
};

double point::distanceFrom(const point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

istream& operator>>(istream& in, point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const point& p) {
    out << p.x << endl << p.y;
    return out;
}

int main() {
    vector<point> elements;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        point p;
        cin >> p;
        elements.push_back(p);
    }

    // Find the leftmost-bottom point
    point referencePoint = elements[0];
    for (int i = 1; i < n; i++) {
        if (elements[i].getX() < referencePoint.getX() ||
            (elements[i].getX() == referencePoint.getX() && elements[i].getY() < referencePoint.getY())) {
            referencePoint = elements[i];
        }
    }

    // Insertion sort based on distance from referencePoint
    for (int j = 1; j < n; j++) {
        point key = elements[j];
        int i = j - 1;
        while (i >= 0 && elements[i].distanceFrom(referencePoint) > key.distanceFrom(referencePoint)) {
            elements[i + 1] = elements[i];
            i = i - 1;
        }
        elements[i + 1] = key;
    }

    // Output sorted points with x and y on separate lines
    for (int i = 0; i < n; i++) {
        cout << elements[i] << endl;
    }

    return 0;
}