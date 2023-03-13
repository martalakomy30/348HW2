#include	<map>

typedef	std::map<std::string,int> 	MapType;

class	VarStore
{
  MapType	map_;
  int		nextRegister_;
  int		nextLabel_;

public :
  VarStore	() :
		map_(),
		nextRegister_(0),
		nextLabel_(0)
		{ }

  ~VarStore	()
		{ }

  int	getNextRegister
		()
  		{
		  return(nextRegister_++);
		}

  int	getRegisterOfVar
		(const char*	varNamePtr
		)
  {
    MapType::const_iterator	iter	= map_.find(varNamePtr);
    int				returnMe;

    if  (iter == map_.end())
    {
      map_[std::string(varNamePtr)] = returnMe	= getNextRegister();
    }
    else
      returnMe	= iter->second;

    return(returnMe);
  }

  int	getNextLabel
		()
  		{
		  return(nextLabel_++);
		}

};
