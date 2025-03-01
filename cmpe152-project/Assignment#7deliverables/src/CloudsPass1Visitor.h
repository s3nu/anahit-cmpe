#ifndef CLOUDSPASS1VISITOR_H_
#define CLOUDSPASS1VISITOR_H_

#include <iostream>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "CloudsBaseVisitor.h"
#include "antlr4-runtime.h"
#include "CloudsVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class CloudsPass1Visitor : public CloudsBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    ofstream j_file;

public:
    CloudsPass1Visitor();
    virtual ~CloudsPass1Visitor();

    ostream& get_assembly_file();

    antlrcpp::Any visitProgram(CloudsParser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(CloudsParser::HeaderContext *ctx) override;  
    antlrcpp::Any visitBody(CloudsParser::BodyContext *ctx) override;

    //antlrcpp::Any visitBlock(CloudsParser::BlockContext *ctx) override;
    antlrcpp::Any visitEnvironments(CloudsParser::EnvironmentsContext *ctx) override;
    antlrcpp::Any visitInit_var(CloudsParser::Init_varContext *ctx) override;
    //antlrcpp::Any visitRun_simulation(CloudsParser::Run_simulationContext *ctx) override;
   /* antlrcpp::Any visitVariable(CloudsParser::VariableContext *ctx) override;
    antlrcpp::Any visitScope(CloudsParser::ScopeContext *ctx) override;
    antlrcpp::Any visitStmt_list(CloudsParser::Stmt_listContext *ctx) override;
    antlrcpp::Any visitAssignmentStmt(CloudsParser::Assignment_stmtContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(CloudsParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(CloudsParser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitRelExpr(CloudsParser::RelExprContext *ctx) override;
    antlrcpp::Any visitRotExpr(CloudsParser::RotExprContext *ctx) override;
    antlrcpp::Any visitInitList(CloudsParser::InitListContext *ctx)override;
    antlrcpp::Any visitNumberConst(CloudsParser::NumberConstContext *ctx) override;
    antlrcpp::Any visitParens(CloudsParser::ParensContext *ctx) override;
    antlrcpp::Any visitInit_list(CloudsParser::Init_listContext *ctx) override;  
    antlrcpp::Any visitInit_var(CloudsParser::Init_varContext *ctx) override;
    antlrcpp::Any visitFunction(CloudsParser::FunctionContext *ctx) override;
    antlrcpp::Any visitFuncName(CloudsParser::FuncNameContext *ctx) override;
    antlrcpp::Any visitArgumentList(CloudsParser::ArgumentListContext *ctx) override;
  */  
    
};

#endif /* CLOUDSPASS1VISITOR_H_ */
