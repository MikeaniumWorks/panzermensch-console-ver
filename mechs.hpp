
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>


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
};

