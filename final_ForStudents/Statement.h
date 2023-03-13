#include	"vector"

class	Statement
{
public :
  Statement	()	{ }

  virtual
  ~Statement	()	{ }

  virtual
  int	toAssembly
		()	= 0;
};


class	IfStatement : public Statement
{
  Statement*	condPtr_;
  Statement*	thenPtr_;
  Statement*	elsePtr_;
public :
  IfStatement	(Statement*	condPtr,
		 Statement*	thenPtr,
		 Statement*	elsePtr	= NULL
		)
		{
		  condPtr_	= condPtr;
		  thenPtr_	= thenPtr;
		  elsePtr_	= elsePtr;
		}

  ~IfStatement	()
		{
		  delete(elsePtr_);
		  delete(thenPtr_);
		  delete(condPtr_);
		}

  int	toAssembly
		()
		{
		  int	condReg		= condPtr_->toAssembly();
		  int	afterLabel	= varStore.getNextLabel();

		  if  (elsePtr_ == NULL)
		  {
		    printf("\tIfFalseGoto Reg%d,Label%02d\n",condReg,afterLabel);
		    thenPtr_->toAssembly();
		    printf("Label%02d:NoOp\n",afterLabel);
		  }
		  else
		  {
		    int	elseLabel	= varStore.getNextLabel();

		    printf("\tIfFalseGoto Reg%d,Label%02d\n",condReg,elseLabel);
		    thenPtr_->toAssembly();
		    printf("\tGoto Label%02d\n",afterLabel);
		    printf("Label%02d:NoOp\n",elseLabel);
		    elsePtr_->toAssembly();
		    printf("Label%02d:NoOp\n",afterLabel);
		  }

		  return(-1);
		}
};


class WhileStatement : public Statement
{
  Statement*	condPtr_;
  Statement*	blockPtr_;
public :
  WhileStatement	(Statement*	condPtr,
			 Statement*	blockPtr
			)
		{
		  condPtr_	= condPtr;
		  blockPtr_	= blockPtr;
		}

  ~WhileStatement	()
		{
		  delete(blockPtr_);
		  delete(condPtr_);
		}

  int	toAssembly
		()
 		{
		  //  YOUR CODE HERE
		}
};


class BlockStatement : public Statement
{
  std::vector<Statement*>	list_;
public :
  BlockStatement	()	{ }

  ~BlockStatement	()
		{
		  for  (int i = 0; i < list_.size();  i++)
		    delete(list_[i]);
		}

  void	add	(Statement*	statePtr
		)
		{
		  list_.push_back(statePtr);
		}

  int	toAssembly
		()
		{
		  //  YOUR CODE HERE
		}
};


class AssignStatement : public Statement
{
  char*		varNamePtr_;
  Statement*	exprPtr_;
public :
  AssignStatement	(char*		varNamePtr,
			 Statement*	exprPtr
			)
		{
		  varNamePtr_	= varNamePtr;
		  exprPtr_	= exprPtr;
		}

  ~AssignStatement	()
		{
		  delete(exprPtr_);
		  free(varNamePtr_);
		}

  int	toAssembly
		()
		{
		  //  YOUR CODE HERE
		}
};


class BinaryOpStatement : public Statement
{
  Statement*	lhsPtr_;
  char		op_;
  Statement*	rhsPtr_;
public :
  BinaryOpStatement	(Statement*	lhsPtr,
			 char		op,
			 Statement*	rhsPtr
			)
		{
		  lhsPtr_	= lhsPtr;
		  op_		= op;
		  rhsPtr_	= rhsPtr;
		}

  ~BinaryOpStatement	()
		{
		  delete(rhsPtr_);
		  delete(lhsPtr_);
		}

  int	toAssembly
		()
		{
		  //  YOUR CODE HERE
		}
};


class	ConstantStatement : public Statement
{
  double	const_;
public :
  ConstantStatement	(double	constant
  			)
		{
		  const_ = constant;
		}

  int	toAssembly
		()
  	 	{
		  //  YOUR CODE HERE
		}
};


class	RValVarNameStatement : public Statement
{
  char*		varNamePtr_;
public :
  RValVarNameStatement	(char*	varNamePtr
  			)
		{
		  varNamePtr_ = varNamePtr;
		}

  ~RValVarNameStatement	()
  		{
		  free(varNamePtr_);
		}

  int	toAssembly
		()
  	 	{
		  //  YOUR CODE HERE
		}
};


class	PrintStatement : public Statement
{
  Statement*		exprPtr_;
public :
  PrintStatement	(Statement*	exprPtr
  			)
		{
		  exprPtr_ = exprPtr;
		}

  ~PrintStatement	()
  		{
		  delete(exprPtr_);
		}

  int	toAssembly
		()
  	 	{
		  //  YOUR CODE HERE
		}
};


class	ReadStatement : public Statement
{
  char*		varNamePtr_;
public :
  ReadStatement	(char*	varNamePtr
  			)
		{
		  varNamePtr_ = varNamePtr;
		}

  ~ReadStatement	()
  		{
		  free(varNamePtr_);
		}

  int	toAssembly
		()
  	 	{
		  //  YOUR CODE HERE
		}
};
