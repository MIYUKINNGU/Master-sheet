#include <iostream>
//The module to be used is 'iostream' in this code.

#define MAX 10
#if MAX == 10
typedef int number;
#elif MAX < 10
typedef float number;
#else
typedef double number;
#endif

using namespace std;

void print(const char* Text);

struct Vector3 {
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;
};

Vector3 ChangeV3(Vector3 vec, auto func(float x, float y, float z) -> Vector3);

class Vector2 {
public:
    double x;
    double y;
    Vector2 operator = (Vector2 obj) {
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }
    Vector2 operator -= (Vector2 obj) {
        this->x -= obj.x;
        this->y -= obj.y;
        return *this;
    }
    Vector2 operator -= (double obj) {
        this->x -= obj;
        this->y -= obj;
        return *this;
    }
    Vector2 operator += (Vector2 obj) {
        this->x += obj.x;
        this->y += obj.y;
        return *this;
    }
    Vector2 operator += (double obj) {
        this->x += obj;
        this->y += obj;
        return *this;
    }
    Vector2 operator - (Vector2 obj) {
        double X = this->x - obj.x;
        double Y = this->y - obj.y;
        return Vector2(X, Y);
    }
    Vector2 operator - (double obj) {
        double X = this->x - obj;
        double Y = this->y - obj;
        return Vector2(X, Y);
    }
    Vector2 operator + (Vector2 obj) {
        double X = this->x + obj.x;
        double Y = this->y + obj.y;
        return Vector2(X, Y);
    }
    Vector2 operator + (double obj) {
        double X = this->x + obj;
        double Y = this->y + obj;
        return Vector2(X, Y);
    }
    Vector2(double x, double y) { this->x = x; this->y = y; }

    void Reset();
};

int main()
{
    std::cout << "Hello World!" << endl;
    print("New function!");

    int intvariable = 0;
    int* intpointer = &intvariable;

    *intpointer = *intpointer + intvariable;
    // == intvariable = intvariable + intvariable;

    Vector3 Vec = { 10, 10, 10 };

    Vec = ChangeV3(Vec, [](float x, float y, float z) {
        x += 10;
        y += 20;
        z += 30;
        Vector3 ANY = { x,y,z };
        return ANY;
    });

    Vector2 Vec2 = Vector2(0.0, 0.0);

    Vec2 += Vector2(10.0, 0.0);

    cout << Vec2.x << ", " << Vec2.y << endl;

    Vec2.Reset();

    cout << Vec2.x << ", " << Vec2.y << endl;

    if (1) {
        for (int i = 0; i<MAX; i--) {
            i++;
            i++;
        }
    }

    cout << sizeof(Vec2) << endl;

    char text[13] = { 'H','E','L','L','O',',',' ','W','O','R','L','D','\0' };

    cout << text << endl;

    return 0;
}

void print(const char* Text) 
{
    std::cout << Text << endl;
}

Vector3 ChangeV3(Vector3 vec, auto func(float x, float y, float z)->Vector3)
{
    return func(vec.x, vec.y, vec.z);
}

void Vector2::Reset() {
    x = 0;
    y = 0;
}