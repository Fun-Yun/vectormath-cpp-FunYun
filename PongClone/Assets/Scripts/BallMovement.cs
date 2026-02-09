using UnityEngine;

public class BallMovement : MonoBehaviour
{
    [SerializeField] private float speed;
    private Vec2 direction;  
    private Vec2 position;
    private Rigidbody2D rb;
    
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        
        float x = Random.Range(0, 2) == 0 ? -1 : 1;
        float y = Random.Range(-1f, 1f);
        direction = new Vec2(x, y);
        direction = VectorMath.VectorNormalize2D(direction);
        
        rb.linearVelocity = direction.ToUnityVector2() * speed;
    }

    void Update()
    {
        //transform.Translate(direction * (speed * Time.deltaTime));
        Vec2 movement = direction;
        movement = VectorMath.VectorScale2D(movement, speed * Time.deltaTime);
        position = VectorMath.VectorAdd2D(position, movement);
        transform.position = position.ToUnityVector2();
        
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        //Get the Surface Normal
        Vec2 surfaceNormal;
        
        if (collision.gameObject.CompareTag("Top"))
            surfaceNormal = new Vec2(0, -1);
        else if (collision.gameObject.CompareTag("Bottom"))
            surfaceNormal = new Vec2(0, 1);
        else if (collision.gameObject.CompareTag("Player1"))
            surfaceNormal = new Vec2(1, 0);
        else if (collision.gameObject.CompareTag("Player2"))
            surfaceNormal = new Vec2(-1, 0);
        else
            return; 
        
        //Reflect ball reflected = V - 2 * (V · N) * N
        direction = VectorMath.VectorReflect2D(direction, surfaceNormal);
    }
}

