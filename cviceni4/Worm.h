//
// Created by aland on 12.10.2026.
//

#ifndef CVIKO3_UKOL_WORM_H
#define CVIKO3_UKOL_WORM_H


class Worm {
private:
    int x,y;
public:
    Worm(int startX = 1, int startY = 1);
    int getX();
    int getY();
    void setPosition(int newX, int newY);
};


#endif //CVIKO3_UKOL_WORM_H
