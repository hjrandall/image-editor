#ifndef _MENUDATA_
#define _MENUDATA_
#include "ActionData.h"
#include <map>
#include <vector>

typedef void (*ActionFunctionType)(ActionData& action_data);
class MenuData{
    public:
        MenuData();
        void addAction(const std::string& name, ActionFunctionType func, const std::string& description);
        const std::vector<std::string>& getNames() const;
        ActionFunctionType getFunction(const std::string& name);
        const std::string& getDescription(const std::string& name);
    // protected:
        std::vector<std::string> names;
        std::map<std::string,ActionFunctionType> functions;
        std::map<std::string,std::string> descriptions;
};
#endif