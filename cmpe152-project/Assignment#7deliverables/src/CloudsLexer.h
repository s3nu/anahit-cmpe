
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from d:\UbuntuFiles\CMPE152Ubuntu\cmpe152newlanguage\Clouds.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  CloudsLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, CLOUDS = 11, REPEAT = 12, UNTIL = 13, 
    IF = 14, THEN = 15, ELSE = 16, WHEN = 17, CENTER = 18, TELEPORT = 19, 
    COLISION = 20, PAUSE = 21, WAIT = 22, MOVE = 23, TO = 24, MOVE_3 = 25, 
    AT = 26, IN = 27, FOR = 28, FINISH = 29, PUTNENV = 30, FUNCTION = 31, 
    ENVIRONMENT = 32, SIMULATION = 33, PRINT = 34, BETWEEN = 35, TYPE = 36, 
    HEIGHT = 37, WIDTH = 38, LENGTH = 39, RADIUS = 40, X = 41, Y = 42, Z = 43, 
    POINT = 44, VELOCITY = 45, SPEED = 46, MUL = 47, DIV = 48, ADD = 49, 
    SUB = 50, MUL_EQ = 51, DIV_EQ = 52, ADD_EQ = 53, SUB_EQ = 54, EQ_OP = 55, 
    NE_OP = 56, LT_OP = 57, LE_OP = 58, GT_OP = 59, GE_OP = 60, ROLL_OP = 61, 
    PITCH_OP = 62, YAW_OP = 63, COM_OP = 64, SEMICOLON = 65, FLOAT = 66, 
    ID = 67, INT = 68, NEWLINE = 69, WS = 70, COMMENT = 71, BLOCK_COM = 72
  };

  CloudsLexer(antlr4::CharStream *input);
  ~CloudsLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

