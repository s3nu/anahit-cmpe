#include <iostream>
#include <string>
#include <vector>

#include "CloudsPass1Visitor.h"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

CloudsPass1Visitor::CloudsPass1Visitor()
    : program_id(nullptr), j_file(nullptr)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    //cout << "=== Pass1Visitor(): symtab stack initialized." << endl;
}

CloudsPass1Visitor::~CloudsPass1Visitor() {}

ostream& CloudsPass1Visitor::get_assembly_file() { return j_file; }

antlrcpp::Any CloudsPass1Visitor::visitProgram(CloudsParser::ProgramContext *ctx)
{
    variable_id_list.resize(0);
    collisionFunctions.resize(0);

    auto value = visitChildren(ctx);

    

//    cout << "=== visitProgram: Printing xref table." << endl;

    // Print the cross-reference table.
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);

    //Generate collisions switch case function
    j_file << "\n\n.method private static handleCollision(I)V\n\n";

//put switch case for collisions from collisionFunctions vector here

    int counter = 1;

    j_file << "\tiload_0\n";
    j_file<< "\tlookupswitch\n";
    for(string name: collisionFunctions)
    {
        j_file <<"\t\t" << counter << ": L" << counter << "\n";
        counter++;
    }

    j_file << "\t\tdefault: END_COLLISION\n\n";


    counter = 1;
    for(string name: collisionFunctions)
    {
        
        //function call
        j_file << "\tL" <<counter << ":\n";
        j_file << "\t\tinvokestatic " << program_name << "/" << name << "()V\n";
        j_file << "\t\tgoto END_COLLISION\n";
        counter++;
    }

    j_file << "\tEND_COLLISION:\n";
    j_file << "\treturn\n\n";

    j_file << ".limit locals 1\n";
    j_file << ".limit stack 50\n";
    j_file << ".end method\n\n";


    return value;
}

antlrcpp::Any CloudsPass1Visitor::visitHeader(CloudsParser::HeaderContext *ctx)
{
//    cout << "=== visitHeader: " + ctx->getText() << endl;

    program_name = "collisionengine/" + ctx->ID()->toString();

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB,
                              new EntryValue(symtab_stack->push()));
    symtab_stack->set_program_id(program_id);

    // Create the assembly output file.
    j_file.open(program_name + ".j");
    if (j_file.fail())
    {
            cout << "***** Cannot open assembly file." << endl;
            exit(-99);
    }

    // Emit the program header.
    j_file << ".class public " << program_name << endl;
    j_file << ".super java/lang/Object" << endl;

    // Emit the RunTimer and PascalTextIn fields.
    j_file << endl;
    j_file << ".field private static _runTimer LRunTimer;" << endl;
    j_file << ".field private static _standardIn LPascalTextIn;" << endl;
    

    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass1Visitor::visitFunctionInit(CloudsParser::FunctionInitContext *ctx)
{
    
    auto type = Predefined::undefined_type;
    if(ctx->return_type() != nullptr){
        string type_name = ctx->return_type()->TYPE()->toString();
        if(type_name == "int"){
            type = Predefined::integer_type;
        }
        else if(type_name == "float"){
            type = Predefined::real_type;
        }
        else if(type_name == "cube"){
            type = Predefined::RectPrism_type;
        }
        else if(type_name == "sphere"){
            type = Predefined::Sphere_type;
        }
        else if(type_name == "cylinder"){
            type = Predefined::Cylinder_type;
        }
        else {
            type = Predefined::undefined_type;
        }
    }
    else{
        type = Predefined::undefined_type;
    }

    string variable_name = ctx->ID()->toString() + "()";
    SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition)DF_VARIABLE);
    variable_id->set_typespec(type);
    variable_id_list.push_back(variable_id);

    return visitChildren(ctx);

}

antlrcpp::Any CloudsPass1Visitor::visitBody(CloudsParser::BodyContext *ctx)
{
     auto value = visitChildren(ctx);

    // Emit the class constructor.
    j_file << endl;
    j_file << ".method public <init>()V" << endl;
    j_file << endl;
    j_file << "\taload_0" << endl;
    j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V" << endl;
    j_file << "\treturn" << endl;
    j_file << endl;
    j_file << ".limit locals 1" << endl;
    j_file << ".limit stack 1" << endl;
    j_file << ".end method" << endl;

    return value;
}


antlrcpp::Any CloudsPass1Visitor::visitEnvironments(CloudsParser::EnvironmentsContext *ctx)
{
    //change to dynamic if this doesn't work
    j_file << ".field private static "
               << ctx->ID()->toString() << "Engine " << "Lcollisionengine/CollisionEngine;" << endl;
    return visitChildren(ctx);
}


