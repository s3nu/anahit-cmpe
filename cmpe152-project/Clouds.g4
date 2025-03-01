grammar Clouds;

@header {
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;
}

program : header function* body ; //done 
header  : CLOUDS ID SEMICOLON; //done

body: block+;

block   : environments //done
        | function    //add if pass1 creates them 
        | run_simulation //remove when fixed 
        ;

//environments: ENVIRNOMENT ID '{' env_stat+ '}'; //use this later
environments: ENVIRONMENT ID scope; //done

// run_simulation: SIMULATION '{' sim_stat+ '}'; //use this later
run_simulation: SIMULATION scope;    //Done               
 
 //need to fix this, dont have declarations or compound_stmt defined

//env_stat:   stat; //add other value envirnoment statements

//sim_stat:   ; //add other simulaiton statments



scope : '{' stmt_list '}'; 

funcscope : '{' (stmt_list)? (return_stmt)? '}' ; 

//statements
stmt_list       : stat SEMICOLON (stat SEMICOLON)* ;



stat : //scope            # scope_node| 
        assignment_stmt // # assignmentStmt
     | init_stmt
     | rotation_stmt
     | functionCall         //# Function_
     | repeat_stmt      //# repeatStmt
     | if_stmt          //# ifStmt
     | when_stmt       // # whenStmt
     | print_stmt       //# printStmt
     | put_stmt        // # putStmt
     | move_stmt     //#moveStmt
     | wait_stmt     //#waitStmt
    // |                  //# emptyStmt
     ;


return_stmt : 'return' expr SEMICOLON;

rotation_stmt   : variable rot_op expr ;

assignment_stmt : variable assignment_operators expr 
                ;


init_stmt       : init_var (ASSIGN_OP '[' init_list ']')?
                | init_var (ASSIGN_OP expr)?
                ; 

repeat_stmt     : REPEAT stmt_list UNTIL expr ;

if_stmt         : IF expr THEN scope ( ELSE scope )? ;


put_stmt        : PUTNENV variable ID
 //               | PUTNENV variable TYPE
                ;

wait_stmt       : WAIT expr;

move_stmt       : MOVE variable TO point_var MOVE_3 expr (MOVE_3 expr)?
                ;

point_var   : '[' init_list ']'
            | ID
            ;

when_stmt       : WHEN '(' expr (',' expr)* ')' THEN ID ;
//change stat to a function pointer, then have
//function built before main?

print_stmt      : PRINT '(' expr ')'
                | PRINT '(' '"' (ID)* '"' ')'
                ;

variable locals [ TypeSpec *type = nullptr ]
        :  //Done 
        | variable '.' obj_vars
        | ID
        ;

expr locals [ TypeSpec *type = nullptr ]
     : expr mul_div_op expr     # mulDivExpr //done first visit
     | expr add_sub_op expr     # addSubExpr //done first visit
     | expr rel_op expr         # relExpr    //done first visit
    // | expr rot_op expr         # rotExpr    //done first visit  
     //| '[' init_list ']'        # initList   //done first visit
     | functionCall             # ExprFunctionCall
     | signedNumber             # signedNumberConst
     | number                   # numberConst //done first visit
     | variable                 # Exprvariable  //done first visit
     | '(' expr ')'             # parens       //done first visit
     ;

init_list   : obj_vars '=' expr (',' obj_vars '=' expr)*  ;  //done first visit

init_var    : TYPE variable; 

obj_vars    : HEIGHT
            | WIDTH
            | LENGTH
            | RADIUS
            | X 
            | Y 
            | Z 
            | DX 
            | DY 
            | DZ
            | CENTER
            | VELOCITY
            | SPEED
            ;

function
    : functionInit funcscope
    ;

functionInit
    : (return_type)? ID '(' init_var (',' init_var )* ')'
    | (return_type)? ID '()'
    ;

return_type : TYPE;

