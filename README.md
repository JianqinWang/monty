#Holberton School Project - interpetor for the Monty language
## Description
This is a Holberton School partner project with @jayjay823 and @rdsim8589. This is an interpetor for the monty byte code.The monty byte code are strored .m files that excute a command line by line. The purpuse of this is project to understand the concepts of FIFO (First in First Out) and LIFO (Last In First Out).

##How To Use
```
$ git clone git@github.com:jayjay823/monty.git
```
compile everything within the directory that ends with .c
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
run the binary file monty with the .m file (only accepts one file at a time)
```
$ ./monty test.m
```

##Completed Features
### Proper usage
Must pass one file that that exist.
if non-existant file passed
```
$ ./monty no_file.m
>>> Error: Can't open file no_file
```
if no files passed or more than one file passed
```
$ ./monty test_1.m test_2.m
>>> USAGE: monty file
```

Files must contain valid opcode
If invalid given
```
$cat test_1.m
>>> bad_fun
>>> push 2
>>> pall
$ ./monty test_1.m
>>> L1: unknown instruction bad_fun
```

The default method of storing will be the stack

### Avaliable opcodes


<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td><b>op codes</b></td>
    <td><b>Description and Examples</b> </td>
  </tr>

  <tr>
    <td>push</td>
    <td>
	The opcode push pushes an element to the stack.</br></br>
	Example:</br>
		<pre><code>$cat test_1.m
>>> push 1
>>> push 2
>>> pall</code></pre>
	output</br>
		<pre><code>$ ./monty test_1.m
