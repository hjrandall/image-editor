#include "MenuData.h"
MenuData::MenuData(){
}
 void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string& description){
     names.push_back(name);
     functions[name]=func;
     descriptions[name]=description;
 }
const std::vector<std::string>& MenuData::getNames() const{
    return names;
}
ActionFunctionType MenuData::getFunction(const std::string& name){
    if (functions.find(name)!= functions.end()){
        return functions[name];
    }
    return 0;
}
const std::string& MenuData::getDescription(const std::string& name){
     if (descriptions.find(name)!= descriptions.end()){
        return descriptions[name];
    }
    static std::string empty="";
    return empty;
}