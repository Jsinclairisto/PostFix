#include<iostream>
#include<stack>
#include "StringSplitter.h"
#include <string>
#include <fstream>

using namespace std;

string add = "+";
string sub = "-";
string mult = "*";
string divide = "/";

double operation(string operation, double val1, double val2){

	if(operation == add){
		return val1+val2;
	}

	if(operation == sub){
		return val1-val2;
	}

	if(operation == mult){
		return val1*val2;
	}

	if(operation == divide){
		return val1/val2;
	}

	return 0;
}


bool isNum(string c){

  if(c != add && c != sub && c != divide && c != mult){
  	return true;
  }else{
  	return false;
   }
}


double evaluatePostfixExpression(string postfix_string) 
{
	double result = -1.0;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");

	return result;
	//TODO: evaluate pieces as a post fix



	for (auto piece : pieces) 
	{
		cout << piece << endl;
		if(isNum(piece) == true)
		{
			double arg = stod(piece);
			postfix_stack.push(arg);

		}
		else
		{
			double val1 = postfix_stack.top();
			postfix_stack.pop();
			double val2 = postfix_stack.top();
			postfix_stack.pop();

			result = operation(piece, val2, val1);
			postfix_stack.push(result);
		}
	}

	while (postfix_stack.empty() == false) 
	{
		

		cout << postfix_stack.top();

		postfix_stack.pop();
	}
	
}

int main(void) 
{
	//prompt user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	//open the file
	ifstream input_file(file_to_open);

	//safety checking
	if (input_file.is_open()) 
	{
		//read from the file as long as more content is available
		while (input_file.good()) 
		{
			string current_line;
			getline(input_file, current_line);
			double result = evaluatePostfixExpression(current_line);
			cout << current_line << "=" << result << endl;

		}
	}

	return 0;
}