#pragma
struct Coordinate {
    int x;
    int y;
    Coordinate(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    Coordinate(){};
    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }
    Coordinate operator+(const Coordinate &other) const {
        return {x + other.x, y + other.y};
    }
    Coordinate operator-(const Coordinate &other) const {
        return {x - other.x, y - other.y};
    }
};

class GameObject {
    Coordinate position;
    char symbol;
public:
    GameObject(Coordinate position, char symbol) : position(position), symbol(symbol) {}
    GameObject(int x,int y, char symbol) : position(Coordinate(x,y)), symbol(symbol) {}

    Coordinate getPosition() const {
        return position;
    }

    char getSymbol() const {
        return symbol;
    }

    void setPosition(Coordinate position) {
        GameObject::position = position;
    }

    void setSymbol(char symbol) {
        GameObject::symbol = symbol;
    }

    /*bool operator==(const GameObject &other) const {
        return position == other.position && symbol == other.symbol;
    }
    bool isCollision(const GameObject &other) const {
        return position == other.position;
    }

    void move(Coordinate offset) {
        position.x += offset.x;
        position.y += offset.y;
    }
    void moveTo(Coordinate position) {
        this->position = position;
    }*/
};