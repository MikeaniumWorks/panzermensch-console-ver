
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using std::string;

 /*
 Tier 1: Aegis, Artemis, Panzer, Emperor
 Tier 2: Custodian, Sentinel, Deathguard, Dreadnought, Hellking, Warmaster
 Tier 3: Krieg, Battlebearer, Ironfire, Blitzkrieg, Hellforge
 Tier 4: Ironmaiden, Stormwind, Bloodlord, Grey Tempest, Thundermaster
 Tier 5: Diligent, Lineholder, Steelspirit, Nightwarden, Wrathrite
 Tier 6: Peacebreaker, Warmage, Voidwalker, Lightdweller, Generic
 */

/*
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
*/
class mech_generic{
public:
    float pilot_health;
    float front_armor;
    bool primary_gun_capable;
    float primary_gun_damage;
    float primary_gun_penetration;
    string primary_gun;
    bool secondary_gun_capable;
    float secondary_gun_damage;
    float secondary_gun_penetration;
    string secondary_gun;
    bool tertiary_gun_capable;
    float tertiary_gun_damage;
    float tertiary_gun_penetration;
    string tertiary_gun;
    bool melee_capable;
    float melee_damage;
    float melee_sharpness;
    string melee_weapon;

    string mech_name;
    float mech_id;
    float tier;

    mech_generic() : pilot_health(9500), front_armor(350), primary_gun_capable(true), primary_gun_damage(300), primary_gun_penetration(300), primary_gun("Primary"),
        secondary_gun_capable(false), secondary_gun_damage(100), secondary_gun_penetration(100), secondary_gun("Secondary"), tertiary_gun_capable(false),
        tertiary_gun_damage(100), tertiary_gun_penetration(100), tertiary_gun("Tertiary"), melee_capable(false), melee_damage(100), melee_sharpness(100), 
        melee_weapon("Sword"), mech_name("Generic"), mech_id(0), tier(6) {};

};

class mech_emperor {

    //     _______                                                     
    //    |_   __ \                                                     
    //      | |_ \_| _ .--..--.  _ .--.   .---.  _ .--.   .--.   _ .--.  
    //      |  _| _ [ `.-. .-. |[ '/'`\ \/ /__\\[ `/'`\]/ .'`\ \[ `/'`\] 
    //     _| |__/ | | | | | | | | \__/ || \__., | |    | \__. | | |     
    //    |________|[___||__||__]| ;.__/  '.__.'[___]    '.__.' [___]    
    //                          [__|     

public:
    float pilot_health = 1000;
    float front_armor = 780;
    bool primary_gun_capable = true;
    float primary_gun_damage = 1260;
    float primary_gun_penetration = 1200;
    string primary_gun = "Godbreaker";
    bool secondary_gun_capable = true;
    float secondary_gun_damage = 750;
    float secondary_gun_penetration = 800;
    string secondary_gun = "Aetheric Blaster";
    bool tertiary_gun_capable = true;
    float tertiary_gun_damage = 21;
    float tertiary_gun_penetration = 2000;
    string tertiary_gun = "Godfire";
    bool melee_capable = true;
    float melee_damage = 700;
    float melee_sharpness = 2000;
    string melee_weapon = "Godslayer";

    string mech_name = "EMPEROR";
    float mech_id = 1;
    float tier = 1;

    mech_emperor() : pilot_health(1000), front_armor(1580), primary_gun_capable(true), primary_gun_damage(1560), primary_gun_penetration(1200), primary_gun("Godbreaker"),
        secondary_gun_capable(true), secondary_gun_damage(550), secondary_gun_penetration(800), secondary_gun("Godstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(21), tertiary_gun_penetration(2000), tertiary_gun("Godfire"), melee_capable(false), melee_damage(1700), melee_sharpness(2000), 
        melee_weapon("Godslayer"), mech_name("Emperor"), mech_id(1), tier(1) {};
};

class mech_panzer {
public:
    float pilot_health;
    float front_armor;
    bool primary_gun_capable;
    float primary_gun_damage;
    float primary_gun_penetration;
    string primary_gun;
    bool secondary_gun_capable;
    float secondary_gun_damage;
    float secondary_gun_penetration;
    string secondary_gun;
    bool tertiary_gun_capable;
    float tertiary_gun_damage;
    float tertiary_gun_penetration;
    string tertiary_gun;
    bool melee_capable;
    float melee_damage;
    float melee_sharpness;
    string melee_weapon;

    string mech_name;
    float mech_id;
    float tier;

    mech_panzer() : pilot_health(1250), front_armor(1850), primary_gun_capable(true), primary_gun_damage(1800), primary_gun_penetration(700), primary_gun("Ironclad"),
        secondary_gun_capable(true), secondary_gun_damage(230), secondary_gun_penetration(1100), secondary_gun("Steelstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(1550), tertiary_gun_penetration(800), tertiary_gun("Goliath"), melee_capable(false), melee_damage(0), melee_sharpness(0),
        melee_weapon("None"), mech_name("Panzer"), mech_id(2), tier(1) {};

};

class mech_artemis {
public:
    float pilot_health;
    float front_armor;
    bool primary_gun_capable;
    float primary_gun_damage;
    float primary_gun_penetration;
    string primary_gun;
    bool secondary_gun_capable;
    float secondary_gun_damage;
    float secondary_gun_penetration;
    string secondary_gun;
    bool tertiary_gun_capable;
    float tertiary_gun_damage;
    float tertiary_gun_penetration;
    string tertiary_gun;
    bool melee_capable;
    float melee_damage;
    float melee_sharpness;
    string melee_weapon;

    string mech_name;
    float mech_id;
    float tier;

    mech_artemis() : pilot_health(700), front_armor(1050), primary_gun_capable(true), primary_gun_damage(975), primary_gun_penetration(950), primary_gun("Wrath of the Stars"),
        secondary_gun_capable(true), secondary_gun_damage(670), secondary_gun_penetration(800), secondary_gun("Lance of Heaven"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(750), melee_sharpness(1600),
        melee_weapon("Astral Claw"), mech_name("Artemis"), mech_id(3), tier(1) {};

};

class mech_aegis {
public:
    float pilot_health;
    float front_armor;
    bool primary_gun_capable;
    float primary_gun_damage;
    float primary_gun_penetration;
    string primary_gun;
    bool secondary_gun_capable;
    float secondary_gun_damage;
    float secondary_gun_penetration;
    string secondary_gun;
    bool tertiary_gun_capable;
    float tertiary_gun_damage;
    float tertiary_gun_penetration;
    string tertiary_gun;
    bool melee_capable;
    float melee_damage;
    float melee_sharpness;
    string melee_weapon;

    string mech_name;
    float mech_id;
    float tier;

    mech_aegis() : pilot_health(600), front_armor(1400), primary_gun_capable(true), primary_gun_damage(1200), primary_gun_penetration(1100), primary_gun("Radiance"),
        secondary_gun_capable(false), secondary_gun_damage(0), secondary_gun_penetration(0), secondary_gun("None"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(1000), melee_sharpness(1600),
        melee_weapon("Lightblade"), mech_name("Aegis"), mech_id(4), tier(1) {};

};

