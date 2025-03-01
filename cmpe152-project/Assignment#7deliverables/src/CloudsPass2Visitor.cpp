#include <iostream>
#include <string>

#include "CloudsPass2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

CloudsPass2Visitor::CloudsPass2Visitor(ostream& j_file)
    : program_name(""), j_file(j_file)
{
}

CloudsPass2Visitor::~CloudsPass2Visitor() {}

antlrcpp::Any CloudsPass2Visitor::visitProgram(CloudsParser::ProgramContext *ctx)
{
    auto value = visitChildren(ctx);
    return value;
}

antlrcpp::Any CloudsPass2Visitor::visitHeader(CloudsParser::HeaderContext *ctx)
{
    program_name = ctx->ID()->toString();
    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass2Visitor::visitBody(CloudsParser::BodyContext *ctx)
{
    j_file << endl;
    j_file << ".method public static main([Ljava/lang/String;)V" << endl;
    j_file << endl;
    j_file << "\tnew RunTimer" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual RunTimer/<init>()V" << endl;
    j_file << "\tputstatic        " << program_name
           << "/_runTimer LRunTimer;" << endl;
    j_file << "\tnew PascalTextIn" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual PascalTextIn/<init>()V" << endl;
    j_file << "\tputstatic        " + program_name
           << "/_standardIn LPascalTextIn;\n" << endl;

    auto value = visitChildren(ctx);

    // Emit the main program epilogue.
    j_file << endl;
    j_file << "\tgetstatic     " << program_name
               << "/_runTimer LRunTimer;" << endl;
    j_file << "\tinvokevirtual RunTimer.printElapsedTime()V" << endl;
    j_file << endl;
    j_file << "\treturn" << endl;
    j_file << endl;
    j_file << ".limit locals 16" << endl;
    j_file << ".limit stack 16" << endl;
    j_file << ".end method" << endl;

    return value;
}
antlrcpp::Any CloudsPass2Visitor::visitBlock(CloudsParser::BlockContext *ctx)
{
    return visitChildren(ctx);

}

antlrcpp::Any CloudsPass2Visitor::visitEnvironments(CloudsParser::EnvironmentsContext *ctx)
{
    current_environment_name = ctx->ID()->toString();
    j_file << "\tldc 100\n" << "\tldc 100\n" << "\tldc 100\n";
    j_file << "\tmultianewarray [[[I 3\n";
    j_file << "\tputstatic " << program_name << "/" 
                << current_environment_name << " " << "[[[I\n" << endl;
    return visitChildren(ctx);
}



antlrcpp::Any CloudsPass2Visitor::visitStat(CloudsParser::StatContext *ctx)
{
    j_file << endl << "; " + ctx->getText() << endl << endl;

    return visitChildren(ctx);
}

antlrcpp::Any CloudsPass2Visitor::visitAssignment_stmt(CloudsParser::Assignment_stmtContext *ctx)
{
    auto value = visit(ctx->expr());

    string type_indicator =
                  (ctx->expr()->type == Predefined::integer_type) ? "I"
                : (ctx->expr()->type == Predefined::real_type)    ? "F"
                :                                                   "?";

    // Emit a field put instruction.
    j_file << "\tputstatic\t" << program_name
           << "/" << ctx->variable()->ID()->toString()
           << " " << type_indicator << endl;

    return value;
}

antlrcpp::Any CloudsPass2Visitor::visitInit_stmt(CloudsParser::Init_stmtContext *ctx)
{
    string var_type = ctx->init_var()->TYPE()->toString();
    var_name = ctx->init_var()->ID()->toString();
    if(var_type == "cube") { 
        jas_type = "[I";
        var_size = 3;
        j_file << "\tldc " << var_size << endl;
        j_file << "\tnewarray int\n";
    }
    
    
    j_file << "\tputstatic " << program_name << "/" 
                << var_name << " " << jas_type << "\n" << endl;

    if(var_type == "cube") { 
        j_file << "\tldc " << 3 << endl;
        j_file << "\tnewarray int\n";
    }
    
    
    j_file << "\tputstatic " << program_name << "/" 
                << var_name << "center"<< " [I" << "\n" << endl;
   
    
    return visitChildren(ctx);
}


antlrcpp::Any CloudsPass2Visitor::visitInit_list(CloudsParser::Init_listContext *ctx)
{
    string number;
     for(int counter = 0; counter < var_size; counter++){
        number = ctx->expr(counter)->getText();
        j_file << "\tgetstatic " << program_name << "/" << var_name << " " << jas_type <<endl;
        j_file << "\tldc\t" << counter << endl;
        j_file << "\tldc\t" << number << endl;//change to support multidimensional arrays
        j_file << "\tiastore\n" << endl;
    }
    return visitChildren(ctx);

}

antlrcpp::Any CloudsPass2Visitor::visitPut_stmt(CloudsParser::Put_stmtContext *ctx)
{
    string put_var_name = ctx->ID()->toString();
    int put_var_number = 0;
    for(int counter = 0; counter <3; counter++){
        j_file << "\tgetstatic\t" << program_name <<"/"<< put_var_name << "center [I\n";
        j_file << "\tldc\t" << counter << endl;
        j_file << "\tldc\t0" <<endl;
        j_file << "\tiastore\n" << endl;
    }
    

    j_file << "\tgetstatic\t" << program_name << "/" << current_environment_name << " [[[I" <<endl;
    j_file << "\tldc 50\n" << "\taaload\n"
            << "\tldc 50\n" << "\taaload\n"
            << "\tldc 50\n";
    if(put_var_name == "cubeobject"){
        put_var_number =1;
    }
    j_file << "\tldc\t" << put_var_number <<endl; //1 represents cube, make general later
    j_file << "\tiastore" << endl;

    return visitChildren(ctx);

}

antlrcpp::Any CloudsPass2Visitor::visitIntegerConst(CloudsParser::IntegerConstContext *ctx)
{
    // Emit a load constant instruction.
   // j_file << "\tldc\t" << ctx->getText() << endl;

    return visitChildren(ctx);
}

/*
antlrcpp::Any CloudsPass2Visitor::visitAdd_Sub_op(CloudsParser::Add_sub_opContext *ctx)
{
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    string op = ctx->add_sub_op()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "iadd"
               : real_mode    ? "fadd"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "isub"
               : real_mode    ? "fsub"
               :                "????";
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

antlrcpp::Any CloudsPass2Visitor::visitMul_div_op(CloudsParser::Mul_div_opContext *ctx)
{
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    string op = ctx->mul_div_op()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "imul"
               : real_mode    ? "fmul"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "idiv"
               : real_mode    ? "fdiv"
               :                "????";
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

antlrcpp::Any CloudsPass2Visitor::visitIf_stmt(CloudsParser::If_stmtContext *ctx)
{
    auto value = visitChildren(ctx->expr());
    auto value2 = visitChildren(ctx->stat());

    string type_indicator = 
                  (ctx->expr()->type == Predefined::integer_type) ? "I"
                | (ctx->expr()->type == Predefined::real_type)    ? "F"
                |                                                   "?";

    j_file  << "\tgetstatic\t" << program_name
            << "/" << ctx->variable()->ID()->toString()
            << " " << type_indicator << endl; 
    j_file  << "\tgetstatic\t" << program_name
            << "/" << ctx->variable()->ID()->toString()
            << " " << type_indicator << endl; 
    j_file  << "\ticonst_0\t" << endl
            << "\tgoto\tL003";
    j_file  << "L002:" << endl << "\ticonst_1\t" << endl
            << "L003:" << endl << "\tifeq\tL001" << endl; 
}
*/



antlrcpp::Any CloudsPass2Visitor::visitRun_simulation(CloudsParser::Run_simulationContext *ctx)
{
    auto value = visitChildren(ctx);
    string output_var_name = "cubeobject";

    j_file << "\tgetstatic\tjava/lang/System/out Ljava/io/PrintStream;" <<endl;
    j_file << "\tldc\t\"Results of Simulation:";
    
/*
//NOT USING printf
    j_file << "\"\n\tinvokevirtual java/io/PrintStream.println(Ljava/lang/String;)V\n";
    j_file << "\tgetstatic\tjava/lang/System/out Ljava/io/PrintStream;" <<endl;
    j_file << "\tldc\t\"cubeobject at x=\"\n";
    j_file << "\tinvokevirtual java/io/PrintStream.print(Ljava/lang/String;)V\n";

    j_file << "\tgetstatic\tjava/lang/System/out Ljava/io/PrintStream;" <<endl;
    j_file << "getstatic\t"<< program_name << "/"<<output_var_name << "center [I\n"
                <<"ldc\t" << 0 <<"\niaload\n";
    j_file << "\tinvokevirtual java/io/PrintStream.print(Ljava/lang/String;)V\n";
//END NOT USING printf
*/

 // USING printf
    j_file << "\n\tcubeobject at x=%d, y=%d, z=%d\"\n";
    j_file << "\ticonst_3\n\tanewarray java/lang/Object\n\tdup\n";
    for(int counter = 0; counter <3; counter ++){
        j_file << "\tldc " << counter << endl;
        j_file << "\tgetstatic\t"<< program_name << "/"<<output_var_name << "center [I\n"
                <<"\tldc\t" << counter <<"\n\tiaload\n";
        j_file << "\tinvokestatic\tjava/lang/Integer.valueOf(I)Ljava/lang/Integer;\n";
        j_file << "\taastore\n";
        if(counter!=2){
            j_file << "\tdup\n";
        }
        
    }
    j_file << "\tinvokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;\npop\n" <<endl;

//END USING printf

    return value;
    
}