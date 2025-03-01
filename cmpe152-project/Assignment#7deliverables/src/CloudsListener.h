
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from d:\UbuntuFiles\CMPE152Ubuntu\cmpe152newlanguage\Clouds.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CloudsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CloudsParser.
 */
class  CloudsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(CloudsParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(CloudsParser::ProgramContext *ctx) = 0;

  virtual void enterHeader(CloudsParser::HeaderContext *ctx) = 0;
  virtual void exitHeader(CloudsParser::HeaderContext *ctx) = 0;

  virtual void enterBody(CloudsParser::BodyContext *ctx) = 0;
  virtual void exitBody(CloudsParser::BodyContext *ctx) = 0;

  virtual void enterBlock(CloudsParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CloudsParser::BlockContext *ctx) = 0;

  virtual void enterEnvironments(CloudsParser::EnvironmentsContext *ctx) = 0;
  virtual void exitEnvironments(CloudsParser::EnvironmentsContext *ctx) = 0;

  virtual void enterRun_simulation(CloudsParser::Run_simulationContext *ctx) = 0;
  virtual void exitRun_simulation(CloudsParser::Run_simulationContext *ctx) = 0;

  virtual void enterScope(CloudsParser::ScopeContext *ctx) = 0;
  virtual void exitScope(CloudsParser::ScopeContext *ctx) = 0;

  virtual void enterStmt_list(CloudsParser::Stmt_listContext *ctx) = 0;
  virtual void exitStmt_list(CloudsParser::Stmt_listContext *ctx) = 0;

  virtual void enterStat(CloudsParser::StatContext *ctx) = 0;
  virtual void exitStat(CloudsParser::StatContext *ctx) = 0;

  virtual void enterAssignment_stmt(CloudsParser::Assignment_stmtContext *ctx) = 0;
  virtual void exitAssignment_stmt(CloudsParser::Assignment_stmtContext *ctx) = 0;

  virtual void enterInit_stmt(CloudsParser::Init_stmtContext *ctx) = 0;
  virtual void exitInit_stmt(CloudsParser::Init_stmtContext *ctx) = 0;

  virtual void enterRepeat_stmt(CloudsParser::Repeat_stmtContext *ctx) = 0;
  virtual void exitRepeat_stmt(CloudsParser::Repeat_stmtContext *ctx) = 0;

  virtual void enterIf_stmt(CloudsParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(CloudsParser::If_stmtContext *ctx) = 0;

  virtual void enterPut_stmt(CloudsParser::Put_stmtContext *ctx) = 0;
  virtual void exitPut_stmt(CloudsParser::Put_stmtContext *ctx) = 0;

  virtual void enterCollision_stmt(CloudsParser::Collision_stmtContext *ctx) = 0;
  virtual void exitCollision_stmt(CloudsParser::Collision_stmtContext *ctx) = 0;

  virtual void enterWait_stmt(CloudsParser::Wait_stmtContext *ctx) = 0;
  virtual void exitWait_stmt(CloudsParser::Wait_stmtContext *ctx) = 0;

  virtual void enterMove_stmt(CloudsParser::Move_stmtContext *ctx) = 0;
  virtual void exitMove_stmt(CloudsParser::Move_stmtContext *ctx) = 0;

  virtual void enterWhen_stmt(CloudsParser::When_stmtContext *ctx) = 0;
  virtual void exitWhen_stmt(CloudsParser::When_stmtContext *ctx) = 0;

  virtual void enterPrint_stmt(CloudsParser::Print_stmtContext *ctx) = 0;
  virtual void exitPrint_stmt(CloudsParser::Print_stmtContext *ctx) = 0;

  virtual void enterVariable(CloudsParser::VariableContext *ctx) = 0;
  virtual void exitVariable(CloudsParser::VariableContext *ctx) = 0;

  virtual void enterIdentifier(CloudsParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(CloudsParser::IdentifierContext *ctx) = 0;

  virtual void enterInitList(CloudsParser::InitListContext *ctx) = 0;
  virtual void exitInitList(CloudsParser::InitListContext *ctx) = 0;

  virtual void enterParens(CloudsParser::ParensContext *ctx) = 0;
  virtual void exitParens(CloudsParser::ParensContext *ctx) = 0;

  virtual void enterAddSubExpr(CloudsParser::AddSubExprContext *ctx) = 0;
  virtual void exitAddSubExpr(CloudsParser::AddSubExprContext *ctx) = 0;

  virtual void enterNumberConst(CloudsParser::NumberConstContext *ctx) = 0;
  virtual void exitNumberConst(CloudsParser::NumberConstContext *ctx) = 0;

  virtual void enterRotExpr(CloudsParser::RotExprContext *ctx) = 0;
  virtual void exitRotExpr(CloudsParser::RotExprContext *ctx) = 0;

  virtual void enterSignedNumberConst(CloudsParser::SignedNumberConstContext *ctx) = 0;
  virtual void exitSignedNumberConst(CloudsParser::SignedNumberConstContext *ctx) = 0;

  virtual void enterRelExpr(CloudsParser::RelExprContext *ctx) = 0;
  virtual void exitRelExpr(CloudsParser::RelExprContext *ctx) = 0;

  virtual void enterMulDivExpr(CloudsParser::MulDivExprContext *ctx) = 0;
  virtual void exitMulDivExpr(CloudsParser::MulDivExprContext *ctx) = 0;

  virtual void enterInit_list(CloudsParser::Init_listContext *ctx) = 0;
  virtual void exitInit_list(CloudsParser::Init_listContext *ctx) = 0;

  virtual void enterInit_var(CloudsParser::Init_varContext *ctx) = 0;
  virtual void exitInit_var(CloudsParser::Init_varContext *ctx) = 0;

  virtual void enterObj_vars(CloudsParser::Obj_varsContext *ctx) = 0;
  virtual void exitObj_vars(CloudsParser::Obj_varsContext *ctx) = 0;

  virtual void enterFunction(CloudsParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(CloudsParser::FunctionContext *ctx) = 0;

  virtual void enterFuncName(CloudsParser::FuncNameContext *ctx) = 0;
  virtual void exitFuncName(CloudsParser::FuncNameContext *ctx) = 0;

  virtual void enterArgumentList(CloudsParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(CloudsParser::ArgumentListContext *ctx) = 0;

  virtual void enterMethodCallArguments(CloudsParser::MethodCallArgumentsContext *ctx) = 0;
  virtual void exitMethodCallArguments(CloudsParser::MethodCallArgumentsContext *ctx) = 0;

  virtual void enterMethodCall_ref(CloudsParser::MethodCall_refContext *ctx) = 0;
  virtual void exitMethodCall_ref(CloudsParser::MethodCall_refContext *ctx) = 0;

  virtual void enterSignedNumber(CloudsParser::SignedNumberContext *ctx) = 0;
  virtual void exitSignedNumber(CloudsParser::SignedNumberContext *ctx) = 0;

  virtual void enterSign(CloudsParser::SignContext *ctx) = 0;
  virtual void exitSign(CloudsParser::SignContext *ctx) = 0;

  virtual void enterIntegerConst(CloudsParser::IntegerConstContext *ctx) = 0;
  virtual void exitIntegerConst(CloudsParser::IntegerConstContext *ctx) = 0;

  virtual void enterFloatConst(CloudsParser::FloatConstContext *ctx) = 0;
  virtual void exitFloatConst(CloudsParser::FloatConstContext *ctx) = 0;

  virtual void enterAssignment_operators(CloudsParser::Assignment_operatorsContext *ctx) = 0;
  virtual void exitAssignment_operators(CloudsParser::Assignment_operatorsContext *ctx) = 0;

  virtual void enterMul_div_op(CloudsParser::Mul_div_opContext *ctx) = 0;
  virtual void exitMul_div_op(CloudsParser::Mul_div_opContext *ctx) = 0;

  virtual void enterAdd_sub_op(CloudsParser::Add_sub_opContext *ctx) = 0;
  virtual void exitAdd_sub_op(CloudsParser::Add_sub_opContext *ctx) = 0;

  virtual void enterRel_op(CloudsParser::Rel_opContext *ctx) = 0;
  virtual void exitRel_op(CloudsParser::Rel_opContext *ctx) = 0;

  virtual void enterRot_op(CloudsParser::Rot_opContext *ctx) = 0;
  virtual void exitRot_op(CloudsParser::Rot_opContext *ctx) = 0;


};

