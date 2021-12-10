//
// Created by alexey on 08.12.2021.
//

#ifndef ISLANDGAME_MODEL_H
#define ISLANDGAME_MODEL_H

#include <SFML/Graphics.hpp>

#include "IObservable.h"
#include "Event.h"

class Model : public IObservable {
public:
    virtual void update(Event event) override;
private:
    sf::Vector2f compute_coordinates(int type);
    void choose_sprite(std::string &image_path, int &width, int &height);
};


#endif //ISLANDGAME_MODEL_H
