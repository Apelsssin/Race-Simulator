#pragma once
class Race {
private:
    int type;
public:
    Race(int i) {
        type = i;
    }
    int get_type();
};