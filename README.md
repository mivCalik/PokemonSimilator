<br><br>
# !!! THIS project includes INHERITANCE - C++  
<br>

# PokemonSimilator
PokemonSimulator Assignment from OOP lecture (ITU BLG252E) with minor changes
Assignment details are in the pdf document. 

  

1. first COMPILE : ```g++ *.cpp -I *.h -o pokemon```

2. then RUN:  ```./pokemon```

<br>

## ADD your pokemons and battle

\# You can change variable names written in <> 

inside main():
1. create a Arena object like

```
    Arena <my_arena>;
```

2. add one electric one psychic pokemon
 ```
    <my_arena>.addPokemon(<string pokemon_name>, 'e', <int HP>, <int ATK>);
    <my_arena>.addPokemon(<string pokemon_name>, 'p', <int HP>, <int ATK>);  
 ```
 3. simulate battle
 ```
    <my_arena>.simulateBattle();
 ```
 
 ## Example output
 
 ![image](https://github.com/mivCalik/PokemonSimilator/assets/57195581/602a7f26-1204-4652-be08-7bbbb3a3a840)

 
