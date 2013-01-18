//Tacuma Solomon
//Computer Science III
//Infix to Expression Tree Conveter and Evaluator

//Algorithm to insert an expression in Infix  notation
//( e.g. 2 * 3 + (6 / 4) - 8 ) to a binary tree.
//In addition to the above requirement, you must implement
//an evaluation of the expression tree.
//This solution includes class templates.

//Precondition: Must be a single digit numbers

#include<iostream>
#include<string>
#include "StackType.h"
using namespace std;

struct node;

int priority(char);
node* makeNode(char);
void attachOperator(StackType<node*>&, StackType<node*>&); 
//Pops operator off of the operators stack, 
//Pops 2 operands of treenode stack and attaches them to operator
int evaluateTree(node*);
void Footer();

struct node{
	char info;
	node* left;
	node* right;
};

int main(){

	string infix; // the infix expression read from the line
    StackType<char> input; // stack for input string
	StackType<node*> operators; // stack for operator pointer addresses
	StackType<node*> treenodes;  // stack for output node pointer addresses
	char temp,again=' ';
	cout << "-Infix to Expression Tree Creator-" << endl;
	cout << "-An expression tree is created from a user inputted infix expression-" << endl;
	
	while (again!='n')
	{
		cout << endl << "Please enter an Infix Mathematical Expression" << endl;
		cin >> infix;
		//Pushes the contents of the string into the input stack
		for (int i=0;i<infix.length();i++){
			input.Push(infix[i]);
		}
		// While the input stack is not empty...
		while(!input.IsEmpty()){
			temp=input.Top();
			input.Pop();
			//If it is operand, make it into a node, add it to output string.
			if (isdigit(temp))  
				treenodes.Push(makeNode(temp));
			//If it is Closing parenthesis, make into node, push it on stack.
			if (temp==')')
				operators.Push(makeNode(temp));
			//If it is an operator, then
			if ((temp=='+') || (temp=='/') || (temp =='-') || (temp=='*')) {
				bool pushed = false;
				while(!pushed){
					//If stack is empty, make node and push operator on stack.
					if(operators.IsEmpty()){
						operators.Push(makeNode(temp));
						pushed=true;
					}
					//If the top of stack is closing parenthesis, make node and push operator on stack.
					else if (operators.Top()->info ==')'){
						operators.Push(makeNode(temp));
						pushed=true;
					}
					//If it has same or higher priority than the top of stack, make node and push operator on stack.
					else if ((priority(temp)>priority(operators.Top()->info)) || (priority(temp)==priority(operators.Top()->info))){
						operators.Push(makeNode(temp));
						pushed=true;
					}
					//Else pop the operator from the stack, perform attachOperator and add it to treenodes. repeat step 5.
					else {
						attachOperator(treenodes,operators);
					}	
				}
			}
			//If it is a opening parenthesis, pop operators from stack and perform attachOperator 
			//until a closing parenthesis is encountered. Pop and discard the closing parenthesis.
			if (temp=='('){
				while (operators.Top()->info!=')')
				{
					attachOperator(treenodes,operators);
				}
				operators.Pop(); // ')' is popped and discarded
			}
		}
		//If there is no more input, unstack the remaining operators and perform attachOperator
		while(!operators.IsEmpty()){
			attachOperator(treenodes,operators);
		}

		int answer = evaluateTree(treenodes.Top());
		cout << endl << "Evaluation: " << answer << endl;
		cout << endl;
		cout << "Would  you like to convert another expression? (y/n)";
		cin >> again;
	} 
	cout << endl;
	Footer();
	system("pause");
	return 0;
}

void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}

//Determines the priority of an operator
int priority(char op){
	if ((op =='+') || (op =='-'))
		return 1;
	if ((op =='/') || (op =='*'))
		return 2;
}

//Places a char from the input stack into a new treenode
node* makeNode(char info){
	node* childnode;
	childnode = new node;
	childnode->info = info;
	childnode->left = NULL;
	childnode->right = NULL;
	return childnode;
}

//Pops an operator from a stack
//Builds a tree node with the top two nodes in the
//treenode stacks as its left and right children. 
void attachOperator(StackType<node*>& treenodes, StackType<node*>& operators){
	node* operatornode = operators.Top();
	operators.Pop();
	operatornode->left = treenodes.Top();
	treenodes.Pop();
	operatornode->right = treenodes.Top();
	treenodes.Pop();
	treenodes.Push(operatornode);
}

//Using a recursive function, the value of the expression is Calculated
int evaluateTree(node* treenode){
	int x,y,z;
	if ((treenode->info) == '+'||(treenode->info) == '-'||(treenode->info) == '*'||(treenode->info) == '/') {
		x = evaluateTree(treenode->left);
		y = evaluateTree(treenode->right);
		if (treenode->info=='+')
			z=x+y;
		else if (treenode->info=='-')
			z=x-y;
		else if (treenode->info=='*')
			z=x*y;
		else if (treenode->info=='/')
			z=x/y;
		return z;
	}
	else return treenode->info - '0';	
}

/*
-Infix to Expression Tree Creator-
-An expression tree is created from a user inputted infix expression-

Please enter an Infix Mathematical Expression
2*3/(2-1)+5*(4-1)

Evaluation: 21

Would  you like to convert another expression? (y/n)n



() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/