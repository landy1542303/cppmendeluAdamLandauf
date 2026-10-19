#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool mine;
    bool revealed;

public:
    Cell();

    void setMine();
    bool isMine() const;

    void reveal();
    bool isRevealed() const;
};

#endif