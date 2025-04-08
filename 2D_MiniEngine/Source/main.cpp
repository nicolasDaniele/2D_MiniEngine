#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "SpriteRendererComponent.h"
#include "InputManager.h"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}), "2D Mini Engine");
    window->setFramerateLimit(60);

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("Assets/Sprites/enemy.png"))
    {
        return -1;
    }

    SpriteRendererComponent* spriteRenderer = new SpriteRendererComponent(window, enemyTexture);
    spriteRenderer->SetPosition(200.f, 150.f);
    spriteRenderer->SetScale(3.f, 3.f);

    InputManager* inputManager = new InputManager();

    while (window->isOpen())
    {
        /*sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }*/

        inputManager->Update();


        if (inputManager->inputState.left)
        {
            printf("LEFT IS PRESSED\n");
        }
        if (inputManager->inputState.right)
        {
            printf("RIGHT IS PRESSED\n");
        }
        if (inputManager->inputState.up)
        {
            printf("UP IS PRESSED\n");
        }
        if (inputManager->inputState.down)
        {
            printf("DOWN IS PRESSED\n");
        }
        if (inputManager->inputState.escape)
        {
            printf("ESCAPE IS PRESSED\n");
            window->close();
        }

        window->clear();
        spriteRenderer->Update();
        window->display();
    }

    delete spriteRenderer;
    delete inputManager;

    return 0;
}