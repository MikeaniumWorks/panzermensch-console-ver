
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
    int mech_id;
    int tier;

    mech_generic() : pilot_health(100000), front_armor(12500), primary_gun_capable(true), primary_gun_damage(20000), primary_gun_penetration(10000), primary_gun("Primary"),
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
    float pilot_health = 0;
    float front_armor = 0;
    bool primary_gun_capable = true;
    float primary_gun_damage = 0;
    float primary_gun_penetration = 0;
    string primary_gun = "Godbreaker";
    bool secondary_gun_capable = true;
    float secondary_gun_damage = 0;
    float secondary_gun_penetration = 0;
    string secondary_gun = "Aetheric Blaster";
    bool tertiary_gun_capable = true;
    float tertiary_gun_damage = 0;
    float tertiary_gun_penetration = 0;
    string tertiary_gun = "Godfire";
    bool melee_capable = true;
    float melee_damage = 0;
    float melee_sharpness = 0;
    string melee_weapon = "Godslayer";

    string mech_name = "EMPEROR";
    int mech_id = 1;
    int tier = 1;

    mech_emperor() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(1560), primary_gun_penetration(1800), primary_gun("Godbreaker"),
        secondary_gun_capable(true), secondary_gun_damage(550), secondary_gun_penetration(800), secondary_gun("Godstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(521), tertiary_gun_penetration(2000), tertiary_gun("Godfire"), melee_capable(false), melee_damage(1700), melee_sharpness(2000), 
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
    int mech_id;
    int tier;

    mech_panzer() : pilot_health(22500), front_armor(1850), primary_gun_capable(true), primary_gun_damage(2100), primary_gun_penetration(1350), primary_gun("Bulwark"),
        secondary_gun_capable(true), secondary_gun_damage(230), secondary_gun_penetration(1000), secondary_gun("Steelstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(1050), tertiary_gun_penetration(3000), tertiary_gun("Kriegrakete"), melee_capable(false), melee_damage(0), melee_sharpness(0),
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
    int mech_id;
    int tier;

    mech_artemis() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(1400), primary_gun_penetration(2500), primary_gun("Wrath of the Stars"),
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
    int mech_id;
    int tier;

    mech_aegis() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(2150), primary_gun_penetration(3000), primary_gun("Wrath of Light"),
        secondary_gun_capable(false), secondary_gun_damage(0), secondary_gun_penetration(0), secondary_gun("None"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(1000), melee_sharpness(1600),
        melee_weapon("Lightblade"), mech_name("Aegis"), mech_id(4), tier(1) {};
    
};

class mech_admin {
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
    int mech_id;
    int tier;

    mech_admin() : pilot_health(200000), front_armor(5000), primary_gun_capable(true), primary_gun_damage(15000), primary_gun_penetration(15000), primary_gun("B.F.G"),
        secondary_gun_capable(true), secondary_gun_damage(50000), secondary_gun_penetration(5000), secondary_gun("Arserailer"), tertiary_gun_capable(true),
        tertiary_gun_damage(200000), tertiary_gun_penetration(10), tertiary_gun("Helltickler"), melee_capable(true), melee_damage(100000), melee_sharpness(1),
        melee_weapon("Banhammer"), mech_name("Admin"), mech_id(5), tier(1) {};

};