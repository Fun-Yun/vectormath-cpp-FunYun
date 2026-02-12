#include <iostream>
#include "VectorMath.h"
#include <cmath>
#include <cassert>

#define endline "\n\n"

// Helper function for float comparison
bool FloatEquals(float a, float b, float epsilon = 0.0001f) {
    return fabs(a - b) < epsilon;
}

// Custom assert function
void Assert(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "[FAIL] " << message << std::endl;
        std::cin.get();  // Pause so you can see the error
        exit(1);  // Exit with error code
        // OR continue without pause and exit to run all tests with output information
    }
}


/// VECTOR 3 TESTS

void TestVectorAdd() {
    std::cout << "Testing VectorAdd..." << std::endl;

    Vec3 a = { 1.0f, 2.0f, 3.0f };
    Vec3 b = { 4.0f, 5.0f, 6.0f };
    Vec3 result = VectorAdd(a, b);

    Assert(result.x == 5.0f, "VectorAdd X component should be 5");
    Assert(result.y == 7.0f, "VectorAdd Y component should be 7");
    Assert(result.z == 9.0f, "VectorAdd Z component should be 9");

    std::cout << "[PASS] VectorAdd: all component checks passed" << endline;
}

void TestVectorSubtract() {
    std::cout << "Testing VectorSubtract..." << std::endl;

    Vec3 a = { 7.0f, 8.0f, 9.0f };
    Vec3 b = { 3.0f, 2.0f, 1.0f };
    Vec3 result = VectorSubtract(a, b);

    Assert(result.x == 4.0f, "VectorSubtract X component should be 4");
    Assert(result.y == 6.0f, "VectorSubtract Y component should be 6");
    Assert(result.z == 8.0f, "VectorSubtract Z component should be 8");

    std::cout << "[PASS] VectorSubtract: all component checks passed" << endline;
}

void TestVectorScale() {
    std::cout << "Testing VectorScale..." << std::endl;

    Vec3 v = { 5.0f, 6.0f, 7.0f };
    float scale = 4.0f;
    Vec3 result = VectorScale(v, scale);

    Assert(result.x == 20.0f, "VectorScale X component should be 20");
    Assert(result.y == 24.0f, "VectorScale Y component should be 24");
    Assert(result.z == 28.0f, "VectorScale Z component should be 28");

    std::cout << "[PASS] VectorScale: all component checks passed" << endline;
}

void TestVectorDivide() {
    std::cout << "Testing normal VectorDivide..." << std::endl;

    Vec3 v = { 10.0f, 20.0f, 30.0f };
    float scalar = 10.0f;
    Vec3 result = VectorDivide(v, scalar);

    Assert(result.x == 1.0f, "Normal VectorDivide X component should be 1");
    Assert(result.y == 2.0f, "Normal VectorDivide X component should be 2");
    Assert(result.z == 3.0f, "Normal VectorDivide X component should be 3");

    std::cout << "[PASS] Normal VectorDivide: all component checks passed" << endline;
}

void TestVectorDivideByZero() {
    std::cout << "Testing VectorDivide by Zero..." << std::endl;

    Vec3 v = { 1.0f, 2.0f, 3.0f };
    Vec3 result = VectorDivide(v, 0.0f);

    Assert(result.x == 0.0f && result.y == 0.0f && result.z == 0.0f, "VectorDivide by Zero should return zero");

    std::cout << "[PASS] VectorDivide by Zero: all component checks passed" << endline;
}



void TestVectorMagnitude() {
    std::cout << "Testing VectorMagnitude..." << std::endl;

    // Test with 3-4-5 triangle (should equal 5)
    Vec3 v = { 3.0f, 4.0f, 0.0f };
    float mag = VectorMagnitude(v);

    Assert(FloatEquals(mag, 5.0f), "VectorMagnitude: |(3,4,0)| should be approximately 5");

    std::cout << "[PASS] VectorMagnitude: all checks passed!" << endline;
}

void TestVectorNormalize() {
    std::cout << "Testing VectorNormalize..." << std::endl;

    Vec3 v = { 3.0f, 4.0f, 0.0f };
    Vec3 normalized = VectorNormalize(v);
    float mag = VectorMagnitude(normalized);

    // Normalized vector should have magnitude of 1
    Assert(FloatEquals(mag, 1.0f), "Normalized vector magnitude should be 1");

    std::cout << "[PASS] VectorNormalize: all checks passed!" << endline;
}

void TestZeroVectorNormalize() {
    std::cout << "Testing zero vector normalization..." << std::endl;

    Vec3 zero = { 0.0f, 0.0f, 0.0f };
    Vec3 result = VectorNormalize(zero);

    // Should return zero vector, not crash
    Assert(result.x == 0.0f && result.y == 0.0f && result.z == 0.0f, "Should return zero vector, not crash");

    std::cout << "[PASS] VectorNormalize Zero: all checks passed!" << endline;
}


// VECTOR 2 TESTS

void TestVector2DAdd() {
    std::cout << "Testing VectorAdd2D..." << std::endl;

    Vec2 a = { 1.0f, 2.0f };
    Vec2 b = { 4.0f, 5.0f };
    Vec2 result = VectorAdd2D(a, b);

    // Use assertions to verify correctness
    Assert(result.x == 5.0f, "VectorAdd X component should be 5");
    Assert(result.y == 7.0f, "VectorAdd Y component should be 7");

    std::cout << "[PASS] VectorAdd2D: all component checks passed" << endline;
}

int main() {
    std::cout << "=== Vector 3 Math Tests ===" << std::endl << std::endl;

    TestVectorAdd();
    TestVectorSubtract();
    TestVectorScale();
    TestVectorDivide();
    TestVectorDivideByZero();
    
    TestVectorMagnitude();
    TestVectorNormalize();
    TestZeroVectorNormalize();



    TestVector2DAdd();

    std::cout << std::endl << "All tests passed!" << std::endl;

    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();

    return 0;
}
