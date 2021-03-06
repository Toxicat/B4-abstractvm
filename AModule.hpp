#ifndef ABSTRACTVM_A_MODULE
# define ABSTRACTVM_A_MODULE

# include <cstdarg>

# include "VM.hpp"
# include "IModule.hpp"

class AModule :	public IModule
{
public:
	AModule(VM &, const std::string &);
	virtual ~AModule(void) {};

	const std::string &name(void) const;
	bool exec(const char *, ...);

protected:
	typedef bool (AModule::*func)(va_list *);

	VM								&_vm;
	const std::string				_name;
	std::map<const std::string, func>	_components;
};


#endif // !ABSTRACTVM_A_MODULE
