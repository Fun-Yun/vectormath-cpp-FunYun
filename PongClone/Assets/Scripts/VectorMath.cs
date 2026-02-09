using System.Runtime.InteropServices;

public static class VectorMath
{
    private const string DllName = "VectorMathematics";
    
    [DllImport(DllName)]
    public static extern Vec3 VectorAdd(Vec3 a, Vec3 b);
    
    [DllImport(DllName)]
    public static extern Vec3 VectorSubtract(Vec3 a, Vec3 b);
}