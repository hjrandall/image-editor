#include "image_menu.h"
std::string getString(ActionData& action_data, const std::string& prompt){
    std::string user_string;
    action_data.getOS() << prompt;
    action_data.getIS() >> user_string;
    return user_string;
}
int getInteger (ActionData& action_data, const std::string& prompt){
    int user_num;
    action_data.getOS() << prompt ;
    action_data.getIS() >> user_num;
    return user_num;
}
double getDouble (ActionData& action_data, const std::string& prompt){
    double user_float;
    action_data.getOS() << prompt;
    action_data.getIS() >> user_float;
    return user_float;
}
int askQuestions3 (ActionData& action_data){
    std::string fav_color = getString(action_data, "What is your favorite color?");
    action_data.getOS()<< " ";
    int fav_int = getInteger(action_data, "What is your favorite integer?");
    action_data.getOS()<< " ";
    double fav_num = getDouble(action_data, "What is your favorite number?");
    action_data.getOS()<<" ";
    for (int i=1; i<=fav_int; i++) {
        action_data.getOS() << i << " " << fav_color << " " << fav_num << std::endl;
    }
    return fav_int;
}

int askHeroQuestions(ActionData& action_data){
    std::string hero;
    int birth_year;
    action_data.getOS() << "Who is your hero? ";
    action_data.getIS()>> hero; 
    action_data.getOS() << "What year were they born? ";
    action_data.getIS() >> birth_year;
    action_data.getOS()<< hero << " was born in "<< birth_year<<".";
    return birth_year;
}
std::string getChoice( ActionData& action_data ){
    std::string prompt="Choice? ";
    return getString(action_data,prompt);
}

void commentLine( ActionData& action_data ){
    unsigned char byte ;
    bool end_of_file=false;
    while (end_of_file != true){
        if (action_data.getIS().good()&& byte!='\n'){
            action_data.getIS().read((char*)&byte,1);
        }
        else{
            end_of_file=true;
        }
    }
    return;
}

void quit(ActionData& action_data){
    action_data.setDone();
    return;
}