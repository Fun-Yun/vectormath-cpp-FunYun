using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class ScoringSystem : MonoBehaviour
{
    [SerializeField] private TMP_Text playerOneText;
    [SerializeField] private TMP_Text playerTwoText;
    
    private int playerOneScore;
    private int playerTwoScore;

    private BallMovement ball;
    
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        playerOneScore = 0;
        playerTwoScore = 0;

        ball = GameObject.FindWithTag("Ball").GetComponent<BallMovement>();
    }

    void Update()
    {
        if((playerOneScore == 5 || playerTwoScore == 5))
        {
            ResetGame();
        }
    }

    public void PlayerOneScored()
    {
        playerOneScore++;
        playerOneText.text = playerOneScore.ToString();
    }

    public void PlayerTwoScored()
    {
        playerTwoScore++;
        playerTwoText.text = playerTwoScore.ToString();
    }

    public void ResetGame()
    {
        playerOneScore = 0;
        playerTwoScore = 0;
        
        playerOneText.text = "0";
        playerTwoText.text = "0";

        ball.ResetBall();
    }
    
    
    
    
    
    
}
