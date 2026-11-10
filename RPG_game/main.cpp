#include <SFML/Graphics.hpp>
 
int main()
{   
	size_t width = 400;
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!");
	//window.setVerticalSyncEnabled(true); //automatically set frame rate == my screen frame rate
    //window.setFramerateLimit(120); //set frame rate == my scree frame rate

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	//shape.setPosition(sf::Vector2f(100.f, 100.f));
	shape.setPosition({ 100.f, 100.f });
    bool isRed = true;

    // game loop
    while (window.isOpen())
    {  
        // event loop == process user input if any
        while (const std::optional event = window.pollEvent())
        {
			if (event->is<sf::Event::Closed>()) 
                window.close();
        }

        //update internal fame simulation 
        shape.move({ 0.1f, 0.1f });
        shape.move({ 0.1f, 0.1f });

        if (isRed){shape.setFillColor(sf::Color::Red);}
        else{shape.setFillColor(sf::Color(128, 0, 128));}

        isRed = !isRed;
        window.clear();
        window.draw(shape);

        // render current fame screen
        window.display();
    }
}

