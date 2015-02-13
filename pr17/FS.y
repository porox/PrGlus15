%{
#include <stdio.h>
#include <string.h>

void yyerror (const char *str)
{
	fprintf(stderr,"ошибка: %s\n",str);
}

int yywrap ()
{
	return 1;
}

main()
{
	yyparse();
}

%}
%token TREAD TREADLN TWRITE TWRITELN TOPENBRACKET TCLOSEBRACKET TENDLN  TASIGMENT TVALUEINT TVALUEREAL TVAR TSTRING

 %%
commands:
	| commands
	command
	;
command:

	ReadLn
	| Read
	| Asigm
	| Write
	| WriteLn
	;

Read : 	TREAD TOPENBRACKET TVAR TCLOSEBRACKET TENDLN  

ReadLn:  TREADLN TOPENBRACKET TVAR TCLOSEBRACKET TENDLN 	

Asigm:  TVAR TASIGMENT  Val  TENDLN 

Val: TVALUEINT  
	| TVALUEREAL 

Write:  TWRITE TOPENBRACKET  TSTRING  TCLOSEBRACKET TENDLN

WriteLn: TWRITELN TOPENBRACKET  TSTRING TCLOSEBRACKET TENDLN

