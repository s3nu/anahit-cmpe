#ifndef COMPILERVISITOR_H_
#define COMPILERVISITOR_H_

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "CloudsBaseVisitor.h"
#include "antlr4-runtime.h"
#include "CloudsVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class CompilerVisitor : public CloudsBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    TypeSpec *data_type;

public:
    CompilerVisitor();
    virtual ~CompilerVisitor();

    antlrcpp::Any visitProgram(CloudsParser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(CloudsParser::HeaderContext *ctx) override;
    antlrcpp::Any visitDecl(CloudsParser::DeclContext *ctx) override;
    antlrcpp::Any visitVar_list(CloudsParser::Var_listContext *ctx) override;
    antlrcpp::Any visitVar_id(CloudsParser::Var_idContext *ctx) override;
    antlrcpp::Any visitType_id(CloudsParser::Type_idContext *ctx) override;
};

#endif /* COMPILERVISITOR_H_ */
