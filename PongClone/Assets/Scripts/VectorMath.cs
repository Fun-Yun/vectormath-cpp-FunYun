using System.Runtime.InteropServices;

public static class VectorMath
{
    private const string DllName = "VectorMathematics";
    
    //Vec2 Operations
    [DllImport(DllName)]
    public static extern Vec2 VectorAdd2D(Vec2 a, Vec2 b);

    [DllImport(DllName)]
    public static extern Vec2 VectorSubtract2D(Vec2 a, Vec2 b);

    [DllImport(DllName)]
    public static extern Vec2 VectorScale2D(Vec2 v, float scale);

    [DllImport(DllName)]
    public static extern Vec2 VectorDivide2D(Vec2 v, float scalar);

    [DllImport(DllName)]
    public static extern float VectorMagnitude2D(Vec2 v);

    [DllImport(DllName)]
    public static extern Vec2 VectorNormalize2D(Vec2 v);

    [DllImport(DllName)]
    public static extern float VectorDot2D(Vec2 a, Vec2 b);
    
    //Vec3 Operations
    [DllImport(DllName)]
    public static extern Vec3 VectorAdd(Vec3 a, Vec3 b);

    [DllImport(DllName)]
    public static extern Vec3 VectorSubtract(Vec3 a, Vec3 b);

    [DllImport(DllName)]
    public static extern Vec3 VectorScale(Vec3 v, float scale);

    [DllImport(DllName)]
    public static extern Vec3 VectorDivide(Vec3 v, float scalar);

    [DllImport(DllName)]
    public static extern float VectorMagnitude(Vec3 v);

    [DllImport(DllName)]
    public static extern Vec3 VectorNormalize(Vec3 v);

    [DllImport(DllName)]
    public static extern float VectorDot(Vec3 a, Vec3 b);

    [DllImport(DllName)]
    public static extern Vec3 VectorCross(Vec3 a, Vec3 b);
    
    //Pong Specific Operations
    [DllImport(DllName)]
    public static extern Vec3 VectorLerp(Vec3 a, Vec3 b, float t);

    [DllImport(DllName)]
    public static extern Vec3 VectorReflect(Vec3 v, Vec3 normal);
    
    [DllImport(DllName)]
    public static extern Vec2 VectorLerp2D(Vec2 a, Vec2 b, float t);

    [DllImport(DllName)]
    public static extern Vec2 VectorReflect2D(Vec2 v, Vec2 normal);
}