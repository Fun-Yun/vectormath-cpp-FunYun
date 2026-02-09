using UnityEngine;
using UnityEngine.InputSystem;

public class PaddleMovement : MonoBehaviour
{
    public float speed = 10f;
    private Vec2 moveInput;
    private Vec2 position;

    public void OnMove(InputAction.CallbackContext context)
    {
        moveInput = Vec2.FromUnityVector2(context.ReadValue<Vector2>());
    }

    void Start()
    {
        position = new Vec2(transform.position.x, transform.position.y);
    }

    void Update()
    {
        Vec2 movement = new Vec2(0, moveInput.y);
        movement = VectorMath.VectorScale2D(movement, speed * Time.deltaTime);
        
        position = VectorMath.VectorAdd2D(position, movement);
        
        transform.position = position.ToUnityVector2();
    }
}
