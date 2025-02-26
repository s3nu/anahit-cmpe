#ifndef WHENEXECUTOR_H_
#define WHENEXECUTOR_H_

#include <map>
#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;

typedef map<int, ICodeNode *> JumpTable;
typedef map<ICodeNode *, JumpTable *> JumpCache;

class WhenExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    WhenExecutor(Executor *parent);

    /**
     * Execute a compound statement.
     * @param node the root node of the compound statement.
     * @return nullptr.
     */
    Object execute(ICodeNode *node);
    //DataValue *execute(ICodeNode *node);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* WHENEXECUTOR_H_ */