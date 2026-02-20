## vectormath-cpp

### Pong Features

-Player 1: W - up, S - down

-Player 2: Up arrow - up, Down arrow - down

-Restart = R

Game ends first to 5.

Ball gets faster every time it bounces

UI for score and win message

Ball bounces off walls and paddles

Ball resets when off screen

### C++ Math DLL + Unity Pong Clone Integration

This project explores vector math by implementing a custom C++ math library and compiling it into a DLL, then integrating it into a Unity Pong clone. The purpose of this project was to understand the mathematics behind movement, collision, and reflection in games instead of relying on built-in systems and functions in unity and other game engines.

The project consists of:

- A C++ vector math library
- A C++ console test application
- A Unity project using the DLL via C# interop

## Architecture Overview

### C++ Math Library

- `VectorMathematics/VectorMath.h`
- `VectorMathematics/VectorMath.cpp`

Compiled as:

- `VectorMathematics.dll`

Exports pure C-style functions using:

- `extern "C"`

to prevent C++ name mangling and allow clean interop with Unity via `DllImport`.

### C++ Test Application

- `VectorMathematicsTests/VectorMathematicsTests.cpp`

A standalone console application used to:

- Validate mathematical correctness
- Test edge cases
- Prevent regressions
- Verify floating-point behavior

### Unity Project – PongClone

- C# wrapper: `Assets/Scripts/VectorMath.cs`
- Interop structs: `Assets/Scripts/Vec2.cs`, `Vec3.cs`
- DLL location: `Assets/Plugins/VectorMathematics.dll`

Unity uses:

- `[DllImport("VectorMathematics")]`

Struct layout is explicitly controlled using:

- `[StructLayout(LayoutKind.Sequential)]`

to guarantee memory compatibility between C++ and C#.

## Implemented Features

### Vec2

- Addition and Subtraction
- Scalar multiplication and division
- Magnitude
- Normalization
- Dot product
- 2D cross product

### Vec3

- Addition and Subtraction
- Scalar multiplication and division
- Magnitude
- Normalization
- Dot product
- Cross product (returns Vec3)

### Pong-Specific Utilities

These were implemented specifically to drive gameplay:

- `VectorLerp` / `VectorLerp2D`
- `VectorReflect` / `VectorReflect2D`

Reflection powers the Pong ball bounce behavior.

### Advanced Utilities

- Clamp
- VectorClamp and VectorClamp2D
- VectorClampMagnitude and VectorClampMagnitude2D

## Why Vectors and Matrices Matter in Game Development

Even the simplest game is built on vector mathematics.

1. **Movement**

- Position, velocity, and acceleration are vectors.
- Movement is fundamentally:

```text
position += velocity * deltaTime
```

Without vector addition and scaling, nothing moves.

2. **Direction & Distance**

- Magnitude gives distance.
- Normalize gives direction.

Used for:

- AI steering
- Projectile aiming
- Homing mechanics
- Player input direction

3. **Facing & Alignment**

The dot product enables:

- “Is the target in front of me?”
- Field-of-view checks
- Angle comparison
- Alignment measurement

4. **Collision & Bounce**

Reflection formula:

```text
R = V - 2 * dot(V, N) * N
```

This powers:

- Ball bounces
- Bullet ricochets
- Physics responses

Implementing this manually clarifies how physics engines work internally.

5. **Matrices (Future Work)**

While not implemented yet, matrices are the natural extension:

- Transformations (rotate / scale / translate)
- Camera projection
- 3D coordinate space conversion
- Model-view-projection pipelines

Vectors describe direction and magnitude.  
Matrices transform entire coordinate systems.

## Implementation Details & Engineering Decisions

### 1. DLL Export Strategy

Unity cannot directly call C++-mangled names.  
Using:

```text
extern "C"
#define EXPORT __declspec(dllexport)
```

ensures stable exported symbols.

This was critical for successful interop.

### 2. Struct Simplicity

Vec2 and Vec3 only contain float members.

- No constructors.
- No methods.
- No padding tricks.

This guarantees:

- Predictable memory layout
- Safe cross-language interop
- No marshalling complexity

### 3. Defensive Math (“Math Explosion Prevention”)

Floating point math can easily break systems.

I implemented safeguards:

**Safe Divide**

```text
if (abs(scalar) < 0.0001f)
    return ZeroVector;
```

Prevents:

- Division by near-zero
- Infinity propagation
- NaN contamination

**Safe Normalize**

If magnitude is approximately zero:

```text
return ZeroVector;
```

Prevents:

- NaNs
- Invalid direction vectors
- Cascading physics errors

**Reflection Normal Safety**

I normalize the normal vector inside VectorReflect.

This makes the function:

- Safer
- More robust
- Less error-prone for external callers

### 4. Composition Over Duplication

Advanced operations reuse basic ones.

For example:

- ClampMagnitude uses Normalize + Scale
- Reflection uses Dot + Scale + Subtract

This mimics real engine design:

- Small, reliable primitives
- Complex behavior built from them

## Testing Strategy

The console test application includes:

- Custom Assert() system
- FloatEquals() with epsilon tolerance

Structured test groups:

- Vec3 basics
- Vec2 basics
- Lerp & Reflect
- Clamp operations
- Edge cases

Edge cases tested:

- Divide by zero
- Normalize zero vector
- Clamp at the boundaries (min/max)
- Very small floats

This testing layer ensures:

- Mathematical correctness
- Stability
- Predictable behavior

## How the DLL is used in PongClone

In the Unity project I wired the C++ functions directly into gameplay:

- `BallMovement.cs`  
  - Uses `VectorScale2D` and `VectorAdd2D` to move the ball based on direction, speed, and `deltaTime`.  
  - Uses `VectorNormalize2D` to keep the direction vector unit length.  
  - Uses `VectorReflect2D` to bounce the ball off paddles and walls.  
  - Uses `Clamp` when calculating the bounce angle so it stays within a reasonable range.

- `PaddleMovement.cs`  
  - Uses `VectorScale2D` and `VectorAdd2D` to move paddles from input.  
  - Uses `Clamp` to keep paddles inside the play area.  
  - Uses `VectorLerp2D` to smoothly interpolate (`lerp`) from the current paddle position to the target position for smoother movement.

## Reflection


Having used Unity for a while and becoming comfortable with its built‑in math/vector library, I found it very eyeopening to do all of this from scratch. I first built the Pong game using Unity’s own `Vector` types, then commented that code out and rewrote the same behaviour using my own `Vec` structs and DLL functions. Seeing both versions side by side made the math feel much more concrete, especially when I watched the ball bounce using my own `VectorReflect2D` and saw how `Clamp` and safe normalization stopped things from exploding when values went out of range.

Working this way forced me to think more carefully about what the engine is actually doing for me. Instead of just calling `Vector3` functions, I had to worry about things like division by zero, normalizing bad inputs, and keeping data layouts compatible between C++ and C#. This project taught me a lot about vector mathematics and also C++ engineering, like creating DLLs, exporting symbols correctly, and wiring them up to another engine.

Overall this project made me more confident working closer to the “engine” layer, not just inside gameplay scripts. It expanded my understanding of both C++ and Unity, and it made me more interested in growing this math library for use in more Unity projects and eventually move towards building my own engine. Writing my own math helped me understand what’s really happening in my games, whether I’m using Unity, Godot, or something custom made in the future.
