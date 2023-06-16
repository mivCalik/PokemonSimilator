#include "pokemon.h"

// Member init. list
Pokemon::Pokemon(std::string p_type, std::string p_name,int p_hp, int p_dmg, int p_PU, int p_recharge) : 
type{p_type}, name{p_name}, HP{p_hp}, damage{p_dmg}, PU_chance{p_PU}, recharge{p_recharge}
{
    std::cout << "\n\n" << type <<" Pokemon " << name << " has entered the arena.\n";
    std::cout << "Class: " << type << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << HP << std::endl;
    std::cout << "Damage: " << damage << std::endl;
};
bool Pokemon::is_dead(){return HP == 0;}
bool Pokemon::PU_attempt(){
    if(PU_counter == 0 && rand()% 101 <= PU_chance){ // rand()%101 --> 0,1,....,100
        PU_counter =recharge;
        std::cout << this->get_name() << " has initiated a power up.\n";
        return true;
    }else{
        PU_counter--;
        return false;
    }
}

std::string Pokemon::get_name() {return name;}
std::string Pokemon::get_type() {return type;}
int Pokemon::get_dmg() {return damage;}
int Pokemon::get_PU(){return PU_chance;}
int Pokemon::get_HP(){return HP;}




electricPokemon::electricPokemon(std::string type,std::string name, int hp, int dmg)
:Pokemon("Electric", name, hp, dmg, 30, 5)
{}

int electricPokemon::attack(){
    int atk = this->get_dmg();
    if(PU_attempt()){ // power up occurs
        atk *= 3; } //  300 % dmg
    return atk;
}


// wont get confuse attack when its already confused 
void electricPokemon::take_dmg(int dmg, char terr, bool is_it_confuse_atk){
    if(terr=='e' && is_it_confuse_atk){ /*wont get confuse*/}
    else if(is_it_confuse_atk){
        is_confused = true;
        confuse_count = 3;
    }
    if(is_confused){        
        confuse_count--;
        if(confuse_count == 0) is_confused =false;
    }
    this->HP -= dmg;
    if(HP < 0) HP = 0; // minimum HP:0
}



psychicPokemon::psychicPokemon(std::string type,std::string name, int hp, int dmg)
:Pokemon("Psychic", name, hp, dmg, 20, 3)
{}

int psychicPokemon::attack(char terr, bool& is_it_confuse_atk){
    int atk = this->get_dmg();
    if(terr == 'p') atk *=2;
    if(this->PU_attempt()) is_it_confuse_atk = true; 
    else is_it_confuse_atk = false;
    return atk;
}
void psychicPokemon::take_dmg(int dmg, const bool confused_opponent){
    if(!confused_opponent){HP -= dmg;}
    if(HP < 0) HP = 0;
}

