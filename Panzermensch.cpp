// Professional coders beware. From this point on is the land of Chaos, where cursed abominations of randomly strung together columns of letters lacking
// both skill and meaning inhabit, This is the point of no return. You have been warned.
// 
//


#include <cstdlib>
#include <chrono>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// #include <json/value.h>


using namespace std;
using namespace rapidjson;



// TIME TO LEARN CLASSES.

// string mechanized_gun_support_infantry[2] = { "PZMGW-54 Battlebearer","PZMGW-22 Stormwind" }; //just for later use.

// Randomization Seed (for distance and beyond.)
void randomizer() {

    auto randomization_seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned>(randomization_seed));
}

void ascii_art_portrait()
{
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".........................................................................................................................................." << endl;
    cout << ".................@@......................................................................................................................." << endl;
    cout << "................@@@@......................................................................................................................" << endl;
    cout << "...............@@..@@....................................................................................................................." << endl;
    cout << "..............@@...@@@@@@............................................................................................@@@@@................" << endl;
    cout << ".............@@@....@@@@@@@...@@@..............................................................................@@@@@@@@@@@@@@@@@.........." << endl;
    cout << "...........@@@...........@@@@@@@@@@...........................................................................@@@@@@@.....@@@@@@@........." << endl;
    cout << "..........@@@..............@@@@..@@@.........................................................................@@................@@........." << endl;
    cout << ".........@@@......................@@@........................................................................@@.....@..........@@........." << endl;
    cout << "........@@@........................@@@...........@@@@@@@@@@@@................................................@@.................@@........" << endl;
    cout << ".....@@@@@...........................@@......@@@@@@@@@@@@@@@@@@@@@...........................................@@@@@@@@.@@..@@@@@@@........." << endl;
    cout << "...@@@@@..............................@@.@@@@@@@@............@@@@@@@@@..............................................@....................." << endl;
    cout << ".@@@@..................................@@@@@......................@@@@@@@@@@@@@....................@@@@@@@@@@@@@@@@@@.....@@@@@@@........." << endl;
    cout << " .@@...................................................................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...............@@@@@@@@@@." << endl;
    cout << ".@...............................................................................@@@@@@@@@@@@@@@@@.................@@@@@@@@....@@@@@@@@@@." << endl;
    cout << "............@@.........@@@@@@@@@@@........@@@@@@@@............................................................@@...@......@@...@.........." << endl;
    cout << "......@@............................@@@@............@@@.......................................................@@..@@......@...@@.........." << endl;
    cout << "..................@@@@@@@@@...............@@@@@@@@........@@@.................................................@@..@@......@@..@@.........." << endl;
    cout << ".........................@@@@@......................@@@.........@@@............................................@..@........@..@@.........." << endl;
    cout << ".@@@...@@@@@................@@@@@@@@@....................@@@@........@.........................................@@.@@.......@..@@.........." << endl;
    cout << ".@@@@@@@@@@@@@@@@@@@@@@@..........@@@@@@@@@@@...................@@@....@@......................................@.............@@@.........." << endl;
    cout << "........................@@@@..............@@@@@@@...................@@....@@.....................................@@@.......@@@@..........." << endl;
    cout << "..........@@@@@@@@@@@@.......@@@...............@@@@@@@................@@@.....@@@@.............................@@@@......................." << endl;
    cout << ".......@@@@@....@@@@@@@@@@@@...@@@@@@.@@...........@@@@@@@@@..............@@............@@................................................" << endl;
    cout << "....@@@@@..................@@@@.....@@@@@@..@@.........@@@@@@@@@@@@@.........@@@@@.........@@............................................." << endl;
    cout << "....@@@.......................@@@........@@@@@@@@.@@@........@@@@@@@@@@@@@..............@@........@@@@@@@................................." << endl;
    cout << "...@@..........................@@@@@............@@@..................@@@@@@@@@.............@@@...............@@..........................." << endl;
    cout << "...@..............................@@@...............@@....@@@@..............@@@@@@@@.............@@@@@@@@@.......@........................" << endl;
    cout << "...@@...............................@@@........@@@@@....@@@@@@@@@................@@@@@@@....................@@@.....@....................." << endl;
    cout << "....@@.....@@@@.......................@@@..@@@@@....@@@@........@@@@..................@@@@......................@@.....@@@................" << endl;
    cout << "....@@..................................@@@@....@@@@@..............@@@@..................@@@@......................@@.......@@@..........." << endl;
    cout << ".....@@.........................@@...........@@@@.....................@@@...................@@@@.......................@@@..........@@...." << endl;
    cout << "......@@@.@@.................@@@........@@@@@...........................@@....................@@@@.........................@@@@@.......@@." << endl;
    cout << ".......@@@@@@@....@@........@@..@@....@@@@................................@@@....................@@@@@..............................@@...." << endl;
    cout << ".........................................................................................................................................." << endl;
}

