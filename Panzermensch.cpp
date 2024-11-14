// Professional coders beware. From this point on is the land of Chaos, where cursed abominations of randomly strung together columns of letters lacking
// both skill and meaning inhabit, This is the point of no return. You have been warned.
// 
//

#include <cstdlib>
#include <cmath>
#include <chrono>
//#include <rapidjson/document.h>
//#include <rapidjson/filereadstream.h>
//#include <rapidjson/istreamwrapper.h>
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

using namespace std;
//using namespace rapidjson;
namespace lightwind {
    string ironman = "if you see this, it worked";
}

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

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
    string player_primary_gun_name = "Gun";
    float player_primary_gun_damage = 0;
    float player_unmodified_primary_gun_damage = 0;
    float player_primary_gun_penetration = 0;
    float player_unmodified_primary_gun_penetration = 0;
    float player_secondary_gun_damage = 0;
    float player_secondary_gun_penetration = 0;
    float player_tertiary_gun_damage = 0;
    float player_tertiary_gun_penetration = 0;
    float player_melee_damage = 0;
    float player_front_armor_health = 0;
    float player_front_armor = 0;
    float player_unmodified_front_armor = 0;
    float player_side_armor_health = 0;
    float player_side_armor = 0;
    float player_rear_armor_health = 0;
    float player_rear_armor = 0;
    float player_pilot_health = 0;
    float player_unmodified_pilot_health = 0;
    float player_gun_penetration = 0;
    float player_veterancy = 0;

    // Enemy Stats
    string enemy_mech = "Enemy";
    int enemy_mech_id = 0;
    float primary_gun_damage = 0;
    float unmodified_primary_gun_damage = 0;
    float primary_gun_penetration = 0;
    float unmodified_primary_gun_penetration = 0;
    float secondary_gun_damage = 0;
    float secondary_gun_penetration = 0;
    float tertiary_gun_damage = 0;
    float tertiary_gun_penetration = 0;
    float melee_damage = 0;
    float front_armor_health = 0;       // Armor Integrity, for front, side and rear. The more Hits The Mech takes, The more Armor Integrity decreases, Once it reaches 0, The front armor gets a massive debuff and Pilot recieves extra damage.
    float front_armor = 0;         
    float unmodified_front_armor = 0;
    float side_armor_health = 0;
    float side_armor = 0;
    float rear_armor_health = 0;
    float rear_armor = 0;
    float pilot_health = 0;   
    float unmodified_pilot_health = 0;
    float veterancy = 0;                // Unused for now. Experience, Which makes movement faster, perception better and accuracy better. It is like levels, so its integers up to 10.
    int ai_overcharge_weight = 4;
    float ai_overcharge_chance = 0;
    int ai_fortify_weight = 4;
    float ai_fortify_chance = 0;
    int ai_repair_weight = 4;
    float ai_repair_chance = 0;
    int ai_fire_weight = 6;
    float ai_fire_chance = 0;
    int ai_aggression = 50;
    int ai_defensiveness = 50;
    float ai_decision_chance = 0;
    int ai_fortify_counter = 0;
    int ai_overcharge_counter = 0;


    // General Stats
    int turn_count = 0;
    int turn_skip_chance_dice = 2;
    int turn_skip_chance_roll = 0;
    int accuracy_modifier = 90;
    int movement_speed_modifier = 100;
    int accuracy_roll = 0;
    int ai_accuracy_roll = 0;
    int ai_accuracy_modifier = 90;
    int dice = 6;
    int dice_result = 0;
    int dice2 = 4;
    int dice3 = 4;
    int dice2_result = 0;
    int dice3_result = 0;
    int ai_mech_dice = 4;
    float damage_multiplier = 0;
    float damage_multiplier_percentage = 0;
    float enemy_damage_multiplier = 0;
    float enemy_damage_multiplier_percentage = 0;
    float actual_damage = 0;
    float done_damage = 0;
    float distance_float = 0;
    float actual_penetration = 0;
    float damage_distance_multiplier = 0;
    float penetration_distance_multiplier = 0;
    float enemy_actual_damage = 0;
    float enemy_done_damage = 0;
    float enemy_distance_float = 0;
    float enemy_actual_penetration = 0;
    float enemy_damage_distance_multiplier = 0;
    float enemy_penetration_distance_multiplier = 0;

    // World Stats.
    const double PI = std::atan(1.0) * 4;
    bool is_player_turn = true;
    bool is_player_attacking = true;
    bool is_player_moving = true; // Unused for now
    bool has_selected_mech = true;
    bool ai_has_selected_mech = true;
    bool is_fortified = false;
    bool is_ai_fortified = false;
    bool has_ai_fortified_once = false;
    bool is_overcharged = false; // Equal False by default.
    bool is_ai_overcharged = false;
    bool has_ai_overcharged_once = false;
    bool is_terrain_on = true;
    bool case_1_hit = false;
    bool case_2_hit = false;
    bool case_3_hit = false;
    bool case_4_hit = false;
    //bool is_effect_on = true;
    int ai_mech_roll = 0;
    const int min_distance = 100;
    const int max_distance = 12000;
    int distance = 0;
    string terrain;               // Unused for now.
    string terrain_modifier_id_1 = "Plains";  // Plains
    string terrain_modifier_id_2 = "Mountains"; // Mountains
    string terrain_modifier_id_3 = "Hills"; // Hills
    string terrain_modifier_id_4 = "Tundra"; // Arctic
    string user_input = "Input";            

    Panzermensch() : player_primary_gun_damage(0), primary_gun_damage(0), player_gun_penetration(0), primary_gun_penetration(0), player_front_armor(0),
        player_front_armor_health(0), player_side_armor(0), player_side_armor_health(0), secondary_gun_damage(0), secondary_gun_penetration(0),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), melee_damage(0), player_rear_armor(0), player_rear_armor_health(0), player_pilot_health(1),
        player_veterancy(0), front_armor(0), front_armor_health(0), side_armor(0),
        side_armor_health(0), rear_armor(0), rear_armor_health(0),
        pilot_health(1), veterancy(0) {}

    void debug_values() {  // Debug, Duh.
        cout << "---->>Enemy Front Armor: " << front_armor << endl;
        cout << "---->>Player Front Armor: " << player_front_armor << endl;
        cout << "---->>Enemy Primary Gun Damage: " << primary_gun_damage << endl;
        cout << "---->>Enemy Primary Gun Penetration: " << primary_gun_penetration << endl;
        cout << "---->>Player Primary Gun Damage: " << player_primary_gun_damage << endl;
        cout << "---->>Player Primary Gun Penetration: " << player_primary_gun_penetration << endl;
    }

    void end_turn() {  // Ends Turn Of Current Person.
        is_player_turn = !is_player_turn;
    }

    void end_mech_selection() { // Sets Player Selection Bool to True. Assigned when Player Selects Mech.
        has_selected_mech = !has_selected_mech;
    }

    void end_ai_mech_selection() { // Ends AI Mech Selection. Sets Ai Mech Selection Bool to True.
        ai_has_selected_mech = !ai_has_selected_mech;
    }

    void fortify_switch_on() {   // ON Switch for Player Fortify Flag.
        is_fortified = true;
    }

    void fortify_switch_off() {   // OFF Switch for Player Fortify Flag.
        is_fortified = false;
    }

    void ai_fortify_switch_on() {   // ON Switch for AI Fortify Flag.
        is_ai_fortified = true;
    }

    void ai_fortify_switch_off() {   // OFF Switch for AI Fortify Flag.
        is_ai_fortified = false;
    }
    
    void overcharge_switch_on() {   // ON Switch for Player Overcharge Flag.
        is_overcharged = true;
    }
    
    void overcharge_switch_off() {   // OFF Switch for Player Overcharge Flag.
        is_overcharged = false;
    }

    void ai_overcharge_switch_on() {   // ON Switch for AI Overcharge Flag.
        is_ai_overcharged = true;
    }

    void ai_overcharge_switch_off() {  // OFF Switch for AI Overcharge Flag.
        is_ai_overcharged = false;
    }

    void unfortify() {   // Checks if Person is Fortified, If more than one turn, It removes the Modifiers so they aren't permanent.
        if (is_player_turn && is_fortified)
        {
            player_front_armor -= (player_unmodified_front_armor * 0.15);
            fortify_switch_off();
        }
        else if (!is_player_turn && is_ai_fortified)
        {
            front_armor -= (unmodified_front_armor * 0.15);
            ai_fortify_switch_off();
        }
        else //DEBUG
        {
            //cout << "Fortified is False!" << endl;
        }
    }

    void unovercharge() { // Checks if Person Has already been Overcharged, If they are, It Removes the Modifiers So they can't fire Endlessly with the same power as being Overcharged.
        if (is_player_turn && is_overcharged)
        {
            player_primary_gun_damage /= 2;
            player_primary_gun_penetration -= (player_unmodified_primary_gun_penetration * 0.25);
            overcharge_switch_off();
        }
        else if (!is_player_turn && is_ai_overcharged)
        {
            primary_gun_damage /= 2;
            primary_gun_penetration -= (unmodified_primary_gun_penetration * 0.25);
            ai_overcharge_switch_off();
            //cout << YELLOW << "AI Unovercharged" << RESET << endl;
        }
        else //DEBUG
        {
            //cout << "Overcharge is False!" << endl;
        }
    }

    void weight_limiter() {    // Limits Weights to 10 So it doesn't increase to the point where No other option can be picked but the oversized option.
        if (ai_fire_weight>10)
        {
            ai_fire_weight = 10;
            ai_fire_weight -= 3;
        }
        else if (ai_fortify_weight > 10)
        {
            ai_fortify_weight = 10;
            ai_fortify_weight -= 3;
        }
        else if (ai_overcharge_weight > 10)
        {
            ai_overcharge_weight = 10;
            ai_overcharge_weight -= 3;
        }
        else if (ai_repair_weight > 10)
        {
            ai_repair_weight = 10;
            ai_repair_weight -= 3;
        }
    }

    void ai_weight_analysis() {  // Analyzes the Weight of all Options based on the Situation.
        float enemy_pilot_percentage = (unmodified_pilot_health * 0.14);
        float enemy_pilot_health_percentage = (unmodified_pilot_health * 0.86);
        float player_pilot_percentage = (player_unmodified_pilot_health * 0.14);
        if (player_front_armor > front_armor)
        {
            
            if (has_ai_fortified_once)
            {
                ai_fortify_weight -= 1;
                ai_fire_weight += 1;
                ai_overcharge_weight += 1;
            }
            else
            {
                ai_fire_weight -= 1;
                ai_fortify_weight += 1;
                ai_overcharge_weight += 1;
            }
        }
        else if (player_front_armor == front_armor || player_front_armor == primary_gun_penetration)
        {
            ai_fire_weight += 1;
            ai_overcharge_weight += 1;
        }
        else if (player_front_armor < front_armor || player_front_armor < primary_gun_penetration)
        {
            if (has_ai_overcharged_once)
            {
                ai_fire_weight += 5;
            }
            else
            {
                ai_fortify_weight -= 2;
                ai_overcharge_weight += 2;
            }
        }
        else if (pilot_health < enemy_pilot_health_percentage)
        {
            ai_repair_weight += 1;
        }
        else if (player_front_armor > front_armor || player_front_armor > primary_gun_penetration)
        {
            ai_fortify_weight += 1;
            ai_overcharge_weight += 1;
        }
        else { //DEBUG
            cout << "Weight Analysis is Faulty!" << endl;
        }
        weight_limiter();
    }
    
    void ai_decision_making() { // The AI Brain, Applies Weight into Chances and Picks Decisions based on the Chance.
        //ai_weight_analysis();

        ai_fire_chance = ((rand() % dice3) + ai_fire_weight);
        cout << ai_fire_chance << " FIRE CHANCE!" << endl;
        ai_fortify_chance = ((rand() % dice3) + ai_fortify_weight);
        cout << ai_fire_chance << " FORTIFY CHANCE!" << endl;
        ai_overcharge_chance = ((rand() % dice3) + ai_overcharge_weight);
        cout << ai_overcharge_chance << " OVERCHARGE CHANCE!" << endl;
        ai_repair_chance = ((rand() % dice3) + ai_repair_weight);
        cout << ai_repair_chance << " REPAIR CHANCE!" << endl;

        if (ai_fire_chance > ai_fortify_chance && ai_fire_chance > ai_overcharge_chance && ai_fire_chance > ai_repair_chance) {
            cout << "They Fire on Us!" << endl;
            enemy_combat_damage();
            unovercharge();
        }
        else if (ai_fortify_chance > ai_fire_chance && ai_fortify_chance > ai_overcharge_chance && ai_fortify_chance > ai_repair_chance)
        {
            ai_fortify_action();
            ai_fortify_weight -= 2;
            ai_overcharge_weight += 1;
            ai_fire_weight += 1;
            ai_fortify_counter += 1;
            has_ai_fortified_once = !has_ai_fortified_once;
        }
        else if (ai_overcharge_chance > ai_fire_chance && ai_overcharge_chance > ai_fortify_chance && ai_overcharge_chance > ai_repair_chance && is_overcharged)
        {
            enemy_combat_damage();
            unovercharge();
        }
        else if (ai_overcharge_chance == ai_fire_chance || ai_overcharge_chance == ai_fortify_chance || ai_overcharge_chance == ai_repair_chance || is_overcharged)
        {
            enemy_combat_damage();
            unovercharge();
        }
        else if (ai_overcharge_chance > ai_fire_chance && ai_overcharge_chance > ai_fortify_chance && ai_overcharge_chance > ai_repair_chance)
        {
            ai_overcharge_action();
            ai_overcharge_weight -= 3;
            ai_fire_weight += 1;
            ai_overcharge_counter += 1;
            has_ai_overcharged_once = !has_ai_overcharged_once;
        }
        else if (ai_repair_chance > ai_fire_chance && ai_repair_chance > ai_overcharge_chance && ai_repair_chance > ai_fortify_chance)
        {
            repair_action();
            ai_repair_weight -= 2;
        }
        else
        {
            enemy_combat_damage();
            unovercharge();
        }
    }
    
    void turn_skip_chance() {     // Still Unused Ability/Function/Effect made to roll a Dice to see if Turns would get Skipped.
        turn_skip_chance_roll = (rand() % turn_skip_chance_dice) + 0;
        switch (turn_skip_chance_roll)
        {
        case(1):
            //case_4_hit = false;
            break;
        case(2):
            end_turn();
            cout << "Turn Skipped! Low Vision!" << endl;
            break;
        default:
            cout << "Turn Not Skipped." << endl;
            break;
        }
    }


    void terrain_roll() {   // Rolls Dice for Terrain Choice.
        dice2_result = (rand() % dice2) + 0;
    }

    void terrain_modifier() {    // Terrain Assigner, Also Adds the Modifiers of the Terrain.
        is_terrain_on = true;
        terrain_roll();
        int terrain_roll = dice2_result;
        switch (terrain_roll)
        {
        case(1):
            cout << "Terrain: " << BRIGHT_BLUE << terrain_modifier_id_1 << RESET << endl;
            break;
        case(2):
            cout << "Terrain: " << BRIGHT_BLUE << terrain_modifier_id_2 << RESET << endl;
            accuracy_modifier -= 40;
            ai_accuracy_modifier -= 40;
            movement_speed_modifier -= 50;
            break;
        case(3):
            cout << "Terrain: " << BRIGHT_BLUE << terrain_modifier_id_3 << RESET << endl;
            accuracy_modifier -= 20;
            ai_accuracy_modifier -= 20;
            movement_speed_modifier -= 25;
            break;
        case(4):
            cout << "Terrain: " << BRIGHT_BLUE << terrain_modifier_id_4 << RESET << endl;
            accuracy_modifier -= 50;
            break;
        default:
            cout << "Terrain: " << BRIGHT_BLUE << terrain_modifier_id_1 << RESET << endl;
            break;
        }
    }

    void diceroll() {      // Dice Roll meant for Day Modifier Choice.
        dice_result = (rand() % dice) + 1;
    }

    void ai_mech_dice_roll() {   // Dice Roll for AI Mech Choosing
        ai_mech_roll = (rand() % ai_mech_dice) + 1;
    }
     
    void modifier_checker() {       // Supposed to check modifiers, So if its Terrain X, it Applies its Values and makes sure it is applied.
        if (is_terrain_on)
        {
            terrain_modifier();
        }
    }

    void random_effects() {       // Supposed to be The Day Modifier Assignor, To Actually Apply the Modifiers.
        if (case_1_hit)
        {
            //Nothing.
        }
        else if (case_2_hit)
        {
            player_primary_gun_damage -= (player_unmodified_primary_gun_damage * (1 - 0.12));
            //cout << "Random Effects 2 Is Active!" << endl;
        }
        else if (case_3_hit)
        {
            front_armor -= (front_armor * (1 - 0.4));
            player_front_armor -= (player_front_armor * (1 - 0.4));
            //cout << "Random Effects 3 Is Active!" << endl;
        }
        else if (case_4_hit)
        {
            //Nothing.
        }
        else
        {
            //cout << "Effects Modifier Didn't Work!" << endl;
        }
    }

    void random_effects_choice() {        // Day Modifier Roller

        int effect_roll = dice_result;

        switch (effect_roll)
        {
        case (1):
            case_1_hit = true;
            cout << RED << "Terrain Unstable!" << RESET << endl;
            cout << RED << "-35% Accuracy." << RESET << endl;
            accuracy_modifier -= 35;
            break;
        case (2):
            case_2_hit = true;
            cout << RED << "Humid Weather." << RESET << endl;
            cout << RED << "Damage Reduced!" << RESET << endl;

            break;
        case (3):
            case_3_hit = true;
            cout << RED << "Night of a Bad Omen!" << RESET << endl;
            cout << RED << "-50% Accuracy!" << RESET << endl;
            cout << RED << "-80% Armor Effectiveness!" << RESET << endl;
            accuracy_modifier -= 50;
            ai_accuracy_modifier -= 25;
            break;
        case (4):
            case_4_hit = true;
            cout << BRIGHT_RED << "Immense Fog." << RESET << endl;
            cout << RED << "-50% Accuracy!" << RESET << endl;
            accuracy_modifier -= 50;
            ai_accuracy_modifier -= 25;
            break;
        case (5):
            cout << GREEN << "Night of a Good Omen!" << RESET << endl;
            cout << GREEN << "+50% Accuracy!" << RESET << endl;
            //cout << GREEN << "+50% Chance to Penetrate!" << RESET << endl;
            accuracy_modifier += 50;
            break;
        default:
            cout << BRIGHT_GREEN << "Everything seems Fine today." << RESET << endl;
            break;
        }
    }

    void randomize_distance() {       // Randomizes Distance.
        distance = rand() % (max_distance - min_distance + 1) + min_distance;
    }

    void player_selecting_mech() {       // Player Mech Selection Function.
        cout << "Choose your Mech:" << endl;
        cout << YELLOW << "Emperor" << RESET << " | " << BRIGHT_BLACK << "Panzer" << RESET << " | " << BLUE << "Artemis" << RESET << " | " << BRIGHT_CYAN << "Aegis" << RESET << " | " << BRIGHT_YELLOW << "Generic" << RESET << endl;
        getline(cin, user_input);
        if (user_input == "Generic")
        {
            player_pilot_health += (mech_generic::mech_generic().pilot_health - 1);
            player_unmodified_pilot_health += mech_generic::mech_generic().pilot_health;
            player_front_armor += mech_generic::mech_generic().front_armor;
            player_unmodified_front_armor += mech_generic::mech_generic().front_armor;
            player_primary_gun_damage += mech_generic::mech_generic().primary_gun_damage;
            player_unmodified_primary_gun_damage += mech_generic::mech_generic().primary_gun_damage;
            player_primary_gun_penetration += mech_generic::mech_generic().primary_gun_penetration;
            player_unmodified_primary_gun_penetration += mech_generic::mech_generic().primary_gun_penetration;
            player_secondary_gun_damage += mech_generic::mech_generic().secondary_gun_damage;
            player_secondary_gun_penetration += mech_generic::mech_generic().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_generic::mech_generic().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_generic::mech_generic().tertiary_gun_penetration;
            player_melee_damage += mech_generic::mech_generic().melee_damage;
            player_primary_gun_name = mech_generic::mech_generic().primary_gun;
            cout << "You Chose The Mech " << BRIGHT_GREEN << mech_generic::mech_generic().mech_name << RESET << endl;
            end_mech_selection();
        }
        else if (user_input == "Emperor")
        {
            player_pilot_health += (mech_emperor::mech_emperor().pilot_health - 1);
            player_unmodified_pilot_health += mech_emperor::mech_emperor().pilot_health;
            player_front_armor += mech_emperor::mech_emperor().front_armor;
            player_unmodified_front_armor += mech_emperor::mech_emperor().front_armor;
            player_primary_gun_damage += mech_emperor::mech_emperor().primary_gun_damage;
            player_unmodified_primary_gun_damage += mech_emperor::mech_emperor().primary_gun_damage;
            player_primary_gun_penetration += mech_emperor::mech_emperor().primary_gun_penetration;
            player_unmodified_primary_gun_penetration += mech_emperor::mech_emperor().primary_gun_penetration;
            player_secondary_gun_damage += mech_emperor::mech_emperor().secondary_gun_damage;
            player_secondary_gun_penetration += mech_emperor::mech_emperor().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_emperor::mech_emperor().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_emperor::mech_emperor().tertiary_gun_penetration;
            player_melee_damage += mech_emperor::mech_emperor().melee_damage;
            player_primary_gun_name = mech_emperor::mech_emperor().primary_gun;
            cout << "You Chose The Mech " << BRIGHT_GREEN << mech_emperor::mech_emperor().mech_name << RESET << endl;
            end_mech_selection();
        }
        else if (user_input == "Panzer")
        {
            player_pilot_health += (mech_panzer::mech_panzer().pilot_health - 1);
            player_unmodified_pilot_health += mech_panzer::mech_panzer().pilot_health;
            player_front_armor += mech_panzer::mech_panzer().front_armor;
            player_unmodified_front_armor += mech_panzer::mech_panzer().front_armor;
            player_primary_gun_damage += mech_panzer::mech_panzer().primary_gun_damage;
            player_unmodified_primary_gun_damage += mech_panzer::mech_panzer().primary_gun_damage;
            player_primary_gun_penetration += mech_panzer::mech_panzer().primary_gun_penetration;
            player_unmodified_primary_gun_penetration += mech_panzer::mech_panzer().primary_gun_penetration;
            player_secondary_gun_damage += mech_panzer::mech_panzer().secondary_gun_damage;
            player_secondary_gun_penetration += mech_panzer::mech_panzer().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_panzer::mech_panzer().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_panzer::mech_panzer().tertiary_gun_penetration;
            player_melee_damage += mech_panzer::mech_panzer().melee_damage;
            player_primary_gun_name = mech_panzer::mech_panzer().primary_gun;
            cout << "You Chose The Mech " << BRIGHT_GREEN << mech_panzer::mech_panzer().mech_name << RESET << endl;
            end_mech_selection();
        }
        else if (user_input == "Artemis")
        {
            player_pilot_health += (mech_artemis::mech_artemis().pilot_health - 1);
            player_unmodified_pilot_health += mech_artemis::mech_artemis().pilot_health;
            player_front_armor += mech_artemis::mech_artemis().front_armor;
            player_unmodified_front_armor += mech_artemis::mech_artemis().front_armor;
            player_primary_gun_damage += mech_artemis::mech_artemis().primary_gun_damage;
            player_unmodified_primary_gun_damage += mech_artemis::mech_artemis().primary_gun_damage;
            player_primary_gun_penetration += mech_artemis::mech_artemis().primary_gun_penetration;
            player_unmodified_primary_gun_penetration += mech_artemis::mech_artemis().primary_gun_penetration;
            player_secondary_gun_damage += mech_artemis::mech_artemis().secondary_gun_damage;
            player_secondary_gun_penetration += mech_artemis::mech_artemis().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_artemis::mech_artemis().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_artemis::mech_artemis().tertiary_gun_penetration;
            player_melee_damage += mech_artemis::mech_artemis().melee_damage;
            player_primary_gun_name = mech_artemis::mech_artemis().primary_gun;
            accuracy_modifier += 45;
            ai_accuracy_modifier -= 35;
            cout << "You Chose The Mech " << BRIGHT_GREEN << mech_artemis::mech_artemis().mech_name << RESET << endl;
            end_mech_selection();
        }
        else if (user_input == "Aegis")
        {
            player_pilot_health += (mech_aegis::mech_aegis().pilot_health - 1);
            player_unmodified_pilot_health += mech_aegis::mech_aegis().pilot_health;
            player_front_armor += mech_aegis::mech_aegis().front_armor;
            player_unmodified_front_armor += mech_aegis::mech_aegis().front_armor;
            player_primary_gun_damage += mech_aegis::mech_aegis().primary_gun_damage;
            player_unmodified_primary_gun_damage += mech_aegis::mech_aegis().primary_gun_damage;
            player_primary_gun_penetration += mech_aegis::mech_aegis().primary_gun_penetration;
            player_unmodified_primary_gun_penetration += mech_aegis::mech_aegis().primary_gun_penetration;
            player_secondary_gun_damage += mech_aegis::mech_aegis().secondary_gun_damage;
            player_secondary_gun_penetration += mech_aegis::mech_aegis().secondary_gun_penetration;
            player_tertiary_gun_damage += mech_aegis::mech_aegis().tertiary_gun_damage;
            player_tertiary_gun_penetration += mech_aegis::mech_aegis().tertiary_gun_penetration;
            player_melee_damage += mech_aegis::mech_aegis().melee_damage;
            player_primary_gun_name = mech_aegis::mech_aegis().primary_gun;
            accuracy_modifier += 25;
            cout << "You Chose The Mech " << BRIGHT_GREEN << mech_aegis::mech_aegis().mech_name << RESET << endl;
            end_mech_selection();
        }
        else 
        {
            cout << "Try again." << endl;
        }
    }

    void ai_mech_selection() {     // AI Mech Selection Function.
        switch (ai_mech_roll)
        {
        case(1): // Emperor
            pilot_health += (mech_emperor::mech_emperor().pilot_health - 1);
            unmodified_pilot_health += mech_emperor::mech_emperor().pilot_health;
            front_armor += mech_emperor::mech_emperor().front_armor;
            unmodified_front_armor += mech_emperor::mech_emperor().front_armor;
            primary_gun_damage += mech_emperor::mech_emperor().primary_gun_damage;
            unmodified_primary_gun_damage += mech_emperor::mech_emperor().primary_gun_damage;
            primary_gun_penetration += mech_emperor::mech_emperor().primary_gun_penetration;
            unmodified_primary_gun_penetration += mech_emperor::mech_emperor().primary_gun_penetration;
            secondary_gun_damage += mech_emperor::mech_emperor().secondary_gun_damage;
            secondary_gun_penetration += mech_emperor::mech_emperor().secondary_gun_penetration;
            tertiary_gun_damage += mech_emperor::mech_emperor().tertiary_gun_damage;
            tertiary_gun_penetration += mech_emperor::mech_emperor().tertiary_gun_penetration;
            melee_damage += mech_emperor::mech_emperor().melee_damage;
            cout << "You Fight an " << BRIGHT_RED << mech_emperor::mech_emperor().mech_name << RESET << endl;
            end_ai_mech_selection();
            break;
        case(2): // Panzer
            pilot_health += (mech_panzer::mech_panzer().pilot_health - 1);
            unmodified_pilot_health += mech_panzer::mech_panzer().pilot_health;
            front_armor += mech_panzer::mech_panzer().front_armor;
            unmodified_front_armor += mech_panzer::mech_panzer().front_armor;
            primary_gun_damage += mech_panzer::mech_panzer().primary_gun_damage;
            unmodified_primary_gun_damage += mech_panzer::mech_panzer().primary_gun_damage;
            primary_gun_penetration += mech_panzer::mech_panzer().primary_gun_penetration;
            unmodified_primary_gun_penetration += mech_panzer::mech_panzer().primary_gun_penetration;
            secondary_gun_damage += mech_panzer::mech_panzer().secondary_gun_damage;
            secondary_gun_penetration += mech_panzer::mech_panzer().secondary_gun_penetration;
            tertiary_gun_damage += mech_panzer::mech_panzer().tertiary_gun_damage;
            tertiary_gun_penetration += mech_panzer::mech_panzer().tertiary_gun_penetration;
            melee_damage += mech_panzer::mech_panzer().melee_damage;
            cout << "You Fight a " << BRIGHT_RED << mech_panzer::mech_panzer().mech_name << RESET << endl;
            end_ai_mech_selection();
            break;
        case(3): // Artemis
            pilot_health += (mech_artemis::mech_artemis().pilot_health - 1);
            unmodified_pilot_health += mech_artemis::mech_artemis().pilot_health;
            front_armor += mech_artemis::mech_artemis().front_armor;
            unmodified_front_armor += mech_artemis::mech_artemis().front_armor;
            primary_gun_damage += mech_artemis::mech_artemis().primary_gun_damage;
            unmodified_primary_gun_damage += mech_artemis::mech_artemis().primary_gun_damage;
            primary_gun_penetration += mech_artemis::mech_artemis().primary_gun_penetration;
            unmodified_primary_gun_penetration += mech_artemis::mech_artemis().primary_gun_penetration;
            secondary_gun_damage += mech_artemis::mech_artemis().secondary_gun_damage;
            secondary_gun_penetration += mech_artemis::mech_artemis().secondary_gun_penetration;
            tertiary_gun_damage += mech_artemis::mech_artemis().tertiary_gun_damage;
            tertiary_gun_penetration += mech_artemis::mech_artemis().tertiary_gun_penetration;
            melee_damage += mech_artemis::mech_artemis().melee_damage;
            enemy_mech_id += mech_artemis::mech_artemis().mech_id;
            ai_accuracy_modifier += 45;
            accuracy_modifier -= 35;
            cout << "You Fight an " << BRIGHT_RED << mech_artemis::mech_artemis().mech_name << RESET << endl;
            end_ai_mech_selection();
            break;
        case(4): // Aegis
            pilot_health += (mech_aegis::mech_aegis().pilot_health - 1);
            unmodified_pilot_health += mech_aegis::mech_aegis().pilot_health;
            front_armor += mech_aegis::mech_aegis().front_armor;
            unmodified_front_armor += mech_aegis::mech_aegis().front_armor;
            primary_gun_damage += mech_aegis::mech_aegis().primary_gun_damage;
            unmodified_primary_gun_damage += mech_aegis::mech_aegis().primary_gun_damage;
            primary_gun_penetration += mech_aegis::mech_aegis().primary_gun_penetration;
            unmodified_primary_gun_penetration += mech_aegis::mech_aegis().primary_gun_penetration;
            secondary_gun_damage += mech_aegis::mech_aegis().secondary_gun_damage;
            secondary_gun_penetration += mech_aegis::mech_aegis().secondary_gun_penetration;
            tertiary_gun_damage += mech_aegis::mech_aegis().tertiary_gun_damage;
            tertiary_gun_penetration += mech_aegis::mech_aegis().tertiary_gun_penetration;
            melee_damage += mech_aegis::mech_aegis().melee_damage;
            ai_accuracy_modifier += 25;
            accuracy_modifier -= 25;
            cout << "You Fight an " << BRIGHT_RED << mech_aegis::mech_aegis().mech_name << RESET << endl;
            end_ai_mech_selection();
            break;
        default: // Generic
            pilot_health += (mech_generic::mech_generic().pilot_health - 1);
            unmodified_pilot_health += mech_generic::mech_generic().pilot_health;
            front_armor += mech_generic::mech_generic().front_armor;
            unmodified_front_armor += mech_generic::mech_generic().front_armor;
            primary_gun_damage += mech_generic::mech_generic().primary_gun_damage;
            unmodified_primary_gun_damage += mech_generic::mech_generic().primary_gun_damage;
            primary_gun_penetration += mech_generic::mech_generic().primary_gun_penetration;
            unmodified_primary_gun_penetration += mech_generic::mech_generic().primary_gun_penetration;
            secondary_gun_damage += mech_generic::mech_generic().secondary_gun_damage;
            secondary_gun_penetration += mech_generic::mech_generic().secondary_gun_penetration;
            tertiary_gun_damage += mech_generic::mech_generic().tertiary_gun_damage;
            tertiary_gun_penetration += mech_generic::mech_generic().tertiary_gun_penetration;
            melee_damage += mech_generic::mech_generic().melee_damage;
            cout << "You Fight a " << BRIGHT_RED << "Generic Bland Enemy." << RESET << endl;
            end_ai_mech_selection();
            break;
        }
    }

    void player_turn() {      // Player Turn Function.

        unfortify();
        cout << BRIGHT_BLUE << "Your Turn! " << RESET << "Your Health: " << BRIGHT_GREEN << player_pilot_health << RESET << endl;
        cout << "Your Actions: " << endl;
        cout << BRIGHT_YELLOW << "Fire" << RESET << " | " << BRIGHT_YELLOW << "Repair" << RESET << " | " << BRIGHT_YELLOW << "Fortify" << RESET << " | " << BRIGHT_YELLOW << "Overcharge" << RESET << endl;
        string user_input;
        getline(cin, user_input);

        if (user_input == "Fire") 
        {
            cout << "Firing " << BRIGHT_GREEN << player_primary_gun_name << RESET << endl;
            player_combat_damage();
            unovercharge();
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

    void enemy_turn() {           // Enemy Turn Function.
        if (pilot_health > 0) {
            unfortify();
            cout << "Enemy Mech Turn!" << endl;
            cout << "Enemy Health: " << BRIGHT_RED << pilot_health << RESET << endl;
            ai_weight_analysis();
            ai_decision_making();
            end_turn();
        }
        else {
            cout << "Enemy Mech Is Broken!" << endl;
        }
    }


    void repair_action() {  // Repair Function
        if (is_player_turn) 
        {
            if (player_pilot_health < unmodified_pilot_health) {
                player_pilot_health += (player_unmodified_pilot_health * 0.10);
                cout << BRIGHT_GREEN << "Pilot Healed!" << RESET << endl;
            }
            else
            {
                cout << BRIGHT_CYAN << "You are Already at Full Health!" << RESET << endl;
            }
        }
        else if (!is_player_turn)
        {
            if (pilot_health < unmodified_pilot_health) {
                pilot_health += (unmodified_pilot_health * 0.10);
                cout << BRIGHT_RED << "Enemy Pilot Healed!" << RESET << endl;
            }
        }
    }

    void fortify_action() {    // Fortify Function
        if (is_player_turn && !is_fortified)
        {
                player_front_armor += (player_front_armor * 0.15);
                cout << BRIGHT_GREEN << "Armor Fortified!" << RESET << endl;
                fortify_switch_on();
        }
    }
    void ai_fortify_action() {     // AI Fortify Function
        if (!is_player_turn && !is_fortified)
        {
            front_armor += (front_armor * 0.15);
            cout << BRIGHT_RED << "Enemy Armor Fortified!" << RESET << endl;
            ai_fortify_switch_on();
        }
    }
    void overcharge_action() {  // Overcharge Function
        if (is_player_turn && !is_overcharged)
        {
                player_primary_gun_damage *= 2;
                player_primary_gun_penetration += (player_unmodified_primary_gun_penetration * 0.25);
                cout << "Main Gun " << BRIGHT_RED << "Overcharged!" << RESET << endl;
                overcharge_switch_on();
        }
    }
    void ai_overcharge_action() {  // AI Overchjarge Function
        if (!is_player_turn && !is_ai_overcharged)
        {
            primary_gun_damage *= 2;
            primary_gun_penetration += (unmodified_primary_gun_penetration * 0.25);
            cout << RED << "Enemy Gun Overcharged!" << RESET << endl;
            ai_overcharge_switch_on();
        }
    }

    void player_combat_value_initializer() { // Initializes Player Stats Values
        actual_damage = player_primary_gun_damage;
        done_damage = 0;
        distance_float = distance - max_distance;
        actual_penetration = player_primary_gun_penetration;
    }

    void player_combat_calculator() { // Calculates Damage and Penetration.
        damage_distance_multiplier = abs(sin((((min_distance - distance_float) / min_distance) * (PI / 2)) * player_unmodified_primary_gun_damage));
        penetration_distance_multiplier = abs(sin((((min_distance - distance_float) / min_distance) * (PI / 2)) * player_unmodified_primary_gun_penetration));

        if (penetration_distance_multiplier > 1)
        {
            penetration_distance_multiplier = 1;
        }
        if (penetration_distance_multiplier < 0.25)
        {
            penetration_distance_multiplier = 0.25;
        }
        if (damage_distance_multiplier < 0.25)
        {
            damage_distance_multiplier = 0.25;
        }
        if (damage_distance_multiplier > 1)
        {
            damage_distance_multiplier = 1;
        }

        damage_multiplier_percentage = abs((front_armor - player_primary_gun_penetration) / (front_armor / 100) / 100);;
        if (damage_multiplier_percentage > 0.5)
        {
            damage_multiplier_percentage = 0.5;
        }

        damage_multiplier = (player_primary_gun_damage * damage_multiplier_percentage);
        actual_penetration *= penetration_distance_multiplier;

        //DEBUG
        cout << "DMG Distance Multiplier =========>" << damage_distance_multiplier << endl;
        cout << "PEN Distance Multiplier =========>" << penetration_distance_multiplier << endl;
    }

    void player_accuracy_roll() {   // Rolls Player Accuracy.
        if (accuracy_modifier < 25) {
            accuracy_modifier = 25;
        }

        accuracy_roll = (rand() % accuracy_modifier) + accuracy_modifier;

        if (accuracy_roll > 100)
        {
            accuracy_roll = 100;
        }

        //DEBUG
        //cout << accuracy_roll << endl;
    }

    void player_combat_damage() {          // Combat Operation, Damage Calculation and Infliction.
        player_combat_value_initializer();
        player_combat_calculator();
        player_accuracy_roll();

        if (accuracy_roll < 40 && enemy_mech_id == 4)
        {
            cout << "Enemy Artemis was Too Fast!" << BRIGHT_RED << " We Missed!" << RESET << endl;
            accuracy_modifier += 3;
        }
        else if (accuracy_roll < 40)
        {
            cout << BRIGHT_RED << " We Missed!" << RESET << endl;
            accuracy_modifier += 3;
        }
        else {
            if (is_player_attacking = true) {
                if (front_armor > -1) {
                    if (actual_penetration >= front_armor)
                    {
                        actual_damage *= damage_distance_multiplier;
                        actual_damage += damage_multiplier;
                        pilot_health -= actual_damage;
                        done_damage += (actual_damage += damage_multiplier);
                        cout << "Target hit!" << BRIGHT_GREEN << " Shot Penetrated!" << RESET <<" Damaged for: " << BRIGHT_GREEN << done_damage << RESET << endl;
                        end_combat_turn();
                    }
                    else if (actual_penetration < front_armor)
                    {
                        actual_damage *= damage_distance_multiplier;
                        pilot_health -= actual_damage;
                        done_damage += (actual_damage * damage_distance_multiplier);
                        cout << "Target hit! Front Armor is " << RED << "TOO THICK!" << RESET << " Damaged For: " << BRIGHT_GREEN << done_damage << RESET << endl;
                        end_combat_turn();
                    }
                    else //DEBUG.
                    {
                        cout << "Something's wrong with the Combat Damage Function." << endl;
                    };
                }
            }
        }
    }

    void enemy_combat_value_initializer() {  // Enemy Combat Stat Initializer.
        enemy_actual_damage = primary_gun_damage;
        enemy_done_damage = 0;
        enemy_distance_float = distance - max_distance;
        enemy_actual_penetration = primary_gun_penetration;
    }

    void enemy_combat_calculator() {  // Calculates Enemy Damage and Penetration.
        enemy_damage_distance_multiplier = abs(sin((((min_distance - enemy_distance_float) / min_distance) * (PI / 2)) * unmodified_primary_gun_damage));
        enemy_penetration_distance_multiplier = abs(sin((((min_distance - enemy_distance_float) / min_distance) * (PI / 2)) * unmodified_primary_gun_penetration));

        if (enemy_penetration_distance_multiplier > 1)
        {
            enemy_penetration_distance_multiplier = 1;
        }
        if (enemy_penetration_distance_multiplier < 0.25)
        {
            enemy_penetration_distance_multiplier = 0.25;
        }
        if (enemy_damage_distance_multiplier < 0.25)
        {
            enemy_damage_distance_multiplier = 0.25;
        }
        if (enemy_damage_distance_multiplier > 1)
        {
            enemy_damage_distance_multiplier = 1;
        }

        enemy_damage_multiplier_percentage = abs((player_front_armor - primary_gun_penetration) / (player_front_armor / 100) / 100);;
        if (enemy_damage_multiplier_percentage > 0.5)
        {
            enemy_damage_multiplier_percentage = 0.5;
        }

        enemy_damage_multiplier = (primary_gun_damage * enemy_damage_multiplier_percentage);
        enemy_actual_penetration *= enemy_penetration_distance_multiplier;

        //DEBUG
        cout << "DMG Distance Multiplier =========>" << enemy_damage_distance_multiplier << endl;
        cout << "PEN Distance Multiplier =========>" << enemy_penetration_distance_multiplier << endl;
    }

    void enemy_accuracy_roll() { // Calculates Enemy Accuracy.
        if (ai_accuracy_modifier < 30) {
            ai_accuracy_modifier = 30;
        }

        ai_accuracy_roll = (rand() % ai_accuracy_modifier) + ai_accuracy_modifier;

        if (ai_accuracy_roll > 100)
        {
            ai_accuracy_roll = 100;
        }

        //DEBUG
        //cout << accuracy_roll << endl;
    }

    void enemy_combat_damage() {       // AI Combat Operation, Damage Calculation and Infliction.
        enemy_combat_value_initializer();
        enemy_combat_calculator();
        enemy_accuracy_roll();

        if (ai_accuracy_roll < 40)
        {
            cout << BRIGHT_GREEN << "The Enemy Missed!" << RESET << endl;
        }
        else
        {
            if (is_player_attacking = true)
            {
                if (player_front_armor > -1) {
                    if (enemy_actual_penetration >= player_front_armor) {
                        enemy_actual_damage *= enemy_damage_distance_multiplier;
                        enemy_actual_damage += enemy_damage_multiplier;
                        player_pilot_health -= enemy_actual_damage;
                        enemy_done_damage += (enemy_actual_damage += enemy_damage_multiplier);
                        cout << "We are Hit!" << BRIGHT_RED << " Their Shot Penetrated!" << RESET << " Damaged for: " << RED << enemy_done_damage << RESET << endl;
                    }
                    else if (enemy_actual_penetration < player_front_armor)
                    {
                        enemy_actual_damage *= enemy_damage_distance_multiplier;
                        player_pilot_health -= enemy_actual_damage;
                        enemy_done_damage += (enemy_actual_damage * enemy_damage_distance_multiplier);
                        cout << "We are Hit! Our Armor was" << BRIGHT_GREEN << " Too Strong!" << RESET << " Damaged for: " << RED << enemy_done_damage << RESET << endl;
                    }
                }
            }
            else
            {
                cout << "This means that Combat Function is NOT accessed." << endl;
            }
        } 
    }
        
        
    void end_combat_turn() {          // Ends Combat Turn. So Far it is Unused, but I have a plan for it later.
        is_player_attacking = !is_player_attacking;
    }



    void mech_encounter() {                // The Ignition, Basically the First Function that Initiates everything.
        cout << BRIGHT_RED << "Enemy Mech Encountered!" << RESET << endl;
        diceroll();
        ai_mech_dice_roll();
        if (ai_has_selected_mech)
        {
            ai_mech_selection();
        }
        random_effects_choice();
        randomize_distance();
        terrain_modifier();
        cout << "Rangefinder reported Distance: " << BRIGHT_CYAN << distance << RESET << " Meters." << endl;

        while (player_pilot_health > 0 && pilot_health > 0) {
            if (is_player_turn) {
                if (has_selected_mech) 
                {
                    player_selecting_mech();
                    random_effects();
                }
                else if (!has_selected_mech){
                    player_turn();
                    cout << "-------" << endl;
                }
            }
            else if (!is_player_turn) {
                enemy_turn();
                cout << "-------" << endl;
            }
        }

        if (player_pilot_health <= 0) {
            cout << RED << "We have been Destroyed!" << RESET << endl;
        }
        else if (pilot_health <= 0)
        {
            cout << BRIGHT_GREEN << "We are Victorious! Enemy Mech Destroyed!" << RESET << endl;
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

