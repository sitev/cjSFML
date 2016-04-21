#include "cj.h"
#include "cjUI.h"
#include "cjSFML.h"

namespace cj {
	RenderWindow::RenderWindow(Control *owner) : Canvas(owner) {
		window = new sf::RenderWindow(sf::VideoMode(640, 480), "Test SFML");
	}

	RenderWindow::RenderWindow(Control *owner, int width, int height, String caption) : Canvas(owner) {
		this->setSize(Size(width, height));
		window = new sf::RenderWindow(sf::VideoMode(width, height), caption.to_string());
	}

	void RenderWindow::line(Rect rect) {}
	void RenderWindow::rectangle(Rect rect) {}
	void RenderWindow::roundRect(Rect rect, int cornerW, int cornerH) {}
	void RenderWindow::ellipse(Rect rect) {}

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
				}
				keyPress(s);

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

}