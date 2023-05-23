/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    int SCOPE = 0;
    int func_addr = -1;
    int array_count = 0;
    #define ENTRY 100


    typedef struct symbol symbol;
    struct symbol {
        char name[30];
        char type[8];
        int scope;
        int addr;
        int line;
        int mut;
        char func_re;
        char func_arg[10];
        struct symbol *next;
        struct symbol *arr_next;
    };

    symbol *sym_table_arr[10];
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    // extern int yylineno;
    // extern int yylex();
    // extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int current_scope);
    static void insert_symbol(char name[], char type[], int current_scope, int line, int mut, char re_type);
    int lookup_symbol(char name[], int current_scope);
    char *symbol_type(int type);
    static void dump_symbol();
    bool Error_check(int ID1, int ID2);
    void Insert_arg_to_func(char name[], char arg[], char ret);
    char * Search_func_arg(char name[]);
    char Search_func_ret(char name[]);

    /* Global variables */
    bool HAS_ERROR = false;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    bool b_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ARROW AS IN DOTDOT RSHIFT LSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <f_val> FLOAT_LIT
// %token <b_val> BOOL_LIT
%token <s_val> ID
// %left '+' '-'
// %left '*' '/' '>' '<' LOR LAND
// %right '!'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Lit Expression TypeName ExpressionExpr assign_op ID_or_LIT FunctionName ParameterList ExpressionStmt Expr_A Expr_B Expr_C Expr_D uexpr AsStmt
%type <s_val> unary_op com_op add_op mul_op shift_op

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : {create_symbol(SCOPE);} GlobalStatementList {while(SCOPE >= 0){dump_symbol(SCOPE);}}
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : PackageStmt
    | NEWLINE
;

PackageStmt
    :PrintLNStmt
    |PrintStmt
    |DecStmt
    |Block
    |AssignStmt
    |IfStmt
    |WhileStmt
    |ForStmt
    |BreakStmt
    |FunctionStmt
    |ReturnStmt
    |Callfunc
;

FunctionStmt
    : Function {func_addr = -1;}
;

Function
    : FunctionName '(' {create_symbol(SCOPE + 1); SCOPE++;} ParameterList ')' ARROW TypeName '{' GlobalStatementList '}' { 
        Insert_arg_to_func($1, $4, $7[0] - 32);
        dump_symbol(SCOPE);
    }
    | FunctionName '(' ')' Block
;

FunctionName
    : FUNC ID { 
        if (!strcmp($2, "main"))
        {
            while (SCOPE > 0)
                dump_symbol(SCOPE--);
        }
        printf("func: %s\n", $2);
        insert_symbol($2, "func", SCOPE, yylineno, -1, 'V');
        Insert_arg_to_func($2, "v", 'V');
        $$ = $2;
    }
;
ParameterList
    : ID':' TypeName {
        insert_symbol($1, $3, SCOPE, yylineno, 0, '-'); 
        int length = strlen($$);
        for (int i = 0; i < length ; i++)
            $$[i] = '\0';
        strncpy( $$, $3, 1);
    }
    | ParameterList ',' ID':' TypeName { 
        insert_symbol($3, $5, SCOPE, yylineno, 0, '-');
        strncat( $$, $5, 1);
    }
;

ReturnStmt
    :RETURN Lit ';' {printf("%creturn\n", $2[0]);}
    |ID '%' ID EQL{
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        printf("REM\n");
    } Lit {printf("EQL\n"); printf("breturn\n");}
;

Callfunc
    :ID '(' ')' ';' {
        printf("call: %s(%s)%c\n", $1, Search_func_arg($1), Search_func_ret($1));
    }
    |ID '(' argument_expr_list ')'{
        printf("call: %s(%s)%c\n", $1, Search_func_arg($1), Search_func_ret($1));
    }
;

argument_expr_list
    :argument_expr_list ',' ID {printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);}
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);}
;

