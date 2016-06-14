#include "cj.h"
#include "cjUI.h"
#include "cjSFML.h"

namespace cj {

	SfmlSprite::SfmlSprite(Control *owner) : Sprite(owner) {
		sprite = new sf::Sprite();
	}


	SfmlSprite::~SfmlSprite() {
		delete sprite;
	}

	sf::Sprite* SfmlSprite::getSfSprite() {
		return sprite;
	}

	void SfmlSprite::setTexture(Texture &tx) {
		SfmlTexture* sfmlTexture = (SfmlTexture*)&tx;
		sf::Texture *sfTexture = sfmlTexture->getSfTexture();
		sprite->setTexture(*sfTexture);
	}

	void SfmlSprite::setTextureRect(Rect r) {
		sf::IntRect rect;
		rect.left = r.pos.x;
		rect.top = r.pos.y;
		rect.width = r.size.w;
		rect.height = r.size.h;

		sprite->setTextureRect(rect);
	}

	void SfmlSprite::setPosition(int x, int y) {
		sprite->setPosition(x, y);
	}

}