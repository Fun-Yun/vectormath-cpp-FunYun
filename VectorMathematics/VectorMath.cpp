//Always include the pch.h first in every cpp
#include "pch.h"

//Then include own items
#include "VectorMath.h"
#include <cmath>


Vec2 VectorAdd2D(Vec2 a, Vec2 b) {
	return { a.x + b.x, a.y + b.y };
}

Vec2 VectorSubtract2D(Vec2 a, Vec2 b) {
	return { a.x - b.x, a.y - b.y};
}

Vec2 VectorScale2D(Vec2 v, float scale) {
	return { scale * v.x, scale * v.y};
}

Vec2 VectorDivide2D(Vec2 v, float scalar) {
	if (scalar < 0.0001f) {
		return {0.0f};
	}
	return { v.x / scalar, v.y / scalar};
}

float VectorMagnitude2D(Vec2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

Vec2 VectorNormalize2D(Vec2 v) {
	float m = VectorMagnitude2D(v);
	if (m < 0.0001f) {
		return {0.0f, 0.0f};
	}
	return VectorDivide2D(v, m);
}

float VectorDot2D(Vec2 a, Vec2 b) {
	return a.x * b.x + a.y * b.y;
}

float VectorCross2D(Vec2 a, Vec2 b)
{
	return a.x * b.y - a.y * b.x;
}

Vec3 VectorAdd(Vec3 a, Vec3 b) {
	return { a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3 VectorSubtract(Vec3 a, Vec3 b) {
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

Vec3 VectorScale(Vec3 v, float scale) {
	return { scale * v.x, scale * v.y, scale * v.z };
}

Vec3 VectorDivide(Vec3 v, float scalar) {
	if (scalar < 0.0001f) {
		return { 0.0f };
	}
	return { v.x / scalar, v.y / scalar, v.z / scalar };
}

float VectorMagnitude(Vec3 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
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
	return VectorSubtract(v, VectorScale(normal, 2.0f * d));
}

Vec2 VectorLerp2D(Vec2 a, Vec2 b, float t) {
	return {
		a.x + t * (b.x - a.x),
		a.y + t * (b.y - a.y),
	};
}

Vec2 VectorReflect2D(Vec2 v, Vec2 normal) {
	normal = VectorNormalize2D(normal);
	float d = VectorDot2D(v, normal);
	return VectorSubtract2D(v, VectorScale2D(normal, 2.0f * d));
}

Vec2 VectorClampMagnitude2D(Vec2 v, float maxLength) {
	float m = VectorMagnitude2D(v);
	if (m < 0.0001f) {
		return { 0.0f, 0.0f };
	}
	if (m > maxLength) {
		v = VectorNormalize2D(v);
		return VectorScale2D(v, maxLength);
	}
	return v;
}

Vec3 VectorClampMagnitude(Vec3 v, float maxLength) {
	float m = VectorMagnitude(v);
	if (m < 0.0001f) {
		return { 0.0f, 0.0f, 0.0f };
	}
	if (m > maxLength) {
		v = VectorNormalize(v);
		return VectorScale(v, maxLength);
	}
	return v;
}

float Clamp(float v, float minVal, float maxVal) {
	if (v > maxVal) 
		return maxVal;
	if (v < minVal) 
		return minVal;
	return v;
}

Vec3 VectorClamp(Vec3 v, float minVal, float maxVal) {
	return{ Clamp(v.x, minVal, maxVal),
		Clamp(v.y, minVal,maxVal),
		Clamp(v.z, minVal, maxVal)};
}

Vec2 VectorClamp2D(Vec2 v, float minVal, float maxVal) {
	return{ Clamp(v.x, minVal, maxVal),
		Clamp(v.y, minVal,maxVal)};
}


