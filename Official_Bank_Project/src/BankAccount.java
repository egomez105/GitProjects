/*
Erick Gomez
May 2, 2022
Java 1 Project 4 Bank
	5 instance variables
		- balance, account name, account number, account type, and interest rate
	1 static variable
		- the previous account number (used for making new account numbers)
	setters and getters for each instance variable
		- no setter for account number
	two constructors
		- default and overloaded with three parameters
	five non-setter/getter methods
		- withdraw, deposit, transfer, add interest, and display all info
			- add interest will use a method from Financial class
*/

public class BankAccount 
{
	// 5 instance variables
	private double balance;
	private String accName;
	private final int accNum;
	private char accType;
	private double interestRate; // default is 3%
	
	// 1 static variable default value = 0
	// maintains the account number update
	private static int lastAccNum = 0;
	
	// constructors -----------------------------------------------------------------------------------
	
	// default
	public BankAccount()
	{
		lastAccNum++;
		accNum = lastAccNum;
		accType = 'C'; // default is a checking account
		
	} // end of BankAccount constructor (default)
	
	// overloaded constructor, 3 parameters: balance, accName, accountType
	public BankAccount(double balance, String accName, char accType)
	{
		// increment the account number for a new object
		lastAccNum++;
		accNum = lastAccNum;
		
		// set the balance, account name, and account type
		this.balance = balance;
		this.accName = accName;
		this.accType = accType;
		
		// only give an interest rate if Savings account
		if (this.accType == 'S' || this.accType == 's')
		{
			this.interestRate = 3; // savings account has 3% interest
		}
		
	} // end of BankAccount constructor (3 parameters)
	
	// methods ---------------------------------------------------------------------------------------
	
	// displays the accounts information (name, balance, number, type)
	void display()
	{
		System.out.print("Account name: " + accName + "\nBalance: $" + balance + "\nAccount number: "
						 + accNum +"\nInterest rate: " + interestRate + "%\nAccount type: ");
		if (accType == 'S' || accType == 's')
		{
			System.out.println("Savings account\n"); // print savings if savings
		}
		else
		{
			System.out.println("Checking acount\n"); // print checking if not savings
		}
	} // end of display method 
	
	
	// subtracts an amount(double) given from the balance(double)
	void withdraw(double widthAmnt)
	{
		if (balance >= widthAmnt)
		{
			balance -= widthAmnt;
		}
		else // only do if there is not enough money in the balance
		{
			throw new IllegalArgumentException("Your broke lol... Insufficient funds!");
		}
		
	} // end of withdraw method
	
	
	// adds an amount(double) given to the balance
	void deposit(double amnt)
	{
		balance += amnt;
	}
	
	
	// moves specified amount(double) from specified account to called account
	void transfer(BankAccount acc, double amount)
	{
		if(acc.balance >= amount)
		{
			this.deposit(amount);
			acc.withdraw(amount);
		}
		else
		{
			throw new IllegalArgumentException(acc.getName() + " is broke lol... Insufficient funds!");
		} // end of if else
		
	} // end of transfer method
	
	
	// adds interest to balance
	void addInterest()
	{
		if (interestRate != 0) // don't run if there is no interest rate 
		{
			balance += Financial.percentOf(interestRate, balance);
		}
		else
		{
			throw new IllegalArgumentException("No interest rate!");
		}
	}
	
	// 4 setter methods --------------------------------------------------------------------------------
	
	void setBalance(double balance)
	{
		this.balance = balance;
	}
	
	void setName(String accName)
	{
		this.accName = accName;
	}
	
	void setAccType(char accType)
	{
		this.accType = accType;
	}
	
	void setInterestRate(double intRate)
	{
		interestRate = intRate;
	}
	
	// 5 getter methods ---------------------------------------------------------------------------------
	
	double getBalance()
	{
		return balance;
	}
	
	String getName()
	{
		return accName;
	}
	
	char getAccType()
	{
		return accType;
	}
	
	double getInterestRate()
	{
		return interestRate;
	}
	
	int getAccNum()
	{
		return accNum;
	}
	
} // end of BankAccount class
