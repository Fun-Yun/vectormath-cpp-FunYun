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
        std::cin.get();
        exit(1);
    }
}


/// VECTOR 3 TESTS

void TestVectorAdd() {
    std::cout << "Testing VectorAdd..." << std::endl;

    Vec3 a = { 1.0f, 2.0f, 3.0f };
    Vec3 b = { 4.0f, 5.0f, 6.0f };
    Vec3 expectedResult = { 5, 7, 9 };
    
    Vec3 result = VectorAdd(a, b);

    Assert(result.x == expectedResult.x, "VectorAdd X component should be 5");
    Assert(result.y == expectedResult.y, "VectorAdd Y component should be 7");
    Assert(result.z == expectedResult.z, "VectorAdd Z component should be 9");

    std::cout << "[PASS] VectorAdd: all component checks passed" << endline;
}

void TestVectorSubtract() {
    std::cout << "Testing VectorSubtract..." << std::endl;

    Vec3 a = { 7.0f, 8.0f, 9.0f };
    Vec3 b = { 3.0f, 2.0f, 1.0f };
    Vec3 expectedResult = { 4.0f, 6.0f, 8.0f };
    
    Vec3 result = VectorSubtract(a, b);

    Assert(result.x == expectedResult.x, "VectorSubtract X component should be 4");
    Assert(result.y == expectedResult.y, "VectorSubtract Y component should be 6");
    Assert(result.z == expectedResult.z, "VectorSubtract Z component should be 8");

    std::cout << "[PASS] VectorSubtract: all component checks passed" << endline;
}

void TestVectorScale() {
    std::cout << "Testing VectorScale..." << std::endl;

    Vec3 v = { 5.0f, 6.0f, 7.0f };
    float scale = 4.0f;
    Vec3 expectedResult = { 20.0f, 24.0f, 28.0f };

    Vec3 result = VectorScale(v, scale);

    Assert(result.x == expectedResult.x, "VectorScale X component should be 20");
    Assert(result.y == expectedResult.y, "VectorScale Y component should be 24");
    Assert(result.z == expectedResult.z, "VectorScale Z component should be 28");

    std::cout << "[PASS] VectorScale: all component checks passed" << endline;
}

void TestVectorDivide() {
    std::cout << "Testing normal VectorDivide..." << std::endl;

    Vec3 v = { 10.0f, 20.0f, 30.0f };
    float scalar = 10.0f;
    Vec3 expectedResult = { 1.0f, 2.0f, 3.0f };

    Vec3 result = VectorDivide(v, scalar);

    Assert(result.x == expectedResult.x, "Normal VectorDivide X component should be 1");
    Assert(result.y == expectedResult.y, "Normal VectorDivide Y component should be 2");
    Assert(result.z == expectedResult.z, "Normal VectorDivide Z component should be 3");

    std::cout << "[PASS] Normal VectorDivide: all component checks passed" << endline;
}

void TestVectorDivideByZero() {
    std::cout << "Testing VectorDivide by Zero..." << std::endl;

    Vec3 v = { 1.0f, 2.0f, 3.0f };
    Vec3 expectedResult = { 0.0f, 0.0f, 0.0f };

    Vec3 result = VectorDivide(v, 0.0f);

    Assert(result.x == expectedResult.x, "VectorDivide by Zero should return zero");
    Assert(result.y == expectedResult.y, "VectorDivide by Zero should return zero");
    Assert(result.z == expectedResult.z, "VectorDivide by Zero should return zero");

    std::cout << "[PASS] VectorDivide by Zero: all component checks passed" << endline;
}



void TestVectorMagnitude() {
    std::cout << "Testing VectorMagnitude..." << std::endl;

    Vec3 v = { 3.0f, 4.0f, 0.0f };
    float expectedResult = 5.0f;

    float result = VectorMagnitude(v);

    Assert(FloatEquals(result, expectedResult), "VectorMagnitude: (3,4,0) should be approximately 5");

    std::cout << "[PASS] VectorMagnitude: all checks passed!" << endline;
}

void TestVectorNormalize() {
    std::cout << "Testing VectorNormalize..." << std::endl;

    Vec3 v = { 3.0f, 4.0f, 0.0f };
    Vec3 normalizedV = VectorNormalize(v);
    float expectedResult = 1.0f;

    float result = VectorMagnitude(normalizedV);

    Assert(FloatEquals(result, 1.0f), "Normalized vector magnitude should be 1");

    std::cout << "[PASS] VectorNormalize: all checks passed!" << endline;
}

