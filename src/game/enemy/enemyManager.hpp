#ifndef SFMLTEST_ENEMYMANAGER_HPP
#define SFMLTEST_ENEMYMANAGER_HPP

#include "enemy.hpp"

#include <vector>
#include <algorithm>
#include <unordered_map>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>

class EnemyManager : public sf::Drawable {
public:

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void tick();

    void initialize();

    void removeEnemy(const Enemy::Ptr &enemy);

    void addEnemy(const Enemy::Ptr &enemy);

    std::size_t getEnemyCount();

    // Gets the enemy which is most advanced.
    Enemy::Ptr getMostProgressedEnemy();

private:
    std::vector<Enemy::Ptr> m_enemies;
    std::unordered_map<EnemyType, sf::Rect<int>> m_enemyTexCoords;
    sf::Texture m_enemyTextureAtlas;
};


#endif //SFMLTEST_ENEMYMANAGER_HPP