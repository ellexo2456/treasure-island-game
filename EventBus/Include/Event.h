//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_EVENT_H
#define ISLANDGAME_EVENT_H

#include <vector>
#include <string>

enum Types {
    user_moved,
};

enum Team {
    first,
    second,
};

struct UserMovedEventData {
    int x;
    int y;
};

struct Event {
    Types type;
    UserMovedEventData user_moved;
};

#endif //ISLANDGAME_EVENT_H