void TestZeroVectorNormalize() {
    std::cout << "Testing zero vector normalization..." << std::endl;

    Vec3 v = { 0.0f, 0.0f, 0.0f };
    Vec3 expectedResult = { 0.0f, 0.0f, 0.0f };

    Vec3 result = VectorNormalize(v);

    Assert(result.x == expectedResult.x, "VectorNormalize by Zero Should return zero vector, not crash");
    Assert(result.y == expectedResult.y, "VectorNormalize by Zero Should return zero vector, not crasho");
    Assert(result.z == expectedResult.z, "VectorNormalize by Zero Should return zero vector, not crash");

    std::cout << "[PASS] VectorNormalize by Zero: all checks passed!" << endline;
}

void TestVectorDot() {
    std::cout << "Testing VectorDot..." << std::endl;

    Vec3 a = { 1.0f, 2.0f, 3.0f };
    Vec3 b = { 4.0f, 5.0f, 6.0f };
    float expectedResult = 32.0f;

    float result = VectorDot(a, b);

    Assert(result == expectedResult, "VectorDot result should be 32");

    std::cout << "[PASS] VectorDot: all checks passed" << endline;
}

void TestVectorCross() {
    std::cout << "Testing VectorCross..." << std::endl;

    Vec3 a = { 1.0f, 0.0f, 0.0f };
    Vec3 b = { 0.0f, 1.0f, 0.0f };
    Vec3 expectedResult = { 0.0f, 0.0f, 1.0f };

    Vec3 result = VectorCross(a, b);

    Assert(result.x == expectedResult.x, "VectorCross X component should be 0");
    Assert(result.y == expectedResult.y, "VectorCross Y component should be 0");
    Assert(result.z == expectedResult.z, "VectorCross Z component should be 1");

    std::cout << "[PASS] VectorCross: all component checks passed" << endline;
}




// VECTOR 2 TESTS

void TestVector2DAdd() {
    std::cout << "Testing VectorAdd2D..." << std::endl;

    Vec2 a = { 1.0f, 2.0f };
    Vec2 b = { 4.0f, 5.0f };
    Vec2 expectedResult = { 5.0f, 7.0f };

    Vec2 result = VectorAdd2D(a, b);

    Assert(result.x == expectedResult.x, "VectorAdd X component should be 5");
    Assert(result.y == expectedResult.y, "VectorAdd Y component should be 7");

    std::cout << "[PASS] VectorAdd2D: all component checks passed" << endline;
}

void TestVector2DSubtract() {
    std::cout << "Testing VectorSubtract2D..." << std::endl;

    Vec2 a = { 7.0f, 8.0f};
    Vec2 b = { 3.0f, 2.0f};
    Vec2 expectedResult = { 4.0f, 6.0f };

    Vec2 result = VectorSubtract2D(a, b);

    Assert(result.x == expectedResult.x, "VectorSubtract2D X component should be 4");
    Assert(result.y == expectedResult.y, "VectorSubtract2D Y component should be 6");

    std::cout << "[PASS] VectorSubtract2D: all component checks passed" << endline;
}

void TestVector2DScale() {
    std::cout << "Testing VectorScale2D..." << std::endl;

    Vec2 v = { 5.0f, 6.0f};
    float scale = 4.0f;
    Vec2 expectedResult = { 20.0f, 24.0f };

    Vec2 result = VectorScale2D(v, scale);

    Assert(result.x == expectedResult.x, "VectorScale2D X component should be 20");
    Assert(result.y == expectedResult.y, "VectorScale2D Y component should be 24");

    std::cout << "[PASS] VectorScale2D: all component checks passed" << endline;
}

void TestVector2DDivide() {
    std::cout << "Testing normal VectorDivide2D..." << std::endl;

    Vec2 v = { 10.0f, 20.0f};
    float scalar = 10.0f;
    Vec2 expectedResult = { 1.0f, 2.0f };

    Vec2 result = VectorDivide2D(v, scalar);

    Assert(result.x == expectedResult.x, "Normal VectorDivide2D X component should be 1");
    Assert(result.y == expectedResult.y, "Normal VectorDivide2D X component should be 2");
   
    std::cout << "[PASS] Normal VectorDivide2D: all component checks passed" << endline;
}

