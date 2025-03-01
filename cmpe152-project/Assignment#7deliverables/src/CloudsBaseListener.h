
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from d:\UbuntuFiles\CMPE152Ubuntu\cmpe152newlanguage\Clouds.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CloudsListener.h"


/**
 * This class provides an empty implementation of CloudsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CloudsBaseListener : public CloudsListener {
public:

  virtual void enterProgram(CloudsParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(CloudsParser::ProgramContext * /*ctx*/) override { }

  virtual void enterHeader(CloudsParser::HeaderContext * /*ctx*/) override { }
  virtual void exitHeader(CloudsParser::HeaderContext * /*ctx*/) override { }

  virtual void enterBody(CloudsParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(CloudsParser::BodyContext * /*ctx*/) override { }

  virtual void enterBlock(CloudsParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CloudsParser::BlockContext * /*ctx*/) override { }

  virtual void enterEnvironments(CloudsParser::EnvironmentsContext * /*ctx*/) override { }
  virtual void exitEnvironments(CloudsParser::EnvironmentsContext * /*ctx*/) override { }

  virtual void enterRun_simulation(CloudsParser::Run_simulationContext * /*ctx*/) override { }
  virtual void exitRun_simulation(CloudsParser::Run_simulationContext * /*ctx*/) override { }

  virtual void enterScope(CloudsParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(CloudsParser::ScopeContext * /*ctx*/) override { }

  virtual void enterStmt_list(CloudsParser::Stmt_listContext * /*ctx*/) override { }
  virtual void exitStmt_list(CloudsParser::Stmt_listContext * /*ctx*/) override { }

  virtual void enterStat(CloudsParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(CloudsParser::StatContext * /*ctx*/) override { }

  virtual void enterAssignment_stmt(CloudsParser::Assignment_stmtContext * /*ctx*/) override { }
  virtual void exitAssignment_stmt(CloudsParser::Assignment_stmtContext * /*ctx*/) override { }

  virtual void enterInit_stmt(CloudsParser::Init_stmtContext * /*ctx*/) override { }
  virtual void exitInit_stmt(CloudsParser::Init_stmtContext * /*ctx*/) override { }

  virtual void enterRepeat_stmt(CloudsParser::Repeat_stmtContext * /*ctx*/) override { }
  virtual void exitRepeat_stmt(CloudsParser::Repeat_stmtContext * /*ctx*/) override { }

  virtual void enterIf_stmt(CloudsParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(CloudsParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterPut_stmt(CloudsParser::Put_stmtContext * /*ctx*/) override { }
  virtual void exitPut_stmt(CloudsParser::Put_stmtContext * /*ctx*/) override { }

  virtual void enterCollision_stmt(CloudsParser::Collision_stmtContext * /*ctx*/) override { }
  virtual void exitCollision_stmt(CloudsParser::Collision_stmtContext * /*ctx*/) override { }

  virtual void enterWait_stmt(CloudsParser::Wait_stmtContext * /*ctx*/) override { }
  virtual void exitWait_stmt(CloudsParser::Wait_stmtContext * /*ctx*/) override { }

  virtual void enterMove_stmt(CloudsParser::Move_stmtContext * /*ctx*/) override { }
  virtual void exitMove_stmt(CloudsParser::Move_stmtContext * /*ctx*/) override { }

  virtual void enterWhen_stmt(CloudsParser::When_stmtContext * /*ctx*/) override { }
  virtual void exitWhen_stmt(CloudsParser::When_stmtContext * /*ctx*/) override { }

  virtual void enterPrint_stmt(CloudsParser::Print_stmtContext * /*ctx*/) override { }
  virtual void exitPrint_stmt(CloudsParser::Print_stmtContext * /*ctx*/) override { }

  virtual void enterVariable(CloudsParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(CloudsParser::VariableContext * /*ctx*/) override { }

  virtual void enterIdentifier(CloudsParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(CloudsParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterInitList(CloudsParser::InitListContext * /*ctx*/) override { }
  virtual void exitInitList(CloudsParser::InitListContext * /*ctx*/) override { }

  virtual void enterParens(CloudsParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(CloudsParser::ParensContext * /*ctx*/) override { }

  virtual void enterAddSubExpr(CloudsParser::AddSubExprContext * /*ctx*/) override { }
  virtual void exitAddSubExpr(CloudsParser::AddSubExprContext * /*ctx*/) override { }

  virtual void enterNumberConst(CloudsParser::NumberConstContext * /*ctx*/) override { }
  virtual void exitNumberConst(CloudsParser::NumberConstContext * /*ctx*/) override { }

  virtual void enterRotExpr(CloudsParser::RotExprContext * /*ctx*/) override { }
  virtual void exitRotExpr(CloudsParser::RotExprContext * /*ctx*/) override { }

  virtual void enterSignedNumberConst(CloudsParser::SignedNumberConstContext * /*ctx*/) override { }
  virtual void exitSignedNumberConst(CloudsParser::SignedNumberConstContext * /*ctx*/) override { }

  virtual void enterRelExpr(CloudsParser::RelExprContext * /*ctx*/) override { }
  virtual void exitRelExpr(CloudsParser::RelExprContext * /*ctx*/) override { }

  virtual void enterMulDivExpr(CloudsParser::MulDivExprContext * /*ctx*/) override { }
  virtual void exitMulDivExpr(CloudsParser::MulDivExprContext * /*ctx*/) override { }

  virtual void enterInit_list(CloudsParser::Init_listContext * /*ctx*/) override { }
  virtual void exitInit_list(CloudsParser::Init_listContext * /*ctx*/) override { }

  virtual void enterInit_var(CloudsParser::Init_varContext * /*ctx*/) override { }
  virtual void exitInit_var(CloudsParser::Init_varContext * /*ctx*/) override { }

  virtual void enterObj_vars(CloudsParser::Obj_varsContext * /*ctx*/) override { }
  virtual void exitObj_vars(CloudsParser::Obj_varsContext * /*ctx*/) override { }

  virtual void enterFunction(CloudsParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(CloudsParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFuncName(CloudsParser::FuncNameContext * /*ctx*/) override { }
  virtual void exitFuncName(CloudsParser::FuncNameContext * /*ctx*/) override { }

  virtual void enterArgumentList(CloudsParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(CloudsParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterMethodCallArguments(CloudsParser::MethodCallArgumentsContext * /*ctx*/) override { }
  virtual void exitMethodCallArguments(CloudsParser::MethodCallArgumentsContext * /*ctx*/) override { }

  virtual void enterMethodCall_ref(CloudsParser::MethodCall_refContext * /*ctx*/) override { }
  virtual void exitMethodCall_ref(CloudsParser::MethodCall_refContext * /*ctx*/) override { }

  virtual void enterSignedNumber(CloudsParser::SignedNumberContext * /*ctx*/) override { }
  virtual void exitSignedNumber(CloudsParser::SignedNumberContext * /*ctx*/) override { }

  virtual void enterSign(CloudsParser::SignContext * /*ctx*/) override { }
  virtual void exitSign(CloudsParser::SignContext * /*ctx*/) override { }

  virtual void enterIntegerConst(CloudsParser::IntegerConstContext * /*ctx*/) override { }
  virtual void exitIntegerConst(CloudsParser::IntegerConstContext * /*ctx*/) override { }

  virtual void enterFloatConst(CloudsParser::FloatConstContext * /*ctx*/) override { }
  virtual void exitFloatConst(CloudsParser::FloatConstContext * /*ctx*/) override { }

  virtual void enterAssignment_operators(CloudsParser::Assignment_operatorsContext * /*ctx*/) override { }
  virtual void exitAssignment_operators(CloudsParser::Assignment_operatorsContext * /*ctx*/) override { }

  virtual void enterMul_div_op(CloudsParser::Mul_div_opContext * /*ctx*/) override { }
  virtual void exitMul_div_op(CloudsParser::Mul_div_opContext * /*ctx*/) override { }

  virtual void enterAdd_sub_op(CloudsParser::Add_sub_opContext * /*ctx*/) override { }
  virtual void exitAdd_sub_op(CloudsParser::Add_sub_opContext * /*ctx*/) override { }

  virtual void enterRel_op(CloudsParser::Rel_opContext * /*ctx*/) override { }
  virtual void exitRel_op(CloudsParser::Rel_opContext * /*ctx*/) override { }

  virtual void enterRot_op(CloudsParser::Rot_opContext * /*ctx*/) override { }
  virtual void exitRot_op(CloudsParser::Rot_opContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

