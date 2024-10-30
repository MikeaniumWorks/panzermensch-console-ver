    
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdbool>
#include "mechs.hpp"
#include "vehicles.hpp"

using namespace std;

class Mechs {

    // Tier 1: Hellking, Warmaster, Artemis, Panzer, Custodian, Emperor
    // Tier 2: Golden Guard, Sentinel, Deathguard, Dreadnought
    // Tier 3: Krieg, Battlebearer, Ironfire, Blitzkrieg
    // Tier 4: Steelbreaker, Stormwind, Bloodlord
    // Tier 5: Diligent, Ironhorse, Steelspirit
    // Tier 6: Peacebreaker, Armistice, Ironmensch

};

      Mechs::Mech(int health, int armor, bool prim_gun, int prim_dmg, int prim_pen, string prim,
      bool sec_gun, int sec_dmg, int sec_pen, string sec,
      bool tert_gun, int tert_dmg, int tert_pen, string tert,
      bool melee, int melee_dmg, int melee_sharp, string name, int id, int mech_tier)
      : pilot_health(health), front_armor(armor), primary_gun_capable(prim_gun), primary_gun_damage(prim_dmg),
      primary_gun_penetration(prim_pen), primary_gun(prim), secondary_gun_capable(sec_gun), secondary_gun_damage(sec_dmg),
      secondary_gun_penetration(sec_pen), secondary_gun(sec), tertiary_gun_capable(tert_gun), tertiary_gun_damage(tert_dmg),
      tertiary_gun_penetration(tert_pen), tertiary_gun(tert), melee_capable(melee), melee_damage(melee_damage),
      melee_sharpness(melee_sharp), mech_name(name), mech_id(id), tier(mech_tier) {}

    Mechs Mechs::generic_mech = Mechs(
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
        5
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
