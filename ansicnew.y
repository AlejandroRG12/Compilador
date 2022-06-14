%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
using namespace std;


extern int yylex();
void yyerror(const char *);
extern FILE *yyin;

#include "symfuncs.h"
#include "genlibnew.h"



enum OP_TYPES{
		PLUS_OP = 1,
		ADDR_OP,
		MINUS_OP,
		DEREF_OP,
		TWOCOMP_OP,
		NOT_OP
};

enum ASSIGN_TYPES{
	EQ_ASSIGN_OP = 1,
	MUL_ASSIGN_OP,
	DIV_ASSIGN_OP,
	MOD_ASSIGN_OP,
	ADD_ASSIGN_OP,
	SUB_ASSIGN_OP,
	LEFT_ASSIGN_OP,
	RIGHT_ASSIGN_OP,
	AND_ASSIGN_OP,
	XOR_ASSIGN_OP,
	OR_ASSIGN_OP,
};

%}

%union {
	struct{
		union{
			int ival;
			double dval;
			char *name;
			char *sval;
			char cval;
		};
		int valtype;
	};
	VAR_DATA *id_data;
	std::list<VAR_DATA *> *idlist;
	int scsp;
	std::list<int> *sqlist;
	int typsp;
	int qual;
	VAR_DATA sym;
	struct{
		int typq;
		int level;
	} pstruc;
	std::list<int> *splist;
	int op;
	int typ;
	int assop;
	int instr;
	struct {
		std::list<int> *breaklist;
		std::list<int> *nextlist;
		std::list<int> *continuelist;
		std::list<GOTO_DATA *> *gotolist;
		std::list<CASE_DATA *> *caselist;
	} lists;
}



%token <name> IDENTIFIER CONSTANT <sval> STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN




%type <id_data> direct_declarator
%type <id_data> declarator
%type <id_data> init_declarator
%type <idlist> init_declarator_list
%type <scsp> storage_class_specifier
%type <sqlist> declaration_specifiers
%type <typsp> type_specifier
%type <qual> type_qualifier
%type <sym> constant_expression
%type <idlist> parameter_type_list
%type <pstruc> pointer
%type <splist> type_qualifier_list
%type <sym> initializer

%type <sym> assignment_expression
%type <sym> expression
%type <sym> primary_expression
%type <sym> postfix_expression
%type <sym> unary_expression
%type <op> unary_operator
%type <typ> type_name
%type <sym> cast_expression
%type <sym> multiplicative_expression
%type <sym> additive_expression
%type <sym> shift_expression
%type <sym> relational_expression
%type <sym> equality_expression
%type <sym> and_expression
%type <sym> exclusive_or_expression
%type <sym> inclusive_or_expression
%type <sym> logical_and_expression
%type <sym> logical_or_expression
%type <sym> conditional_expression
%type <sym> argument_expression_list
%type <assop> assignment_operator
%type <lists> M
%type <instr> N
%type <lists> selection_statement
%type <lists> statement
%type <lists> labeled_statement
%type <lists> compound_statement
%type <lists> iteration_statement
%type <lists> statement_list
%type <lists> jump_statement
%type <sym> logic_expression
%type <sym> logic_expression_statement
%type <sym> expression_statement
%type <sqlist> specifier_qualifier_list



%type <idlist> parameter_list
%type <sym> parameter_declaration

%nonassoc NOELSE
%nonassoc ELSE


%start translation_unit
%%

primary_expression
	: IDENTIFIER			{ printf("primary_expression : IDENTIFIER\n");
							  string *name = new string($1);
							  symrec *s = getsym(name);
							  if(s == NULL)
							  {
									printf("Variable %s \n", $1);
									yyerror("Variable not declared! ");
							  }
							  cout<< "<" << *name << ">\n";
							  $$.var = s;
							  $$.typ = s->typ;
							  $$.dimlist = s->dimlist;
							  $$.plevel = 0;
							}		
	| CONSTANT				{ printf("primary_expression : CONSTANT\n");
							  symrec *s;
							  std::string *name;
							  switch($<valtype>1)
							  {
									case DOUBLEVAL:
									cout << "<(double)" << $<dval>1 << ">\n";
									name = newtemp();
									s = putsym(name, DOUBLEVAL | CONST_SPEC);
									$$.val.doubleval = $<dval>1;
									*(double *)(datablock+s->offset) = $<dval>1;
									$$.typ = s->typ;
									$$.var = s;
									break;
									case INTVAL:
									cout<< "<(int)" << $<ival>1 << ">\n";
									name = newtemp();
									s = putsym(name, INTVAL |CONST_SPEC);
									$$.val.intval = $<ival>1;
									*(int *)(datablock+s->offset) = $<ival>1;
									$$.typ = s->typ;
									$$.var = s;
									break;
									case CHARVAL:
									cout<<"<(char)" << $<cval>1 <<">\n";
									s = putsym(name, CHARVAL | CONST_SPEC);
									$$.val.charval = $<cval>1;
									*(char *)(datablock+s->offset) = $<cval>1;
									$$.typ = s->typ;
									$$.var = s;
									break;
							  }
							}		
	| STRING_LITERAL		{ printf("primary_expression : STRING_LITERAL\n");
							  symrec *s;
							  std::string *name;
							  string *str = new string($1);
							  cout << "<\"" << *str << "\">\n";
							  name = newtemp();
							  s = putsym(name, STRVAL | CONST_SPEC);
							  s->size = strlen($1)+1;
							  memcpy(datablock+s->offset, $1, s->size);
							  data_location(s->size);
							  $$.name = name;
							  $$.typ = s->typ;
							  $$.var = s;
							}
	| '(' expression ')'	{printf("primary_expression : '(' expression ')'\n"); $$=$2;}		
	;