class Panzermensch {

    // I have decided to make a rudimentary game, In which there are player and enemy mechs, the two fight in turns with each having their own option.
    // In this mech game that i shall name Panzermensch, you as a player mech must kill the enemy and have to fight a Boss at the end.

    // This is basically the precursor or demo version of a much more ambitious yet achievable project that i have, of an actual Videogame with full on 3D graphics.
    // Said Videogame Will have multiplayer, easy modificability and campaigns. Its styled to be a horde shooter where you go do missions CO-OP.

public:


    // Player Stats
    string player_mech;
    int player_front_armor_health;
    int player_front_armor;
    int player_side_armor_health;
    int player_side_armor;
    int player_rear_armor_health;
    int player_rear_armor;
    int player_pilot_health;
    int player_gun_penetration;
    int player_veterancy;

    // Enemy Stats
    int front_armor_health;       // Basically Armor Integrity, for front, side and rear.
    int front_armor;              // The Armor itself, the more hits it takes, the lesser it gets (by a small magnitude), and the more its 'Health' or Integrity Decreases.
    int side_armor_health;
    int side_armor;
    int rear_armor_health;
    int rear_armor;
    int pilot_health;             // When Armor Integrity breaks, The Pilot is technically exposed, however if Said Shot penetrates armor, then it does infact damage the pilot + armor integrity.
    int veterancy;                // Unused for now. Experience, Which makes movement faster, perception better and accuracy better. It is like levels, so its integers up to 10.

    // also, all this comments are just for me to explain things to myself more so i understand better.

    // General Stats

    int primary_gun_damage;
    int gun_penetration;
    //int done_damage;
    int turn_counter = 0;
    int fortify_function_counter = 0;
    int overcharge_function_counter = 0;
    int battleshock_function_counter = 0;

    // World Stats that may or may not be used.
    bool is_player_turn = true;
    bool is_player_attacking = true;
    //bool is_player_moving = true; // Unused for now.
    bool is_overcharged = false;
    bool is_fortified = false;
    bool is_battleshocked = false;
    //int angle;                    // Unused for now... I plan on detailing this game A LOT.
    int distance = 0;
    //string terrain;               // Unused for now.
    string user_input;            // obvious.

    Panzermensch() : primary_gun_damage(500), player_gun_penetration(300), gun_penetration(300), player_front_armor(350),
        player_front_armor_health(100), player_side_armor(280), player_side_armor_health(100),
        player_rear_armor(160), player_rear_armor_health(75), player_pilot_health(600),
        player_veterancy(0), front_armor(350), front_armor_health(100), side_armor(180),
        side_armor_health(100), rear_armor(100), rear_armor_health(75),
        pilot_health(600), veterancy(0) {}

    void end_turn() {

        // gonna add a turn function here, just putting this so it doesn't fuck up my code, i hate seeing "X Errors" being more than 0.
        is_player_turn = !is_player_turn;
        if (is_fortified = true)
        {
            is_fortified = false;
        }
        else if (is_overcharged = true)
        {
            is_overcharged = false;
        }
    }

    void randomize_distance() {
        const int min_distance = 100;
        const int max_distance = 12000;
        int randomized_distance;
        randomized_distance = rand() % (max_distance - min_distance + 1) + min_distance;
        distance += randomized_distance;
    }

    void player_turn() {

        cout << "Your Turn!" << endl;
        string user_input;
        getline(cin, user_input);
        //fortify_function_checker();

        if (user_input == "Fire") 
        {
            player_combat_damage(is_player_attacking = true);
            end_turn();
        }
        else if (user_input == "Repair") 
        {
            repair_action();
            end_turn();
        }
        else if (user_input == "Fortify") 
        {
            fortify_action();
            end_turn();
        }
        else if (user_input == "Overcharge")
        {
            overcharge_action();
            end_turn();
        }
        else
        {
            cout << "What you say? I don't understand you over the Microphone! TIME WASTED!" << endl;
            end_turn();
            return;
        }
    }

    void enemy_turn() {
        if (pilot_health > 0) {
            cout << "Enemy Mech Turn! They Fire at us!" << endl;
            enemy_combat_damage(!is_player_attacking);
            end_turn();
        }
        else {
            cout << "Enemy Mech Is Broken!" << endl;
        }

    }


