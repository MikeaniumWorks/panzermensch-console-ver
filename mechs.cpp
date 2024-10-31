    
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdbool>
#include "mechs.hpp"
#include "vehicles.hpp"

using namespace std;

    /*
     Tier 1: Hellking, Warmaster, Artemis, Panzer, Emperor
     Tier 2: Custodian, Sentinel, Deathguard, Dreadnought
     Tier 3: Krieg, Battlebearer, Ironfire, Blitzkrieg
     Tier 4: Steelmaster, Stormwind, Bloodlord
     Tier 5: Diligent, Lineholder, Steelspirit
     Tier 6: Peacebreaker, Armaedon, Irosticain, Generic
    */

class Vehicle;

class Mech : public Vehicle {
public:
    int pilot_health;
    int front_armor;
    bool primary_gun_capable;
    int primary_gun_damage;
    int primary_gun_penetration;
    string primary_gun;
    bool secondary_gun_capable;
    int secondary_gun_damage;
    int secondary_gun_penetration;
    string secondary_gun;
    bool tertiary_gun_capable;
    int tertiary_gun_damage;
    int tertiary_gun_penetration;
    string tertiary_gun;
    bool melee_capable;
    int melee_damage;
    int melee_sharpness; // Basically Melee Penetration, It is added JUST IN CASE.

    string mech_name;
    int mech_id;
    int tier;

    Mech(int health, int armor, bool prim_gun, int prim_dmg, int prim_pen, string prim_name,
        bool sec_gun, int sec_dmg, int sec_pen, string sec,
        bool tert_gun, int tert_dmg, int tert_pen, string tert,
        bool melee, int melee_dmg, int melee_sharp, string name, int id, int mech_tier);


    static Mech generic_mech;
    static Mech emperor_mech;


}


    Mech Mech::generic_mech = Mech(
        100,
        100,
        true,
        100,
        100,
        "Nerdspeech",
        // int primary_gun_emotional_damage = 2147483647;
        false,
        100,
        100,
        "Slipper",
        // int secondary_gun_emotional_damage = 2147483647;
        false,
        100,
        100,
        "Belt",
        // int tertiary_gun_emotional_damage = 2147483647;
        false,
        100,
        100,
        "Vanilla Mech",
        0,
        6
        );
    
    //     _______                                                     
    //    |_   __ \                                                     
    //      | |_ \_| _ .--..--.  _ .--.   .---.  _ .--.   .--.   _ .--.  
    //      |  _| _ [ `.-. .-. |[ '/'`\ \/ /__\\[ `/'`\]/ .'`\ \[ `/'`\] 
    //     _| |__/ | | | | | | | | \__/ || \__., | |    | \__. | | |     
    //    |________|[___||__||__]| ;.__/  '.__.'[___]    '.__.' [___]    
    //                          [__|                                    

    void emperor_mech(){
        int pilot_health = 1000;
        int front_armor = 780;
        int primary_gun_damage = 1260;
        int primary_gun_penetration = 1200;
        string primary_gun = "Godbreaker";
        int secondary_gun_damage = 750;
        int secondary_gun_penetration = 800;
        string secondary_gun = "Aetheric Blaster";
        int tertiary_gun_damage = 21;
        int tertiary_gun_penetration = 2000;
        string tertiary_gun = "Godfire";
        bool melee_capable = true;
        int melee_damage = 700;
        int melee_armor_penetration = 2000;

        string mech_name = "EMPEROR";
        int mech_id = 1;
        int tier = 1;

    }

};

int main() {

}


