/*
    filename: lexer.l
*/

/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #define print_token(token) \
        printf("%-8s \t %s\n", strcmp(token, "NEWLINE")? yytext: "", token)
    
    void print_str();
    void print_com();
    int line_num = 0;
    int comment_num = 0;
    bool comment_enter = true;
    int last_comment_line = -1;
%}

/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber {digit}*\.{digit}+
quota \"
sliteral \"(\\.|[^"\\])*\"
ccomment \/\/.*
c_comment "/*"([^*]|\n|"*"+[^/])*"*"+"/"

/* Rules section */
%%
"+"         { print_token("ADD"); }
"-"         { print_token("SUB"); }
"*"         { print_token("MUL"); }
"/"         { print_token("QUO"); }
"%"         { print_token("REM"); }
">"         { print_token("GTR"); }
"<"         { print_token("LSS"); }
">="        { print_token("GEQ"); }
"<="        { print_token("LEQ"); }
"=="        { print_token("EQL"); }
"!="        { print_token("NEQ"); }
"="         { print_token("ASSIGN"); }
"+="        { print_token("ADD_ASSIGN"); }
"-="        { print_token("SUB_ASSIGN"); }
"*="        { print_token("MUL_ASSIGN"); }
"/="        { print_token("QUO_ASSIGN"); }
"%="        { print_token("REM_ASSIGN"); }
"&"         { print_token("BAND"); }
"|"         { print_token("BOR"); }
"~"         { print_token("BNOT"); }
">>"        { print_token("RSHIFT"); }
"&&"        { print_token("LAND"); }
"||"        { print_token("LOR"); }
"!"         { print_token("NOT"); }
"("         { print_token("LPAREN"); }
")"         { print_token("RPAREN"); }
"["         { print_token("LBRACK"); }
"]"         { print_token("RBRACK"); }
"{"         { print_token("LBRACE"); }
"}"         { print_token("RBRACE"); }
";"         { print_token("SEMICOLON"); }
","         { print_token("COMMA"); }
{quota}     { print_token("QUOTA"); }
":"         { print_token("COLON"); }
"\n"        { print_token("NEWLINE"); line_num++; comment_enter = true; }
"->"        { print_token("ARROW"); }
"<<"        { print_token("LSHIFT"); }
"print"     { print_token("PRINT"); }
"println"   { print_token("PRINTLN"); }
"if"        { print_token("IF"); }
"else"      { print_token("ELSE"); }
"for"       { print_token("FOR"); }
"i32"       { print_token("INT"); }
"f32"       { print_token("FLOAT"); }
".."        { print_token("DOTDOT"); }
"bool"      { print_token("BOOL"); }
"true"      { print_token("TRUE"); }
"false"     { print_token("FALSE"); }
"let"       { print_token("LET"); }
"mut"       { print_token("MUT"); }
"fn"        { print_token("FUNC"); }
"return"    { print_token("RETURN"); }
"break"     { print_token("BREAK"); }
"as"        { print_token("AS"); }
"in"        { print_token("IN"); }
"while"     { print_token("WHILE"); }
"loop"      { print_token("LOOP"); }
{inumber}   { print_token("INT_LIT"); }
{fnumber}   { print_token("FLOAT_LIT"); }
{sliteral}  { print_str(); }
{id}        { print_token("IDENT"); }
{ccomment}  { comment_num++; print_token("COMMENT"); }
{c_comment} { print_com(); }


<<EOF>>     { line_num++; yyterminate(); }
[ \t]+      {;}
.           {;}
%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}

void print_str()
{
    printf("%-8s \t %s\n", "\"", "QUOTA");
    if (yyleng > 2)
    {
        yytext[yyleng - 1] = '\0';
        printf("%-8s \t %s\n", &yytext[1], "STRING_LIT");
    }
    printf("%-8s \t %s\n", "\"", "QUOTA");
}

void print_com()
{
    printf("%-8s       \t %-s\n", yytext,  "MUTI_LINE_COMMENT");
    int count_line = 0;
    for (int i = 0; i < yyleng; i++)
        if (yytext[i] == '\n')
            count_line++;

    line_num += count_line;
    comment_num += count_line + comment_enter;
    comment_enter = false;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}