%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[Rr][Ee][Aa][Dd][Ll][Nn]                			return TREADLN;
[Rr][Ee][Aa][Dd]                    				return TREAD;
[Ww][Rr][Ii][Tt][Ee]						return TWRITE;
[Ww][Rr][Ii][Tt][Ee][Ll][Nn]				return TWRITELN;
\(											return TOPENBRACKET;
\)											return TCLOSEBRACKET;
;											return TENDLN;
:=											return TASIGMENT;
[\-\+]?[1-9][0-9]*							return TVALUEINT;
[\-\+]?[1-9][0-9]*([Ee][\-\+]?[0-9]{1,})?([\.][0-9]+([Ee][\-\+]?[0-9]{1,})?)?  	return TVALUEREAL;
[a-zA-Z_][a-zA-Z_0-9]*   					return TVAR;
([#][0-9]{1,})*([\']([#][0-9]{1,})*[^\']*([\'][\'])*[^\']*[\'])*([#][0-9]{1,})*		return TSTRING;
\n
[  \t]+
%%
