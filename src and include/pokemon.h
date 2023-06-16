#include "ctime" // when srand(time(NULL)) used
#include <iostream>
#include <cstdlib>

class Pokemon{
    public:
        Pokemon(std::string, std::string,int,int,int,int);   
        bool is_dead(); 
        std::string get_name() ;
        int get_HP();  
    protected:
        int HP;
        int recharge_count;   
		int PU_counter;
        std::string get_type() ;
        int get_dmg();
        int get_PU();
        bool PU_attempt();
        
    private:
        const std::string name;
        const std::string type;
        const int damage;
        const int PU_chance; // pertantage value
		const int recharge;
};


class electricPokemon:public Pokemon{
    public:
		electricPokemon(std::string,std::string,int,int);        
        int attack();
        void take_dmg(int, char, bool);
        bool is_confused = false; // for starters  
    private:
		int confuse_count=0
    ;
};



class psychicPokemon:public Pokemon{
    public:
        psychicPokemon(std::string,std::string,int,int);
        int attack(char terrain, bool&);  
        void take_dmg(int,const bool);
    private:

};