    void repair_action() {
        if (is_player_turn) 
        {
            if (player_pilot_health < 600) {
                player_pilot_health += 400;
                cout << "Pilot Healed!" << endl;
            }
            else if (player_pilot_health > 599) {
                cout << "Health Full! Time Wasted!" << endl;
            }
        }
    }

    void fortify_action() {
        if (is_player_turn && !is_fortified)
        {
            player_front_armor *= 2;
            player_side_armor *= 2;
            player_rear_armor *= 2;
            cout << "Armor Fortified!" << endl;
            fortify_function_counter += 1;
            is_fortified = true;
        }
        else if (!is_player_turn)
        {
            front_armor += 50;
            side_armor += 50;
            rear_armor += 25;
            cout << "Enemy Armor Fortified!" << endl;
        }
    }
    void overcharge_action() {
        if (is_player_turn && !is_overcharged)
        {
            primary_gun_damage * 1.5;
            player_gun_penetration * 1.5;
            cout << "Main Gun Overcharged!" << endl;
            is_overcharged = true;
        }
    }


    void turn_checker() {
        if (turn_counter % 2==0) 
        {
            player_front_armor /= 2;
            player_side_armor /= 2;
            player_rear_armor /= 2;
            //fortify_function_counter += 1;
        }
        else 
        {
            // do nothing
        }
    }

    void player_combat_damage(bool is_player_attacking) {          // What happens when the guns fire.

        //const int min_distance = 100;
        //const int max_distance = 12000;

        int actual_damage = 500;
        int done_damage = 0;
        int damage_multiplier = static_cast<int>(player_gun_penetration - front_armor) * 0.05f;
        int damage_falloff = 0.6915;//distance * 0.0001;

        if (is_player_attacking) {
            if (front_armor > 349) {
                if (player_gun_penetration > front_armor)
                {
                    pilot_health -= ((actual_damage * damage_multiplier));
                    done_damage += ((actual_damage * damage_multiplier));
                    cout << "Target hit in Front armor! Damaged for: " << done_damage << endl;
                }
                else if (player_gun_penetration < front_armor)
                {
                    pilot_health -= static_cast<int>((actual_damage) / 4);
                    done_damage += static_cast<int>((actual_damage) / 4);
                    cout << "Target hit! Front Armor is TOO THICK! Damaged For: " << done_damage << endl;
                }
                else
                {
                    cout << "Something's wrong with the Front Armor Value" << endl;
                };
            }
        }
    }

    void enemy_combat_damage(bool is_player_attacking) 
    {

        int actual_damage = 500;
        int done_damage = 0;
        int damage_multiplier = (gun_penetration - front_armor) * 0.05;

        if (!is_player_attacking)
        {
            if (player_front_armor > 349) {
                if (gun_penetration > player_front_armor) {
                    player_pilot_health -= (actual_damage * damage_multiplier);
                    done_damage += (actual_damage * damage_multiplier);
                    cout << "We are Hit in Front armor! Damaged for: " << done_damage << endl;
                }
                else if (gun_penetration < player_front_armor)
                {
                    player_pilot_health -= (actual_damage / 4);
                    done_damage += (actual_damage / 4);
                    cout << "We are Hit! But Their Shot could not Penetrate! Damaged for: " << done_damage << endl;
                }
            }
        }
    }
        
        




    void mech_encounter() {                // this is supposed to be what happens first, but i lack the knowledge to know.

        cout << "Enemy Mech Encountered!" << endl;
        randomize_distance();
        cout << "Rangefinder reported Distance: " << distance << " Meters." << endl;
        cout << "You have Four Actions, What do you Choose?" << endl;
        cout << "Fire | Repair | Overcharge | Fortify" << endl;

        while (player_pilot_health > 0 && pilot_health > 0) {
            if (is_player_turn) {
                player_turn();
            }
            else if (!is_player_turn) {
                enemy_turn();
              //  cout << "" << endl;
            }
        }

        if (player_pilot_health <= 0) {
            cout << "We have been Destroyed!" << endl;
        }
        else if (pilot_health <= 0)
        {
            cout << "We are Victorious! Enemy Mech Destroyed!" << endl;
        }

    }

};

// SURPRISE STORMWAFFLE


int main()
{
    //ascii_art_portrait();
    cout << "STATUS: Radio On." << endl;
    randomizer();
    Panzermensch game;
    game.mech_encounter();

    return 0;
}