antlrcpp::Any CloudsPass1Visitor::visitInit_var(CloudsParser::Init_varContext *ctx)
{

    //init_var = TYPE and ID

    //TYPE
    string var_type = ctx->TYPE()->toString();
    string jas_type = "Lcollisionengine/";
    if(var_type == "cube"){
        ctx->variable()->type = Predefined::RectPrism_type;
        jas_type += "RectPrism;";
    }
    //SPhere has radius
    else if(var_type == "sphere"){
        ctx->variable()->type = Predefined::Sphere_type;
        jas_type += "Sphere;"; //array (not sure)
    }
    //cylinder (radius, height)
    else if(var_type == "cylinder"){
        ctx->variable()->type = Predefined::Cylinder_type;
        jas_type += "Cylinder;"; //array (not sure)
    }
    /*
    else if(var_type == "tetra"){
        jas_type = "[I"; //array (not sure)
    }
    */
    else if(var_type == "point"){
        ctx->variable()->type = Predefined::Point_type;
       jas_type += "Point;"; //array (not sure)
    }
    else if(var_type == "int"){
        ctx->variable()->type = Predefined::integer_type;
        jas_type = "I"; //integer
    }
    else if(var_type == "float"){
        ctx->variable()->type = Predefined::real_type;
        jas_type = "F"; //float 
    }
    else{
        ctx->variable()->type = nullptr;
        jas_type = "?"; //nullptr
    }

    //jasmin code
     j_file << ".field private static "
               << ctx->variable()->ID()->toString() << " " << jas_type << endl;
   
     
    //parsing identifiers and placing it in the system table
    string variable_name = ctx->variable()->ID()->toString();
    SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition)DF_VARIABLE);
    variable_id->set_typespec(ctx->variable()->type);
    variable_id_list.push_back(variable_id);


    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass1Visitor::visitWhen_stmt(CloudsParser::When_stmtContext *ctx)
{
    collisionFunctions.push_back(ctx->ID()->toString());

    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass1Visitor::visitAddSubExpr(CloudsParser::AddSubExprContext *ctx){

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;
    ctx->type = type;

    return value;
}

antlrcpp::Any CloudsPass1Visitor::visitMulDivExpr(CloudsParser::MulDivExprContext *ctx){

     auto value = visitChildren(ctx);

    //check the expr type
    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    //type checking if both nodes are of same type
    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;

    //set the type
    ctx->type = type;

    return value;
}

antlrcpp::Any CloudsPass1Visitor::visitRelExpr(CloudsParser::RelExprContext *ctx){

       auto value = visitChildren(ctx);

    //check the expr type
    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    //type checking if both nodes are of same type
    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;

    //set the type
    ctx->type = type;

    return value;
}


/*
antlrcpp::Any CloudsPass1Visitor::visitRotExpr(CloudsParser::RotExprContext *ctx){

       auto value = visitChildren(ctx);

    //check the expr type
    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    //type checking if both nodes are of same type
    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;

    //set the type
    ctx->type = type;

    return value;
}
*/



antlrcpp::Any CloudsPass1Visitor::visitSignedNumberConst(CloudsParser::SignedNumberConstContext *ctx){


    auto value = visitChildren(ctx);
    ctx->type = ctx->signedNumber()->type;
    return value;
    

}
antlrcpp::Any CloudsPass1Visitor::visitSignedNumber(CloudsParser::SignedNumberContext *ctx){

     auto value = visit(ctx->number());
    ctx->type = ctx->number()->type;
    return value;
}

antlrcpp::Any CloudsPass1Visitor::visitNumberConst(CloudsParser::NumberConstContext *ctx){

    auto value = visit(ctx->number());
    ctx->type = ctx->number()->type;
    return value;

}

antlrcpp::Any CloudsPass1Visitor::visitIntegerConst(CloudsParser::IntegerConstContext *ctx){

    ctx->type = Predefined::integer_type;
    return visitChildren(ctx);

}

antlrcpp::Any CloudsPass1Visitor::visitFloatConst(CloudsParser::FloatConstContext *ctx){
    ctx->type = Predefined::real_type;
    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass1Visitor::visitParens(CloudsParser::ParensContext *ctx){
    auto value = visitChildren(ctx);
    ctx->type = ctx->expr()->type;
    return value;
}

antlrcpp::Any CloudsPass1Visitor::visitExprvariable(CloudsParser::ExprvariableContext *ctx)
{
    
    auto value = visitChildren(ctx);
    
    ctx->type = ctx->variable()->type;

    return value;

}


antlrcpp::Any CloudsPass1Visitor::visitVariable(CloudsParser::VariableContext *ctx)
{
    if(ctx->obj_vars() == nullptr){
       string variable_name = ctx->ID()->toString();
        SymTabEntry *variable_id = symtab_stack->lookup(variable_name);

        ctx->type = variable_id->get_typespec();
    }
    else{
        ctx->type = Predefined::integer_type;
    }
    
    return visitChildren(ctx);

}


antlrcpp::Any CloudsPass1Visitor::visitFunctionCall(CloudsParser::FunctionCallContext *ctx)
{
    string variable_name = ctx->ID()->toString() + "()";
    SymTabEntry *variable_id = symtab_stack->lookup(variable_name);
    if(variable_id != nullptr){
        if(variable_id->get_typespec() != nullptr){
            ctx->type = variable_id->get_typespec();
        }
        else{
            ctx->type = nullptr;
        }
    }
   
    
    return visitChildren(ctx);
    
}


antlrcpp::Any CloudsPass1Visitor::visitExprFunctionCall(CloudsParser::ExprFunctionCallContext *ctx)
{
    auto value = visitChildren(ctx);

    ctx->type = ctx->functionCall()->type;

    return value;
}