void TestVector2DDivideByZero() {
    std::cout << "Testing VectorDivide2D by Zero..." << std::endl;

    Vec2 v = { 1.0f, 2.0f};
    Vec2 expectedResult = { 0.0f, 0.0f };

    Vec2 result = VectorDivide2D(v, 0.0f);

    Assert(result.x == expectedResult.x, "VectorDivide2D by Zero should return zero");
    Assert(result.y == expectedResult.y, "VectorDivide2D by Zero should return zero");

    std::cout << "[PASS] VectorDivide2D by Zero: all component checks passed" << endline;
}

void TestVectorMagnitude2D() {
    std::cout << "Testing VectorMagnitude2D..." << std::endl;

    Vec2 v = { 3.0f, 4.0f};
    float expectedResult = 5.0f;

    float result = VectorMagnitude2D(v);

    Assert(FloatEquals(result, expectedResult), "VectorMagnitude: (3,4) should be approximately 5");

    std::cout << "[PASS] VectorMagnitude2D: all checks passed!" << endline;
}

void TestVectorNormalize2D() {
    std::cout << "Testing VectorNormalize2D..." << std::endl;

    Vec2 v = { 3.0f, 4.0f};
    Vec2 normalized = VectorNormalize2D(v);
    float expectedResult = 1.0f;

    float result = VectorMagnitude2D(normalized);

    Assert(FloatEquals(result, expectedResult), "Normalized vector magnitude should be 1");

    std::cout << "[PASS] VectorNormalize2D: all checks passed!" << endline;
}

void TestZeroVectorNormalize2D() {
    std::cout << "Testing zero vector normalization 2D..." << std::endl;

    Vec2 zero = { 0.0f, 0.0f };
    Vec2 expectedResult = { 0.0f, 0.0f };

    Vec2 result = VectorNormalize2D(zero);

    Assert(result.x == expectedResult.x, "VectorNormalize2D should return zero vector");
    Assert(result.y == expectedResult.y, "VectorNormalize2D should return zero vector");

    std::cout << "[PASS] VectorNormalize2D Zero: all checks passed!" << endline;
}

void TestVectorDot2D() {
    std::cout << "Testing VectorDot2D..." << std::endl;

    Vec2 a = { 1.0f, 2.0f };
    Vec2 b = { 3.0f, 4.0f };
    float expectedResult = 11.0f;

    float result = VectorDot2D(a, b);

    Assert(result == expectedResult, "VectorDot2D result should be 11");

    std::cout << "[PASS] VectorDot2D: all checks passed" << endline;
}

void TestVectorCross2D() {
    std::cout << "Testing VectorCross2D..." << std::endl;

    Vec2 a = { 1.0f, 0.0f };
    Vec2 b = { 0.0f, 1.0f };
    float expectedResult = 1.0f;

    float result = VectorCross2D(a, b);

    Assert(result == expectedResult, "VectorCross2D result should be 1");

    std::cout << "[PASS] VectorCross2D: all checks passed" << endline;
}

//Pong Specific Tests

void TestVectorLerp() {
    std::cout << "Testing VectorLerp..." << std::endl;

    Vec3 a = { 0.0f, 0.0f, 0.0f };
    Vec3 b = { 10.0f, 20.0f, 30.0f };
    Vec3 expectedResult = { 5.0f, 10.0f, 15.0f };

    Vec3 result = VectorLerp(a, b, 0.5f);

    Assert(result.x == 5.0f, "VectorLerp X component should be 5");
    Assert(result.y == 10.0f, "VectorLerp Y component should be 10");
    Assert(result.z == 15.0f, "VectorLerp Z component should be 15");

    std::cout << "[PASS] VectorLerp: all component checks passed" << endline;
}

void TestVectorLerpZeroEdgeCase() {
    std::cout << "Testing VectorLerp Zero..." << std::endl;

    Vec3 a = { 0.0f, 0.0f, 0.0f };
    Vec3 b = { 10.0f, 20.0f, 30.0f };
    Vec3 expectedResult = { 0.0f, 0.0f, 0.0f };

    Vec3 result = VectorLerp(a, b, 0.0f); //Edge case
    Assert(result.x == expectedResult.x, "VectorLerp Zero should return start v");
    Assert(result.y == expectedResult.y, "VectorLerp Zero should return start v");
    Assert(result.z == expectedResult.z, "VectorLerp Zero should return start v");

    std::cout << "[PASS] VectorLerpZero: all component checks passed" << endline;
}

