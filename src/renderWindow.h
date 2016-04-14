#pragma once

namespace cj {
	class RenderWindow : public Canvas {
	protected:
		sf::RenderWindow *window;
	public:
		RenderWindow(Control *owner);
		RenderWindow(Control *owner, int width, int height, String caption);
	};
}