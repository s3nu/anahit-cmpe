
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from d:\UbuntuFiles\CMPE152Ubuntu\cmpe152newlanguage\Clouds.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CloudsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CloudsParser.
 */
class  CloudsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CloudsParser.
   */
    virtual antlrcpp::Any visitProgram(CloudsParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitHeader(CloudsParser::HeaderContext *context) = 0;

    virtual antlrcpp::Any visitBody(CloudsParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitBlock(CloudsParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitEnvironments(CloudsParser::EnvironmentsContext *context) = 0;

    virtual antlrcpp::Any visitRun_simulation(CloudsParser::Run_simulationContext *context) = 0;

    virtual antlrcpp::Any visitScope(CloudsParser::ScopeContext *context) = 0;

    virtual antlrcpp::Any visitStmt_list(CloudsParser::Stmt_listContext *context) = 0;

    virtual antlrcpp::Any visitStat(CloudsParser::StatContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_stmt(CloudsParser::Assignment_stmtContext *context) = 0;

    virtual antlrcpp::Any visitInit_stmt(CloudsParser::Init_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRepeat_stmt(CloudsParser::Repeat_stmtContext *context) = 0;

    virtual antlrcpp::Any visitIf_stmt(CloudsParser::If_stmtContext *context) = 0;

    virtual antlrcpp::Any visitPut_stmt(CloudsParser::Put_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCollision_stmt(CloudsParser::Collision_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWait_stmt(CloudsParser::Wait_stmtContext *context) = 0;

    virtual antlrcpp::Any visitMove_stmt(CloudsParser::Move_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWhen_stmt(CloudsParser::When_stmtContext *context) = 0;

    virtual antlrcpp::Any visitPrint_stmt(CloudsParser::Print_stmtContext *context) = 0;

    virtual antlrcpp::Any visitVariable(CloudsParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(CloudsParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitInitList(CloudsParser::InitListContext *context) = 0;

    virtual antlrcpp::Any visitParens(CloudsParser::ParensContext *context) = 0;

    virtual antlrcpp::Any visitAddSubExpr(CloudsParser::AddSubExprContext *context) = 0;

    virtual antlrcpp::Any visitNumberConst(CloudsParser::NumberConstContext *context) = 0;

    virtual antlrcpp::Any visitRotExpr(CloudsParser::RotExprContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumberConst(CloudsParser::SignedNumberConstContext *context) = 0;

    virtual antlrcpp::Any visitRelExpr(CloudsParser::RelExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivExpr(CloudsParser::MulDivExprContext *context) = 0;

    virtual antlrcpp::Any visitInit_list(CloudsParser::Init_listContext *context) = 0;

    virtual antlrcpp::Any visitInit_var(CloudsParser::Init_varContext *context) = 0;

    virtual antlrcpp::Any visitObj_vars(CloudsParser::Obj_varsContext *context) = 0;

    virtual antlrcpp::Any visitFunction(CloudsParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFuncName(CloudsParser::FuncNameContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(CloudsParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitMethodCallArguments(CloudsParser::MethodCallArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall_ref(CloudsParser::MethodCall_refContext *context) = 0;

    virtual antlrcpp::Any visitSignedNumber(CloudsParser::SignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitSign(CloudsParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConst(CloudsParser::IntegerConstContext *context) = 0;

    virtual antlrcpp::Any visitFloatConst(CloudsParser::FloatConstContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_operators(CloudsParser::Assignment_operatorsContext *context) = 0;

    virtual antlrcpp::Any visitMul_div_op(CloudsParser::Mul_div_opContext *context) = 0;

    virtual antlrcpp::Any visitAdd_sub_op(CloudsParser::Add_sub_opContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(CloudsParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitRot_op(CloudsParser::Rot_opContext *context) = 0;


};

