// Professional coders beware. From this point on is the land of Chaos, where cursed abominations of randomly strung together columns of letters lacking
// both skill and meaning inhabit, This is the point of no return. You have been warned.
// 
//

#include <cstdlib>
#include <cmath>
#include <chrono>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <sqlext.h>
//#include <sqltypes.h>
//#include <sql.h>
//#include <json/value.h>
//#include "mechs.cpp"
#include "mechs.hpp"
//#include "vehicles.hpp"


using namespace rapidjson;
using std::string;
using std::endl;
using std::cout;
using std::cin;
namespace lightwind {
    string ironman = "if you see this, it worked";
}



// TIME TO LEARN CLASSES.


// Randomization Seed (for distance and beyond.)
void randomizer() {

    auto randomization_seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned>(randomization_seed));
}

class Vehicle {

public:
    int health = 100;
    int speed = 30;
    string vehicle;
};


class Panzermensch {

    // This a rudimentary game, In which there are player and enemy mechs, the two fight in turns with each having their own options Like Fortify, Overcharge etc.
    // In this mech game that i shall name Panzermensch, you as a player mech must kill the enemy and have to fight a Boss at the end.

    // This is basically the precursor or demo version of a much more ambitious yet achievable project that i have, of an actual Videogame with full on 3D graphics.
    // Said Videogame Will have multiplayer, easy modificability and campaigns. Its styled to be a horde shooter where you go do missions CO-OP.

public:


    // Player Stats
    string player_mech = "Player";
    int player_primary_gun_damage = 0;
    int player_primary_gun_penetration = 0;
    int player_secondary_gun_damage = 0;
    int player_secondary_gun_penetration = 0;
    int player_tertiary_gun_damage = 0;
    int player_tertiary_gun_penetration = 0;
    int player_melee_damage = 0;
    int player_front_armor_health = 0;
    int player_front_armor = 0;
    int player_side_armor_health = 0;
    int player_side_armor = 0;
    int player_rear_armor_health = 0;
    int player_rear_armor = 0;
    int player_pilot_health = 0;
    int player_gun_penetration = 0;
    int player_veterancy = 0;

    // Enemy Stats
    int front_armor_health = 0;       // Armor Integrity, for front, side and rear. The more Hits The Mech takes, The more Armor Integrity decreases, Once it reaches 0, The front armor gets a massive debuff and Pilot recieves extra damage.
    int front_armor = 0;              
    int side_armor_health = 0;
    int side_armor = 0;
    int rear_armor_health = 0;
    int rear_armor = 0;
    int pilot_health = 0;             
    int veterancy = 0;                // Unused for now. Experience, Which makes movement faster, perception better and accuracy better. It is like levels, so its integers up to 10.


    // General Stats

    int primary_gun_damage = 0;
    int gun_penetration = 0;
    int secondary_gun_damage = 0;
    //int tertiary_gun_damage = 0;
    //int done_damage;

    // World Stats.
    bool is_player_turn = true;
    bool is_player_attacking = true;
    bool is_player_moving = true; // Unused for now
    bool has_selected_mech = true;
    //int angle;                    // Unused for now.
    int distance = 0;
    //string terrain;               // Unused for now.
    string user_input = "Input";            

    Panzermensch() : player_primary_gun_damage(0), primary_gun_damage(500), player_gun_penetration(0), gun_penetration(0), player_front_armor(0),
        player_front_armor_health(0), player_side_armor(0), player_side_armor_health(0),
        player_rear_armor(0), player_rear_armor_health(0), player_pilot_health(1),
        player_veterancy(0), front_armor(350), front_armor_health(0), side_armor(0),
        side_armor_health(0), rear_armor(0), rear_armor_health(0),
        pilot_health(600), veterancy(0) {}

    void end_turn() {

        is_player_turn = !is_player_turn;
    }



    void end_mech_selection() {
        has_selected_mech = !has_selected_mech;
    }

    void randomize_distance() {
        const int min_distance = 100;
        const int max_distance = 12000;
        distance = rand() % (max_distance - min_distance + 1) + min_distance;
    }

