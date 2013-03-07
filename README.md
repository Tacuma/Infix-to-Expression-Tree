Infix to Expression Tree
========================


Data Structures/Concepts Used:
==============================
Templates, Stacks, Binary Search Tree, Evaluating an expression Tree, Recursion


Description:
============
This program takes input from the console in the form of an infix expression, 
and then converts it into binary tree format.
The Tree is then evaluated.

The algorithm for converting to an exp. tree is as follows:
	While the input stack is not empty...
	If it is operand, make it into a node, add it to output string.
	If it is Closing parenthesis, make into node, push it on stack.
	If it is an operator, then
		If stack is empty, make node and push operator on stack.
		If the top of stack is closing parenthesis, make node and push operator on stack.
		If it has same or higher priority than the top of stack, make node and push operator on stack.
		Else pop the operator from the stack, perform attachOperator and add it to treenodes. repeat 
	If it is a opening parenthesis, pop operators from stack and perform attachOperator 
	   until a closing parenthesis is encountered. Pop and discard the closing parenthesis.
	If there is no more input, unstack the remaining operators and perform attachOperator

Evaluating the Expression tree is done recursively


Output:
=======
	-Infix to Expression Tree Creator-
	-An expression tree is created from a user inputted infix expression-

	Please enter an Infix Mathematical Expression
	2*3/(2-1)+5*(4-1)

	Evaluation: 21

	Would  you like to convert another expression? (y/n)n



	() Code by Tacuma Solomon
	() Not for Redistribution or Reuse.

	Press any key to continue . . .

