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
### Proper useage
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
	The opcode push pushes an element to the stack.</br>
	<code> $cat test_1.m</code></br>
	<code> >>> push 1</code></br>
	<code> >>> push 2</code></br>
	<code> >>> pall</code></br>
	output</br>
	<code> $ ./monty test_1.m</code></br
	<code> >>> 1</code></br>
	<code> >>> 2</code></br>

	Will produce an error if push is not followed a negative or postive int</br>
	<code>L<line_number>: usage: push integer<code></br>
    </td>
  </tr>
  <tr>
    <td>pall</td>
    <td>
      Forces proceed to with a sign even if positive</br>
      <code>_printf("A%dlast", 5);</code></br>
      <code>_printf("A%+dlast", 5);</code></br>
    output</br>
      <code>$ A5last</code></br>
      <code>$ A+5last</code></br>
    </td>
  </tr>
  <tr>
    <td>pint</td>
    <td>d, i</td>
    <td>
    if no sign is given, proceed with space
      <code>_printf("A%dlast", 5);</code></br>
      <code>_printf("A% dlast", 5);</code></br>
    output
      <code>$ A5last</code></br>
      <code>$ A 5last</code></br>
    </td>
  </tr>
  <tr>
   <td>pop</td>
    <td>
    Used with o, x or X specifiers the value is preceded with 0, 0x,or 0X respectively for values different than zero.
      <code>_printf("%o, 1");</code></br>
      <code>_printf("%#o, 1");</code></br>
    output
      <code>$1</code></br>
      <code>$01</code></br>
    </td>
  </tr>
  <tr>
    <td>swap</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>add</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
  <td>nop</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>sub</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>div</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>mul</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>mod</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>pchar</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>pstr</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>rotl</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>rotr</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>queue</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
  <tr>
    <td>stack</td>
    <td>
     left pad with spaces with 0
      <code>_printf("A%3dlast", 5);</code></br>
      <code>_printf("A%03dlast", 5);</code></br>
    output
      <code>$ A  5last</code></br>
      <code>$ A005last</code></br>
    </td>
  </tr>
</table>


##Contributors
*Jay Wang* - [Github](https://github.com/jayjay823) || [Twitter](https://twitter.com/jianqinwang94) || [email](jianqin.wang@holbertonschool.com)

*Richard Sim* - [Github](https://github.com/rdsim8589) || [Twitter](https://twitter.com/richard_d_sim) || [email](richard.sim@holbertonschool.com)

##Want to be contributor?
reach out to any of the Contributors