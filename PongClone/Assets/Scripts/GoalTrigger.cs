using System;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;

public class GoalTrigger : MonoBehaviour
{
    [SerializeField] private bool isGoalOne;
    [SerializeField] private ScoringSystem scoringSystem;


    private void OnTriggerEnter2D(Collider2D other)
    {
        if (isGoalOne)
        {
            scoringSystem.PlayerTwoScored();
        }
        else
        {
            scoringSystem.PlayerOneScored();
        }
    }
}