>>> 1
>>> 2</code></pre>

	if push is not followed a negative or postive int, output will be:</br>
	<code>L(line_number): usage: push integer<code></br>
    </td>
  </tr>

  <tr>
    <td>pall</td>
    <td>
	The opcode pall prints all the values on the stack, starting from the top of the stack.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 1</code></br>
		<code> >>> 2</code></br>
    </td>
  </tr>

  <tr>
    <td>pint</td>
    <td>
	The opcode pint prints the value at the top of the stack, followed by a new line.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pint</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>

	If stack empty, output will be:</br>
	<code>L(line_number): can't pint, stack empty</code>
    </td>
  </tr>

  <tr>
   <td>pop</td>
    <td>
        The opcode pop removes the top element of the stack.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> pop</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 1</code></br>

	If stack is empty, output will be</br>
	<code>L(line_number): can't pop an empty stack</code></br>
    </td>
  </tr>

  <tr>
    <td>swap</td>
    <td>
	The opcode swap swaps the top two elements of the stack.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> swap</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 1</code></br>
		<code> >>> 2</code></br>

	If the stack is less than two elements long, output will be:</br>
	<code>L(line_number): can't swap, stack too short</code></br>
    </td>
  </tr>

  <tr>
    <td>add</td>
    <td>
	The opcode add adds the top two elements of the stack. The two elements will be replaced with one element that is the sum of the two elements. The stack is now one element shorter.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> add</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 3</code></br>

	If the stack is less than two elements long, output will be: </br>
	<code>L(line_number): can't add, stack too short</code></br>
    </td>
  </tr>

  <tr>
  <td>nop</td>
    <td>
	The opcode nop doesn't do anything</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> nop</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
    </td>
  </tr>

  <tr>
    <td>sub</td>
    <td>
	The opcode sub subtracts the top elements from second top element of the stack. The two elements will be replaced with one element that is the subtraction of the two elements. The stack is now one element shorter.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> sub</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> -1</code></br>

	If the stack is less than two elements long, output will be: </br>
	<code>L(line_number): can't sub, stack too short</code></br>

  </tr>

  <tr>
    <td>div</td>
    <td>
	The opcode div divides the seconds top element by the top element of the stack. The two elements will be replaced with one element that is the division of the two elements. The stack is now one element shorter.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 6</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> div</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 6</code></br>
		<code> >>> 3</code></br>

	If the stack is less than two elements long, output will be: </br>
	<code>L(line_number): can't div, stack too short</code></br>

	If the the top element of the stack is 0, output will be:</br>
	<code>L(line_number): division by zero</code></br>
    </td>
  </tr>

  <tr>
    <td>mul</td>
    <td>
	The opcode mul multiplies the second top element of the stack with the top element of the stack. The two elements will be replaced with one element that is the division of the two elements. The stack is now one element shorter.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 6</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> mul</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 6</code></br>
		<code> >>> 12</code></br>
	If the stack is less than two elements long, output will be: </br>
	<code>L(line_number): can't mul, stack too short</code></br>

    </td>
  </tr>

  <tr>
    <td>mod</td>
    <td>
	The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack. The two elements will be replaced with one element that is the division of the two elements. The stack is now one element shorter.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 6</code></br>
		<code> >>> push 2</code></br>
		<code> >>> pall</code></br>
		<code> >>> mod</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 2</code></br>
		<code> >>> 6</code></br>
		<code> >>> 0</code></br>

	If the stack is less than two elements long, output will be:</br>
	<code>L(line_number): can't mod, stack too short</code></br>

	If the the top element of the stack is 0, output will be:</br>
	<code>L(line_number): division by zero</code></br>
    </td>
  </tr>

  <tr>
    <td>#</td>
    <td>
	When the first non-space character of a line is #,  this line is treated a comment (don't do anything)</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> # Nothing will print</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>

    </td>
  </tr>

  <tr>
    <td>pchar</td>
    <td>
	The opcode pchar prints the ascii character of element at the top of the stack, followed by a new line.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 72</code></br>
		<code> >>> pchar</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> H</code></br>

	If stack is empty, output will be:</br>
	<code>L(line_number): can't pchar an empty stack</code></br>

	If the value is not in the ascii table (man ascii), output will be:</br>
	<code>L(line_number): can't pchar, value out of range</code></br>
    </td>
  </tr>
  <tr>
    <td>pstr</td>
    <td>
	The opcode pstr prints the string starting at the top of the stack. The int values will be treated as ascii value characters. The string will stop when the stack is over, the values of the element is 0 or not in the ascii table. </br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 0</code></br>
		<code> >>> push 65</code></br>
		<code> >>> push 72</code></br>
		<code> >>> pstr</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> HA</code></br>

	If the stack is empty, output will be:</br>
	<code> >>> </code></br>

    </td>
  </tr>

  <tr>
    <td>rotl</td>
    <td>
	The opcode rotl rotates the stack to the top. The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 0</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> push 3</code></br>
		<code> >>> pall</code></br>
		<code> >>> rotl</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 3</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 0</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 0</code></br>
		<code> >>> 3</code></br>
    </td>
  </tr>
  <tr>
    <td>rotr</td>
    <td>
	The opcode rotr rotates the stack to the bottom. The last element of the stack becomes the top element of the stack.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> push 0</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> push 3</code></br>
		<code> >>> pall</code></br>
		<code> >>> rotr</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 3</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 0</code></br>
		<code> >>> 0</code></br>
		<code> >>> 3</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
    </td>
  </tr>
  <tr>
    <td>queue</td>
    <td>
	The opcode queue sets the format of the data to a queue (FIFO).</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> queue</code></br>
		<code> >>> push 0</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> push 3</code></br>
		<code> >>> pall</code></br>

	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 0</code></br>
		<code> >>> 1</code></br>
		<code> >>> 2</code></br>
		<code> >>> 3</code></br>
    </td>
  </tr>
  <tr>
    <td>stack</td>
    <td>
        The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.</br></br>
	Example:</br>
		<code> $cat test_1.m</code></br>
		<code> >>> stack</code></br>
		<code> >>> push 0</code></br>
		<code> >>> push 1</code></br>
		<code> >>> push 2</code></br>
		<code> >>> push 3</code></br>
		<code> >>> pall</code></br>
	output</br>
		<code> $ ./monty test_1.m</code></br>
		<code> >>> 3</code></br>
		<code> >>> 2</code></br>
		<code> >>> 1</code></br>
		<code> >>> 0</code></br>
    </td>
  </tr>
</table>


##Contributors
*Jay Wang* - [Github](https://github.com/jayjay823) || [Twitter](https://twitter.com/jianqinwang94) || [email](jianqin.wang@holbertonschool.com)

*Richard Sim* - [Github](https://github.com/rdsim8589) || [Twitter](https://twitter.com/richard_d_sim) || [email](richard.sim@holbertonschool.com)

##Want to be contributor?
reach out to any of the Contributors