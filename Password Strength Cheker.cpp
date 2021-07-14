// C++ program to check if a given password is
// strong or not.

#include <bits/stdc++.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
#include <string.h>
#include<conio.h>

using namespace std;
 
void printStrongNess(string input)
{
    int n = input.size();
    
    // Checking lower alphabet in string
    
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu"
        "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
 
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
 
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
 
    // Strength of password
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\tStrength of password:-";
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
	{
	   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	   cout << "Strong" << endl;
    }
    else if ((hasLower || hasUpper) && specialChar && (n >= 6))
	{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	  cout << "Moderate" << endl;
    }
    else 
	{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	  cout << "Weak" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
 
// Driver code
int main()
{
    string password;
    	cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl;
		cout<<endl;
		cout<<"\t\t  ±±±±± "<<endl;
		cout<<"\t\t  ±   ± "<<endl;
		cout<<"\t\t±±±±±±±±±"<<endl;
		cout<<"\t\t±±±± ±±±±"<<endl;
		cout<<"\t\t±±±±±±±±±"<<endl; 
		
		cout<<endl;
		cout<<"        PASSWORD  STRENGTH  CHECKER      "<<endl;
		cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl<<endl; 
		  
	cout<<endl<<"\tEnter Password: ";
	cin>> password;
	//Validity Checker-------------
			
    string s1,s2;
    int flag=0;
    if(password.size()<6) flag=1;
    for(int i=0;i<password.size();i++)
    {
    	if(isalpha(password[i])) 
		{ 
		   s2+=tolower(password[i]);
		}
		else s2+=password[i];
	}
    string b=" ";
    string a="";
    string s="subiya21022000";
    
    // checing white space 
    size_t found = password.find(b);
    if (found != string::npos) flag=1;
    
    //generating sub strings
    for (int len = 2; len <= s2.size(); len++)
    {   
        // Pick ending point
        for (int i = 0; i <= s2.size() - len; i++)
        {
            int j = i + len - 1;           
            for (int k = i; k <= j; k++) 
			{
			   a+=s[k];
		    } 
		    
		    //checking sub string is present or not 
            found = s2.find(a);
            if (found != string::npos) flag=1;   
        }
    }
    
    cout<<"\n\t\tChecking Validity\n\t";
    for(int i=0; i<35; i++)
	{
			cout<<(char)176;
			Sleep(50);
    }
    
    if(flag) 
	{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	  cout<<"\n\n\t\tInvalid Password\n\n";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else 
	{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	  cout<<"\n\n\t\tPassword is valid";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	  cout<<"\n\n\t\tChecking Strength\n\t";
      for(int i=0; i<35; i++)
	  {
			cout<<(char)176;
			Sleep(50);
      }
      cout<<"\n\n";
      printStrongNess(password);
   }
    return 0;
}
