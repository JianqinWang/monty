#Holberton School Project - interpetor for the Monty language
## Description
This is a Holberton School partner project with @jayjay823 and @rdsim8589. This is an interpetor for the monty language.The monty language are .m files that excute a command line by line. The purpuse of this is project to understand the concepts of FIFO (First in First Out) and LIFO (Last In First Out).

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

### Avaliable opcodes
format tags must follow the format of [flags][width][.precision][length]specifier

| **op code** | **output**                            |
|---------------|---------------------------------------|
| c             | characters                            |
| s		| string of characters                  |
| i or d        | signed decimal int                    |
| u             | unsigned decimal int                  |
| o             | signed octal                          |
| x             | unsigned hexadecimal int              |
| X             | unsigned hexadecimal int (Upper Case) |
| b             | Binary                                |
| p             | pointer address                       |


<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td><b>op codes</b></td>
    <td><b>Effected Specifers</b></td>
    <td><b>Description and Examples</b> </td>
  </tr>
  <tr>
    <td>-</td>
    <td>d, i, u, o, x, X, b, c, s</td>
    <td>
	Left justify</br>
	<code>_printf("A%3dlast", 5);</code></br>
	<code>_printf("A%-3dlast", 5);</code></br>
	output</br>
	<code>$ A  5last</code></br>
        <code>$ A5  last</code></br>
    </td>
  </tr>
  <tr>
    <td>+</td>
    <td>d, i</td>
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
    <td>(space)</td>
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
    <td>#</td>
    <td>o, x, X </td>
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
    <td>0</td>
    <td>d, i, u, o, x</td>
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


<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td><b>width</b></td>
    <td><b>Effected Specifers</b></td>
    <td><b>Description and Examples</b> </td>
  </tr>
  <tr>
    <td>-</td>
    <td>d, i, u, o, x, X, b, c, s</td>
    <td>
	minimum number to be printed</br>
	<code>_printf("A%dlast", 5);</code></br>
	<code>_printf("A%3dlast", 5);</code></br>
	output</br>
	<code>$ A5last</code></br>
        <code>$ A  5last</code></br>
    </td>
  </tr>
</table>

<table class="tg">
  <col width="45%">
  <col width="65%">
  <tr>
    <td><b>.percision</b></td>
    <td><b>Effected Specifers</b></td>
    <td><b>Description and Examples</b> </td>
  </tr>
  <tr>
    <td>-</td>
    <td>d, i, u, o, x, X, s</td>
    <td>
	For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros.</br>
	<code>_printf("A%dlast", 5);</code></br>
	<code>_printf("A%.3dlast", 5);</code></br>
	output</br>
	<code>$ A5last</code></br>
        <code>$ A005last</code></br>
	</br>
	For s − this is the maximum number of characters to be printed.</br>
	<code>_printf("A%s", "Holberton");</code></br>
	<code>_printf("A%.3s", "Holberton");</code></br>
	output</br>
	<code>$ Holberton</code></br>
        <code>$ Hol</code></br>
    </td>
  </tr>
</table>
##Future features
format tags -, +, (space), #, and width for the pointer flag
implement the length format tags

##Contributors
*Justin Marsh* - [Github](https://github.com/j-tyler) || [Twitter](https://twitter.com/dogonthecircuit) || [email](justin.marsh@holbertonschool.com)

*Richard Sim* - [Github](https://github.com/rdsim8589) || [Twitter](https://twitter.com/richard_d_sim) || [email](richard.sim@holbertonschool.com)

##Want to be contributor?
reach out to any of the Contributors