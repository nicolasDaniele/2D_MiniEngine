#include <./SFML/Graphics.hpp>
#include "SpriteRendererComponent.h"

int main()
{
    sf::Vector2f viewSize(1024, 768);
    sf::VideoMode vm(viewSize.x, viewSize.y);
    sf::RenderWindow window(vm, "2D Mini Engine", sf::Style::Default);

    SpriteRendererComponent* spriteRenderer = new SpriteRendererComponent(&window);
    spriteRenderer->SetPosition(200.f, 150.f);
    spriteRenderer->SetTexture("Assets/Sprites/enemy.png");
    spriteRenderer->SetScale(3.f, 3.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        spriteRenderer->Update();
        window.display();
    }

    delete spriteRenderer;

    return 0;
}