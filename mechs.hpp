
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>


using std::string;
using std::cout;
using std::endl;

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
    string mech_description;
    int mech_id;
    int tier;


};*/


class mech_generic {
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
    string mech_description;
    int mech_id;
    int tier;


    mech_generic() : pilot_health(100000), front_armor(12500), primary_gun_capable(true), primary_gun_damage(20000), primary_gun_penetration(10000), primary_gun("Primary"),
        secondary_gun_capable(false), secondary_gun_damage(100), secondary_gun_penetration(100), secondary_gun("Secondary"), tertiary_gun_capable(false),
        tertiary_gun_damage(100), tertiary_gun_penetration(100), tertiary_gun("Tertiary"), melee_capable(false), melee_damage(100), melee_sharpness(100),
        melee_weapon("Sword"), mech_name("Generic"), mech_id(0), tier(6), mech_description(": Why would you even choose this?") {};

    void ability1() {
        std::cout << "Generic Ability Is Accessed!" << std::endl;

    }
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
    float secondary_gun_damage;
    float secondary_gun_penetration;
    string secondary_gun = "Aetheric Blaster";
    bool tertiary_gun_capable = true;
    float tertiary_gun_damage;
    float tertiary_gun_penetration;
    string tertiary_gun = "Godfire";
    bool melee_capable = true;
    float melee_damage;
    float melee_sharpness;
    string melee_weapon = "Godslayer";

    string mech_name = "EMPEROR";
    string mech_description = "Description";
    int mech_id = 1;
    int tier = 1;

