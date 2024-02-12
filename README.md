# shunting_yard

## Task
Create a calculator program which accepts an arithmetic expression in infix format. 
The program must translate the expression into Reverse Polish Notation using the shunting method.
The program must evaluate the expression and return the correct result.

A valid expression:

• must only contain the operators +, -, *, /, and modulo (percent)
• must only have integer values
• can contain parentheses, but each group must be properly closed
• can contain spaces
Since we are doing whole number arithmetic, divisions are euclidian keeping only the quotient, while the remainder can be obtained with a modulo operation.

## Description
This program uses a stack and a queue to execute the shunting-yard algorithm. 

First, the expression is parsed in the cli.c:
* The 2nd argument is transformed from a string into an array of tokens, stored in a struct "string_array" data structure.
* If an invalid character is found, a parse error is sent.
* If the expression's parentheses aren't balanced, a parse error is sent.

Next, the string_array* token is turned from an infix expression into postfix (Reverse Polish):
* Here, the shunting yard algorithm makes use of a stack and a queue.

Finally, the postfix expression is evaluated:
* The program checks for other possible parse errors including division by zero.
* If there are no errors the result is returned


## Installation
Compile the program via the command line interface using the command "make my_bc"

## Usage
```
./my_bc + "mathematical expression within quotes"
```

### The Core Team
Created as a solo project by:
rswhipple aka Rebecca Whipple Silverstein

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
