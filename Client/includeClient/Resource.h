//
// Created by alexey on 18.12.2021.
//

#ifndef ISLANDGAME_RESOURCE_H
#define ISLANDGAME_RESOURCE_H

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

class Resource {
public:
    sf::Font font;
    sf::Text text;
    std::string resource_count_string;
    //std::ostringstream resource_count_string;

    virtual void text_render(int resource_count, sf::Vector2f coordinates) = 0;
};

class ShipResource : public Resource {
public:
    ShipResource (const std::string& path_to_font_file) {
        font.loadFromFile(path_to_font_file);
        text = {"", font, 15};
        text.setColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
    virtual void text_render(int resource_count, sf::Vector2f coordinates) override;
};

#endif //ISLANDGAME_RESOURCE_H