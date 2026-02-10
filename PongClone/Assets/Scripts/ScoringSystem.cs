using UnityEngine;
using TMPro;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ScoringSystem : MonoBehaviour
{
    [SerializeField] private TMP_Text playerOneText;
    [SerializeField] private TMP_Text playerTwoText;
    [SerializeField] private TMP_Text winnerText;
    [SerializeField] private GameObject winScreen;
    
    [SerializeField] private GameObject playerOne;
    [SerializeField] private GameObject playerTwo;
    [SerializeField] private BallMovement ball;
    
    private int playerOneScore;
    private int playerTwoScore;
    private int winScore = 5;
    
    void Start()
    {
        playerOneScore = 0;
        playerTwoScore = 0;
    }
    
    public void PlayerOneScored()
    {
        playerOneScore++;
        playerOneText.text = playerOneScore.ToString();
        CheckWinCondition();
    }

    public void PlayerTwoScored()
    {
        playerTwoScore++;
        playerTwoText.text = playerTwoScore.ToString();
        CheckWinCondition();
    }

    private void CheckWinCondition()
    {
        if((playerOneScore == winScore || playerTwoScore == winScore))
        {
            ball.gameEnded = true;
            string winner = (playerOneScore == winScore) ? "Player One" : "Player Two";
            ToggleWinScreen(winner);
        }
    }

    public void ResetGame()
    {
        winScreen.SetActive(false);
        
        playerOneScore = 0;
        playerTwoScore = 0;
        
        playerOneText.text = "0";
        playerTwoText.text = "0";

        Time.timeScale = 1;
        ball.gameEnded = false;
        ball.ResetBall();
    }

    private void ToggleWinScreen(string winner)
    {
        Time.timeScale = 0;
        winScreen.SetActive(true);
        winnerText.text = winner + " wins!";
        
    }

    public void OnReset(InputAction.CallbackContext context)
    {
        if (!context.performed) return;

        ResetGame();
    }
}