functionCall locals [ TypeSpec *type = nullptr ]
    : ID '(' expr (',' expr)* ')'
    | ID '()'
    ;

argumentList
    : // No arguments
    | expr (',' expr)* 
    | variable
    ;
    

methodCallArguments
    : // No arguments
    | expr (',' expr)*  // Some arguments
    ;

methodCall_ref
    : // No arguments
    | '&' expr (',' '&'expr)*  // Some arguments
    ;

signedNumber locals [  TypeSpec *type = nullptr ] 
    : sign number 
    ;
sign : ADD | SUB ;

number locals [ TypeSpec *type = nullptr ]
    : INT    # integerConst
    | FLOAT      # floatConst
    ;
assignment_operators : ASSIGN_OP | ADD_EQ | SUB_EQ | MUL_EQ | DIV_EQ ;

mul_div_op : MUL | DIV ; //multiple or divide
add_sub_op : ADD | SUB ; //add or subtract
rel_op     : EQ_OP | NE_OP | LT_OP | LE_OP | GT_OP | GE_OP ; //relational operators
rot_op     : ROLL_OP | PITCH_OP | YAW_OP ; //rotational operators



//key words
CLOUDS      : 'Clouds'      ;
REPEAT      : 'REPEAT'      ;
UNTIL       : 'UNTIL'       ;
IF          : 'IF'          ;
THEN        : 'THEN'        ;
ELSE        : 'ELSE'        ;
WHEN        : 'WHEN'        ;
CENTER      : 'center'      ;
TELEPORT    : 'teleport'    ;
COLISION    : 'collision'   ;
WAIT        : 'wait'        ;
MOVE        : 'move'        ;
TO          : 'to'          ;
MOVE_3      :   IN    
            |   FOR
            |   AT  
            ;
AT          : 'at'          ;
IN          : 'in'          ;
FOR         : 'for'         ;
FINISH      : 'finish'      ;
PUTNENV     : 'putnenv'     ;
FUNCTION    : 'function'    ;
ENVIRONMENT : 'environment' ;
SIMULATION  : 'simulation'  ;
PRINT       : 'print'       ;
BETWEEN     : 'between'     ;

//types
TYPE:   SPHERE 
    |   'cube' 
    |   'cylinder' 
//    |   'cone'
    |   'tetra' 
    |   POINT
    | 'int'
    | 'float' 
    ;

SPHERE: 'sphere' ;

//init keywords
HEIGHT  : 'height';
WIDTH   : 'width';
LENGTH  : 'length';
RADIUS  : 'radius';
X       : 'x';
Y       : 'y';
Z       : 'z';
DX      : 'dx';
DY      : 'dy';
DZ      : 'dz';
POINT   : 'point';
VELOCITY: 'velocity';
SPEED   : 'speed';


//operators

ASSIGN_OP : '=' ;
MUL :   '*' ; // assigns token name to '*' used above in grammar
DIV :   '/' ;
ADD :   '+' ;
SUB :   '-' ;

MUL_EQ :   '*=';
DIV_EQ :   '/=';
ADD_EQ :   '+=';
SUB_EQ :   '-=';

EQ_OP :    '==';
NE_OP :    '!=';
LT_OP :    '<' ;
LE_OP :    '<=';
GT_OP :    '>' ;
GE_OP :    '>=';

ROLL_OP : '~R' ; //roll
PITCH_OP :'~P' ; //pitch
YAW_OP :  '~Y' ; //yaw

COM_OP : '//' ;
SEMICOLON : ';';



FLOAT: INT+ '.' INT*                                          //Float definition
     |      '.' INT+
     ;	
     
ID  :   [a-zA-Z]+ ;      // match identifiers
INT :   [0-9]+ ;         // match integers

NEWLINE : '\r'? '\n' ->skip  ;
WS  :  [ \t]+ -> skip ; // toss out whitespace
COMMENT : COM_OP ~[\r\n]* -> skip;
BLOCK_COM : '/*' .*? '*/' -> skip; //skip comments


