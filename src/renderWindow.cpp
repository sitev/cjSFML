#include "cj.h"
#include "cjUI.h"
#include "cjSFML.h"

namespace cj {
	RenderWindow::RenderWindow(Control *owner) : Canvas(owner) {
		window = new sf::RenderWindow(sf::VideoMode(640, 480), "Test SFML");
		m_sprite = new sf::Sprite();
	}

	RenderWindow::RenderWindow(Control *owner, int width, int height, String caption) : Canvas(owner) {
		this->setSize(Size(width, height));
		window = new sf::RenderWindow(sf::VideoMode(width, height), caption.to_string());
		m_sprite = new sf::Sprite();
	}

	void RenderWindow::line(Rect rect) {}
	void RenderWindow::rectangle(Rect rect) {}
	void RenderWindow::fillRectangle(Rect rect) {
		sf::RectangleShape rectangle(sf::Vector2f(rect.size.w, rect.size.h));
		rectangle.setPosition(sf::Vector2f(rect.pos.x, rect.pos.y));
		uchar r, g, b;
		this->color.get256(r, g, b);
		if (texture == nullptr) {
			rectangle.setFillColor(sf::Color(r, g, b));
		}
		else {
			SfmlTexture *sfmlTexture = (SfmlTexture*)texture;
			sf::Texture *sfTexture = sfmlTexture->getSfTexture();
			rectangle.setTexture(sfTexture);
			rectangle.setTextureRect(sf::IntRect(0, 0, ceil(rect.size.w), ceil(rect.size.h)));
		}
		window->draw(rectangle);
	}

	void RenderWindow::roundRect(Rect rect, int cornerW, int cornerH) {}
	void RenderWindow::ellipse(Rect rect) {}

	void RenderWindow::sprite(Rect rect, Sprite &sprite) {
		if (texture == nullptr) return;
		
		SfmlSprite *sfmlSprite = (SfmlSprite*)&sprite;
		sf::Sprite *sfSprite = sfmlSprite->getSfSprite();
		sfSprite->setPosition(rect.pos.x, rect.pos.y);
		

		/*
		SfmlTexture *sfmlTexture = (SfmlTexture*)texture;
		sf::Texture *sfTexture = sfmlTexture->getSfTexture();
		m_sprite->setTexture(*sfTexture);
		//m_sprite->setTextureRect(sf::IntRect(0, 0, ceil(rect.size.w), ceil(rect.size.h)));

		m_sprite->setPosition(rect.pos.x, rect.pos.y);
		*/
		window->draw(*sfSprite);
	}


	bool RenderWindow::isOpen() {
		return window->isOpen();
	}

	bool RenderWindow::pollEvent(sf::Event &event) {
		return window->pollEvent(event);
	}

	void RenderWindow::eventHandler() {
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:                 ///< The window requested to be closed (no data)
				window->close();
				break;
			case sf::Event::MouseButtonPressed: {  ///< A mouse button was pressed (data in event.mouseButton)
				MouseButton mb;
				switch (event.mouseButton.button) {
				case sf::Mouse::Left:
					mb = mbtLeft;
					break;
				case sf::Mouse::Right:
					mb = mbtRight;
					break;
				case sf::Mouse::Middle:
					mb = mbtMiddle;
					break;
				}

				ShiftKeys sk;
				Point pt(event.mouseButton.x, event.mouseButton.y);

				mouseDown(mb, sk, pt);
				break;
			}
			case sf::Event::MouseButtonReleased: {    ///< A mouse button was released (data in event.mouseButton)
				MouseButton mb;
				switch (event.mouseButton.button) {
				case sf::Mouse::Left:
					mb = mbtLeft;
					break;
				case sf::Mouse::Right:
					mb = mbtRight;
					break;
				case sf::Mouse::Middle:
					mb = mbtMiddle;
					break;
				}

				ShiftKeys sk;
				Point pt(event.mouseButton.x, event.mouseButton.y);

				mouseUp(mb, sk, pt);
				break;
			}

			case sf::Event::KeyPressed:             ///< A key was pressed (data in event.key)
				String s = "";
				switch (event.key.code) {
				case sf::Keyboard::E: 
					s = "E";
					break;
				case sf::Keyboard::B:
					s = "B";
					break;
				case sf::Keyboard::R:
					s = "R";
					break;
				case sf::Keyboard::S:
					s = "S";
					break;
				case sf::Keyboard::L:
					s = "L";
					break;
				default:
					int key = event.key.code;
					ShiftKeys shk;
					keyDown(key, shk);
				}
				if (s != "") keyPress(s);

				break;
				/*
					Resized,                ///< The window was resized (data in event.size)
					LostFocus,              ///< The window lost the focus (no data)
					GainedFocus,            ///< The window gained the focus (no data)
					TextEntered,            ///< A character was entered (data in event.text)
					
					KeyReleased,            ///< A key was released (data in event.key)
					MouseWheelMoved,        ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
					MouseWheelScrolled,     ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
					
					
					MouseMoved,             ///< The mouse cursor moved (data in event.mouseMove)
					MouseEntered,           ///< The mouse cursor entered the area of the window (no data)
					MouseLeft,              ///< The mouse cursor left the area of the window (no data)
					JoystickButtonPressed,  ///< A joystick button was pressed (data in event.joystickButton)
					JoystickButtonReleased, ///< A joystick button was released (data in event.joystickButton)
					JoystickMoved,          ///< The joystick moved along an axis (data in event.joystickMove)
					JoystickConnected,      ///< A joystick was connected (data in event.joystickConnect)
					JoystickDisconnected,   ///< A joystick was disconnected (data in event.joystickConnect)
					TouchBegan,             ///< A touch event began (data in event.touch)
					TouchMoved,             ///< A touch moved (data in event.touch)
					TouchEnded,             ///< A touch event ended (data in event.touch)
					SensorChanged
					*/
			}
			/*
			if (event.type == sf::Event::MouseButtonPressed)
			{
				map->mouseEventsHundler(&event);
			}
			if (event.type == sf::Event::Closed)
				window->close();
				*/
			//map->mouseEventsHundler(&event);
		}
	}

	void RenderWindow::close() {
		window->close();
	}

	void RenderWindow::clear() {
		window->clear();
	}

	void RenderWindow::display() {
		window->display();
	}

}