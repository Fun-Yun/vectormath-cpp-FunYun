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
    Assert(result.y == 2.0f, "Normal VectorDivide Y component should be 2");
    Assert(result.z == 3.0f, "Normal VectorDivide Z component should be 3");

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

void TestVectorDot() {
    std::cout << "Testing VectorDot..." << std::endl;

    Vec3 a = { 1.0f, 2.0f, 3.0f };
    Vec3 b = { 4.0f, 5.0f, 6.0f };

    float result = VectorDot(a, b);

    Assert(result == 32.0f, "VectorDot result should be 32");

    std::cout << "[PASS] VectorDot: all checks passed" << endline;
}

void TestVectorCross() {
    std::cout << "Testing VectorCross..." << std::endl;

    Vec3 a = { 1.0f, 0.0f, 0.0f };
    Vec3 b = { 0.0f, 1.0f, 0.0f };

    Vec3 result = VectorCross(a, b);

    Assert(result.x == 0.0f, "VectorCross X component should be 0");
    Assert(result.y == 0.0f, "VectorCross Y component should be 0");
    Assert(result.z == 1.0f, "VectorCross Z component should be 1");

    std::cout << "[PASS] VectorCross: all component checks passed" << endline;
}




// VECTOR 2 TESTS

void TestVector2DAdd() {
    std::cout << "Testing VectorAdd2D..." << std::endl;

    Vec2 a = { 1.0f, 2.0f };
    Vec2 b = { 4.0f, 5.0f };
    Vec2 result = VectorAdd2D(a, b);

    Assert(result.x == 5.0f, "VectorAdd X component should be 5");
    Assert(result.y == 7.0f, "VectorAdd Y component should be 7");

    std::cout << "[PASS] VectorAdd2D: all component checks passed" << endline;
}

void TestVector2DSubtract() {
    std::cout << "Testing VectorSubtract2D..." << std::endl;

    Vec2 a = { 7.0f, 8.0f};
    Vec2 b = { 3.0f, 2.0f};
    Vec2 result = VectorSubtract2D(a, b);

    Assert(result.x == 4.0f, "VectorSubtract2D X component should be 4");
    Assert(result.y == 6.0f, "VectorSubtract2D Y component should be 6");

    std::cout << "[PASS] VectorSubtract2D: all component checks passed" << endline;
}

void TestVector2DScale() {
    std::cout << "Testing VectorScale2D..." << std::endl;

    Vec2 v = { 5.0f, 6.0f};
    float scale = 4.0f;
    Vec2 result = VectorScale2D(v, scale);

    Assert(result.x == 20.0f, "VectorScale2D X component should be 20");
    Assert(result.y == 24.0f, "VectorScale2D Y component should be 24");

    std::cout << "[PASS] VectorScale2D: all component checks passed" << endline;
}

void TestVector2DDivide() {
    std::cout << "Testing normal VectorDivide2D..." << std::endl;

    Vec2 v = { 10.0f, 20.0f};
    float scalar = 10.0f;
    Vec2 result = VectorDivide2D(v, scalar);

    Assert(result.x == 1.0f, "Normal VectorDivide2D X component should be 1");
    Assert(result.y == 2.0f, "Normal VectorDivide2D X component should be 2");
   
    std::cout << "[PASS] Normal VectorDivide2D: all component checks passed" << endline;
}

void TestVector2DDivideByZero() {
    std::cout << "Testing VectorDivide2D by Zero..." << std::endl;

    Vec2 v = { 1.0f, 2.0f};
    Vec2 result = VectorDivide2D(v, 0.0f);

    Assert(result.x == 0.0f && result.y == 0.0f, "VectorDivide2D by Zero should return zero");

    std::cout << "[PASS] VectorDivide2D by Zero: all component checks passed" << endline;
}

void TestVectorMagnitude2D() {
    std::cout << "Testing VectorMagnitude2D..." << std::endl;

    Vec2 v = { 3.0f, 4.0f};
    float mag = VectorMagnitude2D(v);

    Assert(FloatEquals(mag, 5.0f), "VectorMagnitude: |(3,4)| should be approximately 5");

    std::cout << "[PASS] VectorMagnitude2D: all checks passed!" << endline;
}

