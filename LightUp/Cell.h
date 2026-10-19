#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool wall;
    bool bulb;
    bool illuminated;

public:
    Cell();
    explicit Cell(bool isWall);

    bool isWall() const;
    bool isBulb() const;
    bool isIlluminated() const;

    void setBulb();
    void setIlluminated();
    char getSymbol() const;
};

#endif