//Always include the pch.h first in every cpp
#include "pch.h"

//Then include own items
#include "VectorMath.h"
#include <cmath>

Vec3 VectorAdd(Vec3 a, Vec3 b) {
	return { a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3 VectorSubtract(Vec3 a, Vec3 b) {
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec3 VectorMultiplication(Vec3 v, float scale) {
	return { scale * v.x, scale * v.y, scale * v.z };
}

Vec3 VectorDivide(Vec3 v, float scalar) {
	return { v.x / scalar, v.y / scalar, v.z / scalar };
}

float VectorMagnitude(Vec3 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float VectorMagnitude2D(Vec2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

float VectorMagnitudeSqr(Vec3 v) {
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec3 VectorNormalize(Vec3 v) {
	float m = VectorMagnitude(v);
	if (m < 0.0001f){
		return {0.0f, 0.0f, 0.0f};
	}
	return VectorDivide(v, m);
}

float VectorDot(Vec3 a, Vec3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 VectorCross(Vec3 a, Vec3 b) {
	return { a.y * b.z - a.z * b.y,
			 a.z * b.x - a.x * b.z,
			 a.x * b.y - a.y * b.x };
}

float VectorDistance(Vec3 a, Vec3 b) {
	return VectorMagnitude(VectorSubtract(a, b));
}

Vec3 VectorLerp(Vec3 a, Vec3 b, float t) {
	return {
		a.x + t * (b.x - a.x),
		a.y + t * (b.y - a.y),
		a.z + t * (b.z - a.z)
	};
}


Vec3 VectorReflect(Vec3 v, Vec3 normal) {
	normal = VectorNormalize(normal);
	float d = VectorDot(v, normal);
	return VectorSubtract(v, VectorMultiplication(normal, 2.0f * d));
}

