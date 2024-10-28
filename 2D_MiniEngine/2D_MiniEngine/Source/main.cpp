#include <./SFML/Graphics.hpp>
#include <stdio.h>
#include "SpriteRendererComponent.h"
#include "InputManager.h"

int main()
{
    sf::Vector2f viewSize(1024, 768);
    sf::VideoMode vm(viewSize.x, viewSize.y);
    sf::RenderWindow window(vm, "2D Mini Engine", sf::Style::Default);

    SpriteRendererComponent* spriteRenderer = new SpriteRendererComponent(&window);
    spriteRenderer->SetPosition(200.f, 150.f);
    spriteRenderer->SetTexture("Assets/Sprites/enemy.png");
    spriteRenderer->SetScale(3.f, 3.f);

    InputManager* inputManager = new InputManager();

    while (window.isOpen())
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
            window.close();
        }




        window.clear();
        spriteRenderer->Update();
        window.display();
    }

    delete spriteRenderer;
    delete inputManager;

    return 0;
}