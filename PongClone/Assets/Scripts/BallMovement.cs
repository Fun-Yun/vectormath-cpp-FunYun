using UnityEngine;

public class BallMovement : MonoBehaviour
{
    [SerializeField] private float speed;
    [SerializeField] private float startSpeed = 2;
    private Vec2 direction;  
    private Vec2 position;
    private Vec2 startPos;
    private Vec2 movement;

    [SerializeField] private float maxBounceAngle = 60f;

    public bool gameEnded;
    
    void Start()
    {
        gameEnded = false;
        startPos = new Vec2(transform.position.x, transform.position.y);
        speed = startSpeed;
        ServeBall();
    }

    void Update()
    {
        if (!gameEnded)
        {
            //transform.Translate(direction * (speed * Time.deltaTime));
            movement = VectorMath.VectorScale2D(direction, speed * Time.deltaTime);
            position = VectorMath.VectorAdd2D(position, movement);
            transform.position = position.ToUnityVector2();
        }
    }

    void ServeBall()
    {
        float x = Random.Range(0, 2) == 0 ? -1 : 1;
        float y = Random.Range(-1f, 1f);
        direction = new Vec2(x, y);
        direction = VectorMath.VectorNormalize2D(direction);
    }

    public void ResetBall()
    {
        movement =  new Vec2(0, 0);
        position = startPos;
        speed = startSpeed;
        ServeBall();
    }

    void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.gameObject.CompareTag("Player1") || collision.gameObject.CompareTag("Player2"))
        {
            GetBounceAngle(collision);
        }
        else
        {
            Vec2 surfaceNormal = Vec2.FromUnityVector2(collision.contacts[0].normal);
            
            direction = VectorMath.VectorReflect2D(direction, surfaceNormal);
            direction = VectorMath.VectorNormalize2D(direction);
        }

        speed += .5f;

        //Get the Surface Normal
        //Vec2 surfaceNormal;

        /* if (collision.gameObject.CompareTag("Top"))
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
        speed += .5f; */
    }

    //Make the ball bounce different depending on where it hits paddle, like OG Pong
    void GetBounceAngle(Collision2D paddleCollision)
    {
        Vec2 paddlePosition = Vec2.FromUnityVector2(paddleCollision.transform.position);
        
        
        float positionOffset = position.y - paddlePosition.y;

        float paddleHeight = paddleCollision.collider.bounds.size.y / 2f;
        float offset = positionOffset / paddleHeight;
        
        offset = VectorMath.Clamp(offset, -1f, 1f);
        offset += Random.Range(-.1f, .1f);
        offset = VectorMath.Clamp(offset, -1f, 1f);
        float angle = offset * maxBounceAngle * Mathf.Deg2Rad;
        
        bool isPlayer1 = paddleCollision.gameObject.CompareTag("Player1");
        float directionX = Mathf.Cos(angle);
        float directionY = Mathf.Sin(angle);

        if (!isPlayer1)
            directionX = -directionX;

        direction = new Vec2(directionX, directionY);
        
        direction = VectorMath.VectorNormalize2D(direction);

    }
    
    private void OnTriggerEnter2D(Collider2D other)
    {
        Debug.Log("TRIGGER HIT: " + other.name);
        
        if (other.CompareTag("Goal"))
        {
            ResetBall();
        }
    }
}