    void player_selecting_mech() {
        cout << "Choose your Mech:" << endl;
        cout << "Emperor" << " | " << "Panzer" << " | " << "Artemis" << " | " << "Aegis" << " | " << "Generic" << endl;
        getline(cin, user_input);
        if (user_input == "Generic")
        {
            player_pilot_health += (mech_generic::mech_generic().pilot_health - 1);
            player_front_armor += mech_generic::mech_generic().front_armor;
            player_primary_gun_damage += mech_generic::mech_generic().primary_gun_damage;
            player_primary_gun_penetration += mech_generic::mech_generic().primary_gun_penetration;
            player_secondary_gun_damage += mech_generic::mech_generic().secondary_gun_damage;
            player_secondary_gun_penetration += mech_generic::mech_generic().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_generic::mech_generic().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_generic::mech_generic().tertiary_gun_penetration;
            player_melee_damage += mech_generic::mech_generic().melee_damage;
            player_front_armor += mech_generic::mech_generic().front_armor;
            end_mech_selection();
        }
        else if (user_input == "Emperor")
        {
            player_pilot_health += (mech_emperor::mech_emperor().pilot_health - 1);
            player_front_armor += mech_emperor::mech_emperor().front_armor;
            player_primary_gun_damage += mech_emperor::mech_emperor().primary_gun_damage;
            player_primary_gun_penetration += mech_emperor::mech_emperor().primary_gun_penetration;
            player_secondary_gun_damage += mech_emperor::mech_emperor().secondary_gun_damage;
            player_secondary_gun_penetration += mech_emperor::mech_emperor().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_emperor::mech_emperor().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_emperor::mech_emperor().tertiary_gun_penetration;
            player_melee_damage += mech_emperor::mech_emperor().melee_damage;
            player_front_armor += mech_emperor::mech_emperor().front_armor;
            end_mech_selection();
        }
        else if (user_input == "Panzer")
        {
            player_pilot_health += (mech_panzer::mech_panzer().pilot_health - 1);
            player_front_armor += mech_panzer::mech_panzer().front_armor;
            player_primary_gun_damage += mech_panzer::mech_panzer().primary_gun_damage;
            player_primary_gun_penetration += mech_panzer::mech_panzer().primary_gun_penetration;
            player_secondary_gun_damage += mech_panzer::mech_panzer().secondary_gun_damage;
            player_secondary_gun_penetration += mech_panzer::mech_panzer().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_panzer::mech_panzer().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_panzer::mech_panzer().tertiary_gun_penetration;
            player_melee_damage += mech_panzer::mech_panzer().melee_damage;
            player_front_armor += mech_panzer::mech_panzer().front_armor;
            end_mech_selection();
        }
        else if (user_input == "Artemis")
        {
            player_pilot_health += (mech_artemis::mech_artemis().pilot_health - 1);
            player_front_armor += mech_artemis::mech_artemis().front_armor;
            player_primary_gun_damage += mech_artemis::mech_artemis().primary_gun_damage;
            player_primary_gun_penetration += mech_artemis::mech_artemis().primary_gun_penetration;
            player_secondary_gun_damage += mech_artemis::mech_artemis().secondary_gun_damage;
            player_secondary_gun_penetration += mech_artemis::mech_artemis().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_artemis::mech_artemis().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_artemis::mech_artemis().tertiary_gun_penetration;
            player_melee_damage += mech_artemis::mech_artemis().melee_damage;
            player_front_armor += mech_artemis::mech_artemis().front_armor;
            end_mech_selection();
        }
        else if (user_input == "Aegis")
        {
            player_pilot_health += (mech_aegis::mech_aegis().pilot_health - 1);
            player_front_armor += mech_aegis::mech_aegis().front_armor;
            player_primary_gun_damage += mech_aegis::mech_aegis().primary_gun_damage;
            player_primary_gun_penetration += mech_aegis::mech_aegis().primary_gun_penetration;
            player_secondary_gun_damage += mech_aegis::mech_aegis().secondary_gun_damage;
            player_secondary_gun_penetration += mech_aegis::mech_aegis().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_aegis::mech_aegis().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_aegis::mech_aegis().tertiary_gun_penetration;
            player_melee_damage += mech_aegis::mech_aegis().melee_damage;
            player_front_armor += mech_aegis::mech_aegis().front_armor;
            end_mech_selection();
        }
        else 
        {
            cout << "Try again." << endl;
        }
        
    }

    void player_turn() {

        cout << "Your Turn!" << endl;
        string user_input;
        getline(cin, user_input);

        if (user_input == "Fire") 
        {
            player_combat_damage();
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
            enemy_combat_damage();
            cout << "If you see this, Enemy_Turn works." << endl;
            end_turn();
        }
        else {
            cout << "Enemy Mech Is Broken!" << endl;
        }

    }


