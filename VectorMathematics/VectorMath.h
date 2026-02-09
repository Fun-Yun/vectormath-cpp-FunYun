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

    //Vec2 Operations
    EXPORT Vec2 VectorAdd2D(Vec2 a, Vec2 b);
    EXPORT Vec2 VectorSubtract2D(Vec2 a, Vec2 b);
    EXPORT Vec2 VectorScale2D(Vec2 a, float scale);
    EXPORT Vec2 VectorDivide2D(Vec2 v, float scale);
    
    EXPORT float VectorMagnitude2D(Vec2 v);
    EXPORT Vec2 VectorNormalize2D(Vec2 v);
    EXPORT float VectorDot2D(Vec2 a, Vec2 b);


    //Vec3 Operations
    EXPORT Vec3 VectorAdd(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorSubtract(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorScale(Vec3 v, float scale);
    EXPORT Vec3 VectorDivide(Vec3 v, float scale);

    EXPORT float VectorMagnitude(Vec3 v);
    EXPORT Vec3 VectorNormalize(Vec3 v);
    EXPORT float VectorDot(Vec3 a, Vec3 b);
    EXPORT Vec3 VectorCross(Vec3 a, Vec3 b);

    
    //Pong Specific
    EXPORT Vec3 VectorLerp(Vec3 a, Vec3 b, float t);
    EXPORT Vec3 VectorReflect(Vec3 v, Vec3 normal);

    EXPORT Vec2 VectorLerp2D(Vec2 a, Vec2 b, float t);
    EXPORT Vec2 VectorReflect2D(Vec2 v, Vec2 normal);
}

#endif