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
[\-\+]?[0-9]*							return TVALUEINT;
[\-\+]?[0-9]*[\.]?[0-9]+([eE][\-\+]?[0-9]+)?  	return TVALUEREAL;
[a-zA-Z_][a-zA-Z_0-9]*   					return TVAR;
(?:[\'](?:[^\']+|[\'][\'])+[\']|[#][0-9]+)+		return TSTRING;
\n
[  \t]+
%%



