#include "arena.h"

Arena::Arena(){print_title();}

void Arena::print_title(){
    std::cout << "\n";
    std::cout << "                                 ,'\\" << std::endl;
    std::cout << "    _.----.        ____         ,'  _\\   ___    ___     ____" << std::endl;
    std::cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << std::endl;
    std::cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << std::endl;
    std::cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << std::endl;
    std::cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << std::endl;
    std::cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << std::endl;
    std::cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << std::endl;
    std::cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << std::endl;
    std::cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << std::endl;
    std::cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << std::endl;
    std::cout << "                               `'                            '-._|" << std::endl;
}

/* Adds only ELECTRIC or PSYCHIC*/
void Arena::addPokemon(char type,std::string name, int init_hp, int dmg){
    if(type == 'e')
        e_poke = new electricPokemon("Electric",name,init_hp,dmg);
    else if(type == 'p')
        p_poke =  new psychicPokemon("Psychic", name, init_hp, dmg);   
}

void Arena::choose_terrain(char& terr){
    if (terr_counter == 0){
        int x = rand() % 5;
        if(x==2) {terr= 'p'; terr_counter = 5;} // 20%
        else if (x==1) {terr ='e';terr_counter = 5;} // 20%
        else terr = 'n'; //60%
    }
    terr_counter--; // terrain wont change

    if(terr == 'n') std::cout << "Current Terrain: none\n";
    else if(terr == 'p') std::cout << "Current Terrain: psychic\n";
    else if (terr == 'e') std::cout << "Current Terrain: electric\n";
}

void Arena::simulateBattle(){

    bool coin;
    std::string first_name;
    char t_type = 'n'; // start with none
    bool is_it_confuse_atk = false;

    while(!e_poke->is_dead() && !p_poke->is_dead()){
        std::cout << "\n\nRound: " << ++round << std::endl;
        coin = rand() %2;
        choose_terrain(t_type);
        if (coin){
            std::cout << e_poke->get_name() <<" goes first.\n";
            p_poke->take_dmg(e_poke->attack(),e_poke->is_confused);
            e_poke->take_dmg(p_poke->attack(t_type,is_it_confuse_atk), t_type, is_it_confuse_atk);
        }else{
            std::cout << p_poke->get_name() <<" goes first.\n";
            e_poke->take_dmg(p_poke->attack(t_type,is_it_confuse_atk), t_type, is_it_confuse_atk);
            p_poke->take_dmg(e_poke->attack(),e_poke->is_confused);
        }
        printRoundStats();
    }
    printMatchResult();

    delete e_poke;
    delete p_poke;
    round = 0;
    terr_counter = 0;
}

void Arena::printRoundStats(){
    std::cout << e_poke->get_name() << " HP: " << e_poke->get_HP() << std::endl;
    std::cout << p_poke->get_name() << " HP: " << p_poke->get_HP() << std::endl;

    if(e_poke->get_HP() < p_poke->get_HP())
        std::cout << p_poke->get_name() << " is in the lead!\n";
    else
        std::cout << e_poke->get_name() << " is in the lead!\n";
}

void Arena::printMatchResult(){
    std::cout << "\n\nMatch Results:\n";

    if(p_poke->get_HP() == 0)
        std::cout << e_poke->get_name() << " has won the match!\n";
    else
        std::cout << p_poke->get_name() << " has won the match!\n";
}

/*
                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|
*/