void TestVectorLerpOneEdgeCase() {
    std::cout << "Testing VectorLerp One..." << std::endl;

    Vec3 a = { 0.0f, 0.0f, 0.0f };
    Vec3 b = { 10.0f, 20.0f, 30.0f };
    Vec3 expectedResult = { 10.0f, 20.0f, 30.0f };

    Vec3 result = VectorLerp(a, b, 1.0f); //Edge case
    Assert(result.x == expectedResult.x, "VectorLerp at 1 should return end v");
    Assert(result.y == expectedResult.y, "VectorLerp at 1 should return end v");
    Assert(result.z == expectedResult.z, "VectorLerp at 1 should return end v");

    std::cout << "[PASS] VectorLerpOne: all component checks passed" << endline;
}

void TestVectorLerp2D() {
    std::cout << "Testing VectorLerp2D..." << std::endl;

    Vec2 a = { 0.0f, 0.0f };
    Vec2 b = { 10.0f, 20.0f };
    Vec2 expectedResult = { 5.0f, 10.0f };

    Vec2 result = VectorLerp2D(a, b, 0.5f);

    Assert(result.x == 5.0f, "VectorLerp2D X component should be 5");
    Assert(result.y == 10.0f, "VectorLerp2D Y component should be 10");

    std::cout << "[PASS] VectorLerp2D: all component checks passed" << endline;
}

void TestVector2DLerpZeroEdgeCase() {
    std::cout << "Testing VectorLerp2D Zero..." << std::endl;

    Vec2 a = { 0.0f, 0.0f };
    Vec2 b = { 10.0f, 20.0f };
    Vec2 expectedResult = { 0.0f, 0.0f };

    Vec2 result = VectorLerp2D(a, b, 0.0f); //Edge case
    
    Assert(result.x == expectedResult.x, "Vector2DLerp Zero should return start v");
    Assert(result.y == expectedResult.y, "Vector2DLerp Zero should return start v");

    std::cout << "[PASS] Vector2DLerpZero: all component checks passed" << endline;
}

void TestVector2DLerpOneEdgeCase() {
    std::cout << "Testing VectorLerp2D One..." << std::endl;

    Vec2 a = { 0.0f, 0.0f };
    Vec2 b = { 10.0f, 20.0f };;
    Vec2 expectedResult = { 10.0f, 20.0f };

    Vec2 result = VectorLerp2D(a, b, 1.0f); //Edge case
    
    Assert(result.x == expectedResult.x, "VectorLerp2D at 1 should return end v");
    Assert(result.y == expectedResult.y, "VectorLerp2D at 1 should return end v");

    std::cout << "[PASS] Vector2DLerpOne: all component checks passed" << endline;
}


void TestVectorReflect() {
    std::cout << "Testing VectorReflect..." << std::endl;

    Vec3 v = { 1.0f, -1.0f, 0.0f };
    Vec3 normal = { 0.0f, 1.0f, 0.0f };
    Vec3 expectedResult = { 1.0f, 1.0f, 0.0f };

    Vec3 result = VectorReflect(v, normal);

    Assert(result.x == expectedResult.x, "VectorReflect X component should be 1");
    Assert(result.y == expectedResult.y, "VectorReflect Y component should be 1");
    Assert(result.z == expectedResult.z, "VectorReflect Z component should be 0");

    std::cout << "[PASS] VectorReflect: all component checks passed" << endline;
}

void TestVectorReflect2D() {
    std::cout << "Testing VectorReflect2D..." << std::endl;

    Vec2 v = { 1.0f, -1.0f };
    Vec2 normal = { 0.0f, 1.0f };
    Vec2 expectedResult = { 1.0f, 1.0f };

    Vec2 result = VectorReflect2D(v, normal);

    Assert(result.x == expectedResult.x, "VectorReflect2D X component should be 1");
    Assert(result.y == expectedResult.y, "VectorReflect2D Y component should be 1");

    std::cout << "[PASS] VectorReflect2D: all component checks passed" << endline;
}

//Advanced Tests

void TestVectorClampMagnitude() {
    std::cout << "Testing VectorClampMagnitude..." << std::endl;

    Vec3 v = { 3.0f, 4.0f, 0.0f };
    float maxLength = 2.0f;
    Vec3 expectedResult = { 1.20f, 1.60f, 0.0f };

    Vec3 result = VectorClampMagnitude(v, maxLength);

    Assert(result.x == expectedResult.x, "VectorClampMagnitude X should be 1.2");
    Assert(result.y == expectedResult.y, "VectorClampMagnitude Y should be 1.6");
    Assert(result.z == expectedResult.z, "VectorClampMagnitude Z should be 0");

    std::cout << "[PASS] VectorClampMagnitude: all component checks passed" << endline;
}

