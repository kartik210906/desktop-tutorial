#include <iostream>
using namespace std;

class vec {
    int x, y, z;

public:
    vec(int a = 0, int b = 0, int c = 0) {
        x = a;
        y = b;
        z = c;
    }

    inline vec operator+(vec v) const {
        return vec(x + v.x, y + v.y, z + v.z);
    }

    inline vec operator-(vec v) const {
        return vec(x - v.x, y - v.y, z - v.z);
    }

    inline vec operator*(vec v) const {
        return vec(x * v.x, y * v.y, z * v.z);
    }

    void print() const {
        cout << x << ", " << y << ", " << z << endl;
    }
};

int main() {
    int x, y, z;
    vec a, b;

    cout << "Enter the values of vector a: \n";
    cout << "input x, y, z: ";
    cin >> x >> y >> z;
    a = vec(x, y, z);

    cout << "Enter the values of vector b: \n";
    cout << "input x, y, z: ";
    cin >> x >> y >> z;
    b = vec(x, y, z);

    vec c = a + b;
    cout << "Addition of vector a and b: ";
    c.print();

    vec d = a - b;
    cout << "Subtraction of vector a and b: ";
    d.print();

    vec e = a * b;
    cout << "Multiplication of vector a and b: ";
    e.print();

    return 0;
}