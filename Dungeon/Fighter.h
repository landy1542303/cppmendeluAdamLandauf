#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>

class Fighter {
private:
    std::string name;
    int hp;
    int attackPower;

public:
    Fighter(const std::string& name, int hp, int attackPower);

    std::string getName() const;
    int getHp() const;
    int getAttackPower() const;
    bool isAlive() const;

    void takeDamage(int amount);
    void heal(int amount);
};

#endif