//
// Created by alexey on 08.12.2021.
//

#ifndef ISLANDGAME_MODEL_H
#define ISLANDGAME_MODEL_H

#include "Player.h"
#include "IObservable.h"
#include "Event.h"

class Model : public IObservable {
public:
    virtual void update(Event event) override;
private:
    sf::Vector2f compute_coordinates(int type, Player &player);
    void choose_sprite(std::string &image_path, int &width, int &height);
};


#endif //ISLANDGAME_MODEL_H
