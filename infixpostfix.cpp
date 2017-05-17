//Includes
#include <vector>
#include <iostream>
#include <string>
using namespace std;
//Main Method
int main()
{
//Initalizations
	vector<string> stack; //Using Vector since I had Problem with list of strings..
	//And I have a very good reason to use string instead of char,since char wont read my Operators..
	//Vectors have pretty much almost the same Member functions as Lists (they dont have unique,which I dont use anyway).
	//http://www.cplusplus.com/reference/vector/vector/?kw=vector
	//http://www.cplusplus.com/reference/list/list/?kw=list
	std::string infix;
	std::string put;
	std::string postfix;
//Input/Output Interface Stuff
  cout << "Enter infix without spaces: ";
  cin >> infix;

//Methods Initalization
bool isOperator(const string &mystr);
int Priority(const string &mystr);

//Read String As Array
//This Main Algorithm Loop
  for (int i=0;i<infix.size();i++)
  {
//Define string put,that we use to put things on postfix.C++ Makes live easier by saving whole string as array,when we dont use spaces.
 	 put = infix[i];

 	  	if (isOperator(put)==0) //If it is Operand...
 			{
 				postfix.append(put); //We put it on Postfix directly.
 			};
 		if (isOperator(put)==1)//If it is Operator...
 			{
 				while(!stack.empty() && Priority(stack.back()) >= Priority(put))//We check Stack if not empty and while not empty,
 				//We check the top Element Priority and the Prioirty of the Operator we want to put.
           		{
                postfix.append(stack.back()); //We append top of the stack.
                stack.pop_back(); //We pop it...
           		}
           		stack.push_back(put); //We put our Operator
 			}
}
//However we have a non-empty Stack still...
while(!stack.empty()) //We missed the Operators in Postfix after last Operand
//So we append then to Postfix,until our Stack is empty
{
                postfix.append(stack.back()); 
                stack.pop_back();	
}

//Print Stack (Was used for Test...)
// 	cout<<"print Stack: \n";
//    for (string n : stack) {
//        std::cout << n <<"\n";
//       }
//Print PostFix

  	cout << "Postfix:" << postfix << "\n";	

  return 0;
}

//Method Definition
bool isOperator(const string &mystr) //Checking if it is Operator or Operand
{
    return (mystr == "+" || mystr == "-" || mystr == "*" || mystr == "/");
}
int Priority(const string &mystr) //Operator Priorities
{
    if(mystr == "*" || mystr == "/") //Multiplication/Division got higher.
    {
        return 2;
    }
    if(mystr== "+" || mystr == "-") //Addition/Substraction got lower.
    {
        return 1;
    }

}