DecStmt
    :LET ID ':' TypeName '=' Lit ';'
    {
        if ($4[0] == 'i')
            insert_symbol($2, "i32", SCOPE, yylineno, 0, '-');
        else if ($4[0] == 'f')
            insert_symbol($2, "f32", SCOPE, yylineno, 0, '-');
        else if ($4[0] == 'b')
            insert_symbol($2, "bool", SCOPE, yylineno, 0, '-');
        else if ($4[0] == 's')
            insert_symbol($2, "str", SCOPE, yylineno, 0, '-');
    }
    |LET MUT ID ':' TypeName '=' Lit ';'
    {
        if ($5[0] == 'i')
            insert_symbol($3, "i32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'f')
            insert_symbol($3, "f32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'b')
            insert_symbol($3, "bool", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 's')
            insert_symbol($3, "str", SCOPE, yylineno, 1, '-');
    }
    |LET MUT ID '=' Lit ';'
    {
        if ($5[0] == 'i')
            insert_symbol($3, "i32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'f')
            insert_symbol($3, "f32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'b')
            insert_symbol($3, "bool", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 's')
            insert_symbol($3, "str", SCOPE, yylineno, 1, '-');
    }
    |LET MUT ID ':' TypeName ';'
    {
        if ($5[0] == 'i')
            insert_symbol($3, "i32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'f')
            insert_symbol($3, "f32", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 'b')
            insert_symbol($3, "bool", SCOPE, yylineno, 1, '-');
        else if ($5[0] == 's')
            insert_symbol($3, "str", SCOPE, yylineno, 1, '-');
    }
    |LET ID ':' Lit ';'
    |LET ID '=' Lit ';'{
        insert_symbol($2, $4, SCOPE, yylineno, 0, '-');
    }
    |LET ID ':' '[' TypeName ';' INT_LIT {printf("INT_LIT %d\n", $7);} ']' '=' '[' Lit ']' ';'{
        insert_symbol($2, "array", SCOPE, yylineno, 0, '-');
    }
;

AssignStmt
    : AssignmetExpr ';'
;

AssignmetExpr
    : ID assign_op Expression {
            if (!Error_check(lookup_symbol($1, SCOPE), lookup_symbol($1, SCOPE)))
                printf("error:%d: undefined: %s\n", yylineno + 1, $1);
            else
                printf("%s\n",$2); 
        }
;

assign_op
    : '=' { $$ = "ASSIGN";}
    | ADD_ASSIGN { $$ = "ADD_ASSIGN";}
    | SUB_ASSIGN { $$ = "SUB_ASSIGN";}
    | MUL_ASSIGN { $$ = "MUL_ASSIGN";}
    | DIV_ASSIGN { $$ = "DIV_ASSIGN";}
    | REM_ASSIGN { $$ = "REM_ASSIGN";}
;

Block
    : '{' { create_symbol(SCOPE + 1); SCOPE++;} GlobalStatementList '}' { dump_symbol(SCOPE);}
;

IfStmt
    : IF Condition Block IfStmt
    | IF Condition Block new_non ELSE Block 
    | IF Condition Block NEWLINE
;

Condition
    :ID { 
        if (lookup_symbol($1, SCOPE) == -1)
            printf("error:%d: undefined: %s\n", yylineno + 1, $1);
        else
            printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
    }
        '>' Lit {
            if (lookup_symbol($1, SCOPE) == -1)
                printf("error:%d: invalid operation: GTR (mismatched types undefined and %s)\n", yylineno + 1, $4);
            printf("GTR\n");
        }
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);} NEQ Lit {printf("NEQ\n");}
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);} EQL Lit {printf("EQL\n");}
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);} '<' Lit {printf("LSS\n");}
    |Callfunc
;

WhileStmt
    :WHILE Condition Block
;

ForStmt
    :FOR ID IN ID '{' {
        printf("IDENT (name=%s, address=%d)\n", $4, lookup_symbol($4, SCOPE) % 10);
        create_symbol(SCOPE + 1); SCOPE++;
        insert_symbol($2, "i32", SCOPE, yylineno, 0, '-');
        } GlobalStatementList '}'

Lit
    : INT_LIT {
        printf("INT_LIT %d\n", $1);
        $$ = "i32";
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $1);
        $$ = "f32";
    }
    | '"' '"' {
        printf("STRING_LIT \"\"\n");
        $$ = "str";
    }
    | '"' STRING_LIT '"' {
        printf("STRING_LIT \"%s\"\n", $2);
        $$ = "str";
    }
    |TRUE {printf("bool TRUE\n"); $$ = "bool";}
    |FALSE {printf("bool FALSE\n"); $$ = "bool";}
    | Lit ',' Lit
    |LoopStmt
    |'&' ID {printf("IDENT (name=%s, address=%d)\n", $2, lookup_symbol($2, SCOPE) % 10);} '[' Lit DOTDOT {printf("DOTDOT\n");} Lit ']'
    |
