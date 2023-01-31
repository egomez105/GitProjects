/*
Dorje Pradhan and Erick Gomez
May 3, 2022
Project 4 Bank
	Add an addInterest method that invokes the static method percentOf from the Financial class
	and takes in two parameters; the interestRate field and the balance field. In this method 
	interest will be added only to savings accounts according to the interestRate value. You 
	should NOT add interest to a checking account.
 */


public class Financial 
{
	// calculates how much should be added to balance(double amount) after interest(double percentage)
	static double percentOf(double percentage, double amount)
	{
		return (percentage / 100) * amount;
	}
	
	
} // end of Financial class