    void repair_action() {
        if (is_player_turn) 
        {
            if (player_pilot_health < 350) {
                player_pilot_health += 400;
                cout << "Pilot Healed!" << endl;
                end_turn();
            }
            else if (side_armor_health < 100) {
                side_armor_health += 20;
                cout << "Pilot Healed!" << endl;
                end_turn();
            }
            else if (rear_armor_health < 75) {
                rear_armor_health += 15;
                cout << "Pilot Healed!" << endl;
                end_turn();
            }
        }
        else if (!is_player_turn)
        {
            if (pilot_health < 350) {
                pilot_health += 100;
                cout << "Enemy Pilot Healed!" << endl;
                end_turn();
            }
            else if (side_armor_health < 100) {
                side_armor_health += 20;
                cout << "Enemy Pilot Healed!" << endl;
                end_turn();
            }
            else if (rear_armor_health < 75) {
                rear_armor_health += 15;
                cout << "Enemy Pilot Healed!" << endl;
                end_turn();
            }
        }
    }

    void fortify_action() {
        if (is_player_turn)
        {
            player_front_armor + 150;
            player_side_armor + 150;
            player_rear_armor + 75;
            cout << "Armor Fortified!" << endl;
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
        if (is_player_turn)
        {
            primary_gun_damage *= 1.5;
            player_gun_penetration *= 1.1;
            cout << "Main Gun Overcharged!" << endl;
        }
    }

    void enemy_overcharge_action() {
        if (!is_player_turn)
        {
            primary_gun_damage *= 1.5;
            gun_penetration *= 1.5;
            cout << "Enemy Main Gun Overcharged!" << endl;
        }
    }

    void player_combat_damage() {          // What happens when the guns fire.

        int actual_damage = player_primary_gun_damage;
        int done_damage = 0;
        int damage_multiplier = (player_primary_gun_penetration - front_armor) * 0.05;

        if (is_player_attacking=true) {
            if (front_armor > 0) {
                if (player_primary_gun_penetration > front_armor)
                {
                    actual_damage*=damage_multiplier;
                    pilot_health -= actual_damage;
                    done_damage += (actual_damage * damage_multiplier);
                    cout << "Target hit in Front armor! Damaged for: " << done_damage << endl;
                    end_combat_turn();
                }
                else if (player_primary_gun_penetration = front_armor)
                {
                    actual_damage/=2;
                    pilot_health -= actual_damage;
                    done_damage += (actual_damage / 2);
                    cout << "Target hit! Front Armor is thick! Damaged for: " << done_damage << endl;
                    end_combat_turn();
                }
                else if (player_primary_gun_penetration < front_armor)
                {
                    actual_damage/=4;
                    pilot_health -= actual_damage;
                    done_damage += (actual_damage / 4);
                    cout << "Target hit! Front Armor is TOO THICK! Damaged For: " << done_damage << endl;
                    end_combat_turn();
                }
                else
                {
                    cout << "Something's wrong with the Front Armor Value" << endl;
                };
            }
        }
    }

    void enemy_combat_damage() 
    {
        int enemy_actual_damage = 500;
        int enemy_done_damage = 0;
        int enemy_gun_penetration = 300;
        int damage_multiplier = (enemy_gun_penetration - player_front_armor) * 0.05;

        if (is_player_attacking=true)
        {
            if (player_front_armor > 0) {
                if (enemy_gun_penetration > player_front_armor) {
                    player_pilot_health -= (enemy_actual_damage * damage_multiplier);
                    enemy_done_damage += (enemy_actual_damage * damage_multiplier);
                    cout << "We are Hit in Front armor! Damaged for: " << enemy_done_damage << endl;
                }
                else if (enemy_gun_penetration = player_front_armor)
                {
                    player_pilot_health -= (enemy_actual_damage / 2);
                    enemy_done_damage += (enemy_actual_damage / 2);
                    cout << "We are Hit! But Front Armor Held! Damaged for: " << enemy_done_damage << endl;
                }
                else if (enemy_gun_penetration < player_front_armor)
                {
                    player_pilot_health -= (enemy_actual_damage / 4);
                    enemy_done_damage += (enemy_actual_damage / 4);
                    cout << "We are Hit! Their Shot Penetrated! Damaged for: " << enemy_done_damage << endl;
                }
            }
        }
        else
        {
            cout << "This means that Combat Function is NOT accessed." << endl;
        }
    }
        
        
    void end_combat_turn() {
        is_player_attacking = !is_player_attacking;
    }



    void mech_encounter() {                // The Ignition, Basically the First Function that Initiates everything.

        cout << "Enemy Mech Encountered!" << endl;
        randomize_distance();
        cout << "Rangefinder reported Distance: " << distance << " Meters." << endl;

        while (player_pilot_health > 0 && pilot_health > 0) {
            if (is_player_turn) {
                if (has_selected_mech) 
                {
                    player_selecting_mech();
                }
                else if (!has_selected_mech){
                    player_turn();
                }
            }
            else if (!is_player_turn) {
                enemy_turn();
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
    cout << "STATUS: Radio On." << endl;
    randomizer();
    Panzermensch game;
    game.mech_encounter();

    return 0;
}

