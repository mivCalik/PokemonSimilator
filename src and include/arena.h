#include "pokemon.h"

class Arena{
    public:
        void addPokemon(char,std::string, int,int);
        void simulateBattle();
        void printRoundStats();
        void printMatchResult();
        int round = 0;
        Arena(); //constructor
    private:
        electricPokemon * e_poke = NULL;
        psychicPokemon * p_poke = NULL;
        int terr_counter = 0;
        void choose_terrain(char&);
        void print_title();
};