postfix_expression
	: primary_expression		{ printf("postfix_expression : primary_expression\n"); $$ =$1; }
	| postfix_expression '[' expression ']'		{ printf("postfix_expression : postfix_expression '[' expression ']'\n"); 
												  $$ = $1;
												  if($1.var == NULL)
												  	yyerror("Error: Array name must be specified");
												  if(!isintegral($3.typ))
												  	yyerror("Array subscript must be integral!\n");
												  if($1.plevel>0){
													string *name = newtemp();
													symrec *s0 = putsym(name, INTVAL | CONST_SPEC);
													*(int *)(datablock+s0->offset) = getsizeof($$.typ);
													name = newtemp();
													symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
													*(int *)(datablock+s1->offset) = getrdim($$.dimlist,$1.plevel-1);
													name = newtemp();
													symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, $3.var, s0, s2);
													name = newtemp();
													symrec *s3 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, $$.var2, s1,s3);
													name = newtemp();
													symrec *s4 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, s3, s2,s4);
													$$.var2 = s4;
												  }
												  else{
													string *name = newtemp();
													symrec *s1 = putsym(name, INTVAL | VAR_SPEC);
													*(int *)(datablock+s1->offset) = getsizeof($$.typ);
													name = newtemp();
													symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
													gencode(MULT_IR, $3.var, s1,s2);
													$$.var2 = s2;
												  }
												  $$.typ |= ARRAY_SPEC;
												  $$.plevel++;
												}
	| postfix_expression '(' ')'		{ printf("postfix_expression : postfix_expression '(' ')'\n"); 
										  symrec *s;
										  std::string *name = newtemp();
										  s = putsym(name, $1.typ & 0x1F);
										  $$.typ = s->typ;
										  gencode(CALL_IR, $1.var, nullptr, s);
										  $$.var = s;
										}
	| postfix_expression '(' argument_expression_list ')'		{ printf("postfix_expression : postfix_expression '(' argument_expression_list ')'\n"); 
																  symrec *s, *s2, *s3;
																  std::list<VAR_DATA *>::reverse_iterator it;
																  std::string *name = newtemp();
																  s = putsym(name, $1.typ & 0x1F);
																  $$.typ = s->typ;
																  for(it = $3.arglist->rbegin(); it != $3.arglist->rend(); it++){
																	gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																  }
																  s3 = new symrec();
																  s3->name = "";
																  s3->offset = $3.arglist->size();
																  gencode(CALL_IR, $1.var, s3, s);
																  $$.var = s;
																}
	| postfix_expression '.' IDENTIFIER		{ printf("postfix_expression : postfix_expression '.' IDENTIFIER\n"); }
	| postfix_expression PTR_OP IDENTIFIER		{ printf("postfix_expression : postfix_expression PTR_OP IDENTIFIER\n"); }
	| postfix_expression INC_OP		{ printf("postfix_expression : postfix_expression INC_OP\n"); 
									  if($1.typ & VAR_SPEC){
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, $1.typ);
									  gencode(STORE_IR, $1.var, nullptr, s);
									  gencode(INC_IR, $1.var, nullptr, $1.var);
									  $$.name = name;
									  $$.typ = $1.typ;
									  $$.var =s;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be an variable");	
									}
	| postfix_expression DEC_OP		{ printf("postfix_expression : postfix_expression DEC_OP\n"); 
									  if($1.typ & VAR_SPEC){
										std::string *name = newtemp();
										symrec *s;
										s = putsym(name, $1.typ);
										gencode(STORE_IR, $1.var, nullptr, s);
										gencode(DEC_IR, $1.var, nullptr, $1.var);
										$$.name = name;
										$$.typ = $1.typ;
										$$.var = s;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be an variable");	
									}
	;

argument_expression_list
	: assignment_expression		{ printf("argument_expression_list : assignment_expression\n"); 
								  std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>();
								  VAR_DATA *newstruc = new VAR_DATA();
								  *newstruc = $1;
								  newlist->push_back(newstruc);
								  $$.name = new std::string();
								  $$.typ = 0;
								  $$.arglist = newlist;
								}
	| argument_expression_list ',' assignment_expression		{ printf("argument_expression_list : argument_expression_list ',' assignment_expression\n"); 
																  VAR_DATA *newstruc = new VAR_DATA();
																  *newstruc = $3;
																  $$ = $1;
																  $$.arglist->push_back(newstruc);
																}
	;

unary_expression
	: postfix_expression		{ printf("unary_expression : postfix_expression\n"); $$ = $1;}
	| INC_OP unary_expression		{ printf("unary_expression : INC_OP unary_expression\n"); 
									  if($2.typ & VAR_SPEC){
										gencode(INC_IR, $2.var, nullptr, $2.var);
										$$.name = $2.name;
										$$.typ = $2.typ;
										$$.var = $2.var;
									  }
									  else
									  	yyerror("ERROR Operand of increment operator must be a variable name\n");
									}
	| DEC_OP unary_expression		{ printf("unary_expression : DEC_OP unary_expression\n"); 
									  if($2.typ & VAR_SPEC){
										gencode(DEC_IR, $2.var, nullptr, $2.var);
										$$.name = $2.name;
										$$.typ = $2.typ;
										$$.var = $2.var;
									  }
									  else
									  	yyerror("ERROR Operand of decrement operator must be a variable name\n");
									}
	| unary_operator cast_expression		{ printf("unary_expression : unary_operator cast_expression\n"); 
											  std::string *name;
											  symrec *s = nullptr;
											  name = newtemp();
											  switch($1){
												case PLUS_OP:
													name = $2.name;
													s=$2.var;
													$$.typ = $2.typ;
													break;
												case ADDR_OP:
													name= newtemp();
													s = putsym(name, INTVAL);
													gencode(ADDRESS_IR, $2.var, nullptr, s);
													$$.typ = INTVAL;
													break;
												case DEREF_OP:
													name = newtemp();
													if(!ispointer($2.typ))
														yyerror("ERROR: OPERAND MUST BE A POINTER\n");
													s = putsym(name, $2.typ & ~POINTER_SPEC);
													gencode(DEREF_IR, $2.var, nullptr, s);
													$$.typ = $2.typ;
													break;
												case MINUS_OP:
													name = newtemp();
													s = putsym(name, $2.typ);
													gencode(MINUS_IR, $2.var, nullptr, s);
													$$.typ = $2.typ;
													break;
												case TWOCOMP_OP:
													name = newtemp();
													s = putsym(name, INTVAL);
													gencode(TWOCOMP_IR, $2.var, nullptr, s);
													$$.typ = INTVAL;
													break;
												case NOT_OP:
													name = newtemp();
													/*s = putsym(name, INTVAL);
													gencode(NOT_IR, $2.var, nullptr, s); */
													$$.truelist = $2.falselist;
													$$.falselist = $2.truelist;
													$$.typ = INTVAL;
													break;
											  }
											  $$.name = name;
											  $$.var = s;
											}
	| SIZEOF unary_expression		{ printf("unary_expression : SIZEOF unary_expression\n"); 
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, INTVAL | CONST_SPEC);
									  *(int *) (datablock+s->offset) = getsizeof($2.typ);
									  $$.name = name;
									  $$.typ = INTVAL | CONST_SPEC;
									  $$.var = s;
									}
	| SIZEOF '(' type_name ')'		{ printf("unary_expression : SIZEOF '(' type_name ')'\n"); 
									  std::string *name = newtemp();
									  symrec *s;
									  s = putsym(name, INTVAL | CONST_SPEC);
									  *(int *) (datablock+s->offset) = getsizeof($3);
									  $$.name = name;
									  $$.typ = INTVAL | CONST_SPEC;
									  $$.var = s;
									}
	;

unary_operator
	: '&'		{ printf("unary_operator : '&'\n");  $$ = ADDR_OP; }
	| '*'		{ printf("unary_operator : '*'\n"); $$ = DEREF_OP; }
	| '+'		{ printf("unary_operator : '+'\n"); $$ = PLUS_OP; }
	| '-'		{ printf("unary_operator : '-'\n"); $$ = MINUS_OP; }
	| '~'		{ printf("unary_operator : '~'\n"); $$ = TWOCOMP_OP; }
	| '!'		{ printf("unary_operator : '!'\n"); $$ = NOT_OP; }
	;

cast_expression
	: unary_expression		{ printf("cast_expression : unary_expression\n"); 
							  $$ = $1;
							  if(isarray($1.typ)){
								string *name = newtemp();
								symrec *s = putsym(name, $1.typ & ~ARRAY_SPEC);
								gencode(LOADA_IR, $1.var, $1.var2, s);
								$$.name = name;
								$$.typ = s->typ;
								$$.var = s;
							  }
							}
	| '(' type_name ')' cast_expression		{ printf("cast_expression : '(' type_name ')' cast_expression\n"); 
											  int typ = $2 & 0x1f;
											  symrec *s = genconv(typ, $4.var);
											  $$.var = s;
											  $$.typ = s->typ;
											  $$.name = new string(s->name);
											}
	;