void TestVectorClampMagnitudeEdgeCase() {
    std::cout << "Testing VectorClampMagnitude Edge Case..." << std::endl;

    Vec3 v = { 1.0f, 2.0f, 2.0f }; // magnitude = 3
    float maxLength = 5.0f;

    Vec3 expectedResult = { 1.0f, 2.0f, 2.0f };
    Vec3 result = VectorClampMagnitude(v, maxLength);

    Assert(result.x == expectedResult.x, "VectorClampMagnitude edge X incorrect");
    Assert(result.y == expectedResult.y, "VectorClampMagnitude edge Y incorrect");
    Assert(result.z == expectedResult.z, "VectorClampMagnitude edge Z incorrect");

    std::cout << "[PASS] VectorClampMagnitudeEdgeCase: all component checks passed" << endline;
}

void TestVectorClampMagnitudeZeroEdgeCase() {
    std::cout << "Testing VectorClampMagnitude Zero Edge Case..." << std::endl;

    Vec3 v = { 0.0f, 0.0f, 0.0f };
    float maxLength = 5.0f;
    Vec3 expectedResult = { 0.0f, 0.0f, 0.0f };

    Vec3 result = VectorClampMagnitude(v, maxLength);

    Assert(result.x == expectedResult.x, "VectorClampMagnitude zero X incorrect");
    Assert(result.y == expectedResult.y, "VectorClampMagnitude zero Y incorrect");
    Assert(result.z == expectedResult.z, "VectorClampMagnitude zero Z incorrect");

    std::cout << "[PASS] VectorClampMagnitudeZeroEdgeCase: all component checks passed" << endline;
}

void TestVectorClampMagnitude2D() {
    std::cout << "Testing VectorClampMagnitude2D..." << std::endl;

    Vec2 v = { 6.0f, 8.0f };
    float maxLength = 5.0f;

    Vec2 expectedResult = { 3.0f, 4.0f };
    Vec2 result = VectorClampMagnitude2D(v, maxLength);

    Assert(result.x == expectedResult.x, "VectorClampMagnitude2D X should be 3");
    Assert(result.y == expectedResult.y, "VectorClampMagnitude2D Y should be 4");

    std::cout << "[PASS] VectorClampMagnitude2D: all component checks passed" << endline;
}

void TestVectorClampMagnitude2DEdgeCase() {
    std::cout << "Testing VectorClampMagnitude2D Edge Case..." << std::endl;

    Vec2 v = { 2.0f, 1.0f }; // magnitude < max
    float maxLength = 5.0f;

    Vec2 expectedResult = { 2.0f, 1.0f };
    Vec2 result = VectorClampMagnitude2D(v, maxLength);

    Assert(result.x == expectedResult.x, "VectorClampMagnitude2D edge X incorrect");
    Assert(result.y == expectedResult.y, "VectorClampMagnitude2D edge Y incorrect");

    std::cout << "[PASS] VectorClampMagnitude2DEdgeCase: all component checks passed" << endline;
}

void TestClamp() {
    std::cout << "Testing Clamp..." << std::endl;

    Assert(Clamp(5.0f, 0.0f, 10.0f) == 5.0f, "Clamp should keep value inside range");
    Assert(Clamp(-5.0f, 0.0f, 10.0f) == 0.0f, "Clamp should clamp to min");
    Assert(Clamp(15.0f, 0.0f, 10.0f) == 10.0f, "Clamp should clamp to max");

    std::cout << "[PASS] Clamp: all checks passed" << endline;
}

void TestClampEdgeCase() {
    std::cout << "Testing Clamp Edge Cases..." << std::endl;

    Assert(Clamp(0.0f, 0.0f, 10.0f) == 0.0f, "Clamp should return min when value equals min");
    Assert(Clamp(10.0f, 0.0f, 10.0f) == 10.0f, "Clamp should return max when value equals max");

    std::cout << "[PASS] ClampEdgeCases: all checks passed" << endline;
}

void TestVectorClamp() {
    std::cout << "Testing VectorClamp..." << std::endl;

    Vec3 v = { -5.0f, 5.0f, 15.0f };
    float minRange = 0.0f;
    float maxRange = 10.0f;
    Vec3 expectedResult = { 0.0f, 5.0f, 10.0f };

    Vec3 result = VectorClamp(v, minRange, maxRange);

    Assert(result.x == expectedResult.x, "VectorClamp X should be 0");
    Assert(result.y == expectedResult.y, "VectorClamp Y should be 5");
    Assert(result.z == expectedResult.z, "VectorClamp Z should be 10");

    std::cout << "[PASS] VectorClamp: all component checks passed" << endline;
}

