#pragma once

#include "cjUI.h"

namespace cj {
	class RenderWindow : public Canvas {
	public:
		sf::RenderWindow *window;
	public:
		RenderWindow(Control *owner);
		RenderWindow(Control *owner, int width, int height, String caption);

		virtual void line(Rect rect);
		virtual void rectangle(Rect rect);
		virtual void roundRect(Rect rect, int cornerW, int cornerH);
		virtual void ellipse(Rect rect);

		virtual bool isOpen();
		virtual bool pollEvent(sf::Event &event);
		virtual void eventHandler();
		virtual void close();

	};
}