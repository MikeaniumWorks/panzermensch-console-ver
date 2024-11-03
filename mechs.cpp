
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdbool>
//#include "mechs.hpp"
//#include "vehicles.hpp"

using std::string;


    /*
     Tier 1: Hellking, Warmaster, Artemis, Panzer, Emperor
     Tier 2: Custodian, Sentinel, Deathguard, Dreadnought
     Tier 3: Krieg, Battlebearer, Ironfire, Blitzkrieg
     Tier 4: Steelmaster, Stormwind, Bloodlord
     Tier 5: Diligent, Lineholder, Steelspirit
     Tier 6: Peacebreaker, Armaedon, Irosticain, Generic
    */



class Mech {
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
    

};

class mech_generic : Mech {    
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
    int melee_sharpness;

    string mech_name;
    int mech_id;
    int tier;

    mech_generic (int = 100, int = 100, bool = true, int = 100, int = 100, string = "Primary", bool = false, int = 100, int = 100, string = "Secondary",
        bool = false, int = 100, int = 100, string = "Tertiary", bool = false, int = 100, int = 100, string, int, int) {};
   
};

class emperor_mech : Mech {

    //     _______                                                     
    //    |_   __ \                                                     
    //      | |_ \_| _ .--..--.  _ .--.   .---.  _ .--.   .--.   _ .--.  
    //      |  _| _ [ `.-. .-. |[ '/'`\ \/ /__\\[ `/'`\]/ .'`\ \[ `/'`\] 
    //     _| |__/ | | | | | | | | \__/ || \__., | |    | \__. | | |     
    //    |________|[___||__||__]| ;.__/  '.__.'[___]    '.__.' [___]    
    //                          [__|     

public:
    int pilot_health = 1000;
    int front_armor = 780;
    bool primary_gun_capable = true;
    int primary_gun_damage = 1260;
    int primary_gun_penetration = 1200;
    string primary_gun = "Godbreaker";
    bool secondary_gun_capable = true;
    int secondary_gun_damage = 750;
    int secondary_gun_penetration = 800;
    string secondary_gun = "Aetheric Blaster";
    bool tertiary_gun_capable = true;
    int tertiary_gun_damage = 21;
    int tertiary_gun_penetration = 2000;
    string tertiary_gun = "Godfire";
    bool melee_capable = true;
    int melee_damage = 700;
    int melee_sharpness = 2000;

    string mech_name = "EMPEROR";
    int mech_id = 1;
    int tier = 1;
};

int stats() {
    mech_generic generic(100, 100, true, 100, 100, "Primary", false, 100, 100, "Secondary", false, 100, 100, "Tertiary", false, 100, 100, "Generic", 0, 6);
    /*
    generic_mech generic;
    emperor_mech EMPEROR;
    generic.pilot_health = 100;
    generic.front_armor = 100; 
    generic.primary_gun_capable = true; 
    generic_mech.primary_gun_damage = 100; 
    generic_mech.primary_gun_penetration = 100; 
    generic_mech.primary_gun = "Primary"; 
    generic_mech.secondary_gun_capable = true; 
    generic.secondary_gun_damage = 100; 
    generic_mech.secondary_gun_penetration = 100; 
    generic_mech.secondary_gun = "Secondary"; 
    generic_mech.tertiary_gun_capable = true; 
    generic_mech.tertiary_gun_damage = 100; 
    generic_mech.tertiary_gun_penetration = 100; 
    generic_mech.tertiary_gun = "Tertiary"; 
    generic_mech.melee_capable = true; 
    generic_mech.melee_damage = 100; 
    generic_mech.melee_sharpness = 100; 
    generic_mech.mech_name = "Generic";
    generic_mech.mech_id = 0;
    generic_mech.tier = 6;
    */
    //
    /*
    Mech emperor_mech; 
    emperor_mech.pilot_health = 1000; 
    emperor_mech.front_armor = 780; 
    emperor_mech.primary_gun_damage = 1260; 
    emperor_mech.primary_gun_penetration = 1200; 
    emperor_mech.primary_gun = "Godbreaker"; 
    emperor_mech.secondary_gun_damage = 750; 
    emperor_mech.secondary_gun_penetration = 800; 
    emperor_mech.secondary_gun = "Aetheric Blaster"; 
    emperor_mech.tertiary_gun_damage = 21; 
    emperor_mech.tertiary_gun_penetration = 2000; 
    emperor_mech.tertiary_gun = "Godfire";
    emperor_mech.melee_capable = true; 
    emperor_mech.melee_damage = 700; 
    emperor_mech.melee_sharpness = 2000; 
    emperor_mech.mech_name = "EMPEROR";
    emperor_mech.mech_id = 1;
    emperor_mech.tier = 1;
    */
}