void TestVectorNormalize2D() {
    std::cout << "Testing VectorNormalize2D..." << std::endl;

    Vec2 v = { 3.0f, 4.0f};
    Vec2 normalized = VectorNormalize2D(v);
    float mag = VectorMagnitude2D(normalized);

    Assert(FloatEquals(mag, 1.0f), "Normalized vector magnitude should be 1");

    std::cout << "[PASS] VectorNormalize2D: all checks passed!" << endline;
}

void TestZeroVectorNormalize2D() {
    std::cout << "Testing zero vector normalization 2D..." << std::endl;

    Vec2 zero = { 0.0f, 0.0f };
    Vec2 result = VectorNormalize2D(zero);

    Assert(result.x == 0.0f && result.y == 0.0f, "VectorNormalize2D should return zero vector");

    std::cout << "[PASS] VectorNormalize2D Zero: all checks passed!" << endline;
}

void TestVectorDot2D() {
    std::cout << "Testing VectorDot2D..." << std::endl;

    Vec2 a = { 1.0f, 2.0f };
    Vec2 b = { 3.0f, 4.0f };

    float result = VectorDot2D(a, b);

    Assert(result == 11.0f, "VectorDot2D result should be 11");

    std::cout << "[PASS] VectorDot2D: all checks passed" << endline;
}

void TestVectorCross2D() {
    std::cout << "Testing VectorCross2D..." << std::endl;

    Vec2 a = { 1.0f, 0.0f };
    Vec2 b = { 0.0f, 1.0f };

    float result = VectorCross2D(a, b);

    Assert(result == 1.0f, "VectorCross2D result should be 1");

    std::cout << "[PASS] VectorCross2D: all checks passed" << endline;
}

//Pong Specific Tests

void TestVectorLerp() {
    std::cout << "Testing VectorLerp..." << std::endl;

    Vec3 a = { 0.0f, 0.0f, 0.0f };
    Vec3 b = { 10.0f, 20.0f, 30.0f };

    Vec3 result = VectorLerp(a, b, 0.5f);

    Assert(result.x == 5.0f, "VectorLerp X component should be 5");
    Assert(result.y == 10.0f, "VectorLerp Y component should be 10");
    Assert(result.z == 15.0f, "VectorLerp Z component should be 15");

    Vec3 result = VectorLerp(a, b, 0.0f); //Edge case
    Assert(result.x == 0.0f && result.y == 0.0f && result.z == 0.0f, "VectorLerp Zero should return start v");

    Vec3 result = VectorLerp(a, b, 1.0f); //Edge case
    Assert(result.x == 10.0f && result.y == 20.0f && result.z == 30.0f, "VectorLerp at 1 should return end v");

    std::cout << "[PASS] VectorLerp: all component checks passed" << endline;
}

void TestVectorLerp2D() {
    std::cout << "Testing VectorLerp2D..." << std::endl;

    Vec2 a = { 0.0f, 0.0f };
    Vec2 b = { 10.0f, 20.0f };

    Vec2 result = VectorLerp2D(a, b, 0.5f);

    Assert(result.x == 5.0f, "VectorLerp2D X component should be 5");
    Assert(result.y == 10.0f, "VectorLerp2D Y component should be 10");

    Vec2 result = VectorLerp2D(a, b, 0.0f); //Edge Case
    Assert(result.x == 0.0f && result.y == 0.0f, "VectorLerp2D Zero should return start v");

    
    Vec2 result = VectorLerp2D(a, b, 1.0f); //Edge Case
    Assert(result.x == 10.0f && result.y == 20.0f, "VectorLerp2D at 1 should return end v");

    std::cout << "[PASS] VectorLerp2D: all component checks passed" << endline;
}

