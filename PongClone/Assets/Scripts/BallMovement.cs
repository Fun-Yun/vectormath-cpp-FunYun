using UnityEngine;

public class BallMovement : MonoBehaviour
{
    [SerializeField] private float speed;
    private Vec2 direction;  
    private Vec2 position;
    
    void Start()
    {
        float x = Random.Range(0, 2) == 0 ? -1 : 1;
        float y = Random.Range(-1f, 1f);
        direction = new Vec2(x, y);
        direction = VectorMath.VectorNormalize2D(direction);
        
        position = new Vec2(transform.position.x, transform.position.y);
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
        
        //Reflect ball reflected = V - 2 * (V · N) * N
    }
}

