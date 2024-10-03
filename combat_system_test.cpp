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

string mechanized_gun_support_infantry[2] = { "PZMGW-54 Battlebearer","PZMGW-22 Stormwind" }; //just for later use.

// Randomization Seed (for distance and beyond.)
void randomizer() {

    auto randomization_seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(static_cast<unsigned>(randomization_seed));
}

class Panzermensch {

    // I have decided to make a rudimentary game, In which there are player and enemy mechs, the two fight in turns with each having their own option.
    // In this mech game that i shall name Panzermensch, you as a player mech must kill the enemy and have to fight a Boss at the end.

    // This is basically the precursor or demo version of a much more ambitious yet achievable project that i have, of an actual Videogame with full on 3D graphics.
    // Said Videogame Will have multiplayer, easy modificability and campaigns. Its styled to be a horde shooter where you go do missions CO-OP.

private:


    // Player Stats
    string player_mech;
    int player_front_armor_health = 0;
    int player_front_armor = 0;
    int player_side_armor_health = 0;
    int player_side_armor = 0;
    int player_rear_armor_health = 0;
    int player_rear_armor = 0;
    int player_pilot_health = 0;
    int player_veterancy = 0;

    // Enemy Stats
    //int front_armor_health = 0;       // Basically Armor Integrity, for front, side and rear.
    int front_armor = 0;              // The Armor itself, the more hits it takes, the lesser it gets (by a small magnitude), and the more its 'Health' or Integrity Decreases.
    //int side_armor_health = 0;
    int side_armor = 0;
    //int rear_armor_health = 0;
    int rear_armor = 0;
    int pilot_health = 0;             // When Armor Integrity breaks, The Pilot is technically exposed, however if Said Shot penetrates armor, then it does infact damage the pilot + armor integrity.
    int veterancy = 0;                // Unused for now. Experience, Which makes movement faster, perception better and accuracy better. It is like levels, so its integers up to 10.

    // also, all this comments are just for me to explain things to myself more so i understand better.

    // General Stats

    //int primary_gun_damage = 0;
    int gun_penetration = 0;
    int done_damage = 0;

    // World Stats that may or may not be used.
    bool is_player_turn = true;
    bool is_player_attacking = true;
    bool is_player_moving = true; // Unused for now.
    //int angle;                    // Unused for now... I plan on detailing this game A LOT.
    int distance = 0;
    //string terrain;               // Unused for now.
    string user_input;            // obvious.

public:
    Panzermensch() : gun_penetration(300), player_front_armor(350),
        player_front_armor_health(100), player_side_armor(280), player_side_armor_health(100),
        player_rear_armor(160), player_rear_armor_health(75), player_pilot_health(500), player_veterancy(0),
        front_armor(240), side_armor(180), rear_armor(100),
        pilot_health(100), veterancy(0) {}

    // primary_gun_damage(500),

    void end_turn() {

        // gonna add a turn function here, just putting this so it doesn't fuck up my code, i hate seeing "X Errors" being more than 0.
        is_player_turn = !is_player_turn;
    }

    void randomize_distance() {
        const int min_distance = 100;
        const int max_distance = 12000;
        distance = rand() % (max_distance - min_distance + 1) + min_distance;
    }

    void player_turn() {

        cout << "Your Turn!" << endl;
        string user_input;
        getline(cin, user_input);

        if (user_input == "Fire") {
            combat_damage(is_player_attacking = true);
            cout << "Damaged For " << done_damage << endl;
            end_turn();
        }
        else if (user_input == "Repair") {
            repair_action();
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
            combat_damage(is_player_attacking = false);
            end_turn();
        }
        else {
            cout << "Enemy Mech Is Broken!" << endl;
        }

    }


    void repair_action() {

        if (player_pilot_health < 500) {
            player_pilot_health += 150;
            end_turn();
        }

    }

    void combat_damage(bool is_player_attacking) {          // What happens when the guns fire.

        int damage_error = 80085;

        int actual_damage = 250;

        int actual_gun_penetration = 300;

        int damage_falloff = (distance / 12000);

        int done_damage = actual_damage;

        bool combat_action = is_player_attacking;

        try
        {
            if (is_player_attacking)
            {
                switch (combat_action) {
                case(0):
                    if (actual_gun_penetration > front_armor) {
                        pilot_health -= actual_damage;
                        cout << "Enemy Damaged For " << actual_damage << endl;
                        cout << "Their Health is: " << pilot_health << endl;
                    }
                    break;
                }
            }

        }
        catch (int damage_error)
        {
            cout << "Yep, Error in the Combat System, Check it." << endl;
        }
    }


    void mech_encounter() {                // this is supposed to be what happens first, but i lack the knowledge to know.

        cout << "Enemy Mech Encountered!" << endl;
        randomize_distance();
        cout << "Rangefinder reported Distance: " << "8741" << " Meters." << endl;

        while (player_pilot_health > 0 && pilot_health > 0) {
            if (is_player_turn) {
                player_turn();
            }
            else if (!is_player_turn) {
                player_turn();
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
    cout << "STATUS: Radio On." << endl;
    randomizer();
    Panzermensch game;
    game.mech_encounter();

    return 0;
}