void TestVectorClampEdgeCase() {
    std::cout << "Testing VectorClamp Edge Case..." << std::endl;

    Vec3 v = { 0.0f, 10.0f, 5.0f };
    float minRange = 0.0f;
    float maxRange = 10.0f;
    Vec3 expectedResult = { 0.0f, 10.0f, 5.0f };

    Vec3 result = VectorClamp(v, minRange, maxRange);

    Assert(result.x == expectedResult.x, "VectorClamp edge X incorrect");
    Assert(result.y == expectedResult.y, "VectorClamp edge Y incorrect");
    Assert(result.z == expectedResult.z, "VectorClamp edge Z incorrect");

    std::cout << "[PASS] VectorClampEdgeCase: all component checks passed" << endline;
}

void TestVectorClamp2D() {
    std::cout << "Testing VectorClamp2D..." << std::endl;

    Vec2 v = { -2.0f, 12.0f };
    float minRange = 0.0f;
    float maxRange = 10.0f;
    Vec2 expectedResult = { 0.0f, 10.0f };

    Vec2 result = VectorClamp2D(v, minRange, maxRange);

    Assert(result.x == expectedResult.x, "VectorClamp2D X component incorrect");
    Assert(result.y == expectedResult.y, "VectorClamp2D Y component incorrect");

    std::cout << "[PASS] VectorClamp2D: all component checks passed" << endline;
}

void TestVectorClamp2DEdgeCase() {
    std::cout << "Testing VectorClamp2D Edge Case..." << std::endl;

    Vec2 v = { 0.0f, 10.0f };
    float minRange = 0.0f;
    float maxRange = 10.0f;
    Vec2 expectedResult = { 0.0f, 10.0f };

    Vec2 result = VectorClamp2D(v, minRange, maxRange);

    Assert(result.x == expectedResult.x, "VectorClamp2D edge X incorrect");
    Assert(result.y == expectedResult.y, "VectorClamp2D edge Y incorrect");

    std::cout << "[PASS] VectorClamp2DEdgeCase: all component checks passed" << endline;
}

int main() {
    std::cout << "=== Vector 3 Math Tests ===" << std::endl << std::endl;

    // ===== Vector3 Basic =====
    TestVectorAdd();
    TestVectorSubtract();
    TestVectorScale();
    TestVectorDivide();
    TestVectorDivideByZero();

    TestVectorMagnitude();
    TestVectorNormalize();
    TestZeroVectorNormalize();

    TestVectorDot();
    TestVectorCross();

    std::cout << "=== Vector 2 Math Tests ===" << std::endl << std::endl;

    // ===== Vector2 Basic =====
    TestVector2DAdd();
    TestVector2DSubtract();
    TestVector2DScale();
    TestVector2DDivide();
    TestVector2DDivideByZero();

    TestVectorMagnitude2D();
    TestVectorNormalize2D();
    TestZeroVectorNormalize2D();

    TestVectorDot2D();
    TestVectorCross2D();

    std::cout << "=== Lerp & Reflect Tests ===" << std::endl << std::endl;

    // ===== Lerp 3D =====
    TestVectorLerp();
    TestVectorLerpZeroEdgeCase();
    TestVectorLerpOneEdgeCase();

    // ===== Lerp 2D =====
    TestVectorLerp2D();
    TestVector2DLerpZeroEdgeCase();
    TestVector2DLerpOneEdgeCase();

    // ===== Reflect =====
    TestVectorReflect();
    TestVectorReflect2D();

    std::cout << "=== Clamp & Advanced Tests ===" << std::endl << std::endl;

    // ===== Clamp Magnitude 3D =====
    TestVectorClampMagnitude();
    TestVectorClampMagnitudeEdgeCase();
    TestVectorClampMagnitudeZeroEdgeCase();

    // ===== Clamp Magnitude 2D =====
    TestVectorClampMagnitude2D();
    TestVectorClampMagnitude2DEdgeCase();

    // ===== Scalar Clamp =====
    TestClamp();
    TestClampEdgeCase();

    // ===== Vector Clamp 3D =====
    TestVectorClamp();
    TestVectorClampEdgeCase();

    // ===== Vector Clamp 2D =====
    TestVectorClamp2D();
    TestVectorClamp2DEdgeCase();

    std::cout << std::endl << "All tests passed!" << std::endl;
    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();

    return 0;
}
