package code;

import java.util.Scanner;

public class EvensAndOdds {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int playersNumber = 0, computersNumber = 0;
		int evenThreshold = 50, wins = 0, losses = 0;
		int evenOrOdd = 0, rounds = 0;
		int playerChoice = 0; // whether the player chose to be even or odd
		
		do
		{
			rounds++;
			System.out.println("Welcome to Evens and Odds!");
			System.out.println("==========================");
			System.out.println("Round:" + rounds +"  wins:"+wins + "  losses:" + losses);
			System.out.println("==========================");
			System.out.println("Even Threshold: " + evenThreshold);
			
			
			System.out.println("\n0. Evens");
			System.out.println("1. Odds");
			System.out.print("\nPlease choose evens or odds: ");
			playerChoice = input.nextInt();
			
			if(playerChoice == 0)
				System.out.println("You are the \"Evens\" player!");
			else
				System.out.println("You are the \"Odds\" player!");
			///TODO: Error trap the above input
				
			
			//Players Input:
			boolean inputSuccess = true;
			do
			{
				inputSuccess = true;
				try
				{
					System.out.print("Please choose a number from 1 to 5:");
					playersNumber = input.nextInt();
				}
				catch (Exception e)
				{
					inputSuccess = false;
					String garbage = input.next();
				}
				
				if(inputSuccess && (playersNumber < 1 || playersNumber > 5) )
					inputSuccess = false;
				
			}while(!inputSuccess);
			//End of player's input
			
			//Beginning of Adaptive Choice Algorithm
			evenOrOdd = (int)(Math.random()*100+1);
			System.out.println("Even or odd number:" + evenOrOdd);
			if(evenOrOdd < evenThreshold)//we are going to choose an even number
				do
				{
					computersNumber = (int)(Math.random()*5+1);
				}while(computersNumber % 2 != playerChoice);
			else // we want to generate an odd number
				do
				{
					computersNumber = (int)(Math.random()*5+1);
				}while(computersNumber % 2 == playerChoice);
			
			//End of the adaptive Algorithm
			
			
			System.out.println("The computer chose " + computersNumber);
			System.out.println("The sum was " + (computersNumber+playersNumber) );
			
			if( (computersNumber + playersNumber) %2 == playerChoice)
			{
				System.out.println("You win~!");
				wins++;
			}
			else
			{
				System.out.println("You lose~!");
				losses++;
			}
			
			//ADAPT
			if(playersNumber % 2 == 0)
				evenThreshold+=2;
			else
				evenThreshold-=2;
			
		}while(rounds < 20);
		
		System.out.println("GAME OVER");
		if(wins>losses)
			System.out.println("You won the match!");
		else if(wins == losses)
			System.out.println("It was a tie!");
		else
			System.out.println("You lost the match!");
		
		
		
		

	}

}