multiplicative_expression
	: cast_expression		{ printf("multiplicative_expression : cast_expression\n"); $$=$1;}
	| multiplicative_expression '*' cast_expression		{ printf("multiplicative_expression : multiplicative_expression '*' cast_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(MULT_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(MULT_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(MULT_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	| multiplicative_expression '/' cast_expression		{ printf("multiplicative_expression : multiplicative_expression '/' cast_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(DIV_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(DIV_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(DIV_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	| multiplicative_expression '%' cast_expression		{ printf("multiplicative_expression : multiplicative_expression '%%' cast_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(MOD_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(MOD_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(MOD_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	;

additive_expression
	: multiplicative_expression		{ printf("additive_expression : multiplicative_expression\n"); $$=$1;}
	| additive_expression '+' multiplicative_expression		{ printf("additive_expression : additive_expression '+' multiplicative_expression\n"); 
															  int typ = gettype($1.typ, $3.typ) & 0x1f;
															  string *name = newtemp();
															  symrec *s = putsym(name, typ);
															  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
																	gencode(ADD_IR, $1.var, $3.var, s );
															  else{
															  	symrec *s2;
																if(($1.typ & 0x1f) == typ){
																	s2 = genconv(typ, $3.var);
																	gencode(ADD_IR, $1.var, s2, s);
																}
																else{
																	s2 = genconv(typ, $1.var);
																	gencode(ADD_IR, s2, $3.var, s);
																}
															  }
															$$.var = s;
															$$.typ = s->typ;
															$$.name = name;
															}
	| additive_expression '-' multiplicative_expression		{ printf("additive_expression : additive_expression '-' multiplicative_expression\n"); 
															  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  	  string *name = newtemp();
														     symrec *s = putsym(name, typ);
														     if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(SUB_IR, $1.var, $3.var, s );
														     else{
															 	symrec *s2;
																if(($1.typ & 0x1f) == typ){
																	s2 = genconv(typ, $3.var);
																		gencode(SUB_IR, $1.var, s2, s);
																}
															 else{
															 	s2 = genconv(typ, $1.var);
																gencode(SUB_IR, s2, $3.var, s);
																 }
														 	 }
														  	 $$.var = s;
														  	 $$.typ = s->typ;
														  	 $$.name = name;
															}
	;

shift_expression
	: additive_expression		{ printf("shift_expression : additive_expression\n"); $$=$1;}
	| shift_expression LEFT_OP additive_expression		{ printf("shift_expression : shift_expression LEFT_OP additive_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(LSHIFT_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(LSHIFT_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(LSHIFT_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	| shift_expression RIGHT_OP additive_expression		{ printf("shift_expression : shift_expression RIGHT_OP additive_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(RSHIFT_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(RSHIFT_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(RSHIFT_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	;

relational_expression
	: shift_expression		{ printf("relational_expression : shift_expression\n"); $$=$1; }
	| relational_expression '<' shift_expression		{ printf("relational_expression : relational_expression '<' shift_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  symrec *s1 = $1.var, *s2 = $3.var;
														  if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
															}
															else{
																s1 = genconv(typ, $1.var);
															}
														  }
															$$.truelist = makelist(nextinstr);
															gencode(IF_LT_IR, s1, s2, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
	| relational_expression '>' shift_expression		{ printf("relational_expression : relational_expression '>' shift_expression\n"); 
														   int typ = gettype($1.typ, $3.typ) & 0x1f;
														  symrec *s1 = $1.var, *s2 = $3.var;
														  if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
															}
															else{
																s1 = genconv(typ, $1.var);
															}
														  }
															$$.truelist = makelist(nextinstr);
															gencode(IF_GT_IR, s1, s2, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
	| relational_expression LE_OP shift_expression		{ printf("relational_expression : relational_expression LE_OP shift_expression\n"); 
														   int typ = gettype($1.typ, $3.typ) & 0x1f;
														  symrec *s1 = $1.var, *s2 = $3.var;
														  if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
															}
															else{
																s1 = genconv(typ, $1.var);
															}
														  }
															$$.truelist = makelist(nextinstr);
															gencode(IF_LE_IR, s1, s2, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
	| relational_expression GE_OP shift_expression		{ printf("relational_expression : relational_expression GE_OP shift_expression\n"); 
														   int typ = gettype($1.typ, $3.typ) & 0x1f;
														  symrec *s1 = $1.var, *s2 = $3.var;
														  if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
															}
															else{
																s1 = genconv(typ, $1.var);
															}
														  }
															$$.truelist = makelist(nextinstr);
															gencode(IF_GE_IR, s1, s2, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														  
														}
	;

equality_expression
	: relational_expression		{ printf("equality_expression : relational_expression\n"); $$ = $1;}
	| equality_expression EQ_OP relational_expression		{ printf("equality_expression : equality_expression EQ_OP relational_expression\n"); 
															  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  	  symrec *s1 = $1.var, *s2 = $3.var;
														      if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															  	if(($1.typ & 0x1f) == typ){
																	s2 = genconv(typ, $3.var);
																}
															  else{
															  	s1 = genconv(typ, $1.var);
															      }
														  	  }
															  $$.truelist = makelist(nextinstr);
															  gencode(IF_EQ_IR, s1, s2, nullptr);
															  $$.falselist = makelist(nextinstr);
															  gencode(GOTO_IR);
														  
															}
	| equality_expression NE_OP relational_expression		{ printf("equality_expression : equality_expression NE_OP relational_expression\n"); 
														      int typ = gettype($1.typ, $3.typ) & 0x1f;
														  	  symrec *s1 = $1.var, *s2 = $3.var;
														      if(($1.typ & 0x1f) != ($3.typ & 0x1f)){
															  	if(($1.typ & 0x1f) == typ){
																	s2 = genconv(typ, $3.var);
																}
															  else{
															  	s1 = genconv(typ, $1.var);
															      }
														  	  }
															  $$.truelist = makelist(nextinstr);
															  gencode(IF_NE_IR, s1, s2, nullptr);
															  $$.falselist = makelist(nextinstr);
															  gencode(GOTO_IR);
															}
	;

and_expression
	: equality_expression		{ printf("and_expression : equality_expression\n"); $$ = $1; }
	| and_expression '&' equality_expression		{ printf("and_expression : and_expression '&' equality_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(AND_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(AND_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(AND_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
													}
	;

exclusive_or_expression
	: and_expression		{ printf("exclusive_or_expression : and_expression\n"); $$ = $1;}
	| exclusive_or_expression '^' and_expression		{ printf("exclusive_or_expression : exclusive_or_expression '^' and_expression\n"); 
														  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  string *name = newtemp();
														  symrec *s = putsym(name, typ);
														  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		gencode(XOR_IR, $1.var, $3.var, s );
														  else{
															symrec *s2;
															if(($1.typ & 0x1f) == typ){
																s2 = genconv(typ, $3.var);
																gencode(XOR_IR, $1.var, s2, s);
															}
															else{
																s2 = genconv(typ, $1.var);
																gencode(XOR_IR, s2, $3.var, s);
															}
														  }
														  $$.var = s;
														  $$.typ = s->typ;
														  $$.name = name;
														}
	;

inclusive_or_expression
	: exclusive_or_expression		{ printf("inclusive_or_expression : exclusive_or_expression\n"); $$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression		{ printf("inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression\n"); 
																  int typ = gettype($1.typ, $3.typ) & 0x1f;
														  		  string *name = newtemp();
														  		  symrec *s = putsym(name, typ);
														  		  if(($1.typ & 0x1f) == ($3.typ & 0x1f))
														  		  gencode(OR_IR, $1.var, $3.var, s );
														  		  else{
																  symrec *s2;
																  if(($1.typ & 0x1f) == typ){
																  	s2 = genconv(typ, $3.var);
																  	gencode(OR_IR, $1.var, s2, s);
															      }
																  else{
																  	s2 = genconv(typ, $1.var);
																  	gencode(OR_IR, s2, $3.var, s);
																  }
														  		}
														  		  $$.var = s;
														  		  $$.typ = s->typ;
														  		  $$.name = name;
																}
	;

M: 		{
			$$.nextlist = makelist(nextinstr);
			gencode(GOTO_IR);
		}
	;

N: 		{
			$$ = nextinstr;
		}
	;

logical_and_expression
	: inclusive_or_expression									{ printf("logical_and_expression : inclusive_or_expression\n"); $$ = $1;}
	| logical_and_expression AND_OP N inclusive_or_expression		{	printf("logical_and_expression : logical_and_expression AND_OP inclusive_or_expression\n"); 
																	backpatch($1.truelist, $3);
																	$$.truelist = $4.truelist;
																	$$.falselist = $1.falselist;
																	$$.falselist->merge(*($4.falselist));
																	$$.typ = INTVAL;
																}
	;

logical_or_expression
	: logical_and_expression									{ printf("logical_or_expression : logical_and_expression\n"); $$ = $1; }
	| logical_or_expression OR_OP N logical_and_expression		{ printf("logical_or_expression : logical_or_expression OR_OP logical_and_expression\n"); 
																	backpatch($1.falselist, $3);
																	$$.falselist = $4.falselist;
																	$$.truelist = $1.truelist;
																	$$.truelist->merge(*($4.truelist));
																	$$.typ = INTVAL;
																}
	;

conditional_expression
	: logical_or_expression							{$$ = $1;}
	| logical_or_expression '?' N expression ':'	{

														string *name = newtemp();
														symrec *s = putsym(name, $4.typ & ~CONST_SPEC | VAR_SPEC);
														gencode(STORE_IR, $4.var, NULL, s);
														$4.var = s;
													}
	  M N conditional_expression					{
														gencode(STORE_IR, $9.var, NULL, $4.var);
														$$.var = $4.var;
														backpatch($1.truelist, $3);
														backpatch($1.falselist, $8);
														backpatch($7.nextlist, nextinstr);
														$$.truelist = nullptr;
														$$.falselist = nullptr;
													}
	;

assignment_expression
	: conditional_expression											{ printf("assignment_expression : conditional_expression\n"); $$ = $1; }
	| unary_expression assignment_operator assignment_expression		{ printf("assignment_expression : unary_expression assignment_operator assignment_expression\n"); 
																		  string *name;
																		  symrec *s, *s2, *s3;

																		  if($3.truelist || $3.falselist){
																			  std::string *name = newtemp();
																			  symrec *s1, *s0;
																			  s0 = putsym(name, INTVAL | CONST_SPEC);
																			  *(int *)(datablock+s0->offset)=0;
																			  name = newtemp();
																			  s1 = putsym(name, INTVAL | CONST_SPEC);
																			  *(int *)(datablock+s1->offset)=1;
																			  name = newtemp();
																			  $3.var = putsym(name, INTVAL | VAR_SPEC);
																			  $3.typ = INTVAL | VAR_SPEC;
																			  $3.name	 = name;
																			  backpatch($3.truelist, nextinstr);
																			  gencode(STORE_IR, s1, nullptr, $3.var);
																			  gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																			  backpatch($3.falselist, nextinstr);
																			  gencode(STORE_IR, s0, nullptr, $3.var);
																		  }
																		  switch($2){
																			case EQ_ASSIGN_OP:
																				if(!isarray($1.typ)){
																					if(($3.typ & 0x1f) == ($1.typ & 0x1f))
																						gencode(STORE_IR, $3.var, nullptr, $1.var);
																				
																				else{
																					s3 = genconv($1.typ, $3.var);
																					gencode(STORE_IR, s3, nullptr, $1.var);
																					}
																				}
																				else{
																					if(($3.typ & 0x1f) == ($1.typ & 0x1f))
																						gencode(STOREA_IR, $3.var, $1.var2, $1.var);
																					else{
																						s3 = genconv($1.typ, $3.var);
																						gencode(STOREA_IR, s3, $1.var2, $1.var);
																						}
																				}
																				break;
																			case MUL_ASSIGN_OP:
																				genassign(MULT_IR, &$1, &$3);
																				break;
																			case DIV_ASSIGN_OP:
																				genassign(DIV_IR, &$1, &$3);
																				break;
																			case MOD_ASSIGN_OP:
																				genassign(MOD_IR, &$1, &$3);
																				break;
																			case ADD_ASSIGN_OP:
																				genassign(ADD_IR, &$1, &$3);
																				break;
																			case SUB_ASSIGN_OP:
																				genassign(SUB_IR, &$1, &$3);
																				break;
																			case LEFT_ASSIGN_OP:
																				genassign(LSHIFT_IR, &$1, &$3);
																				break;
																			case RIGHT_ASSIGN_OP:
																				genassign(RSHIFT_IR, &$1, &$3);
																				break;
																			case AND_ASSIGN_OP:
																				genassign(AND_IR, &$1, &$3);
																				break;
																			case XOR_ASSIGN_OP:
																				genassign(XOR_IR, &$1, &$3);
																				break;	
																			case OR_ASSIGN_OP:
																				genassign(OR_IR, &$1, &$3);
																				break;
																		    } 
																		}
	;

assignment_operator
	: '='				{ printf("assignment_operator : '='\n"); $$ = EQ_ASSIGN_OP; }
	| MUL_ASSIGN		{ printf("assignment_operator : MUL_ASSIGN\n"); $$ = MUL_ASSIGN_OP;}
	| DIV_ASSIGN		{ printf("assignment_operator : DIV_ASSIGN\n"); $$ = DIV_ASSIGN_OP;}
	| MOD_ASSIGN		{ printf("assignment_operator : MOD_ASSIGN\n"); $$ = MOD_ASSIGN_OP;}
	| ADD_ASSIGN		{ printf("assignment_operator : ADD_ASSIGN\n"); $$ = ADD_ASSIGN_OP;}
	| SUB_ASSIGN		{ printf("assignment_operator : SUB_ASSIGN\n"); $$ = SUB_ASSIGN_OP;}
	| LEFT_ASSIGN		{ printf("assignment_operator : LEFT_ASSIGN\n"); $$ = LEFT_ASSIGN_OP;}
	| RIGHT_ASSIGN		{ printf("assignment_operator : RIGHT_ASSIGN\n"); $$ = RIGHT_ASSIGN_OP;}
	| AND_ASSIGN		{ printf("assignment_operator : AND_ASSIGN\n"); $$ = AND_ASSIGN_OP;}
	| XOR_ASSIGN		{ printf("assignment_operator : XOR_ASSIGN\n"); $$ = XOR_ASSIGN_OP;}
	| OR_ASSIGN			{ printf("assignment_operator : OR_ASSIGN\n"); $$ = OR_ASSIGN_OP;}
	;

expression
	: assignment_expression		{ printf("expression : assignment_expression\n"); $$ = $1; }
	| expression ',' assignment_expression		{ printf("expression : expression ',' assignment_expression\n"); $$ = $1; }
	;

constant_expression
	: conditional_expression		{ printf("constant_expression : conditional_expression\n"); $$ = $1; }
	;

declaration
	: declaration_specifiers ';'		{ printf("declaration : declaration_specifiers ';'\n"); }
	| declaration_specifiers init_declarator_list ';'		{ printf("declaration : declaration_specifiers init_declarator_list ';'\n"); 
															  int typ;
															  std::list<VAR_DATA *>::iterator it;
															  typ = get_type($1);
															  cout<<"Declaring variables: "<<endl;
															  for(it = $2->begin(); it != $2->end(); it++)
															  {
																symrec *s;
																cout<< *(*it)->name << endl;
																if(isarray((*it)->typ))
																	installarray((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F),(*it)->dimlist);
																else
																	if(isfunction((*it)->typ))
																		s=install((*it)->name, typ | FUNC_SPEC | ((*it)->typ & ~0xF1));
																else{
																	s = install((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F));
																	if((*it)->init){
																		if(currscope>0)
																			gencode(STORE_IR, (*it)->var, nullptr, s);
																		else{
																			initvar(s,(*it)->var);
																		}
																	}
																}	
															  }
															}
	;

declaration_specifiers
	: storage_class_specifier		{ printf("declaration_specifiers : storage_class_specifier\n"); 
									  list<int> *newlist = new list<int>;
									  newlist->push_back($1);
									  $$ = newlist;
									}
	| storage_class_specifier declaration_specifiers		{ printf("declaration_specifiers : storage_class_specifier declaration_specifiers\n"); 
															  $$ = $2;
															  $$->push_back($1);
															}
	| type_specifier		{ printf("declaration_specifiers : type_specifier\n"); 
							  list<int> *newlist = new list<int>;
							  newlist->push_back($1);
							  $$=newlist;
							}
	| type_specifier declaration_specifiers		{ printf("declaration_specifiers : type_specifier declaration_specifiers\n"); 
												  $$=$2;
												  $$->push_back($1);
												}
	| type_qualifier		{ printf("declaration_specifiers : type_qualifier\n"); 
							  list<int> *newlist = new list<int>;
							  newlist->push_back($1);
							  $$=newlist;
							}
	| type_qualifier declaration_specifiers		{ printf("declaration_specifiers : type_qualifier declaration_specifiers\n"); 
												  $$=$2;
												  $$->push_back($1);
												}
	;

init_declarator_list
	: init_declarator		{ std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
							  VAR_DATA *newstruc = $1;
							  printf("init_declarator_list : init_declarator\n");
							  newlist->push_back(newstruc);
							  $$ = newlist;
							}
	| init_declarator_list ',' init_declarator		{ printf("init_declarator_list : init_declarator_list ',' init_declarator\n"); 
													  $$ = $1;
													  $$->push_back($3);
													}
	;

init_declarator
	: declarator		{ printf("init_declarator : declarator\n"); 
						  $$ = $1;
						}
	| declarator '=' initializer		{ printf("init_declarator : declarator '=' initializer\n"); 
										  $$ = $1;
										  $$->init = 1;
										  $$->var = $3.var;
										}
	;

storage_class_specifier
	: TYPEDEF		{ printf("storage_class_specifier : TYPEDEF\n");  $$ = TYPENAME_SPEC; }
	| EXTERN		{ printf("storage_class_specifier : EXTERN\n"); $$ = EXTERN_SPEC; }
	| STATIC		{ printf("storage_class_specifier : STATIC\n"); $$ = STATIC_SPEC; }
	| AUTO		{ printf("storage_class_specifier : AUTO\n"); $$ = AUTO_SPEC; }
	| REGISTER		{ printf("storage_class_specifier : REGISTER\n"); $$ = REGISTER_SPEC; }
	;

type_specifier
	: VOID		{ printf("type_specifier : VOID\n"); $$ = VOID_SPEC; }
	| CHAR		{ printf("type_specifier : CHAR\n"); $$ = CHAR_SPEC; }
	| SHORT		{ printf("type_specifier : SHORT\n"); $$ = SHORT_SPEC; }
	| INT		{ printf("type_specifier : INT\n"); $$ = INT_SPEC;}
	| LONG		{ printf("type_specifier : LONG\n"); $$ = LONG_SPEC; }
	| FLOAT		{ printf("type_specifier : FLOAT\n"); $$ = FLOAT_SPEC; }
	| DOUBLE		{ printf("type_specifier : DOUBLE\n"); $$ = DOUBLE_SPEC; }
	| SIGNED		{ printf("type_specifier : SIGNED\n"); $$ = SIGNED_SPEC; }
	| UNSIGNED		{ printf("type_specifier : UNSIGNED\n"); $$ = UNSIGNED_SPEC; }
	| struct_or_union_specifier		{ printf("type_specifier : struct_or_union_specifier\n"); }
	| enum_specifier		{ printf("type_specifier : enum_specifier\n"); $$ = ENUM_SPEC; }
	| TYPE_NAME		{ printf("type_specifier : TYPE_NAME\n"); $$ = TYPENAME_SPEC; }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'		{ printf("struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}'\n"); }
	| struct_or_union '{' struct_declaration_list '}'		{ printf("struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}'\n"); }
	| struct_or_union IDENTIFIER		{ printf("struct_or_union_specifier : struct_or_union IDENTIFIER\n"); }
	;

struct_or_union
	: STRUCT		{ printf("struct_or_union : STRUCT\n"); }
	| UNION		{ printf("struct_or_union : UNION\n"); }
	;

struct_declaration_list
	: struct_declaration		{ printf("struct_declaration_list : struct_declaration\n"); }
	| struct_declaration_list struct_declaration		{ printf("struct_declaration_list : struct_declaration_list struct_declaration\n"); }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'		{ printf("struct_declaration : specifier_qualifier_list struct_declarator_list ';'\n"); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list		{ printf("specifier_qualifier_list : type_specifier specifier_qualifier_list\n"); 
													  $$ = $2;
													  $$->push_back($1);
													}
	| type_specifier		{ printf("specifier_qualifier_list : type_specifier\n"); 
							  std::list<int> *newlist = new std::list<int>;
							  newlist->push_back($1);
							  $$ = newlist;
							}
	| type_qualifier specifier_qualifier_list		{ printf("specifier_qualifier_list : type_qualifier specifier_qualifier_list\n"); 
													  $$ = $2;
													  $$->push_back($1);
													}
	| type_qualifier		{ printf("specifier_qualifier_list : type_qualifier\n"); 
							  std::list<int> *newlist = new std::list<int>;
							  newlist->push_back($1);
							  $$ = newlist;
							}
	;

struct_declarator_list
	: struct_declarator		{ printf("struct_declarator_list : struct_declarator\n"); }
	| struct_declarator_list ',' struct_declarator		{ printf("struct_declarator_list : struct_declarator_list ',' struct_declarator\n"); }
	;

struct_declarator
	: declarator		{ printf("struct_declarator : declarator\n"); }
	| ':' constant_expression		{ printf("struct_declarator : ':' constant_expression\n"); }
	| declarator ':' constant_expression		{ printf("struct_declarator : declarator ':' constant_expression\n"); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'		{ printf("enum_specifier : ENUM '{' enumerator_list '}'\n"); }
	| ENUM IDENTIFIER '{' enumerator_list '}'		{ printf("enum_specifier : ENUM IDENTIFIER '{' enumerator_list '}'\n"); }
	| ENUM IDENTIFIER		{ printf("enum_specifier : ENUM IDENTIFIER\n"); }
	;

enumerator_list
	: enumerator		{ printf("enumerator_list : enumerator\n"); }
	| enumerator_list ',' enumerator		{ printf("enumerator_list : enumerator_list ',' enumerator\n"); }
	;

enumerator
	: IDENTIFIER		{ printf("enumerator : IDENTIFIER\n"); }
	| IDENTIFIER '=' constant_expression		{ printf("enumerator : IDENTIFIER '=' constant_expression\n"); }
	;

type_qualifier
	: CONST		{ printf("type_qualifier : CONST\n"); $$ = CONST_SPEC; }
	| VOLATILE		{ printf("type_qualifier : VOLATILE\n"); $$ = VOLATILE_SPEC; }
	;

declarator
	: pointer direct_declarator		{ 
										printf("declarator: pointer direct_declarator\n");
										$$ = $2;
										$$->plevel = $1.level;
										$$->typ |= POINTER_SPEC | $1.typq;
									}
	| direct_declarator		{ printf("declarator : direct_declarator\n"); 
							  $$ = $1;
							  if(isarray($$->typ))
							  {
								  if(allzero($$->dimlist))
								  {
									  $$->typ &= ~ARRAY_SPEC;
									  $$->typ |= POINTER_SPEC;
								  }
								  else{
									  if(product($$->dimlist) == 0)
									  	yyerror("Array dimensions must be specified!");
								  }
							  }
							}
	;

direct_declarator
	: IDENTIFIER		{
							printf("direct_declarator: IDENTIFIER");
							string *name = new string($1);
							cout<<"<"<< *name << ">\n";
							VAR_DATA *newsym = new VAR_DATA();
							newsym->name = name;
							newsym->dimlist = nullptr;
							$$ = newsym;
						}
	| '(' declarator ')' 	{
						   	printf("direct_declarator: '(' declarator ')'    \n");
						 	}
	| direct_declarator '[' constant_expression ']'   	 {
													   		printf("direct_declarator: direct_declarator '[' constant_expression ']'    \n");
															if(!isintegral($3.typ))
																yyerror("Array dimensions must be integral!");
															if(!isconstant($3.typ))
																yyerror("Array dimensions must be constant!");
															$$ = $1;
															if($$->dimlist == nullptr)
																$$->dimlist = new list<int>;
															$$->dimlist->push_back($3.val.intval);
															$$->typ |= ARRAY_SPEC;
													   	}
	| direct_declarator '[' ']'		{
										printf("direct_declarator: direct_declarator '[' ']'\n");
										$$ = $1;
										if($$->dimlist == nullptr)
											$$->dimlist = new list<int>;
										$$->dimlist->push_back(0);
										$$->typ |= ARRAY_SPEC;
									}
	| direct_declarator '(' parameter_type_list ')'		{
														printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");	
														$$ = $1;
														$$->typ |= FUNC_SPEC;
														$$->arglist = $3;
														$$->init = 0;																			
														}
	| direct_declarator '(' identifier_list ')'		{
													printf("direct_declarator:  direct_declarator '(' identifier_list ')'\n ");
													}
	| direct_declarator '(' ')'		{
									printf("direct_declarator: direct_declarator '(' ')'\n");
									$$ = $1;
									$$->typ |= FUNC_SPEC;
									$$->init = 0;
									}
	;

pointer
	: '*'		{ printf("pointer : '*'\n"); 
				  $$.typq = POINTER_SPEC;
				  $$.level = 1;
				}
	| '*' type_qualifier_list		{ printf("pointer : '*' type_qualifier_list\n"); 
									  $$.typq = get_type($2) | POINTER_SPEC;
									  $$.level = 1;
									}
	| '*' pointer		{ printf("pointer : '*' pointer\n"); 
						  $$ = $2;
						  $$.level++;
						}
	| '*' type_qualifier_list pointer		{ printf("pointer : '*' type_qualifier_list pointer\n"); 
											  $$ = $3;
											  $$.typq = get_type($2);
											  $$.level++;
											}
	;

type_qualifier_list
	: type_qualifier		{ printf("type_qualifier_list : type_qualifier\n"); 
							  list<int> *newlist = new list<int>();
							  newlist->push_back($1);
							  $$ = newlist;
							}
	| type_qualifier_list type_qualifier		{ printf("type_qualifier_list : type_qualifier_list type_qualifier\n"); 
												  $$ = $1;
												  $$->push_back($2);
												}
	;


parameter_type_list
	: parameter_list		{  printf("parameter_type_list: parameter_list\n"); 
							   $$ = $1; 
							}
	| parameter_list ',' ELLIPSIS		{ printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");}
	;

parameter_list
	: parameter_declaration		{ printf("parameter_list : parameter_declaration\n");
								  std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
								  VAR_DATA *newstruc = new VAR_DATA();
								  *newstruc = $1;
								  newlist->push_back(newstruc);
								  $$ = newlist;
								}
	| parameter_list ',' parameter_declaration		{ printf("parameter_list : parameter_list ',' parameter_declaration\n");
													  $$ = $1;
													  VAR_DATA *newstruc = new VAR_DATA();
													  *newstruc = $3;
													  $$->push_back(newstruc);
													}
	;

parameter_declaration
	: declaration_specifiers declarator		{ printf("parameter_declaration : declaration_specifiers declarator\n");
											  $$.name =$2->name;
											  if(!isarray($2->typ))
											  	$$.typ = get_type($1);
											  else
											  	$$.typ = $$.typ = get_type($1) | ARRAY_SPEC;
											}
	| declaration_specifiers abstract_declarator		{ printf("parameter_declaration : declaration_specifiers abstract_declarator\n"); }
	| declaration_specifiers		{ printf("parameter_declaration : declaration_specifiers\n"); }
	;

identifier_list
	: IDENTIFIER		{ printf("identifier_list : IDENTIFIER\n"); 
						  	
						}
	| identifier_list ',' IDENTIFIER		{ printf("identifier_list : identifier_list ',' IDENTIFIER\n"); }
	;

type_name
	: specifier_qualifier_list		{ printf("type_name : specifier_qualifier_list\n"); 
									  $$ = get_type($1);
									}
	| specifier_qualifier_list abstract_declarator		{ printf("type_name : specifier_qualifier_list abstract_declarator\n"); }
	;

abstract_declarator
	: pointer		{ printf("abstract_declarator : pointer\n"); }
	| direct_abstract_declarator		{ printf("abstract_declarator : direct_abstract_declarator\n"); }
	| pointer direct_abstract_declarator		{ printf("abstract_declarator : pointer direct_abstract_declarator\n"); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'		{ printf("direct_abstract_declarator : '(' abstract_declarator ')'\n"); }
	| '[' ']'		{ printf("direct_abstract_declarator : '[' ']'\n"); }
	| '[' constant_expression ']'		{ printf("direct_abstract_declarator : '[' constant_expression ']'\n"); }
	| direct_abstract_declarator '[' ']'		{ printf("direct_abstract_declarator : direct_abstract_declarator '[' ']'\n"); }
	| direct_abstract_declarator '[' constant_expression ']'		{ printf("direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']'\n"); }
	| '(' ')'		{ printf("direct_abstract_declarator : '(' ')'\n"); }
	| '(' parameter_type_list ')'		{ printf("direct_abstract_declarator : '(' parameter_type_list ')'\n"); }
	| direct_abstract_declarator '(' ')'		{ printf("direct_abstract_declarator : direct_abstract_declarator '(' ')'\n"); }
	| direct_abstract_declarator '(' parameter_type_list ')'		{ printf("direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')'\n"); }
	;

initializer
	: assignment_expression		{ printf("initializer : assignment_expression\n"); $$ = $1; }
	| '{' initializer_list '}'		{ printf("initializer : '{' initializer_list '}'\n"); }
	| '{' initializer_list ',' '}'		{ printf("initializer : '{' initializer_list ',' '}'\n"); }
	;

initializer_list
	: initializer		{ printf("initializer_list : initializer\n"); }
	| initializer_list ',' initializer		{ printf("initializer_list : initializer_list ',' initializer\n"); }
	;

P : /* */
	;

statement
	: labeled_statement			{ 
									printf("statement : labeled_statement\n"); 
									$$ = $1;
									$$.nextlist = NULL;
								}
	| P 						{
									enter_scope();
								}
	  compound_statement		{ 
									printf("statement : compound_statement\n"); 
	  								//printlocalvars();
									$$ = $3;
	  							}
	| expression_statement		{ 
									printf("statement : expression_statement\n"); 
									$$.nextlist = NULL;
									$$.breaklist = NULL;
									$$.continuelist = NULL;
									$$.gotolist = NULL;
									$$.caselist = NULL;
								}
	| selection_statement		{ 
									printf("statement : selection_statement\n"); 
									$$ = $1;
									$$.caselist = NULL;
								}
	| iteration_statement		{ 
									printf("statement : iteration_statement\n"); 
									$$ = $1;
									$$.caselist = NULL;
								}
	| jump_statement			{ 
									printf("statement : jump_statement\n"); 
									$$ = $1;
									$$.caselist = NULL;
								}
	;

labeled_statement
	: IDENTIFIER ':' N statement		{ 
											printf("labeled_statement : IDENTIFIER ':' statement\n"); 
											putlab(new string($1), $3);
											$$.nextlist = NULL;
											$$.breaklist = NULL;
											$$.continuelist = NULL;
											$$.gotolist = NULL;
											$$.caselist = NULL;
										}
	| CASE constant_expression ':' N statement		{
														printf("labeled_statement : CASE constant_expression ':' statement\n"); 
														$$.breaklist = $5.breaklist;
														$$.continuelist = $5.continuelist;
														$$.gotolist = $5.gotolist;
														if(!isconstant($2.typ))
															yyerror("ERROR: CASE expression must be constant\n");
														if(!isintegral($2.typ))
															yyerror("ERROR: CASE expression must be integral constant\n");
														$$.caselist = makecaselist($2.val, $2.typ, $4);
													}
	| DEFAULT ':' N statement						{ 
														printf("labeled_statement : DEFAULT ':' N statement\n"); 
														$$.breaklist = $4.breaklist;
														$$.continuelist = $4.continuelist;
														$$.gotolist = $4.gotolist;
														$$.caselist = makecaselist($3);
													}
	;

compound_statement
	: '{' '}'										{
														printf("compound_statement : '{' '}'\n");
														$$.breaklist = NULL;
														$$.continuelist = NULL;
														$$.gotolist = NULL;
														$$.nextlist = NULL;
													}
	| '{' statement_list '}'						{
														printf("compound_statement : '{' statement_list '}'\n"); 
														$$ = $2;
													}
	| '{' declaration_list '}'						{
														printf("compound_statement : '{' declaration_list '}'\n"); 
														$$.breaklist = NULL;
														$$.continuelist = NULL;
														$$.gotolist = NULL;
														$$.nextlist = NULL;
													}
	| '{' declaration_list statement_list '}'		{
														printf("compound_statement : '{' declaration_list statement_list '}'\n"); 
														$$ = $3;
													}
	;

declaration_list
	: declaration		{ printf("declaration_list : declaration\n"); }
	| declaration_list declaration		{ printf("declaration_list : declaration_list declaration\n"); }
	;

statement_list
	: statement						{ 
										printf("statement_list : statement\n"); 
										$$ = $1;
									}
	| statement_list N statement	{
										printf("statement_list : statement_list statement\n"); 
										backpatch($1.nextlist, $2);
										$$ = $1;
										$$.nextlist = $3.nextlist;
										$$.breaklist = merge($1.breaklist, $3.breaklist);
										$$.continuelist = merge($1.continuelist, $3.continuelist);
										$$.gotolist = merge($1.gotolist, $3.gotolist);
										$$.caselist = merge($1.caselist, $3.caselist);
									}
	;

expression_statement
	: ';'					{ 
								printf("expression_statement : ';'\n"); 
								$$.truelist = nullptr;
								$$.falselist = nullptr;
							}
	| expression ';'		{ 
								printf("expression_statement : expression ';'\n"); 
								$$ = $1;
							}
	;

logic_expression: expression					{	
													$$ = $1;
													if($1.truelist == nullptr || $1.falselist == nullptr){
														std::string *name = newtemp();
														symrec *s0;
														s0 = putsym(name, INTVAL | CONST_SPEC);
														*(int *)(datablock+s0->offset) = 0;
														$$.truelist = makelist(nextinstr);
														gencode(IF_NE_IR, $1.var, s0, nullptr);
														$$.falselist = makelist(nextinstr);
														gencode(GOTO_IR);
													}
												}
;

logic_expression_statement : expression_statement	{
														$$ = $1;
														if($1.truelist == nullptr || $1.falselist == nullptr){
															std::string *name = newtemp();
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															*(int *)(datablock+s0->offset) = 0;
															$$.truelist = makelist(nextinstr);
															gencode(IF_NE_IR, $1.var, s0, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													}
	;

selection_statement
: IF '(' logic_expression ')' N statement %prec NOELSE			{ 	printf("expression_statement : IF '(' expression ')' N statement ");
																		backpatch($3.truelist, $5);
																		$$.nextlist = merge($3.falselist, $6.nextlist);
																		$$.breaklist = $6.breaklist;
																		$$.continuelist = $6.continuelist;
																		$$.gotolist = $6.gotolist;
																	}
	| IF '(' logic_expression ')' N statement ELSE M N statement		{ 	printf("selection_statement : IF '(' expression ')' statement ELSE statement\n"); 
																		backpatch($3.truelist, $5);
																		backpatch($3.falselist, $9);
																		$$.nextlist = merge($6.nextlist, $8.nextlist, $10.nextlist);
																		$$.breaklist = merge($6.breaklist, $10.breaklist);
																		$$.continuelist = merge($6.continuelist, $10.continuelist);
																		$$.gotolist = merge($6.gotolist, $10.gotolist);
																	}
	| SWITCH M '(' expression ')' statement		{ 
													printf("selection_statement : SWITCH '(' expression ')' statement\n"); 
													if(!isintegral($4.typ))
														yyerror("ERROR: swtich expression must be integral");
													$6.breaklist = merge($6.breaklist, makelist(nextinstr));
													gencode(GOTO_IR);
													backpatch($2.nextlist, nextinstr);
													std::list<CASE_DATA *>::iterator it;
													if($6.caselist != NULL){
														for(it = $6.caselist->begin(); it != $6.caselist->end(); it++){
															int addr = (*it)->addr;
															int typ = (*it)->typ;
															if(typ == VOIDVAL)
																gencode(GOTO_IR, addr);
															else{
																std::string *name = newtemp();
																symrec *s = putsym(name, INTVAL | CONST_SPEC);
																symrec*s1 = $4.var;
																*(int *)((char *)datablock+s->offset) = (*it)->val.intval;
																if(isconstant($4.typ)){
																	name = newtemp();
																	s1 = putsym(name, INTVAL | CONST_SPEC);
																	*(int *)((char *)datablock+s1->offset) = $4.val.intval;
																}
																gencode(IF_EQ_IR, s, s1, addr);
															}
														}
														backpatch($6.breaklist, nextinstr);
														$$.breaklist = NULL;
														$$.continuelist = $6.continuelist;
														$$.gotolist = $6.gotolist;
														$$.nextlist = NULL;
													}
												}
	;

iteration_statement
	: WHILE N '(' logic_expression ')' N statement									{ 
																						printf("iteration_statement : WHILE '(' expression ')' statement\n"); 
																						backpatch($7.nextlist, $2);
																						backpatch($7.continuelist, $2);
																						backpatch($4.truelist, $6);
																						$$.nextlist = $4.falselist;
																						gencode(GOTO_IR, $2);
																						backpatch($7.breaklist, nextinstr);
																						$$.breaklist = NULL;
																						$$.continuelist = NULL;
																						$$.gotolist = $7.gotolist;
																					}
	| DO N statement WHILE N '(' logic_expression ')' ';'										{ 
																									printf("iteration_statement : DO statement WHILE '(' expression ')' ';'\n"); 
																									backpatch($7.truelist, $2);
																									backpatch($3.nextlist, $5);
																									backpatch($3.continuelist, $5);
																									backpatch($3.breaklist, nextinstr);
																									$$.breaklist = NULL;
																									$$.continuelist = NULL;
																									$$.nextlist  = $7.falselist;
																									$$.gotolist = $3.gotolist;
																								}
	| FOR '(' expression_statement N logic_expression_statement N ')' statement					{ 
																									printf("iteration_statement : FOR '(' expression_statement expression_statement ')' statement\n"); 
																									backpatch($5.truelist, $6);
																									backpatch($8.nextlist, $4);
																									backpatch($8.continuelist, $4);
																									$$.nextlist = $5.falselist;
																									gencode(GOTO_IR, $4);
																									backpatch($8.breaklist, nextinstr);
																									$$.breaklist = NULL;
																									$$.continuelist = NULL;
																									$$.gotolist = $8.gotolist;
																								}
	| FOR '(' expression_statement N logic_expression_statement N expression ')' M N statement	{ 
																									printf("iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement\n");
																									backpatch($5.truelist, $10);
																									backpatch($11.nextlist, $6);
																									backpatch($9.nextlist, $4);
																									$$.nextlist = $5.falselist;
																									gencode(GOTO_IR, $6);
																									backpatch($11.breaklist, nextinstr);
																									$$.breaklist = NULL;
																									$$.continuelist = NULL;
																									$$.gotolist = $11.gotolist;
																								}
	;

jump_statement
	: GOTO IDENTIFIER ';'		{ 
									printf("jump_statement : GOTO IDENTIFIER ';'\n"); 
									$$.continuelist = NULL;
									$$.breaklist = NULL;
									$$.nextlist = NULL;
									$$.caselist = NULL;
									$$.gotolist = makelist(new string($2), nextinstr);
									gencode(GOTO_IR);
								}
	| CONTINUE ';'				{ 
									printf("jump_statement : CONTINUE ';'\n"); 
									$$.breaklist = NULL;
									$$.nextlist = NULL;
									$$.caselist = NULL;
									$$.gotolist = NULL;
									$$.continuelist = makelist(nextinstr);
									gencode(GOTO_IR);
								}
	| BREAK ';'					{ 
									printf("jump_statement : BREAK ';'\n"); 
									$$.nextlist = NULL;
									$$.continuelist = NULL;
									$$.caselist = NULL;
									$$.gotolist = NULL;
									$$.breaklist = makelist(nextinstr);
									gencode(GOTO_IR);	
								}
	| RETURN ';'				{ 
									printf("jump_statement : RETURN ';'\n"); 
						  			gencode(RET_IR);
									$$.breaklist = NULL;
									$$.nextlist = NULL;
									$$.continuelist = NULL;
									$$.caselist = NULL;
									$$.gotolist = NULL;
								}
	| RETURN expression ';'		{ printf("jump_statement : RETURN expression ';'\n"); 
								  	gencode(RET_IR, $2.var, nullptr, nullptr);
								  	$$.breaklist = NULL;
								  	$$.nextlist = NULL;
								  	$$.continuelist = NULL;
									$$.caselist = NULL;
									$$.gotolist = NULL;
								}
	;

translation_unit
	: external_declaration		{ printf("translation_unit : external_declaration\n"); }
	| translation_unit external_declaration		{ printf("translation_unit : translation_unit external_declaration\n"); }
	;

external_declaration
	: function_definition		{ printf("external_declaration : function_definition\n"); }
	| declaration		{ printf("external_declaration : declaration\n"); }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement		{ printf("function_definition : declaration_specifiers declarator declaration_list compound_statement\n"); }
	| declaration_specifiers declarator 		{ 
													
													int typ = get_type($1) | $2->typ;
													curr_func = install($2->name, typ);
													gencode(PROC_IR, curr_func);
													localsyms = new symboltable();
													enter_scope();
													installarg($2->arglist);
													lab_table.clear();
													setargs();	
												}
		compound_statement						{ 
													printf("function_definition :  declaration_specifiers declarator compound_statement\n"); 
													printlocalvars();
													exit_scope();
													curr_func->func_desc.sym_table = localsyms;
													gencode(ENDPROC_IR, curr_func);
													patch_gotos($4.gotolist);
												}
	| declarator declaration_list compound_statement {printf("function_definition : declarator declaration_list compound_statement\n"); }
	| declarator 								{ 
													int typ = $1->typ;
													
													curr_func = install($1->name, typ);
													gencode(PROC_IR, curr_func);
													localsyms = new symboltable();
													enter_scope();
													installarg($1->arglist);
													lab_table.clear();
													setargs();
													}
		compound_statement		{
									printf("function_definition : declarator compound_statement\n"); 
								  	printlocalvars();
								  	exit_scope();
								  	curr_func->func_desc.sym_table = localsyms;
								  	gencode(ENDPROC_IR, curr_func);
									patch_gotos($3.gotolist);
								}
	;


%%
#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(const char *s)
{ 
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char*argv[])
{
	//Tabla de simbolos globales
	string fname;
	sym_table = new symboltable();
	printf("Compilador de ANSI C 1985 version 0.9\n\n");
	//Abrir el archivo para el analisis lexico
	if(argc > 1){
		yyin = fopen(argv[1], "rt");
		fname = argv[1];
	}
	else{
		printf("Uso: %s archivo\n\n", argv[0]);
		exit(1);
	}
	yyparse();
	printvars();
	cout << "\nCodigo Intermedio:\n";
	print_icode();
	print_code(fname);
	return 0;
}