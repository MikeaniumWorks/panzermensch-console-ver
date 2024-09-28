// Professional coders beware. From this point on is the land of Chaos, where cursed abominations of randomly strung together columns of letters lacking
// both skill and meaning inhabit, This is the point of no return. You have been warned.
// 
// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

string mechanized_gun_support_infantry[2] = { "PZMGW-54 Battlebearer","PZMGW-22 Stormwind" };

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
    int player_front_armor_health;
    int player_front_armor;
    int player_side_armor_health;
    int player_side_armor;
    int player_rear_armor_health;
    int player_rear_armor;
    int player_pilot_health;
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
    int done_damage;

    // World Stats that may or may not be used.
    bool is_player_turn = true;
    bool is_player_attacking = true;
    bool is_player_moving = true; // Unused for now.
    //int angle;                    // Unused for now... I plan on detailing this game A LOT.
    int distance;
    string terrain;               // Unused for now.
    string user_input;            // obvious.

public:
    Panzermensch() : primary_gun_damage(500), gun_penetration(300), player_front_armor(350), player_front_armor_health(100), player_side_armor(280), player_side_armor_health(100), player_rear_armor(160), player_rear_armor_health(75), player_pilot_health(100), player_veterancy(0), front_armor(240), front_armor_health(100), side_armor(180), side_armor_health(100), rear_armor(100), rear_armor_health(75), pilot_health(100), veterancy(0) {}

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
            combat_damage(primary_gun_damage, is_player_attacking=true);
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
            combat_damage(primary_gun_damage, false);
            cout << "Our Front Armor Health: " << player_front_armor_health << " Damaged for: " << done_damage << endl;
            cout << "Our Side Armor Health: " << player_side_armor_health << " Damaged for: " << done_damage << endl;
            cout << "Our Rear Armor Health: " << player_rear_armor_health << " Damaged for: " << done_damage << endl;
            cout << "Our Pilot Health: " << player_pilot_health << " Damaged for: " << done_damage << endl;
            end_turn();
        }
        else {
            cout << "Enemy Mech Is Broken!" << endl;
        }

    }


    void repair_action() {

        if (front_armor_health < 100) {
            front_armor_health += 20;
            end_turn();
        }
        else if (side_armor_health < 100) {
            side_armor_health += 20;
            end_turn();
        }
        else if (rear_armor_health < 75) {
            rear_armor_health += 15;
            end_turn();
        }

    }

    void combat_damage(int primary_gun_damage, bool is_player_attacking) {          // What happens when the guns fire.

        //const int min_distance = 100;
        //const int max_distance = 12000;

        float damage_reduction_by_distance = static_cast<float>(distance) / 12000;
        float actual_penetration = gun_penetration * 1;
        float actual_damage = static_cast<float>((primary_gun_damage + actual_penetration)) * (1.0 - damage_reduction_by_distance);

        int combat_damage = 0; //= (distance > 500) ? rand() % 2 : rand() % 3;
        int done_damage = static_cast<int>(actual_damage);

        if (!is_player_attacking) {
            switch (combat_damage) {

            case(0): // Front armor area

                if (front_armor >= 350) {
                    if (damage_reduction_by_distance >= front_armor) {

                        front_armor_health -= done_damage /= 2;
                        pilot_health /= 2;
                        cout << "Target hit in Front armor! Damaged for: " << done_damage << endl;
                    }
                    else if (front_armor_health <= 100)
                    {

                        pilot_health -= done_damage;
                        cout << "Target hit the pilot directly. Damaged for: " << done_damage << endl;
                    }
                }
                break;

            case(1): // Side armor area

                if (side_armor >= 280) {
                    if (damage_reduction_by_distance >= side_armor) {

                        side_armor_health -= done_damage /= 2;
                        pilot_health /= 2;
                        cout << "Target Hit! Damaged for: " << done_damage << endl;
                    }
                    else if (side_armor_health <= 100)
                    {

                        pilot_health -= done_damage;
                        cout << "Target hit the pilot directly. Damaged for: " << done_damage << endl;
                    }
                }
                break;

            case(2): // Rear armor area

                if (rear_armor >= 150) {
                    if (damage_reduction_by_distance >= front_armor) {

                        front_armor_health -= done_damage /= 2;
                        pilot_health /= 2;
                        cout << "Target hit in the rear. Damaged for: " << done_damage << endl;
                    }
                    else if (rear_armor_health <= 100)
                    {

                        pilot_health -= done_damage;
                        cout << "Target hit the pilot directly. Damaged for: " << done_damage << endl;
                    }
                }

                break;

            }
        }

        else if (is_player_attacking)
        {
            switch (combat_damage) {
                {
            case(0): // Front armor area

                if (player_front_armor > 350) {
                    if (damage_reduction_by_distance >= player_front_armor) {
                        int current_player_front_armor_health = player_front_armor_health - done_damage;

                        player_front_armor_health -= done_damage /= 2;
                        player_pilot_health /= 2;
                        cout << "Enemy hit our front armor. Damaged for: " << done_damage << "Our Front armor health is " << current_player_front_armor_health << endl;
                    }
                    else if (player_front_armor_health <= 100)
                    {

                        player_pilot_health -= done_damage;
                        cout << "Enemy hit our pilot directly. Damaged for: " << done_damage << endl;
                    }
                }
                break;

            case(1): // Side armor area

                if (player_side_armor > 280) {
                    if (damage_reduction_by_distance >= player_side_armor) {

                        player_side_armor_health -= done_damage /= 2;
                        pilot_health /= 2;
                        cout << "Enemy hit our side armor. Damaged for: " << done_damage << endl;
                    }
                    else if (player_side_armor_health <= 100)
                    {

                        player_pilot_health -= done_damage;
                        cout << "Enemy hit our pilot directly. Damaged for: " << done_damage << endl;
                    }
                }
                break;

            case(2): // Rear armor area

                if (player_rear_armor > 150) {
                    if (damage_reduction_by_distance >= player_rear_armor) {

                        player_rear_armor_health -= done_damage /= 2;
                        player_pilot_health /= 2;
                        cout << "Enemy hit our rear armor. Damaged for: " << done_damage << endl;
                    }
                    else if (player_rear_armor_health <= 100)
                    {

                        player_pilot_health -= done_damage;
                        cout << "Enemy hit the pilot directly. Damaged for: " << done_damage << endl;
                    }
                }

                break;
                }
            }
        }
    }



    void mech_encounter() {                // this is supposed to be what happens first, but i lack the knowledge to know.

        cout << "Enemy Mech Encountered!" << endl;
        randomize_distance();
        cout << "Rangefinder reported Distance: " << distance << " Meters." << endl;

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
    cout << "STATUS: Radio On." << endl;
    randomizer();
    Panzermensch game;
    game.mech_encounter();

    return 0;
}

