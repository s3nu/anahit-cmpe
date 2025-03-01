#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "CloudsLexer.h"
#include "CloudsParser.h"
#include "CloudsPass1Visitor.h"
#include "CloudsPass2Visitor.h"

using namespace std;
using namespace antlrcpp;
using namespace antlr4;

int main(int argc, const char *args[])
{
    ifstream ins;
    ins.open(args[1]);

    ANTLRInputStream input(ins);
    CloudsLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    CloudsParser parser(&tokens);
    tree::ParseTree *tree = parser.program();

    CloudsPass1Visitor *pass1 = new CloudsPass1Visitor();
    pass1->visit(tree);

    ostream& j_file = pass1->get_assembly_file();

    CloudsPass2Visitor *pass2 = new CloudsPass2Visitor(j_file);
    pass2->visit(tree);

    delete tree;
    return 0;
}