void TestVectorReflect() {
    std::cout << "Testing VectorReflect..." << std::endl;

    Vec3 v = { 1.0f, -1.0f, 0.0f };
    Vec3 normal = { 0.0f, 1.0f, 0.0f };

    Vec3 result = VectorReflect(v, normal);

    Assert(result.x == 1.0f, "VectorReflect X component should be 1");
    Assert(result.y == 1.0f, "VectorReflect Y component should be 1");
    Assert(result.z == 0.0f, "VectorReflect Z component should be 0");

    std::cout << "[PASS] VectorReflect: all component checks passed" << endline;
}

void TestVectorReflect2D() {
    std::cout << "Testing VectorReflect2D..." << std::endl;

    Vec2 v = { 1.0f, -1.0f };
    Vec2 normal = { 0.0f, 1.0f };

    Vec2 result = VectorReflect2D(v, normal);

    Assert(result.x == 1.0f, "VectorReflect2D X component should be 1");
    Assert(result.y == 1.0f, "VectorReflect2D Y component should be 1");

    std::cout << "[PASS] VectorReflect2D: all component checks passed" << endline;
}

//Advanced Tests

void TestVectorClampMagnitude() {
    std::cout << "Testing VectorClampMagnitude..." << std::endl;

    Vec3 v = { 6.0f, 8.0f, 0.0f }; // magnitude = 10
    Vec3 result = VectorClampMagnitude(v, 5.0f);

    Assert(FloatEquals(VectorMagnitude(result), 5.0f),
        "VectorClampMagnitude magnitude should be 5");

    std::cout << "[PASS] VectorClampMagnitude: all checks passed" << endline;
}

void TestVectorClampMagnitude2D() {
    std::cout << "Testing VectorClampMagnitude2D..." << std::endl;

    Vec2 v = { 6.0f, 8.0f }; // magnitude = 10
    Vec2 result = VectorClampMagnitude2D(v, 5.0f);

    Assert(FloatEquals(VectorMagnitude2D(result), 5.0f),
        "VectorClampMagnitude2D magnitude should be 5");

    std::cout << "[PASS] VectorClampMagnitude2D: all checks passed" << endline;
}

void TestClamp() {
    std::cout << "Testing Clamp..." << std::endl;

    Assert(Clamp(5.0f, 0.0f, 10.0f) == 5.0f, "Clamp should keep value inside range");
    Assert(Clamp(-5.0f, 0.0f, 10.0f) == 0.0f, "Clamp should clamp to min");
    Assert(Clamp(15.0f, 0.0f, 10.0f) == 10.0f, "Clamp should clamp to max");

    std::cout << "[PASS] Clamp: all checks passed" << endline;
}

void TestVectorClamp() {
    std::cout << "Testing VectorClamp..." << std::endl;

    Vec3 v = { -5.0f, 5.0f, 15.0f };
    Vec3 result = VectorClamp(v, 0.0f, 10.0f);

    Assert(result.x == 0.0f, "VectorClamp X should be clamped to 0");
    Assert(result.y == 5.0f, "VectorClamp Y should remain 5");
    Assert(result.z == 10.0f, "VectorClamp Z should be clamped to 10");

    std::cout << "[PASS] VectorClamp: all component checks passed" << endline;
}

void TestVectorClamp2D() {
    std::cout << "Testing VectorClamp2D..." << std::endl;

    Vec2 v = { -5.0f, 15.0f };
    Vec2 result = VectorClamp2D(v, 0.0f, 10.0f);

    Assert(result.x == 0.0f, "VectorClamp2D X should be clamped to 0");
    Assert(result.y == 10.0f, "VectorClamp2D Y should be clamped to 10");

    std::cout << "[PASS] VectorClamp2D: all component checks passed" << endline;
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
    TestVector2DSubtract();
    TestVector2DScale();
    TestVector2DDivide();
    TestVector2DDivideByZero();

    TestVectorMagnitude2D();
    TestVectorNormalize2D();
    TestZeroVectorNormalize2D();

    std::cout << std::endl << "All tests passed!" << std::endl;

    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();

    return 0;
}
