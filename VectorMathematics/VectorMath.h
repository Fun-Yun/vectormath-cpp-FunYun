#pragma once

#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" {
    EXPORT Vec3 VectorAdd(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorSubtract(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorMultiplication(Vec3 v, float scale);
    EXPORT Vec3 VectorDivide(Vec3 v, float scale);

    EXPORT float VectorMagnitude(Vec3 v);
    EXPORT float VectorMagnitude2D(Vec2 v);
    EXPORT float VectorMagnitudeSqr(Vec3 v);

    EXPORT Vec3 VectorNormalize(Vec3 v);

    EXPORT float VectorDot(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorCross(Vec3 a, Vec3 b);

    EXPORT float VectorDistance(Vec3 a, Vec3 b);

    EXPORT Vec3 VectorLerp(Vec3 a, Vec3 b, float t);
    EXPORT Vec3 VectorReflect(Vec3 v, Vec3 normal);
 
}

#endif