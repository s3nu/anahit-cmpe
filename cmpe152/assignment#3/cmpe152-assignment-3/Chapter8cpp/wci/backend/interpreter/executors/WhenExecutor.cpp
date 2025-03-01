#include <vector>
#include <map>
#include "WhenExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

WhenExecutor::WhenExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object WhenExecutor::execute(ICodeNode *node)
{
    vector<ICodeNode *> children = node->get_children();
    bool test = true;
    int when_size = children.size();
    int curr_node = 0;
    while (test && (curr_node < when_size - 2))
    {
          ICodeNode *when_branch = children[curr_node];
          ExpressionExecutor expression_executor(this);
          StatementExecutor statement_executor(this);
          ICodeNode *expr_node = when_branch->get_children()[0];
          ICodeNode *statement_node = when_branch->get_children()[1];
          Object data_value = expression_executor.execute(expr_node);
          if(cast(data_value, bool))
          {
            statement_executor.execute(statement_node);
            test = false;
          }
          curr_node++;
    }
    if (test) {
	    //creating the otherwise_node it will be the last child of when
	    ICodeNode *otherwise_node = children[when_size-1];
	    StatementExecutor statement_executor(this);		//executing the statement node of otherwise
	    ICodeNode *statement_node = otherwise_node->get_children()[0];
	    statement_executor.execute(statement_node);
    }
    ++execution_count;  // count the SELECT statement itself
    return Object();    // empty
}
}}}}  // namespace wci::backend::interpreter::executors