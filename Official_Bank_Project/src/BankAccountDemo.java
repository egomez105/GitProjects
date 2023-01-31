/*
Dorje Pradhan and Erick Gomez
May 2, 2022
Java 1 Project 4 Bank
	Test each of the methods created in the BankAccount class
	make sure to document each aspect well
	use three objects: adam, sam, and leila
		- use overloaded constructor at least once
	make sure to print each method in order to check for errors
*/

public class BankAccountDemo 
{
	
	public static void main(String[] args)
	{
		// instantiating objects adam, sam, and leila
		BankAccount adamAcc = new BankAccount(); // checking account
		BankAccount samAcc = new BankAccount(10000, "Sam", 'S'); // savings account
		BankAccount leilaAcc = new BankAccount(45000, "Leila's Account", 'S'); // savings account
		
		
		// giving Adam some money and a name
		adamAcc.setBalance(100);
		adamAcc.setName("Adam's family");
		
		// checking adam's info
		adamAcc.display();
		
		// checking sam's info
		samAcc.display();
		
		// checking leila's info
		leilaAcc.display();
		
		// testing transfer methods
		adamAcc.transfer(samAcc, 100);
		
		// checking info after transfer
		System.out.println("Checking info after transfer ----------\n");
		adamAcc.display();
		samAcc.display();
		
		// testing withdraw method
		leilaAcc.withdraw(600);
		
		// checking leila's info after withdraw
		System.out.println("Checking info after withdraw ----------\n");
		leilaAcc.display();
		
		// testing deposit method
		adamAcc.deposit(4000);
		
		// checking info after deposit
		System.out.println("Checking info after deposit -----------\n");
		adamAcc.display();
		
		// testing addInterest method
		leilaAcc.addInterest();
		
		// checking info after interest
		System.out.println("Checking info after interest ----------\n");
		leilaAcc.display();
		
		// testing setter and getter methods -------------------------------------------
		
		// setting and getting balance
		System.out.println("Testing setters and getters ------------\n");
		leilaAcc.setBalance(1000);
		System.out.println(leilaAcc.getBalance());
		
		// setting and getting account type
		adamAcc.setAccType('S');
		System.out.println(adamAcc.getAccType());
		
		// setting and getting account name
		samAcc.setName("Not Sam's account ;)");
		System.out.println(samAcc.getName());
		
		// setting and getting Interest rate
		leilaAcc.setInterestRate(20);
		System.out.println(leilaAcc.getInterestRate());
		
		// getting the account number
		System.out.println(adamAcc.getAccNum());
		
		
		// testing exceptions -----------------------------------------------------------
		
		// leilaAcc.withdraw(100000000);
		// adamAcc.addInterest();
//		samAcc.transfer(leilaAcc, 1000000000);
		
	} // end of main method
	
	
} // end of BankAccountDemo class
