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

}