#include <iostream>
#include <string>
#include <vector>

#include "CompilerVisitor.h"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

CompilerVisitor::CompilerVisitor()
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);
}

CompilerVisitor::~CompilerVisitor()
{
}

antlrcpp::Any CompilerVisitor::visitProgram(CloudsParser::ProgramContext *ctx)
{
    cout << "Visiting program" << endl;
    auto value = visitChildren(ctx);

    // Print the cross-reference table.
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);

    return value;
}

antlrcpp::Any CompilerVisitor::visitHeader(CloudsParser::HeaderContext *ctx)
{
    string program_name = ctx->IDENTIFIER()->toString();
    cout << "Program name = " << program_name << endl;

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB,
                              new EntryValue(symtab_stack->push()));
    symtab_stack->set_program_id(program_id);

    return visitChildren(ctx);
}

antlrcpp::Any CompilerVisitor::visitDecl(CloudsParser::DeclContext *ctx)
{
    cout << "Visiting dcl" << endl;
    return visitChildren(ctx);
}

antlrcpp::Any CompilerVisitor::visitVar_list(CloudsParser::Var_listContext *ctx)
{
    cout << "Visiting variable list" << endl;
    variable_id_list.resize(0);

    return visitChildren(ctx);
}

antlrcpp::Any CompilerVisitor::visitVar_id(CloudsParser::Var_idContext *ctx)
{
    string variable_name = ctx->IDENTIFIER()->toString();
    cout << "Declared Id = " << variable_name << endl;

    SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);
    variable_id_list.push_back(variable_id);

    return visitChildren(ctx);
}

antlrcpp::Any CompilerVisitor::visitType_id(CloudsParser::Type_idContext *ctx)
{
    string type_name = ctx->IDENTIFIER()->toString();
    cout << "Type = " << type_name << endl;

    data_type = type_name == "integer" ? Predefined::integer_type
              : type_name == "real"    ? Predefined::real_type
                                       : nullptr;

    for (SymTabEntry *id : variable_id_list) id->set_typespec(data_type);

    return visitChildren(ctx);
}