;

LoopStmt
    :LOOP Block
;

BreakStmt
    :BREAK Lit ';'
;

PrintLNStmt
    : PRINTLN '(' Expression ')' ';' {
        printf("PRINTLN %s\n", $3);
    }
;

PrintStmt
    : PRINT '(' new_non Expression new_non ')' ';' {
        printf("PRINT %s\n", $4);
    }
;

new_non
    :
    |NEWLINE
;

Expression
    :AsStmt %prec LOWER_THAN_ELSE
    |ExpressionStmt
    |NEWLINE Expression
    |NEWLINE
    |
    |Lit
    |ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);} '[' Lit ']' {
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    |ExpressionExpr 
;

AsStmt
    :ID AS TypeName {
            printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
            printf("%c2%c\n", symbol_type(lookup_symbol($1, SCOPE) / 10)[0], $3[0]);
            strcpy($$, $3);
    }
    |Lit AS TypeName {printf("%c2%c\n", $1[0], $3[0]); 
        $$ = $3;
    }
    |'(' ExpressionStmt ')' {$$ = $2;}
    |ID {printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10); strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));}
    |Lit
;

ExpressionStmt
    : ExpressionStmt LOR Expr_A { printf("LOR\n"); $$ = "bool"; }
    | Expr_A {$$ = $1;}
;

Expr_A
    : Expr_A LAND Expr_B { printf("LAND\n"); }
    | Expr_B { $$ = $1;}
;

Expr_B
    : Expr_B com_op Expr_C { printf("%s\n", $2); }
    | Expr_C { $$ = $1; }
;

Expr_C
    : Expr_C add_op Expr_D { printf("%s\n", $2);}
    | Expr_D { $$ = $1; }
;

Expr_D
    : Expr_D mul_op AsStmt { $$ = $1; printf("%s\n", $2); }
    | uexpr { $$ = $1;}
;

uexpr
    : AsStmt { $$ = $1;}
    | unary_op uexpr { printf("%s\n", $1); $$ = $2; }
;

unary_op
    : '+' { $$ = "POS"; }
    | '-' { $$ = "NEG"; }
    | '!' { $$ = "NOT";}
;

com_op
    : '>' {$$ = "GTR"; }
    | '<' { $$ = "LSS"; }
    | GEQ { $$ = "GEQ";}
    | LEQ { $$ = "LEQ"; }
    | EQL { $$ = "EQL"; }
    | NEQ { $$ = "NEQ"; }
;

add_op
    : '+' { $$ = "ADD"; }
    | '-' { $$ = "SUB"; }
;

mul_op
    : '*' { $$ = "MUL"; }
    | '/' { $$ = "DIV"; }
    | '%' { $$ = "REM"; }
;

ExpressionExpr
    : AsStmt '+' AsStmt {printf("ADD\n");}
    | ID '-' ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        printf("SUB\n");
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    | ID '*' ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        printf("MUL\n");
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    | ID '/' ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        printf("DIV\n");
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    | ID '%' ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        printf("REM\n");
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
    | ID LSHIFT ID {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, SCOPE) % 10);
        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, SCOPE) % 10);
        if (lookup_symbol($1, SCOPE) / 10 != lookup_symbol($3, SCOPE) / 10)
            printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n", yylineno + 1, symbol_type(lookup_symbol($1, SCOPE) / 10), symbol_type(lookup_symbol($3, SCOPE) / 10));
        printf("LSHIFT\n");
        strcpy($$, symbol_type(lookup_symbol($1, SCOPE) / 10));
    }
;

TypeName
    : INT { $$ = "i32";}
    | FLOAT { $$ ="f32";}
    | '&' { $$ = "str";}
    | '&' STR { $$ = "str";}
    | BOOL { $$ = "bool";}
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int current_scope) {
    printf("> Create symbol table (scope level %d)\n", current_scope);
}