    mech_emperor() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(1560), primary_gun_penetration(1800), primary_gun("Godbreaker"),
        secondary_gun_capable(true), secondary_gun_damage(550), secondary_gun_penetration(800), secondary_gun("Godstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(521), tertiary_gun_penetration(2000), tertiary_gun("Godfire"), melee_capable(false), melee_damage(1700), melee_sharpness(2000),
        melee_weapon("Godslayer"), mech_name("Emperor"), mech_id(1), tier(1), mech_description(": The Emperor of All Humanity, Entombed in This Golden Walking Coffin. Little is known by our history on how he came to be in this, But what is known, He houses immense Psionic might, His Wrath is made manifest; For all shall Show him what passes for Fury amongst their misbegotten kind.") {};

    void ability1() {
        std::cout << YELLOW << "ALL SHALL FACE THE WRATH OF HUMANITY!" << RESET << std::endl;
    }

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
    string mech_description;
    int mech_id;
    int tier;

    mech_panzer() : pilot_health(30000), front_armor(1300), primary_gun_capable(true), primary_gun_damage(2000), primary_gun_penetration(1350), primary_gun("Bulwark"),
        secondary_gun_capable(true), secondary_gun_damage(230), secondary_gun_penetration(1000), secondary_gun("Steelstorm"), tertiary_gun_capable(true),
        tertiary_gun_damage(1050), tertiary_gun_penetration(3000), tertiary_gun("Kriegrakete"), melee_capable(false), melee_damage(0), melee_sharpness(0),
        melee_weapon("None"), mech_name("Panzer"), mech_id(2), tier(1), mech_description(": Lord of All That is Iron and Steel. Panzer, Hardy, Petty, and is Resilience incarnate For; Panzer is a Warrior of Iron, Within and Without.") {};

    void ability1() {
        std::cout << RED << "BULWARK STANDS!" << RESET << std::endl;
    }
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
    string mech_description;
    int mech_id;
    int tier;

    mech_artemis() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(1400), primary_gun_penetration(2500), primary_gun("Wrath of the Stars"),
        secondary_gun_capable(true), secondary_gun_damage(670), secondary_gun_penetration(800), secondary_gun("Lance of Heaven"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(750), melee_sharpness(1600),
        melee_weapon("Astral Claw"), mech_name("Artemis"), mech_id(3), tier(1), mech_description(": Knight of The Stars and The Void that inhabits, Fast as The Eye, Never seen, Never Certain, You can never catch her; All shall Beware the Knight of Void.") {};

    void ability1() {
        std::cout << BLUE << "Artemis Lance Active!" << RESET << std::endl;
    }

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
    string mech_description;
    int mech_id;
    int tier;

    mech_aegis() : pilot_health(20000), front_armor(1800), primary_gun_capable(true), primary_gun_damage(2150), primary_gun_penetration(3000), primary_gun("Wrath of Light"),
        secondary_gun_capable(false), secondary_gun_damage(0), secondary_gun_penetration(0), secondary_gun("None"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(1000), melee_sharpness(1600),
        melee_weapon("Lightblade"), mech_name("Aegis"), mech_id(4), tier(1), mech_description(": Wrath of Light, Lord of all that is Radiant, Bar the Emperor of Course. Some say he is a God wrapped inside a Mech, Some Say its a Mech entombing a God, None know Anything; He may not even be a God.") {};

    void ability1() {
        std::cout << BRIGHT_WHITE << "YOUR DARKNESS SHALL BE BANISHED!" << RESET << std::endl;
    }

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
    string mech_description;
    int mech_id;
    int tier;

    mech_admin() : pilot_health(200000), front_armor(5000), primary_gun_capable(true), primary_gun_damage(15000), primary_gun_penetration(15000), primary_gun("B.F.G"),
        secondary_gun_capable(true), secondary_gun_damage(50000), secondary_gun_penetration(5000), secondary_gun("Arserailer"), tertiary_gun_capable(true),
        tertiary_gun_damage(200000), tertiary_gun_penetration(10), tertiary_gun("Helltickler"), melee_capable(true), melee_damage(100000), melee_sharpness(1),
        melee_weapon("Banhammer"), mech_name("Admin"), mech_id(5), tier(1), mech_description(": Administrator of all, Creator of this Realm. Some say his real name is Mikeanium, No one knows whether it is true or not; They bore a dozen names throughout their existence.") {};

    void ability1() {
        std::cout << RED << "BANHAMMER ACTIVE!" << RESET << std::endl;
    }

};

class mech_krieg {
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
    string mech_description;
    int mech_id;
    int tier;

    mech_krieg() : pilot_health(20000), front_armor(5000), primary_gun_capable(true), primary_gun_damage(2312), primary_gun_penetration(1500), primary_gun("Warbearer"),
        secondary_gun_capable(true), secondary_gun_damage(5253), secondary_gun_penetration(750), secondary_gun("Hellsallen"), tertiary_gun_capable(true),
        tertiary_gun_damage(2112), tertiary_gun_penetration(10), tertiary_gun("Verdun"), melee_capable(true), melee_damage(6000), melee_sharpness(1),
        melee_weapon("Warhammer"), mech_name("Krieg"), mech_id(6), tier(1), mech_description(": Embodiement of All that is War. Unyielding, Unrelenting, and Mighty. Legends and Myths tattle about him defeating Ares in Melee combat, Though no one knows; War is uncertain, and never changes.") {};

    void ability1() {
        std::cout << RED << "ONTO WAR!" << RESET << std::endl;
    }

};

class mech_orion {
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
    string mech_description;
    int mech_id;
    int tier;

    mech_orion() : pilot_health(18000), front_armor(2500), primary_gun_capable(true), primary_gun_damage(3165), primary_gun_penetration(1500), primary_gun("Lance of Hyguard"),
        secondary_gun_capable(true), secondary_gun_damage(1241), secondary_gun_penetration(2600), secondary_gun("Aquilon spear"), tertiary_gun_capable(false),
        tertiary_gun_damage(0), tertiary_gun_penetration(0), tertiary_gun("None"), melee_capable(true), melee_damage(0), melee_sharpness(0),
        melee_weapon("None"), mech_name("Orion"), mech_id(7), tier(1), mech_description(": A Riddle, Wrapped in a Cipher, Wrapped in an Enigma. Artemis's Greatest Rival, The only one to ever hit her; Champion of A Hundred Pantheons.") {};

    void ability1() {
        std::cout << CYAN << "FOR THE HEAVENS!" << RESET << std::endl;
    }

};
