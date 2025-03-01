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
    vector<string> collisionFunctions;
    string program_name;

public:
    CloudsPass1Visitor();
    virtual ~CloudsPass1Visitor();

    ostream& get_assembly_file();

    antlrcpp::Any visitProgram(CloudsParser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(CloudsParser::HeaderContext *ctx) override;  
    antlrcpp::Any visitFunctionInit(CloudsParser::FunctionInitContext *ctx) override;
    antlrcpp::Any visitEnvironments(CloudsParser::EnvironmentsContext *ctx) override;
    antlrcpp::Any visitBody(CloudsParser::BodyContext *ctx) override;
    antlrcpp::Any visitInit_var(CloudsParser::Init_varContext *ctx) override;

    antlrcpp::Any visitWhen_stmt(CloudsParser::When_stmtContext *ctx) override;

    antlrcpp::Any visitMulDivExpr(CloudsParser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(CloudsParser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitRelExpr(CloudsParser::RelExprContext *ctx) override;
//    antlrcpp::Any visitRotExpr(CloudsParser::RotExprContext *ctx) override;
    antlrcpp::Any visitSignedNumberConst(CloudsParser::SignedNumberConstContext *ctx)override;
    antlrcpp::Any visitSignedNumber(CloudsParser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitNumberConst(CloudsParser::NumberConstContext *ctx) override;
    antlrcpp::Any visitIntegerConst(CloudsParser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(CloudsParser::FloatConstContext *ctx) override;
    antlrcpp::Any visitParens(CloudsParser::ParensContext *ctx) override;
    antlrcpp::Any visitExprvariable(CloudsParser::ExprvariableContext *ctx) override;
    antlrcpp::Any visitVariable(CloudsParser::VariableContext *ctx) override;
    antlrcpp::Any visitFunctionCall(CloudsParser::FunctionCallContext *ctx) override;
    antlrcpp::Any visitExprFunctionCall(CloudsParser::ExprFunctionCallContext *ctx) override;

   
    
};

#endif /* CLOUDSPASS1VISITOR_H_ */