static void insert_symbol(char name[], char type[], int current_scope, int line, int mut, char re_type) {
    symbol *new_symbol = malloc(sizeof(symbol));
    strcpy(new_symbol->name, name);
    strcpy(new_symbol->type, type);
    new_symbol->scope = current_scope;
    new_symbol->line = line + 1;
    new_symbol->mut = mut;
    new_symbol->func_re = re_type;
    new_symbol->next = NULL;
    int addr = 0;
    if (sym_table_arr[0] == NULL)
        sym_table_arr[0] = new_symbol;
    else   
    {
        symbol *tmp;
        for (int i = 0; i <= SCOPE; i++)
        {
            if (!sym_table_arr[i])
                break;
            tmp = sym_table_arr[i];
            while (tmp->next != NULL)
                tmp = tmp->next;
        }
        if (sym_table_arr[SCOPE])
            tmp->next = new_symbol;
        else
            sym_table_arr[SCOPE] = new_symbol;
        addr = tmp->addr + 1;
    }
    // function
    if (type[1] == 'u')
    {
        new_symbol->addr = -1;
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, new_symbol->addr, current_scope);
    }
    else
    {
        func_addr++;
        new_symbol->addr = func_addr;
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, new_symbol->addr, current_scope);
    }
}

int lookup_symbol(char name[], int current_scope) {
    symbol *search_pointer;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    // doesn't find the target
    if (strcmp(name, search_pointer->name))
        return -1;

    int type = 1;// 1:int, 2:float, 3:bool, 4:str, 5:array
    switch (search_pointer->type[0])
    {
        case 'i':
            type = 1;
            break;
        case 'f':
            type = 2;
            break;
        case 'b':
            type = 3;
            break;
        case 's':
            type = 4;
            break;
        case 'a':
            type = 5;
            break;
    }
    return type*10 + (search_pointer->addr);
}

static void dump_symbol(int current_scope) {
    printf("\n> Dump symbol table (scope level: %d)\n", current_scope);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");

    int index = 0;
    symbol *current_symbol = sym_table_arr[current_scope];
    while (current_symbol)
    {
        symbol *current_symbol_next = current_symbol->next;
        if (!strcmp(current_symbol->type, "func"))
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d(%s)%c",
                    index, current_symbol->name, current_symbol->mut, current_symbol->type, current_symbol->addr, current_symbol->line, current_symbol->func_arg, current_symbol->func_re);
            for (int i = 0; i < 7 - strlen(current_symbol->func_arg); i++)
                printf(" ");
            printf("\n");
        }
        else
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10c\n",
                    index, current_symbol->name, current_symbol->mut, current_symbol->type, current_symbol->addr, current_symbol->line, current_symbol->func_re);
        index++;
        free(current_symbol);
        current_symbol = current_symbol_next;
    }
    sym_table_arr[current_scope] = NULL;
    SCOPE--;
}

char * symbol_type(int type)
{
    switch (type)
    {
        case 1:
            return "i32";
        case 2:
            return "f32";
        case 3:
            return "bool";
        case 4:
            return "str";
        case 5:
            return "array";
    }
    return "x";
}

bool Error_check(int ID1, int ID2)
{
    if (ID1 == -1 || ID2 == -1)
        return false;
    if (ID1 / 10 != ID2 / 10)
        return false;
    return true;
}

void Insert_arg_to_func(char name[], char arg[], char ret)
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }
    search_pointer->func_re = ret;
    strcpy(search_pointer->func_arg, arg);
    for (int i = 0; i < strlen(search_pointer->func_arg); i++)
        search_pointer->func_arg[i] -= 32;
}

char * Search_func_arg(char name[])
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    return search_pointer->func_arg;
}

char Search_func_ret(char name[])
{
    symbol *search_pointer;
    int current_scope = SCOPE;
    while (current_scope >= 0)
    {
        if (sym_table_arr[current_scope])
            search_pointer = sym_table_arr[current_scope];
        else
        {
            current_scope--;
            continue;
        }

        while (search_pointer->next != NULL && strcmp(name, search_pointer->name))
            search_pointer = search_pointer->next;

        if (!strcmp(name, search_pointer->name))
            break;
        else
            current_scope--;
    }

    return search_pointer->func_re;
}