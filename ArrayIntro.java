package code;

import java.util.Scanner;

public class ArrayIntro {
	
	public static void populateSequentially (int[] numbers){
		for(int x = 0; x < numbers.length; x++)
			numbers[x] = x+1;
	}
	
	public static void display(int[] numbers) {
		
		System.out.println();
		
		for(int x = 0; x < numbers.length; x++)
		{
			if (numbers[x] < 10)
				System.out.print(numbers[x] + "   ");
			else if(numbers[x] < 100)
				System.out.print(numbers[x] +"  ");
			else
				System.out.print(numbers[x] + " ");
			
			if((x+1) % 10 == 0)
				System.out.println();
		}
		
	}
	
	public static void populateRandomly(int[] numbers) {
		for(int x = 0; x < numbers.length; x++)
			numbers[x] = (int)(Math.random()*100 + 1);
	}
	
	public static void shuffle(int[] numbers) {
		
		for(int x = 0; x< numbers.length; x++)
		{
			int index1 = (int)(Math.random()*numbers.length);
		
			int temp = numbers[index1];
			numbers[index1] = numbers[x];
			numbers[x] = temp;
		}

	}
	
	public static int find(int target, int[] numbers) {
		
		for(int x = 0; x< numbers.length; x++)
			if(numbers[x] == target)
				return x;
		
		return -1;	
	}
	
	public static boolean checkAscending(int[] numbers) {
		
		for(int x = 1; x< numbers.length; x++)
			if(numbers[x] < numbers[x-1])
				return false;
		return true;
		
	}
	
	public static void shuffleSort(int[] numbers) {
		
		int counter = 10000;
		
		while(!checkAscending(numbers) && counter > 0) {
			shuffle(numbers);
			counter--;
		}
		
		if(checkAscending(numbers))
			System.out.println("SUCCESS!");
		else 
			System.out.println("FAILED.");
	}
	
	public static int findLowest(int[] numbers) {
		
		int lowest = numbers[0];
		
		for(int x = 1; x < numbers.length; x++){
			if(numbers[x] < lowest)
				lowest = numbers[x];
		}
		return lowest;
		
	}
	
	public static int countOccurences(int target, int[] numbers) {
		
		int counter = 0;
		for(int x = 0; x < numbers.length; x++) 
			if(numbers[x] == target)
				counter++;
			
		return counter;
	}
	
	public static void findAndReplace(int[] numbers, int findTarget, int replaceTarget) {
		for(int x = 0; x < numbers.length; x++) 
			if(numbers[x] == findTarget)
				numbers[x] = replaceTarget;
		
	}
	
	public static int largest10(int[] numbers){
		
		int sum = 0;
		int largest = 0;
		
		//TEST CODE
		int startingIndex = 0;
		
		for(int start = 0; start <= numbers.length-10; start++) {
			
			sum = 0;
			
			for(int x= 0; x < 10; x++)//calculating the sum of this section
				sum += numbers[start+x];
			
			if(sum > largest)
			{
				largest = sum;
				startingIndex = start;
			}
			
		}
		
		//TESTCODE
		System.out.println("Starting point at: " + startingIndex);
		return largest;
		
	}
	

	public static void main(String[] args) {
		
		int[] numbers = new int[100];
		int choice = 0;
		Scanner input = new Scanner(System.in);
		
		
		do{
			System.out.println("\n0. Exit the program");
			System.out.println("1. Populate the array sequentially");
			System.out.println("2. Populate the array randomly");
			System.out.println("3. Display the array");
			System.out.println("4. Shuffle the array");
			System.out.println("5. Find a value in the array");
			System.out.println("6. Check if the list is in ascending order");
			System.out.println("7. Shuffle the list back into order");
			System.out.println("8. Find the lowest value in the array");
			System.out.println("9. Count how many instances of a number are in the array");
			System.out.println("10. Find and replace a number");
			System.out.println("11. Find the largest sum of 10 consecutive numbers");
			
			System.out.print("Please enter a choice: ");
			choice = input.nextInt();
			
			if(choice == 1)
				populateSequentially(numbers);
			else if(choice == 2)
				populateRandomly(numbers);
			else if(choice == 3)
				display(numbers);
			else if(choice == 4)
				shuffle(numbers);
			else if(choice == 5) {
				System.out.print("What number would you like to look for? ");
				int target = input.nextInt();
				System.out.println( "Item is in index " + find(target, numbers) );	
			}
			else if(choice == 6)
				if( checkAscending(numbers) )
					System.out.println("Ascending.");
				else
					System.out.println("Not Ascending.");
			else if (choice == 7)
				shuffleSort(numbers);
			else if (choice == 8)
				System.out.println( "Lowest Number: " + findLowest(numbers) );
			else if(choice == 9)
			{
				System.out.print("What number would you like to look for? ");
				int target = input.nextInt();
				System.out.println( target + " appears " + countOccurences(target, numbers) + " time(s)." );
			}
			else if(choice == 10)
			{
				System.out.print("What number would you like to look for? ");
				int findTarget = input.nextInt();
				System.out.print("What number would you like to replace it with? ");
				int replaceTarget = input.nextInt();
			
				findAndReplace(numbers, findTarget, replaceTarget);
			}
			else if (choice == 11)
				System.out.println( "Largest 10 numbers sum: " + largest10(numbers) );
			
			
			
			
				
			
		}while(choice != 0);
		
			
	}

}
