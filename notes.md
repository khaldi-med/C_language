
* "#" (hash) at the beginning of the first line. It means that the content of this line is a preprocessor directive.
    * The prefix “pre” suggests that these operations are performed before the full processing (compilation) takes place. The changes the preprocessor introduces are controlled entirely by its directives. In the example program, we’re dealing with the include directive. When the preprocessor encounters that directive, it replaces the directive with the content of the file whose name is listed in the directive (like stdio.h). 

* Every function in “C” begins with the following set of information:
    - what is the result of the function? (int, char, void,..)
    - what is the name of the function?
    - how many parameters does the function have and what are their names?

* IDE (Integrated Development Environment) is a software application that typically consists of a code editor, a compiler, a debugger, and a graphical user interface (GUI) builder.

* Here are some descriptions and examples of some of the built in types:

	- void	Empty Type	
	-	char	Single Character/Byte	char last_initial = 'H';
	-	int	Integer	int age = 23;
	-	long	Integer that can hold larger values	long age_of_universe = 13798000000;
	-	float	Decimal Number	float liters_per_pint = 0.568f;
	-	double	Decimal Number with more precision	double speed_of_swallow = 0.01072896;

* cc -std=c99 -Wall
* for debugging the errors there is some tool like: **Valgrind**, **gdb**.

* Inside a conditional statement's parentheses any value that is not 0 will evaluate to true. This is important to remember as many conditions use this to check things implicitly.

* gcc -g3 --> The command calls gcc with arguments -g3 (enable maximum debugging info).

* **argc**: of type int, the number of arguments passed to the program from the command line

* **argv**: of a pointer type, which is an array of the arguments (essentially all the words on the command line, including the program name).

* To get a **man page** from a specific section, use **man section name**, **e.g. man 3 printf**.

* ctrl-Z:
	Suspend the process. This will leave a stopped process lying around. Type jobs to list all your stopped processes, fg to restart the last process (or fg %1 to start process %1 etc.), bg to keep running the stopped process in the background, kill %1 to attempt to end process %1 politely, kill -KILL %1 to end process %1 even if it is intercepting normal kills.


```
If you have a runaway process that you can’t get rid of otherwise, you can use ps g to get a list of all your processes and their process ids. The kill command can then be used on the offending process, e.g. kill -KILL 6666 if your evil process has process id 6666. Sometimes the killall command can simplify this procedure, e.g. killall -KILL evil halts all process with command name evil.
```

* For example, decimal 31 can be written as 037 in octal and 0x1f or 0X1F in hex.




































