This is the first part of the project of building my own compiler. It is part of the the grade to the course of Compilers (INF01147) at Federal University of Rio Grande do Sul. 
 
==================================================  

In order to run you must have flex installed (ubuntu/debian):  
 **sudo apt-get install flex**

After that you just need to run the Makefile:  
 **make**

And then execute it feeding a file containing the code to be analysed:  
 **./etapa1 < example1**  
 **./etapa1 < example2**  

The result will be a list of all tokens found in the file provided or an error in case of lexical problems.

Besides that, a hash table containing all the valid literals and symbols is provided.


==================================================

To better understand what is the lexical definition accepted, please take a look at the task description (in portuguese):
[Task description](https://bitbucket.org/bpsilva/compiler-01_lexical_analysis/src/f12e26addcca1d1ac8894d7026391534afafd571/definicao.pdf?at=master&fileviewer=file-view-default)