%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[Rr][Ee][Aa][Dd]                    return TOKREAD;
[Rr][Ee][Aa][Dd][Ll][Nn]                return TOKREADLN;
[Ww][Rr][Ii][Tt][Ee]			return TOKWRITE;
[Ww][Rr][Ii][Tt][Ee][Ll][Nn]		return TOKWRITELN;
\(					return TOKOPENBRACKET;
\)					return TOKCLOSEBRACKET;
;					return TOKENDLN;
\'					return TOKCOMM;
:=					return TOKASIGMENT;
[-?+?][0-9]+				return TOKVALUEINT;
[-?+?][0-9]+[.][0-9]+[Ee][-?+?][0-9]+	return TOKVALUEREAL;
[a-zA-Z_][a-zA-Z_0-9]			return TOKVAR;
[\'][.]					return TOKSTRING;
\n
[ \t]+
%%
